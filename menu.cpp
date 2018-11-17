/*********************************************************************
** Program name: Circular Linked List 
** Author: Ryan DiRezze
** Date: November 11, 2018
** Description: Implements the main menu and other menu-like
   functions.
*********************************************************************/

#include "menu.hpp"

// game introduction menu
void introMenu(bool& status) {
   // introduction
   string program_name = "searchSort program in Lab 8";
   cout << "Hello! Welcome to the " << program_name << "!" << endl << endl;
   
   cout << "What would you like to do?" << endl;
   cout << "   1. Start" << endl;
   cout << "   2. Exit" << endl;
   cout << endl << "Selection: ";
   int quit;
   cin >> quit;
   intValidation(quit);

   // begin the game
   if(quit == 1) {
      status = true;
   }
   else if(quit == 2) {
      // end the game
      cout << endl;
      status = false;
   }
}

// primary menu that users use to navigate the program
void GameMenu(int& option1) {
   
   // ensure a valid character is chosen for team #1
   while(option1 != 1 && option1 != 2 && option1 != 3 && option1 != 4 && option1 != 5 && option1 != 6) {
      // menu prompt
      cout << "Please select an option from the following choices:" << endl;
      cout << "Input the option1's corresponding letter to make a selection..." << endl << endl;
      
      // menu choices
      cout << "    1. Vampire" << endl;
      cout << "    2. Barbarian" << endl;
      cout << "    3. Blue Men" << endl;
      cout << "    4. Medusa" << endl;
      cout << "    5. Harry Potter" << endl;
      cout << "    6. Exit" << endl;

      cout << endl << "Player Selection: ";
      cin >> option1;
      intValidation(option1);

      if(option1 != 1 && option1 != 2 && option1 != 3 && option1 != 4 && option1 != 5 && option1 != 6) {
         cout << endl;
         while(option1 != 1 && option1 != 2 && option1 != 3 && option1 != 4 && option1 != 5 && option1 != 6) {
            cout << "Uh oh! It looks like you didn't input a valid menu option1... Please try again." << endl << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            cout << "Team #1: ";
            cin >> option1;
            cout << endl;
         }
      }
      if(option1 == 6) {
         break;
      }
   }
}


// the main/primary menu that users arrive at after starting the program;
// this menu allows the user to navigate to various areas of the program
// to perform different transactions and view different data.
void OLD_GameMenu(char& option1) {
   // introduction
   string program_name = "Doubly-linked List";
   cout << "Hello! Welcome to the " << program_name << "!" << endl << endl;

   while(tolower(option1) != 'a' && tolower(option1) != 'b' && tolower(option1) != 'c' && tolower(option1) != 'd' && tolower(option1) != 'e' && tolower(option1) != 'f' && tolower(option1) != 'g' && tolower(option1) != 'h') {
      // menu prompt
      cout << "Please select an option from the following choices:" << endl;
      cout << "Input the option's corresponding letter to make a selection..." << endl << endl;
      
      // menu choices
      cout << "    a. Add a new node to the head" << endl;
      cout << "    b. Add a new node to the tail" << endl;
      cout << "    c. Delete the first node in the list" << endl;
      cout << "    d. Delete the last node in the list" << endl;
      cout << "    e. Traverse the list reversely (tail to head)" << endl;
      cout << "    f. Print the head node's value" << endl;
      cout << "    g. Print the tail node's value" << endl;
      cout << "    h. Exit the program" << endl << endl;

      cout << "Selection: ";
      cin >> option1;
      charValidation(option1);

      if(tolower(option1) != 'a' && tolower(option1) != 'b' && tolower(option1) != 'c' && tolower(option1) != 'd' && tolower(option1) != 'e' && tolower(option1) != 'f' && tolower(option1) != 'g' && tolower(option1) != 'h') {
         cout << endl;
         while(tolower(option1) != 'a' && tolower(option1) != 'b' && tolower(option1) != 'c' && tolower(option1) != 'd' && tolower(option1) != 'e' && tolower(option1) != 'f' && tolower(option1) != 'g' && tolower(option1) != 'h') {
            cout << "Uh oh! It looks like you didn't input a valid menu option... Please try again." << endl << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            cout << "Selection: "; 
            cin >> option1;
            cout << endl;
         }
      }
      else {
         cout << endl;
      }
      if(tolower(option1) == 'f') {
         break;
      }
   }
}

// a small prompt that asks the user if he/she would like to return to the main
// menu; this was intended to appear after the user performs some transaction
void mainMenuReturn(bool& x) {
   int option = 0;
   while(option != 9 && option != 5) {
      cout << "Do you want to return to the main menu?" << endl;
      cout << "   1. Yes" << endl;
      cout << "   2. No" << endl;
      cout << endl << "Selection: ";
      cin >> option;
      intValidation(option);

      if(option == 1) {
         x = true;
         option = 9;       // let the program escape the 'while loop' & return to the menu
      }
      
      else if(option == 2) {
         cout << endl << "Do you want to exit the program?" << endl;
         cout << "   1. Yes" << endl;
         cout << "   2. No" << endl;
         cout << endl << "Selection: ";
         cin >> option;
         intValidation(option);
         
         // escape the 'while loop' & quit the program
         if(option == 1) {
            x = false;
            option = 5;
         }
         
         // do nothing and let the program run back through the 'while loop'
         else if(tolower(option) == 2) {
            cout << endl;
            //option = 'n'
         }
      }
   }
}
