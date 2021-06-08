/**
 * @file listdriver.cpp
 * @brief tests for list.cpp class that contain nodes from node.cpp that contain
 * data from any data type, tested using employee and nodedata
 * @author Braxton Goss
 */
#include "employee.h"
#include "list.h"
#include "nodedata.h" // as a template, must add nodedata include
#include <cassert>

// testing to make sure isEmpty() returns proper values on empty lists (tested
// it on full lists in other test functions)
void testIsEmpty() {
  List<NodeData> myList;
  assert(myList.isEmpty());

  List<Employee> myListEmployee;
  assert(myListEmployee.isEmpty());
  cout << "NODEDATA AND EMPLOYEE PASSED ISEMPTY" << endl;
}

// TESTING THE = OPERATOR FOR NODEDATA AND EMPLOYEE
void testEqualsOperator() {
  /*
   * NODEDATA TEST
   */
  List<NodeData> myList;
  List<NodeData> myList2;

  ifstream infile("listdata.txt");
  if (!infile) {
    cout << "File could not be opened." << endl;
    return;
  }
  myList.buildList(infile);

  ifstream infile2("listdata2.txt");
  if (!infile2) {
    cout << "File could not be opened." << endl;
    return;
  }
  myList2.buildList(infile2);

  // testing two full lists with operator overload =
  myList = myList2;
  assert(myList == myList2);
  cout << "EQUALS OPERATOR OVERLOAD FOR NODEDATA TEST PASSED" << endl;

  /*
   * EMPLOYEE TEST
   */
  List<Employee> myListEmployees;
  List<Employee> myListEmployees2;

  ifstream infile3("employeedata.txt");
  if (!infile3) {
    cout << "File could not be opened." << endl;
    return;
  }
  myListEmployees.buildList(infile3);

  ifstream infile4("employeedata2.txt");
  if (!infile4) {
    cout << "File could not be opened." << endl;
    return;
  }
  myListEmployees2.buildList(infile4);

  myListEmployees = myListEmployees2;

  assert(myListEmployees == myListEmployees2);
  cout << "EQUALS OPERATOR OVERLOAD FOR EMPLOYEES TEST PASSED" << endl;
}

// TESTING COPY CONSTRUCTOR FOR NODEDATA AND EMPLOYEE
void testCopyConstructor() {
  /*
   * NODEDATA TEST
   */
  List<NodeData> myList;

  ifstream infile("listdata.txt");
  if (!infile) {
    cout << "File could not be opened." << endl;
    return;
  }
  myList.buildList(infile);

  // Call Copy Constructor
  List<NodeData> testingList(myList);

  assert(myList == testingList);
  cout << "ASSERT PASSED, LIST COPY CONSTRUCTOR WORKING FOR NODEDATA" << endl;

  /*
   * EMPLOYEE TEST
   */
  List<Employee> myListEmployees;

  ifstream infile2("employeedata.txt");
  if (!infile2) {
    cout << "File could not be opened." << endl;
    return;
  }
  myListEmployees.buildList(infile2);

  // call copy constr
  List<Employee> testingEmployeeList(myListEmployees);

  assert(myListEmployees == testingEmployeeList);
  cout << "ASSERT PASSED, LIST COPY CONSTRUCTOR WORKING FOR EMPLOYEE" << endl;
}

// TESTING INSERT AND RETRIEVE IN SAME TEST FOR NODEDATA AND EMPLOYEE
void testInsertAndRetrieve() {

  /*
   * NODEDATA TEST
   */
  List<NodeData> myList;

  ifstream infile("listdata.txt");
  if (!infile) {
    cout << "File could not be opened." << endl;
    return;
  }
  myList.buildList(infile);

  NodeData *ptr = new NodeData(100, 'z');
  myList.insert(ptr);
  NodeData *returnPtr;

  cout << "Testing Retrieve to get: " << *ptr;
  assert(myList.retrieve(*ptr, returnPtr));
  assert(returnPtr == ptr);
  cout << "Successfully Retrieved: " << *returnPtr;

  /*
   * EMPLOYEE TEST
   */
  List<Employee> myListEmployee;

  ifstream infile2("employeedata.txt");
  if (!infile2) {
    cout << "File could not be opened." << endl;
    return;
  }
  myListEmployee.buildList(infile2);

  Employee *ptr2 = new Employee("Archer", "James", 9834, 85000);
  myListEmployee.insert(ptr2);
  Employee *returnPtr2;

  cout << "Testing Retrieve to get: " << *ptr2;
  assert(myListEmployee.retrieve(*ptr2, returnPtr2));
  assert(returnPtr2 == ptr2);
  cout << "Successfully Retrieved: " << *returnPtr2;
}

