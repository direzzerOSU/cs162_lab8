
#include "menu.hpp"
#include "searchSort.hpp"

// integrates all functions to run the program
int main() {
   cout << endl;

   bool status = true;

   while(status) {

      // request the user to start/end the program
      introMenu(status);

      // notify the user that the program is starting
      if(status) {
         cout << endl << "Beginning program..." << endl;
         cout << "Opening files..." << endl;
      }

      else {
         break;   // end program
      }

      ifstream baselineFile, earlyFile, midFile, lateFile;

      // open all text files
      cout << endl << "Opening files..." << endl;
      baselineFile.open("/Users/ryandirezze/Documents/GitHub/cs162_lab8/baseline.txt");
      earlyFile.open("/Users/ryandirezze/Documents/GitHub/cs162_lab8/early.txt");
      midFile.open("/Users/ryandirezze/Documents/GitHub/cs162_lab8/mid.txt");
      lateFile.open("/Users/ryandirezze/Documents/GitHub/cs162_lab8/end.txt");

      // translate all text files into arrays
      cout << "Translating file contents into arrays..." << endl;

      // baseline file (no '0' included in list of integers)
      cout << endl << "Translating baseline.txt..." << endl;
      searchSort* baseline = new searchSort();
      baseline->arrayFromFile(baselineFile);
      cout << "   baseline.txt translation SUCCESSFUL" << endl;

      // '0' located at the beginning of a list of ints
      cout << endl << "Translating early.txt..." << endl;
      searchSort* early = new searchSort();
      early->arrayFromFile(earlyFile);
      cout << "   early.txt translation SUCCESSFUL" << endl;

      // '0' located at the middle of a list of ints
      cout << endl << "Translating mid.txt..." << endl;
      searchSort* mid = new searchSort();
      mid->arrayFromFile(midFile);
      cout << "   mid.txt translation SUCCESSFUL" << endl;

      // '0' located at the end of a list of ints
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

      baseline->print();

      // if true; the value is in the file
      cout << endl << "RESULTS:" << endl;
      
      // check the baseline file (value should not be found)
      if(baseline->simpleSearch(val)) {
         cout << "   baseline.txt: target value found" << endl;
      }
      else {
         cout << "   baseline.txt: target value not found" << endl;
      }

      // check the early.txt file (value should be found)
      if(early->simpleSearch(val)) {
         cout << "   early.txt:    target value found" << endl;
      }
      else {
         cout << "   early.txt:    target value not found" << endl;
      }

      // check the mid.txt file (value should be found)
      if(mid->simpleSearch(val)) {
         cout << "   mid.txt:      target value found" << endl;
      }
      else {
         cout << "   mid.txt:      target value not found" << endl;
      }

      // check the late.txt file (value should be found)
      if(late->simpleSearch(val)) {
         cout << "   late.txt:     target value found" << endl;
      }
      else {
         cout << "   late.txt:     target value not found" << endl;
      }

//      // step through each list of integers (from the file)
//      for(int n=0; n<4; n++) {
//
//         // choose the appropriate object (file/array) as the loop makes each 'step'
//         searchSort* object;
//         if(n == 0) {
//            object = baseline;
//         }
//         else if(n == 1) {
//            object = early;
//         }
//         else if(n == 2) {
//            object = mid;
//         }
//         else if(n == 3) {
//            object = late;
//         }
//
//         // print the (unsorted) array
//         cout << endl << "Preparing to sort the array..." << endl;
//         cout << endl << "   Unsorted array:" << endl;
//
//         // step through the original (unsorted) array & print
//         cout << "      ";
//         for(int k=0; k<object->getLength(); k++) {
//            cout << object->getInteger(k) << " ";
//         }
//
//         // sort the list
//         cout << endl << "   Sorting array..." << endl;
//         object->countSort();
//
//         // print the (sorted) array
//         cout << "   Sorted array:" << endl;
//         cout << "      ";
//         for(int k=0; k<object->getLength(); k++) {
//            cout << object->getInteger(k) << " ";
//         }
//      }

      // determine what the program should 'do' next
      cout << endl;
      mainMenuReturn(status);    // ask if the user would like to re-run the program
      cout << endl;
   }

   return 0;
}

