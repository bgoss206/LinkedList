/**
 * @file employee.h
 * @brief holds the employee class for testing list.cpp
 * @author Braxton Goss
 */
#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

const int MAXID = 9999;

class Employee {

  // prints out the employee data
  friend ostream &operator<<(ostream &, const Employee &);

public:
  /**
   * @pre employee is declared with any amount of parameters
   * @post employee  is intialized with 4 values,
   * @param default values will result if parameters of initialization are not
   * passed
   */
  Employee(string = "dummyLast", string = "dummyFirst", int = 0, int = 0);

  /**
   * Copy Constructor
   * @pre employee is declared prior or during statement with same type as
   * copyEmployee
   * @post caller employee is set to the copyEmployee contents
   * @param copyEmployee : employee to be copied
   */
  Employee(const Employee &copyEmployee);

  /**
   * @pre ifstream is declared with file containing data to be set to the
   * employee
   * @post file is not modified, employee object intialized with data from line
   * in file
   * @param stream : file containing data for employee iniitalization
   * @return boolean value : true if data set correctly, false if not
   */
  bool setData(ifstream &stream); // fill object with data from file

  /**
   * @pre object is properly initialized
   * @post employee is not changed, private value of ID returned
   * @return string containing the caller employee's ID number
   */
  string getID();

  /**
   * @pre object is properly initalized
   * @post employee is not changed, private value of salary is returned
   * @return string containing te caller employee's salary
   */
  string getSalary();

  /**
   * @pre object is properly initialized
   * @post employee is not changed, private value of firstName is returned
   * @return string containing caller employee's firstName is returned
   */
  string getFirstName();

  /**
   * @pre object is properly intiialized
   * @post employee is not changed, private value of lastName is returned
   * @return string containing caller employee's lastName is returned
   */
  string getLastName();

  /**
   * @pre object being copied is initiailized properly
   * @post caller object (left-hand-side) is changed to the object inside the
   * parameter
   * @param copyEmployee : not changed, copied to the caller
   * @return employee to be set to the left-hand-side of the caller
   */
  Employee &operator=(const Employee &copyEmployee);

  // comparison operators
  bool operator<(const Employee &) const;
  bool operator<=(const Employee &) const;
  bool operator>(const Employee &) const;
  bool operator>=(const Employee &) const;
  bool operator==(const Employee &) const;
  bool operator!=(const Employee &) const;

private:
  string lastName;  // employee's last name
  string firstName; // employee's first name
  int idNumber;     // employee's ID number
  int salary;       // employee's salary
};

#endif
