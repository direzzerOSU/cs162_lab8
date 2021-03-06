/*********************************************************************
** Program name: searchSort Lab8
** Author: Ryan DiRezze
** Date: November 18, 2018
** Description: Implementation of functions when searching & sorting.
*********************************************************************/

#include "searchSort.hpp"

// deconstructor
searchSort::~searchSort() {
   if(array != nullptr) {
      delete[] array;
   }
   if(originalArray != nullptr) {
      delete[] originalArray;
   }
}

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
//      cout << "   Counting the number of elements in the current file..." << endl;

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
//      cout << "   File opened successfully..." << endl;
      length = elementCount(inputFile);
      array = new int[length];
      inputFile.seekg(0, inputFile.beg);
      inputFile.clear();

      // execute the loop until the file is empty
//      cout << "   Beginning to loop through file's elements..." << endl;
      std::string elem;
      int n=0;
      
      while(inputFile.good()) {
         char a;
         int b;
         inputFile.get(a);
         std::stringstream ss;
         ss << a;

         // check if the end of file was flagged when trying to read another char
         if(!inputFile.good()) {
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

   setMaxValue();
}

// linear search function
bool searchSort::simpleSearch(int value) {
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

// returns an integer at a specific location within the array
int searchSort::getInteger(int location) {
   return array[location];
}

// updates the max (largest) value within the object's array
void searchSort::setMaxValue() {
   int value = -10;
   for(int n=0; n<length; n++) {
      if(array[n] > value) {
         value = array[n];
      }
   }
   maxValue = value;  // value = largest (max) value in the array
}

// returns the largest value (integer) found within the array
int searchSort::getMaxValue() {
   return maxValue;
}

// exports the object's array to a text file
void searchSort::exportFile(std::string filename) {

   std::ofstream outputFile(filename, std::ofstream::out);

   for(int n=0; n<length; n++) {
      outputFile << array[n];
   }

   outputFile.close();
}

// sorts a list of integers with the 'counting sort' algorithm
void searchSort::countSort() {
   originalArray = array;

   int* sortedArray = new int[length];   // sorted [updated] array
   int* arrayCounts;    // track the count of ints smaller than the value of the array's index

//   setMaxValue();

   arrayCounts = new int[maxValue+1];  // element for each value within the original (unsorted) array

   for(int n=0; n<=maxValue; n++) {
      arrayCounts[n] = 0;
   }
   
   // count the frequency of integer values within the (unsorted) array
   for(int n=0; n<length; n++) {
      arrayCounts[array[n]] += 1;
   }

   int y = 0;     // keep track of the element location within the (sorted) array

   // print the sorted array
   
   // step through the 'keys' (int values from the unsorted array) with frequency counts
   for(int n=0; n<=maxValue; n++) {

      // step through the frequency count of each 'key' (value of an int from the (unsorted) array
      for(int k=0; k<arrayCounts[n]; k++) {
         sortedArray[y] = n;     // place the 'key' (int value) in the next spot of the array
         y++;  // add 1 to indicate the 'next' location/element in the (sorted) array
      }
   }

   // update & sort the object's array
   int* temp = array;
   array = sortedArray;

//   delete temp;   // free (unsorted) array memory
   delete[] arrayCounts;     // free frequency count array memory
//   delete sortedArray;
}

// search for an integer with binary search
bool searchSort::binarySearch(int searchVal) {
   int low, mid, high, diff;
   low = 0;
   high = length-1;

//   cout << "Searching for " << searchVal << "..." << endl;

   // cut the search area in half until range is searched
   while(low <= high) {
      mid = (low + high)/2;

//      cout << endl << "low[" << low << "] = " << array[low] << endl;
//      cout << "high[" << high << "] = " << array[high] << endl;
//      cout << "mid[" << mid << "] =  " << array[mid] << endl;

      if(array[mid] == 0) {
 //        cout << endl << "searchValue found!" << endl;
         return true;
      }
      else if(array[mid] > searchVal) {
         high = mid-1;
      }
      else if(array[mid] < searchVal) {
         low = mid+1;
      }
   }
   return false;   
}

// sets an object's (output) filename
void searchSort::setFilename(std::string x) {
   filename = x;
}

// returns an object's (output) filename
std::string searchSort::getFilename() {
   return filename;
}