// TESTING REMOVE FOR NODEDATA AND EMPLOYEE
void testRemove() {

  /*
   * NODEDATA TEST
   */
  List<NodeData> myList;

  ifstream infile("listdata.txt");
  if (!infile) {
    cout << "File could not be opened." << endl;
    return;
  }
  myList.buildList(infile);

  cout << "List before removal:" << endl;
  cout << endl << myList << endl;
  NodeData *ptr1 = new NodeData(44, 'c');
  NodeData *ptr2;
  cout << "attempting to remove: " << *ptr1 << endl;
  bool success = myList.remove(*ptr1, ptr2);
  if (success) {
    cout << "removed: " << *ptr2 << endl;
    delete ptr2;
    ptr2 = nullptr;
    delete ptr1;
    ptr1 = nullptr;
  } else {
    cout << "could not find " << *ptr2 << " to remove" << endl;
  }
  cout << "List after removal:" << endl;
  cout << endl << myList << endl;

  /*
   * EMPLOYEE TEST
   */
  List<Employee> myListEmployee;

  ifstream infile2("employeedata.txt");
  if (!infile2) {
    cout << "File could not be opened." << endl;
    return;
  }
  myListEmployee.buildList(infile2);

  cout << "List before removal:" << endl;
  cout << endl << myListEmployee << endl;
  Employee *ptr3 = new Employee("Depp", "Johnny", 1029, 100000);
  Employee *ptr4;
  cout << "attempting to remove: " << *ptr3 << endl;
  bool success2 = myListEmployee.remove(*ptr3, ptr4);
  if (success2) {
    cout << "removed: " << *ptr4 << endl;
    delete ptr4;
    ptr4 = nullptr;
    delete ptr3;
    ptr3 = nullptr;
  } else {
    cout << "could not find " << *ptr4 << " to remove" << endl;
  }
  cout << "List after removal:" << endl;
  cout << endl << myListEmployee << endl;
}

// TESTING EQUALITY OPERATORS == AND != ON NODEDATA AND EMPLOYEE CLASSES
void testEqualityOperators() {

  /**
   * NODEDATA TEST
   */
  List<NodeData> myList;
  List<NodeData> myList2;
  List<NodeData> myList3;

  ifstream infile("listdata.txt");
  if (!infile) {
    cout << "File could not be opened." << endl;
    return;
  }
  myList.buildList(infile);

  ifstream infile2("listdata2.txt");
  if (!infile2) {
    cout << "File could not be opened." << endl;
    return;
  }
  myList2.buildList(infile2);

  // filling myList3 with same contents from myList
  ifstream infile3("listdata.txt");
  if (!infile3) {
    cout << "File could not be opened." << endl;
    return;
  }
  myList3.buildList(infile3);

  // myList is pulling from the same file as myList3
  // TESTING !=
  assert(myList != myList2);
  assert(!(myList != myList3));
  cout << "NOT EQUALS ASSERTS PASSED FOR NODEDATA " << endl;

  // TESTING ==
  assert(myList == myList3);
  assert(!(myList == myList2));
  cout << "EQUALS ASSERTS PASSED FOR NODEDATA" << endl;

  /**
   * EMPLOYEE TEST
   */
  List<Employee> myListEmployee;
  List<Employee> myListEmployee2;
  List<Employee> myListEmployee3;

  ifstream infile4("employeedata.txt");
  if (!infile4) {
    cout << "File could not be opened." << endl;
    return;
  }
  myListEmployee.buildList(infile4);

  ifstream infile5("employeedata2.txt");
  if (!infile5) {
    cout << "File could not be opened." << endl;
    return;
  }
  myListEmployee2.buildList(infile5);

  // filling myListEmployee3 with same contents from myListEmployee
  ifstream infile6("employeedata.txt");
  if (!infile6) {
    cout << "File could not be opened." << endl;
    return;
  }
  myListEmployee3.buildList(infile6);

  // myList is pulling from the same file as myList3
  // TESTING !=
  assert(myList != myList2);
  assert(!(myList != myList3));
  cout << "NOT EQUALS ASSERTS PASSED FOR EMPLOYEE" << endl;

  // TESTING ==
  assert(myList == myList3);
  assert(!(myList == myList2));
  cout << "EQUALS ASSERTS PASSED FOR EMPLOYEE" << endl;
}

