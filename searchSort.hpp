#ifndef SEARCHSORT_H
#define SEARCHSORT_H

#include<fstream>
using std::ifstream;
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<string>
using std::string;
using std::getline;
using std::stoi;
#include<cstdlib>
#include<sstream>

class searchSort {
 public:
    searchSort() {}
    ~searchSort();
    void countSort();   // Works Cited: https://brilliant.org/wiki/counting-sort/
    void setMaxValue();
    int getMaxValue();
    int elementCount(ifstream&);
    void arrayFromFile(ifstream&);
    bool simpleSearch(int);
    void print();
    int getInteger(int);
    void setLength(int);
    int getLength();
    void exportFile(std::string);
    bool binarySearch(int);
    void setFilename(std::string);
    std::string getFilename();
 private:
    int* array;
    int* originalArray;
    int length = 0;
    int maxValue = 0;
    std::string filename = "";
};
#endif
