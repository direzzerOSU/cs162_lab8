/*********************************************************************
** Program name: searchSort Lab8
** Author: Ryan DiRezze
** Date: November 18, 2018
** Description: Defines input validation functions.
*********************************************************************/

// begin the include guard
#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

// include the files that are required for the input validation function to run properly
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<string>
#include<limits>

// works cited
   // (1) http://www.cplusplus.com/reference/istream/istream/ignore/

// function prototype

// validate the user's input is the correct type (i.e., int and char, respectively)
void intValidation(int&);
void charValidation(char&);
void charValidationOnly(char&);
void floatValidation(float& value);

// check for a valid yes or no selection from user input
void validYesNo(char&);

// validate the user's input is a correct menu option (tailored to the OSU IMS, Lab4, assignment)
void validMMChoice(char&);
void validBldgChoice(char& value);
void validTypeChoice(char& value);

#endif   // end of include guard