// TESTING MERGE FOR NODEDATA AND EMPLOYEE
void testMerge() {
  /**
   * NODEDATA TEST
   */
  List<NodeData> myList;  // pulls from listdata.txt
  List<NodeData> myList2; // pulls from listdata2.txt
  List<NodeData> myList3; // pulls from listdata.txt
  List<NodeData> myList4; // pulls from listdata2.txt
  List<NodeData> myList5; // pulls from listdata.txt
  List<NodeData> myList6; // pulls from listdata2.txt

  ifstream infile("listdata.txt");
  if (!infile) {
    cout << "File could not be opened." << endl;
    return;
  }
  myList.buildList(infile);

  ifstream infile2("listdata2.txt");
  if (!infile2) {
    cout << "File could not be opened." << endl;
    return;
  }
  myList2.buildList(infile2);

  // filling myList3 with same contents that are in myList
  ifstream infile3("listdata.txt");
  if (!infile3) {
    cout << "File could not be opened." << endl;
    return;
  }
  myList3.buildList(infile3);

  // filling myList4 with same contents that are in myList2
  ifstream infile4("listdata2.txt");
  if (!infile4) {
    cout << "File could not be opened." << endl;
    return;
  }
  myList4.buildList(infile4);

  ifstream infile5("listdata.txt");
  if (!infile5) {
    cout << "File could not be opened." << endl;
    return;
  }
  myList5.buildList(infile5);

  ifstream infile6("listdata2.txt");
  if (!infile6) {
    cout << "File could not be opened." << endl;
    return;
  }
  myList6.buildList(infile6);

  cout << "NodeData List1: " << endl << myList << endl;
  cout << "NodeData List2: " << endl << myList2 << endl;
  cout << "NodeData List3: " << endl << myList3 << endl;
  cout << "NodeData List4: " << endl << myList4 << endl;
  cout << "------------------------------" << endl;
  cout << endl
       << "Merging List1 with List2 (List1 is a parameter of the method)"
       << endl;
  cout << "------------------------------" << endl;
  myList.merge(myList, myList2);
  cout << myList << endl;
  assert(!myList.isEmpty());
  assert(myList2.isEmpty());
  cout << "PASSED TEST WITH SAME LIST AS PARAM" << endl;

  cout << "------------------------------" << endl;
  cout << endl
       << "Merging EmptyList with List3 and List4 as parameters of the method"
       << endl;
  cout << "------------------------------" << endl;
  List<NodeData> myEmptyList;
  myEmptyList.merge(myList3, myList4);
  cout << myEmptyList << endl;
  assert(myList3.isEmpty());
  assert(myList4.isEmpty());
  assert(!myEmptyList.isEmpty());
  cout << "PASSED TEST WITH EMPTY MERGE" << endl;

  cout << "List5: " << endl << myList5 << endl;
  cout << "List6: " << endl << myList6 << endl;
  cout << "------------------------------" << endl;
  cout << endl << "Merging non-empty with 2 other non-empty lists" << endl;
  cout << "------------------------------" << endl;

  // myEmptyList is no longer empty at this point, can use for this test
  myEmptyList.merge(myList5, myList6);
  assert(myList5.isEmpty());
  assert(myList6.isEmpty());

  cout << "All three merged:" << endl;
  cout << myEmptyList << endl;

  /**
   * NODEDATA TEST
   */
  List<Employee> myListEmployee;  // pulls from employeedata.txt
  List<Employee> myListEmployee2; // pulls from employeedata2.txt
  List<Employee> myListEmployee3; // pulls from employeedata.txt
  List<Employee> myListEmployee4; // pulls from employeedata2.txt
  List<Employee> myListEmployee5; // pulls from employeedata.txt
  List<Employee> myListEmployee6; // pulls from employeedata2.txt

  ifstream infile7("employeedata.txt");
  if (!infile7) {
    cout << "File could not be opened." << endl;
    return;
  }
  myListEmployee.buildList(infile7);

  ifstream infile8("employeedata2.txt");
  if (!infile8) {
    cout << "File could not be opened." << endl;
    return;
  }
  myListEmployee2.buildList(infile8);

  // filling myList3 with same contents that are in myList
  ifstream infile9("employeedata.txt");
  if (!infile9) {
    cout << "File could not be opened." << endl;
    return;
  }
  myListEmployee3.buildList(infile9);

  // filling myList4 with same contents that are in myList2
  ifstream infile10("employeedata2.txt");
  if (!infile10) {
    cout << "File could not be opened." << endl;
    return;
  }
  myListEmployee4.buildList(infile10);

  ifstream infile11("employeedata.txt");
  if (!infile11) {
    cout << "File could not be opened." << endl;
    return;
  }
  myListEmployee5.buildList(infile11);

  ifstream infile12("employeedata2.txt");
  if (!infile12) {
    cout << "File could not be opened." << endl;
    return;
  }
  myListEmployee6.buildList(infile12);

  cout << "Employee List1: " << endl << myListEmployee << endl;
  cout << "Employee List2: " << endl << myListEmployee2 << endl;
  cout << "Employee List3: " << endl << myListEmployee3 << endl;
  cout << "Employee List4: " << endl << myListEmployee4 << endl;
  cout << "------------------------------" << endl;
  cout << endl
       << "Merging EmployeeList1 with EmployeeList2 (EmployeeList1 is a "
          "parameter of the method)"
       << endl;
  cout << "------------------------------" << endl;
  myListEmployee.merge(myListEmployee, myListEmployee2);
  cout << myList << endl;
  assert(!myList.isEmpty());
  assert(myList2.isEmpty());
  cout << "PASSED TEST WITH SAME LIST AS PARAM" << endl;

  cout << "------------------------------" << endl;
  cout << endl
       << "Merging EmptyList with List3 and List4 as parameters of the method"
       << endl;
  cout << "------------------------------" << endl;
  List<Employee> myEmptyListEmployee;
  myEmptyListEmployee.merge(myListEmployee3, myListEmployee4);
  cout << myEmptyListEmployee << endl;
  assert(myListEmployee3.isEmpty());
  assert(myListEmployee4.isEmpty());
  assert(!myEmptyListEmployee.isEmpty());
  cout << "PASSED TEST WITH EMPTY MERGE FOR EMPLOYEE" << endl;

  cout << "Employee List5: " << endl << myListEmployee5 << endl;
  cout << "Employee List6: " << endl << myListEmployee6 << endl;
  cout << "------------------------------" << endl;
  cout << endl << "Merging non-empty with 2 other non-empty lists" << endl;
  cout << "------------------------------" << endl;

  // myEmptyList is no longer empty at this point, can use for this test
  myEmptyListEmployee.merge(myListEmployee5, myListEmployee6);
  assert(myListEmployee5.isEmpty());
  assert(myListEmployee6.isEmpty());

  cout << "All three merged:" << endl;
  cout << myEmptyListEmployee << endl;
}

