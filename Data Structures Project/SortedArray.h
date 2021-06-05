#ifndef DATA_STRUCTURES_PROJECT_SORTEDARRAY_H
#define DATA_STRUCTURES_PROJECT_SORTEDARRAY_H


#include <string>
#include "Cell.h"

class SortedArray
{
private:
    int size,index; // index is the next empty position where we can insert a word
    Cell *array;

    //auxiliary methods
    int binarySearch(const string&,int,int);
    void binaryInsert(const string&,int,int);
public:
    // constructors - destructor
    SortedArray();
    SortedArray(int newSize);
    ~SortedArray();


    //basic operations
    int Search(const string&);
    bool Insert(const string&);
    void Delete(const string&);

    //auxiliary methods
    void PrintElement(); // this method was used only for personal info
    bool isFull() const;
};

#endif //DATA_STRUCTURES_PROJECT_SORTEDARRAY_H
