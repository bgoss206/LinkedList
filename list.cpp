/**
 * @file list.cpp
 * @brief Implementation of the List ADT, can contain any type of Node<itemType>
 * @author Braxton Goss
 */
#include "node.h"

// Constructor for empty parameter initalization
template <typename T> List<T>::List() { head = nullptr; }

// destructor
template <typename T> List<T>::~List() {
  makeEmpty(); // simply calls the makeEmpty() method on current list
}

// copy constructor
template <class T> List<T>::List(const List<T> &copyList) {
  head = new Node<T>(*copyList.head);
  Node<T> *tempCurr = head;
  Node<T> *tempOther = copyList.head->getNext();
  while (tempOther) {
    tempCurr->setNext(new Node<T>(*tempOther));
    tempCurr = tempCurr->getNext();
    tempOther = tempOther->getNext();
  }
}

/**
 * isEmpty
 * check to see if List is empty as defined by a NULL head
 */
template <typename T> bool List<T>::isEmpty() const {
  return (head == nullptr);
}

/**
 * insert
 * insert an item into list; operator< of the T class
 * has the responsibility for the sorting criteria
 */
template <typename T> bool List<T>::insert(T *data) {

  Node<T> *ptr = new Node<T>();
  if (ptr == nullptr) {
    return false;
  } // out of memory, bail

  ptr->setItem(data); // link the node to data

  // if the list is empty or if the node should be inserted before
  // the list1 node of the list
  if (isEmpty() || *ptr->getItem() < *head->getItem()) {
    ptr->setNext(head);
    head = ptr;
  }

  // then check the rest of the list until we find where it belongs
  else {
    Node<T> *tail = head->getNext(); // to walk list
    Node<T> *previous = head;        // to walk list, lags behind

    // walk until end of the list or found position to insert
    while (tail != nullptr && *tail->getItem() < *ptr->getItem()) {
      previous = tail; // walk to next node
      tail = tail->getNext();
    }

    // insert new node, link it in
    ptr->setNext(tail);
    previous->setNext(ptr);
  }
  return true;
}

/**
 * buildList
 * continually insert new items into the list
 */
template <typename T> void List<T>::buildList(ifstream &infile) {
  T *ptr;
  bool successfulRead; // read good data
  bool success;        // successfully insert
  for (;;) {
    ptr = new T;
    successfulRead = ptr->setData(infile); // fill the T object
    if (infile.eof()) {
      delete ptr;
      ptr = nullptr;
      break;
    }

    // insert good data into the list, otherwise ignore it
    if (successfulRead) {
      success = insert(ptr);
    } else {
      delete ptr;
      ptr = nullptr;
    }

    // if item was not inserted, throw it away
    if (!success) {
      delete ptr;
      ptr = nullptr;
    }
  }
}

/**
 * Remove
 * takes a single target and another reference pointer to theObject
 * The list2 parameter will point to the removed object for the driver class to
 * use If the target node is found, it is deleted from the list and memory
 */
template <typename T> bool List<T>::remove(const T &target, T *&theObject) {
  bool success = false;

  Node<T> *prev = nullptr; // starts by pointing to head
  Node<T> *curr = head;    // starts by pointing to head
  theObject = nullptr;

  // checking for target
  while (curr != nullptr) {
    if ((*(curr->getItem()) == target)) { // target found
      if (prev == nullptr) {              // if we're at the head
        if (curr->getNext() ==
            nullptr) {    // if there's no more elements past the head
          head = nullptr; // null it out
        } else { // if there is an element past the head, set the head to next
          head = curr->getNext();
        }
      } else { // if we're not at the head, skip over it
        prev->setNext(curr->getNext());
      }
      // delete either way b/c found
      theObject = curr->getItem();
      curr->setItem(nullptr);
      delete curr;
      success = true;
      break;
    } else { // if not found at tail iteration, traverse further
      prev = curr;
      curr = curr->getNext();
    }
  }
  return success; // return either found = true or not found = false
}

/**
 * retrieve
 * Similar to remove, target's object will be sent back in theObject
 * but it will NOT be deleted from the list or memory
 */