// TESTING INTERSECT ON NODEDATA AND EMPLOYEE
void testIntersect() {

  /**
   * NODEDATA TEST
   */
  List<NodeData> myList;  // pulls from listdata.txt
  List<NodeData> myList2; // pulls from listdata2.txt

  ifstream infile("listdata.txt");
  if (!infile) {
    cout << "File could not be opened." << endl;
    return;
  }
  myList.buildList(infile);

  ifstream infile2("listdata2.txt");
  if (!infile2) {
    cout << "File could not be opened." << endl;
    return;
  }
  myList2.buildList(infile2);

  // blank list test
  List<NodeData> emptyList;
  emptyList.intersect(myList, myList2);
  cout << emptyList << endl;

  // same in parameter test
  myList.intersect(myList, myList2);
  cout << myList << endl;

  // non-empty list (not parameter)
  List<NodeData> myList3;
  myList3.insert(new NodeData(12, 'h'));
  myList3.insert(new NodeData(33, 'b'));
  myList3.insert(new NodeData(-5, 'z'));
  myList3.intersect(myList, myList2);
  cout << myList3 << endl;

  /**
   * EMPLOYEE TEST
   */
  List<Employee> myListEmployee;  // pulls from employeedata.txt
  List<Employee> myListEmployee2; // pulls from employeedata2.txt

  ifstream infile3("employeedata.txt");
  if (!infile3) {
    cout << "File could not be opened." << endl;
    return;
  }
  myListEmployee.buildList(infile3);

  ifstream infile4("employeedata2.txt");
  if (!infile4) {
    cout << "File could not be opened." << endl;
    return;
  }
  myListEmployee2.buildList(infile4);

  // blank list test
  List<Employee> emptyListEmployee;
  emptyListEmployee.intersect(myListEmployee, myListEmployee2);
  cout << emptyListEmployee << endl;

  // same in parameter test
  myListEmployee.intersect(myListEmployee, myListEmployee2);
  cout << myListEmployee << endl;

  // non-empty list (not parameter)
  List<Employee> myListEmployee3;
  myListEmployee3.insert(new Employee("Summers", "Angel", 5091, 90000));
  myListEmployee3.insert(new Employee("Ramirez", "Carlos", 5013, 95000));
  myListEmployee3.insert(new Employee("Goss", "Braxton", 1234, 100000));
  myListEmployee3.intersect(myListEmployee, myListEmployee2);
  cout << myListEmployee3 << endl; // should contain 3 copies of Goss Braxton
                                   // because all 3 have Goss Braxton
}

