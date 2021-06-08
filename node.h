/**
 * @file node.h
 * @brief Modified from the Node class by Frank M. Carrano and Timothy M. Henry.
 * @author Braxton Goss
 */
#ifndef NODE_
#define NODE_

template <class ItemType> class Node {
private:
  ItemType *itemPtr;    // Pointer to a data item
  Node<ItemType> *next; // Pointer to next node

public:
  /**
   * @pre default constructor, no preconditions
   * @post node is initalized empty and nullptr to next
   */
  Node();

  /**
   * @pre caller node is set to contain the itemType within parameter
   * @post node is allocated
   * @param anItemPtr : contains an object of type ItemType to be set within the
   * node for data
   */
  Node(ItemType *anItemPtr);

  /**
   * @pre list is declared with 2 parameters, an data type, and a next pointer
   * @post list is initialized with both private data members intialized
   * @param anItemPtr : points to the data to be stored in the node
   * @param nextNodePtr : points to the next node
   */
  Node(ItemType *anItemPtr, Node<ItemType> *nextNodePtr);

  /**
   * Node Copy Constructor
   * @pre both nodes are declared either within the calling statement or prior
   * @post caller node is set to the Node passed within the parameters
   * @param Node : node to be copied to the caller node
   */
  Node(const Node<ItemType> &Node);

  /**
   * @pre - node is declared
   * @post - node is deleted and memory is deallocated
   */
  ~Node();

  /**
   * @pre caller node is already declared
   * @post caller node's item pointer is set to ItemType of the parameter
   * @param anItemPtr : contains a pointer to the data to be stored within this
   * node
   * @return void return value - item is set
   */
  void setItem(ItemType *anItemPtr);

  /**
   * @pre caller node is already declared
   * @post caller node's next pointer is set to the node within the parameter
   * @param nextNodePtr : contains a pointer to the next node to be set within
   * this caller's next variable
   * @return void return value - next is set
   */
  void setNext(Node<ItemType> *nextNodePtr);

  /**
   * @pre caller's item is either nullptr or set
   * @post caller's item is returned
   * @return pointer to the Item is returned
   */
  ItemType *getItem() const;

  /**
   * @pre caller's next is either nullptr or set to next
   * @post caller's next is returned
   * @return pointer to the next node is returned
   */
  Node<ItemType> *getNext() const;
};

#include "node.cpp"
#endif