template <typename T>
bool List<T>::retrieve(const T &target, T *&theObject) const {
  bool success = false;
  theObject = nullptr;
  Node<T> *curr = head; // starts by pointing to head

  // checking for target
  while (curr != nullptr) {
    if ((*(curr->getItem()) == target)) { // target found
      theObject = curr->getItem(); // get item ptr and give it to return object
      success = true;              // object was found
      break;
    } else { // otherwise, traverse
      curr = curr->getNext();
    }
  }
  return success; // return either found = true or not found = false
}

// two cases that merge needs to work on
// list1.merge(list1, list2);
// list1.merge(list2, list3);

/**
 * Merge
 * two lists together into the current list. Duplicates are allowed
 * No new memory is allocated. If the caller list is non-empty, will also merge
 * with the lists
 */
template <typename T> void List<T>::merge(List<T> &list1, List<T> &list2) {
  Node<T> *list1Node = list1.head;
  Node<T> *list2Node = list2.head;

  Node<T> *tempHead; // dummy head used to store the location of the merged list
  Node<T> *tail;     // used for traversal and appending to the linked list

  // figuring out which head to start with
  if (*list1Node->getItem() < *list2Node->getItem()) {
    tail = list1Node;
    tempHead = list1Node;
    list1Node = list1Node->getNext();
  } else {
    tail = list2Node;
    tempHead = list2Node;
    list2Node = list2Node->getNext();
  }

  // traverse
  while (list1Node && list2Node) {
    if (*list1Node->getItem() < *list2Node->getItem()) {
      tail->setNext(list1Node);
      list1Node = list1Node->getNext();

    } else {
      tail->setNext(list2Node);
      list2Node = list2Node->getNext();
    }
    tail = tail->getNext();
  }

  // add on extra from other remaining nodes (can assume they are greater due to
  // comparison)
  if (list1Node) {
    tail->setNext(list1Node);
  }
  if (list2Node) {
    tail->setNext(list2Node);
  }

  // at this point, both parameter lists are merged into tempHead
  list1.head = nullptr;
  list2.head = nullptr;

  // SPECIAL CASE CHECK: FULL CALLER LIST (this)
  // if the calling list (this) is not an empty list i.e.
  // NonEmptyList.merge(list1, list2)
  if (!(this->isEmpty())) {
    list2.head =
        tempHead; // merged list is now passed to merge with current list
    this->merge(*this, list2); // recursively call to merge 3 lists into 1 list
  } else {                 // if the calling list (this) IS an empty list i.e
                           // emptyList.merge(list1, list2)
    this->head = tempHead; // set list, method over
    return;
  }
}

/**
 *
 * intersect
 * given two lists, set the caller list to the intersections of those two lists
 */
