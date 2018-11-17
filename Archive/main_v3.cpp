
#include "menu.hpp"
#include "searchSort.hpp"

// integrates all functions to run the program
int main() {
   cout << endl;

   bool status = true;

   while(status) {

      introMenu(status);
      ifstream baselineFile, earlyFile, midFile, lateFile;

      // open all text files
      cout << endl << "Opening files..." << endl;
      baselineFile.open("/Users/ryandirezze/Documents/GitHub/cs162_lab8/baseline.txt");
      earlyFile.open("/Users/ryandirezze/Documents/GitHub/cs162_lab8/early.txt");
      midFile.open("/Users/ryandirezze/Documents/GitHub/cs162_lab8/mid.txt");
      lateFile.open("/Users/ryandirezze/Documents/GitHub/cs162_lab8/end.txt");

//      int* baselineArray;
//      int baselineLength = elementCount(baselineFile);
//      int* earlyArray;
//      int earlyLength = elementCount(earlyFile);
//      int* midArray;
//      int midLength = elementCount(midFile);
//      int* lateArray;
//      int lateLength = elementCount(lateFile);

//      if(baselineFile) {
//         std::string text;
//         baselineFile >> text;
//         cout << text << endl;
//      }

      // translate all text files into arrays
      cout << endl << "Translating file contents into arrays..." << endl;
      cout << endl << "Translating baseline.txt..." << endl;
      searchSort* baseline = new searchSort();
      baseline->arrayFromFile(baselineFile);
      cout << "   baseline.txt translation SUCCESSFUL" << endl;
      cout << endl << "Translating early.txt..." << endl;
      searchSort* early = new searchSort();
      early->arrayFromFile(earlyFile);
      cout << "   early.txt translation SUCCESSFUL" << endl;
      cout << endl << "Translating mid.txt..." << endl;
      searchSort* mid = new searchSort();
      mid->arrayFromFile(midFile);
      cout << "   mid.txt translation SUCCESSFUL" << endl;
      cout << endl << "Translating late.txt..." << endl;
      searchSort* late = new searchSort();
      late->arrayFromFile(lateFile);
      cout << "   late.txt translation SUCCESSFUL" << endl;

      // what value should be searched for?
      cout << endl << "What number should be searched for? (0 - 9, inclusive)" << endl;
      cout << "   Number: ";
      int val = -5;
      cin >> val;
      intValidation(val);  // validate the input is an integer

      // make sure the user inputs a value <= 9
      while(val >= 10) {
         cout << "Whoops! You entered a number that's too big... \nPlease enter a number from 1 to 9, inclusive..." << endl;
         cout << "   Number: ";
         cin >> val;
         intValidation(val);
      }

      // if true; the value is in the file
      cout << endl << "RESULTS:" << endl;

//      cout << "Baseline: " << endl;
//      baseline->print();
      
      // check the baseline file (value should not be found)
      if(baseline->simpleSearch(val)) {
         cout << "   baseline.txt: target value found" << endl;
      }
      else {
         cout << "   baseline.txt: target value not found" << endl;
      }

//      cout << endl;

      // check the early.txt file (value should be found)
      if(early->simpleSearch(val)) {
         cout << "   early.txt:    target value found" << endl;
      }
      else {
         cout << "   early.txt:    target value not found" << endl;
      }

//      cout << endl;

      // check the mid.txt file (value should be found)
      if(mid->simpleSearch(val)) {
         cout << "   mid.txt:      target value found" << endl;
      }
      else {
         cout << "   mid.txt:      target value not found" << endl;
      }

//      cout << endl;

      // check the late.txt file (value should be found)
      if(late->simpleSearch(val)) {
         cout << "   late.txt:     target value found" << endl;
      }
      else {
         cout << "   late.txt:     target value not found" << endl;
      }

      cout << endl;

      mainMenuReturn(status);

      cout << endl;
   }

   return 0;
}

