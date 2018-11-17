// implementation of basic searching algorithms with text files as inputs

#include "searchSort_v3.hpp"

// sets the length of the object
void searchSort::setLength(int x) {
   length = x;
}

// returns the length of the object
int searchSort::getLength() {
   return length;
}

// count the # of elements in a text file
int searchSort::elementCount(ifstream& inputFile) {
   inputFile.seekg(0, inputFile.beg);
   inputFile.clear();
   int val;
   std::string elem;

   if(inputFile) {
      cout << "   Counting the number of elements in the current file..." << endl;

      while(inputFile.good()) {
         inputFile >> elem;
      }
      
   }

//   cout << "      elem.length() = " << elem.length() << endl;
   return elem.length();
}

// translates an array from a text file into an array for use within the program
void searchSort::arrayFromFile(ifstream& inputFile) {

   // verify the file opens successfully
   if(inputFile) {
      cout << "   File opened successfully..." << endl;
      length = elementCount(inputFile);
      array = new int[length];
      inputFile.seekg(0, inputFile.beg);
      inputFile.clear();

      // execute the loop until the file is empty
      cout << "   Beginning to loop through file's elements..." << endl;
      std::string elem;
      int n=0;
      
      while(inputFile.good()) {
         char a;
         int b;
         inputFile.get(a);
         std::stringstream ss;
         ss << a;

         // check if the end of file was flagged when trying to read another char
         if(inputFile.good()) {
            break;
         }

         ss >> b;
         array[n] = b;
//         cout << "array[" << n << "] = " << array[n] << endl;
         n++;
      }
   }
   else {
      cout << "   File unable to open..." << endl;
   }
}

// linear search function
bool searchSort::search(int value) {
//bool searchSort::search(int value) {
   for(int n=0; n<length; n++) {
//      cout << "array[" << n << "] = " << array[n] << endl;
      if(array[n] == value) {
         return true;   // if the value is found
      }
   }
   return false;  // if the value isn't found
}

void searchSort::print() {
   for(int n=0; n<length; n++) {
      cout << "array[" << n << "] = " << array[n] << endl;
   }
}