int main() {
  cout << "STARTING TESTS..." << endl << endl;

  cout << "------------------------------------" << endl;
  cout << "TESTING EQUALITY OPERATORS: == & != " << endl;
  cout << "------------------------------------" << endl;
  testEqualityOperators();
  cout << "------------------------------------" << endl;

  cout << "TESTING REMOVE" << endl;
  cout << "------------------------------------" << endl;
  testRemove();
  cout << "------------------------------------" << endl;

  cout << "TESTING INSERT AND RETRIEVE" << endl;
  cout << "------------------------------------" << endl;
  testInsertAndRetrieve();
  cout << "------------------------------------" << endl;

  cout << "TESTING INTERSECT" << endl;
  cout << "------------------------------------" << endl;
  testIntersect();
  cout << "------------------------------------" << endl;

  cout << "TESTING MERGE" << endl;
  cout << "------------------------------------" << endl;
  testMerge();
  cout << "------------------------------------" << endl;

  cout << "------------------------------------" << endl;
  cout << "TESTING LIST COPY CONSTRUCTOR" << endl;
  cout << "------------------------------------" << endl;
  testCopyConstructor();
  cout << "------------------------------------" << endl;

  cout << "------------------------------------" << endl;
  cout << "TESTING EQUALS OPERATOR" << endl;
  cout << "------------------------------------" << endl;
  testEqualsOperator();
  cout << "------------------------------------" << endl;

  cout << "------------------------------------" << endl;
  cout << "TESTING ISEMPTY" << endl;
  cout << "------------------------------------" << endl;
  testIsEmpty();
  cout << "------------------------------------" << endl;

  return 0;
}