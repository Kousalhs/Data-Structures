#ifndef DATA_STRUCTURES_PROJECT_UNSORTEDARRAY_H
#define DATA_STRUCTURES_PROJECT_UNSORTEDARRAY_H


#include <string>
#include "Cell.h"

using namespace std;


class UnsortedArray
{
private:
    int size,index; // index is the next empty position where we can insert a word
    Cell *array;
public:
    // constructors - destructor
    UnsortedArray();
    UnsortedArray(int newSize);
    ~UnsortedArray();

    //basic operations
    int USearch(const string&);
    bool UInsert(const string&);
    void UDelete(const string&);


    //auxiliary method
    bool isFull() const;


};

#endif //DATA_STRUCTURES_PROJECT_UNSORTEDARRAY_H
