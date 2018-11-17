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
    void countSort();
    void setMaxValue();
    int getMaxValue();
    int elementCount(ifstream&);
    void arrayFromFile(ifstream&);
    bool simpleSearch(int);
    void print();
    int getInteger(int);
    void setLength(int);
    int getLength();
 private:
    int* array;
    int length = 0;
    int maxValue = 0;
};
#endif
