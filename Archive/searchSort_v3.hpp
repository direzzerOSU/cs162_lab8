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
    int elementCount(ifstream&);
    void arrayFromFile(ifstream&);
    bool search(int);
    void print();
    void setLength(int);
    int getLength();
 private:
    int* array;
    int length = 0;
};
#endif