template <typename T> void List<T>::intersect(List<T> &list1, List<T> &list2) {

  // if either list is empty, there will be no intersection points
  if (list1.isEmpty() || list2.isEmpty()) {
    if (!this->isEmpty()) { // if the caller list is a non-empty list
      makeEmpty();
    }
    return;
  }

  // CASE #1: caller list empty
  if (!head) {
    Node<T> *currTraversal = list1.head;
    Node<T> *otherTraversal = list2.head;
    while (currTraversal != nullptr) { // traverse parameter list1
      otherTraversal = list2.head; // reset traversal node for list2 each loop
      while (otherTraversal != nullptr) {
        if (*(currTraversal->getItem()) ==
            *(otherTraversal->getItem())) { // match found
          this->insert(
              (new T(*(currTraversal->getItem())))); // insert to caller list
        }
        otherTraversal = otherTraversal->getNext();
      }
      currTraversal = currTraversal->getNext();
    }
  } else if (*this == list1) { // CASE #2: if caller list is the first parameter
    List<T> listOfMatches;
    Node<T> *currTraversal = head;
    Node<T> *otherTraversal = list2.head;
    while (
        currTraversal) { // traverse current list since it is the same as list1
      otherTraversal = list2.head; // reset traversal node for list2 each loop
      while (otherTraversal) {
        if (*(currTraversal->getItem()) ==
            *(otherTraversal->getItem())) { // match found
          listOfMatches.insert((new T(*(
              currTraversal->getItem())))); // store in temporary listOfMatches
        }
        otherTraversal = otherTraversal->getNext();
      }
      currTraversal = currTraversal->getNext();
    }
    *this = listOfMatches; // set temporary listOfMatches to the caller list

  } else if (*this ==
             list2) { // CASE #3: if caller list is the second parameter
    List<T> listOfMatches;
    Node<T> *currTraversal = list1.head;
    Node<T> *otherTraversal = head;

    while (currTraversal != nullptr) {
      otherTraversal =
          list2.head; // reset traverssal node for caller traversal each loop
      while (otherTraversal != nullptr) {
        if (*(currTraversal->getItem()) ==
            *(otherTraversal->getItem())) { // match found
          listOfMatches.insert((new T(*(
              currTraversal->getItem())))); // store in temporary listOfMatches
        }
        otherTraversal = otherTraversal->getNext();
      }
      currTraversal = currTraversal->getNext();
    }
    *this = listOfMatches; // set temporary listOfMatches to the caller list

  } else { // CASE #4: if the caller list is non-empty and not also a parameter
    makeEmpty(); // delete everything in it since they will not be relevant to
                 // the matches
    Node<T> *currTraversal = list1.head;
    Node<T> *otherTraversal = list2.head;
    while (currTraversal != nullptr) { // traverse list1
      otherTraversal = list2.head; // reset list2 traversal each list1 iteration
      while (otherTraversal != nullptr) {
        if (*(currTraversal->getItem()) ==
            *(otherTraversal->getItem())) { // match found
          insert((new T(*(currTraversal->getItem()))));
        }
        otherTraversal = otherTraversal->getNext();
      }
      currTraversal = currTraversal->getNext();
    }
  }
  return; // end of method
}

/**
 * Operator==
 * tests two lists for equality
 * relies on the contained object's != operator to find any mismatched items
 */
template <typename T> bool List<T>::operator==(const List<T> &otherList) const {
  bool success = true;

  // if they're both empty, they're equal
  if (this->isEmpty() && otherList.isEmpty()) {
    return success;
  }

  // traversal pointers starting at each list head
  Node<T> *thisHead = head;
  Node<T> *otherHead = otherList.head;

  // while both have more items to traverse, traverse them both equally
  while (thisHead != nullptr && otherHead != nullptr) {
    if (*thisHead->getItem() != *otherHead->getItem()) {
      success = false; // if something is found to be not equal within item
                       // comparison, lists don't match -- exit loop
      break;
    } else { // if both items in current iteration are the same, keep traversing
      thisHead = thisHead->getNext();
      otherHead = otherHead->getNext();
      continue;
    }
  }
  return success; // if lists are found to be fully equal, success = true. if
                  // items were found to be different, success = false
}

/**
 * Not equals !=
 * operator will always be the opposite of ==
 * return the opposite of the == operator
 */
template <typename T> bool List<T>::operator!=(const List<T> &otherList) const {
  return !(*this == otherList); // just return the opposite of the == function
}

/**
 * Operator overload for =
 * creates a deep copy of the otherList and returns to the left-hand-side list
 * new memory is allocated using the copy construtor
 */
template <typename T> List<T> &List<T>::operator=(const List<T> &otherList) {
  makeEmpty(); // ensure Left-Hand-Side is empty prior to setting

  // set equal using same code from list copy constructor
  head = new Node<T>(*otherList.head);
  Node<T> *tempCurr = head;
  Node<T> *tempOther = otherList.head->getNext();
  while (tempOther) {
    tempCurr->setNext(new Node<T>(*tempOther));
    tempCurr = tempCurr->getNext();
    tempOther = tempOther->getNext();
  }
  return *this;
}

/**
 * MakeEmpty()
 * traverses the list, moving head and deleting until it is completely empty
 */
template <typename T> void List<T>::makeEmpty() {
  while (head) {                  // while there are still nodes to traverse
    Node<T> *nodeToDelete = head; // temp head for deletion
    head = head->getNext();       // increment head
    delete nodeToDelete;
    nodeToDelete = nullptr; // clean up memory
  }
}