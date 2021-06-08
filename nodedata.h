/**
 * @file nodedata.h
 * @brief Simple object containing one integer and one character (used as type
 * for node class)
 * @author Braxton Goss
 */

#ifndef NODEDATA_H
#define NODEDATA_H

#include <fstream>
#include <iostream>
using namespace std;

//---------------------------  class NodeData  ------------------------------
class NodeData { // incomplete class
  friend ostream &operator<<(ostream &, const NodeData &);

public:
  /**
   *@pre NodeData object is declared within this call
   *@post NodeData object's fields are set to either the default values of 0 and
   *'z' or the parameters sent
   *@param int - integer to be stored
   *@param char - character to be stored
   */
  NodeData(int n = 0, char c = 'z'); // default constructor

  /**
   *@pre NodeData object is already declared
   *@post NodeData data is set with user prompt
   *@return boolean value : true if setting data was successful, false otherwise
   */
  bool setData(); // sets data by prompting user

  /**
   *@pre NodeData object is already declared
   *@post NodeData object's data is set from a file read
   *@param stream : contains the file information to read in the data
   *@return boolean value : true if setting data from file was successful, false
   *otherwise
   */
  bool setData(ifstream &stream); // reads data from file

  /**
   *@pre Copy Constructor - both objects are declared
   *@post caller NodeData is a deepcopy set to the contents of copyData
   *parameter
   *@param copyData : contains NodeData to be copied
   */
  NodeData(const NodeData &copyData);

  // <, > are defined by order of num; if nums are equal, ch is compared
  bool operator<(const NodeData &) const;
  bool operator>(const NodeData &) const;
  bool operator==(const NodeData &) const;
  bool operator!=(const NodeData &) const;
  bool operator<=(const NodeData &) const;
  bool operator>=(const NodeData &) const;

private:
  int num; // private number
  char ch; // private character
};

#endif
