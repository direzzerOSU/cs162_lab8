/*********************************************************************
** Program name: searchSort Lab8
** Author: Ryan DiRezze
** Date: November 18, 2018
** Description: Implements the main menu and other menu-like
   functions.
*********************************************************************/

#ifndef MENU_H
#define MENU_H

#include "inputValidation.hpp"

#include<fstream>
using std::ifstream;
using std::ofstream;
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<string>
using std::string;

// function prototype for the program's menu
void introMenu(bool&);
void GameMenu(int&);
//void OLD_GameMenu(char&);
void mainMenuReturn(bool&);

#endif
