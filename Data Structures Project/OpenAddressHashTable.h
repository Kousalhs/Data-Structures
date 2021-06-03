#ifndef DATA_STRUCTURES_PROJECT_OPENADDRESSHASHTABLE_H
#define DATA_STRUCTURES_PROJECT_OPENADDRESSHASHTABLE_H


#include <string>
#include "Cell.h"

class OpenAddressHashTable
{
private:
    int size;
    int occupied;
    Cell *array;
public:
    //constructors - destructor
    OpenAddressHashTable();
    OpenAddressHashTable(int newSize);
    ~OpenAddressHashTable();

    //hash functions used for double hashing
    unsigned long int HashFunction1(string const&) const;
    unsigned long int HashFunction2(string const&) const;

    //basic operations
    bool insert(const string&);
    int search(const string&);

    //auxiliary method
    void expandArray(const string &);
    bool isFull() const;
};


#endif //DATA_STRUCTURES_PROJECT_OPENADDRESSHASHTABLE_H
