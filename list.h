/**
 * @file list.h
 * @brief Header file for the implementation of a list ADT. The list can contain
 * any type of Node<ItemType>. The itemtypes used to test this class are
 * Employee and Nodedata. But any data will work within the nodes.
 * @author Braxton Goss
 */
#ifndef LIST_H
#define LIST_H

#include "node.h"
#include <fstream>
#include <iostream>

using namespace std;

template <typename T> class List {

  /**
   * @pre list must be initialized
   * @post list is non-modiifed, text only returned
   * @param output : ostream to be returned to the caller (usually cout)
   * @param theList: list to be printed (const b/c it cannot be modified while
   * printing)
   * @return ostream with all of the elements in the list
   */
  // output operator for class List, print data,
  // responsibility for output is left to object stored in the list
  friend ostream &operator<<(ostream &output, const List<T> &thelist) {
    Node<T> *current = thelist.head;
    while (current != nullptr) {
      output << *current->getItem();
      current = current->getNext();
    }
    return output;
  }

public:
  /**
   * @pre default constructor call
   * @post item is allocated with a nullptr head
   * @return no return value, but new list is created
   */
  List(); // default constructor

  /**
   * Calls makeEmpty() to nullptr and delete entire linked list
   * @pre destructor is called automatically when a list goes out of scope or
   * when delete is explcitly called
   * @post list is completely emptied.
   */
  ~List();

  /**
   * Copy Constructor
   * @pre list is allocated using an already constructed list
   * @post caller list is full of the entire otherObject
   * @param copyList: contains the list to be copied
   */
  List(const List &copyList);

  /**
   * @pre list is already created, item being added is of the same type as the
   * current list
   * @post item is inserted into a newly allocated node of type T
   * @param T*: Pointer to the object to be added to the linked list
   * @return boolean : true if inserted correctly, false if not able to insert
   */
  bool insert(T *);

  /**
   * @pre list is initalized
   * @post list remains unchanged, caller is notified via boolean of empty or
   * not empty
   * @return boolean : true if list is fully empty, false if contains any nodes
   */
  bool isEmpty() const;

  /**
   * build a list from datafile
   * @pre ifstream is declared showing where to pull the data from
   * @post list is fully built, file remains unchanged
   * @param ifstream& : reference to the ifstream to open the file containing
   * the data
   * @return void - no return
   */
  void buildList(ifstream &);

  /**
   * @pre list is delared (empty or not)
   * @post list is changed and reordered if found,
   * caller is notified of successful removal or not, theObject points to the
   * item inside of found node
   * @param target : item to search for within the list
   * @param theObject : contains a pointer to the object that is stored within
   * the node
   * @return boolean : true if item is removed successfully, false if not found
   * within list
   */
  bool remove(const T &target, T *&theObject);

  /**
   * @pre list is already declared (can be empty or not)
   * @post list is unchanged(const method), returned boolean of retrieval
   * attempt
   * @param target: item to search for within the list
   * @param theObject : contains a pointer to the object that is stored within
   * the node
   * @return boolean : true if item match is found, false if not found
   */
  bool retrieve(const T &target, T *&theObject) const;

  /**
   * @pre lists within parameters and caller are declared (non-empty or empty)
   * @post caller is set to the merged version of both parameters, including
   * anything that may have been in the caller as well
   * @param list1 : reference to the first list to be merged (may also be the
   * same as caller)
   * @param list2 : reference to the second list to be merged (may laos be the
   * same as caller)
   * @return void return value, caller is set to the merged list
   */
  void merge(List &list1, List &list2);

  /**
   * @pre caller list is declared and both parameters are also decalred (empty
   * or non-empty)
   * @post caller list is set to the intersection points between the lists
   * unless either list is null (in which case there would be no matching
   * values)
   * @param list1 : list is declared as the same type as list2 (empty or
   * non-empty)
   * @param list2 : list is declared as same type as list1 (empty or non-empty)
   * @return void return value, caller is set to the newly allocated
   * intersections unless either parameter list is empty
   */
  void intersect(List &list1, List &list2);

  /**
   * @pre list is declared
   * @post list is made empty (mainly used within destructor)
   * @return void return value, caller is madeEmpty and each node is deleted
   */
  void makeEmpty();

  /**
   * @pre both lists being compared are declared and the same type T
   * @post both lists are not modified, result of comparison is returned
   * @param otherList : constant reference to list to be compared of itemType T
   * @return boolean value : true if not equal, false if objects are equal
   */
  bool operator!=(const List<T> &otherList) const;

  /**
   * @pre both lists being compared are declared and the same type T
   * @post both lists are not modified, result of comparison is returned
   * @param otherList : constant reference to list to be compared of itemType T
   * @return boolean value : true if equal, false if not equal
   */
  bool operator==(const List<T> &otherList) const;

  /**
   * @pre the parameter list is intialized
   * @post left hand side of caller operation is set to the contents of the
   * parameter
   * @param otherList : constant reference to list of itemType T to be copied to
   * the left-hand-side caller
   * @return new list is returned and set to the left-hand-side, anything that
   * was in the caller before is deleted.
   */
  List<T> &operator=(const List<T> &otherList);

private:
  Node<T> *head; // pointer to first node in list
};

#include "list.cpp"

#endif
