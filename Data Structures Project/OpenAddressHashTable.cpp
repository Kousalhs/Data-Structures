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
        hashVal1 = 37*hashVal1 +  s[i];
    return hashVal1 % (this->size);
}

unsigned long int OpenAddressHashTable::HashFunction2(string const& s) const //Hash function 2
{
    unsigned long int hashVal2=0;
    unsigned long int valueToReturn = 0;
    for (int i = 0; i < s[i]!='\0'; i++)
        hashVal2 = 13*hashVal2 + s[i];
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
    //cout << "Starting insert" << endl;

    unsigned long int index = 0 , hashValue1= HashFunction1(s) , hashValue2 = HashFunction2(s);
    int i = -1;

    do
    {
        i++; // at the very first check, i has value -1+1=0, and increases by 1 at every "collision"
        index = (hashValue1+ i * hashValue2) % size;  // double hashing
        //cout << "Searching in " << index << endl;
        if (array[index].getS() == s)
        {
            //cout << "Found!" << endl;
            array[index].Exists();
            return true;
        }
    }
    while(array[index].isOccupied()); // loop stops when an unoccupied position is found

    if (isFull()) // if the array if full then a new array is created with his size doubled
    {
        //cout << "Array full. Trying to double the size" << endl;
        Cell *newArray = new Cell [size*2];
        if(newArray == nullptr)
            return false;
        for (int oldElement = 0; oldElement < size; oldElement++) // hashing old elements to new array
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
       // cout << "Array expanded" << endl;
    }

    i=-1;
    do
    {
        i++;
        index = (hashValue1+ i * hashValue2) % size;  // double hashing
        //cout << "Searching in " << index << endl;
    }
    while(array[index].isOccupied());  // loop stops when an unoccupied position is found
    array[index].setS(s);
    occupied++;
    /* cout<<"{ "<<endl;
     for (int j = 0; j < size ; ++j)
     {

             cout<<(array[j].getS().empty() ? "empty" : array[j].getS())<< "(" << array[j].getK() << ")"<<endl;

     }
     cout<<"}"<<endl;
     */

    return true;
}

int OpenAddressHashTable::search(const string &s)
{
    //cout<<"Starting search!"<<endl;
    unsigned long int index=0,hashValue1 = HashFunction1(s), hashValue2 = HashFunction2(s);
    int i=-1;
    do
    {
        i++;
        index = (hashValue1+ i * hashValue2) % size;  // double hashing
        //cout<<"Searching in " << index << endl;
        if (array[index].getS() == s)
        {
           // cout<<"Word found!"<<endl;
            return array[index].getK(); //if the word is found return its frequency
        }

    }
    while(array[index].isOccupied());  // loop stops when an unoccupied position is found
    return 0; //loop ends without finding the word
}