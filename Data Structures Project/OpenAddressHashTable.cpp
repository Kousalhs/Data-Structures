#include "OpenAddressHashTable.h"
#include <iostream>
using namespace std;


OpenAddressHashTable::OpenAddressHashTable()
{
    size = 15;
    occupied=0;
    array = new Cell[15];
}

OpenAddressHashTable::OpenAddressHashTable(int newSize)
{
    size = newSize;
    occupied=0;
    array = new Cell[size];
}

OpenAddressHashTable::~OpenAddressHashTable() { delete [] array;}

unsigned long int OpenAddressHashTable::HashFunction1(string const& s) const //Hash function 1
{
    unsigned long int hashVal1=0;
    for (int i = 0; s[i]!='\0'; i++)
        hashVal1 = hashVal1 +  s[i];
    return hashVal1 % (this->size);

}

unsigned long int OpenAddressHashTable::HashFunction2(string const& s) const //Hash function 2
{
    unsigned long int hashVal2=0;
    unsigned long int valueToReturn = 0;
    for (int i = 0; s[i]!='\0'; i++)
        hashVal2 = hashVal2 + s[i];
    valueToReturn = hashVal2 % (this->size);
    return (valueToReturn) ? valueToReturn : 1;
}

bool OpenAddressHashTable::isFull() const
{
    float loadFactor = (float) occupied/(float) size;
    if (loadFactor >= 0.5)
        return true;
    return false;
}

bool OpenAddressHashTable::insert(const string &s)
{
    unsigned long int index = 0 , hashValue1= HashFunction1(s) , hashValue2 = HashFunction2(s);
    int i = -1;

    do
    {
        i++; // at the very first check, i has value -1+1=0, and increases by 1 at every "collision"
        index = (hashValue1+ i * hashValue2) % (this->size);  // double hashing

        if (array[index].getS() == s) // if the word inserted is equal to the word then increase its frequency
        {
            array[index].Exists();
            return true;
        }

    }
    while(array[index].isOccupied()); // loop stops when an unoccupied position is found

    if (isFull()) // if the array if full then a new array is created with his size doubled
    {
        expandArray(s);
    }

    i=-1;
    do
    {
        i++;
        index = (hashValue1+ i * hashValue2) % size;  // double hashing
    }
    while(array[index].isOccupied());  // loop stops when an unoccupied position is found
    array[index].setS(s); // Setting the word
    occupied++;

    return true;
}

void OpenAddressHashTable::expandArray(const string &s)
{
    unsigned long int index = 0 , hashValue1=0 , hashValue2 = 0;

    Cell *newArray = new Cell [size*2];
    if(newArray == nullptr)
        return;
    for (int oldElement = 0; oldElement <= size; oldElement++) // hashing old elements to new array
    {
        if (array[oldElement].isOccupied())
        {
            int j = -1;
            hashValue1 = HashFunction1(array[oldElement].getS());
            hashValue2 = HashFunction2(array[oldElement].getS());
            do
            {
                j++;
                index = (hashValue1+ j * hashValue2) % (size*2);
            }
            while(newArray[index].isOccupied());
            newArray[index].setS(array[oldElement].getS(),array[oldElement].getK()); // setting words
        }
    }
    delete [] array;
    array = newArray;
    size*=2;
    hashValue1 = HashFunction1(s); //setting new word for Hashfunction1
    hashValue2 = HashFunction2(s); //setting new word for Hashfunction2
}

int OpenAddressHashTable::search(const string &s)
{
    unsigned long int index=0,hashValue1 = HashFunction1(s), hashValue2 = HashFunction2(s);
    int i=-1;
    do
    {
        i++;
        index = (hashValue1+ i * hashValue2) % size;  // double hashing

        if (array[index].getS() == s)
        {
            return array[index].getK(); //if the word is found return its frequency
        }

    }
    while(array[index].isOccupied());  // loop stops when an unoccupied position is found
    return 0; //loop ends without finding the word
}


