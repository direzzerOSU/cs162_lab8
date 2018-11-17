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
 private:
    int* array;
    int* unsortedArray;
    int length = 0;
    int maxValue = 0;
};
#endif
