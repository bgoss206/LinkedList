/**
 * @file nodedata.cpp
 * @brief holds and manages the data to be used within node.cpp
 * @author Braxton Goss
 */

#include "nodedata.h"

//----------------------------------------------------------------------------
// constructor
NodeData::NodeData(int n, char c) {
  num = n;
  ch = c;
}

// copy constructor
NodeData::NodeData(const NodeData &copyData) {
  num = copyData.num;
  ch = copyData.ch;
}

//----------------------------------------------------------------------------
// setData
// set data by prompting user
bool NodeData::setData() {
  cout << "Please enter an integer: ";
  cin >> num;
  cout << "Please enter a character: ";
  cin >> ch;
  return true;
}

//----------------------------------------------------------------------------
// setData
// set data from file
bool NodeData::setData(ifstream &infile) {
  infile >> num >> ch;
  return true;
}

//----------------------------------------------------------------------------
// operator<
// < defined by value of num; if nums equal, ch is used
bool NodeData::operator<(const NodeData &obj) const {
  if (num < obj.num)
    return true;
  if (num == obj.num)
    return ch < obj.ch;
  return false;
}

//----------------------------------------------------------------------------
// operator<=
bool NodeData::operator<=(const NodeData &obj) const {
  return (*this < obj) || (*this == obj);
}

//----------------------------------------------------------------------------
// operator>
// > defined by value of num; if nums equal, ch is used
bool NodeData::operator>(const NodeData &obj) const {
  if (num > obj.num)
    return true;
  if (num == obj.num)
    return ch > obj.ch;
  return false;
}

//----------------------------------------------------------------------------
// operator>=
bool NodeData::operator>=(const NodeData &obj) const {
  return (*this > obj) || (*this == obj);
}

//----------------------------------------------------------------------------
// operator==
// > defined by value of num; if nums equal, ch is used
bool NodeData::operator==(const NodeData &obj) const {
  return num == obj.num && ch == obj.ch;
}

//----------------------------------------------------------------------------
// operator!=
// > defined by value of num; if nums equal, ch is used
bool NodeData::operator!=(const NodeData &obj) const { return !(*this == obj); }

//----------------------------------------------------------------------------
// operator<<
// display NodeData object
ostream &operator<<(ostream &output, const NodeData &obj) {
  output << obj.num << ' ' << obj.ch << endl;
  return output;
}
