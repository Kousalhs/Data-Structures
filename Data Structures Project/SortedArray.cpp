#include "SortedArray.h"
#include <iostream>

using namespace std;

SortedArray::SortedArray()
{
    size=15;
    index=0;
    array = new Cell[15];
}

SortedArray::SortedArray(int newSize)
{
    size = newSize;
    index=0;
    array = new Cell[size];
}

SortedArray::~SortedArray() {delete [] array;}

int SortedArray::binarySearch(const string& s, int low , int high) // s = wordGiven
{
    if(low>high) // recursion break condition
        return 0;
    int mid=(low+high)/2;
    if (array[mid].getS() == s) // if mid word is equal to the new word
        return array[mid].getK(); // return its frequency
    else if(array[mid].getS() > s) // if mid word is greater than the new word
        high = mid - 1; // set high
    else if(array[mid].getS() < s) // if mid word is smaller tha the new word
        low = mid + 1; // set low
    return binarySearch(s,low,high); // recursion
}

int SortedArray::Search(const string &s) // s = wordGiven
{
    return binarySearch(s,0,(index) ? index - 1 : index);
}

bool SortedArray::isFull() const
{
    return (index==size);
}

void SortedArray::binaryInsert(const string& s, int low, int high) // s = wordGiven
{

    int mid=(low+high)/2; // first we need to find mid element of the array
    if (low>high || high==low)
    {
        if (s > array[low].getS()) // if they word inserted is greater than the word at the lower part, shift then set word
        {
            for (int i = index -1; i >= low+1; i--)
                array[i+1]=array[i];
            array[low+1].setS(s);
            index++;
            return;
        }

        else if (s < array[low].getS()) // if they word inserted is smaller than the word at the higher part, shift then set word
        {
            for (int i = index-1; i >= low ; i--)
                array[i+1]=array[i];
            array[low].setS(s);
            index++;
            return;
        }

        else if (s == array[low].getS()) // if they word inserted is equal with the word who is already inserted then just increase its frequency
        {
            array[low].Exists();
            return;
        }
    }
    if (array[mid].getS() == s) // if they word inserted is equal with the word at the middle who is already inserted then just increase its frequency
    {
        array[mid].Exists();
        return;
    }
    else if (array[mid].getS() > s) // setting high part of array
        high = (mid) ? mid - 1 : mid;
    else if (array[mid].getS() < s) // setting low part of array
        low = mid + 1;
    binaryInsert(s,low,high); //recursion
}

bool SortedArray::Insert(const string &s) // s = wordGiven
{
    if (!index) //first word inserted
    {
        array[index].setS(s);
        index++;
        return true;
    }
    if (isFull())  // if the array if full then a new array is created with his size doubled
    {
        Cell *newArray = new Cell [size*2];
        if(newArray == nullptr)
            return false;
        for (int i = 0; i < size; i++)
            newArray[i]=array[i];
        delete []array;
        array = newArray;
        size*=2;
    }
    binaryInsert(s,0, index - 1); // recursion for insertion
    return true;
}

void SortedArray::Delete(const string &s) // s = wordGiven
{
    int position = 0;
    for (int i = 0; i < index; i++) // linear search
    {
        if(array[i].getS()==s)
        {
            position=i; // finding the word for deletion
            break;
        }
    }
    if (array[position].getK()<=0) // if the word has 0  appearances, delete it
    {
        for (int i = position; i <index-1 ; i++)
        {
            array[i]=array[i+1]; // shifting words
        }
        index--; // decreasing index
    }
    else
        array[position].minusExists(); // if the word has at least one appearance, decrease it
}

void SortedArray::PrintElement()
{
    cout<<"{ "<<endl;
    for (int i = 0; i < index; i++)
    {
        cout<<array[i].getS()<< "(" << array[i].getK() << ")"<<endl;
    }
    cout<<"}"<<endl;
}