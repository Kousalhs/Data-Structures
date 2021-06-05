#include "UnsortedArray.h"

using namespace std;

UnsortedArray::UnsortedArray()
{
    size=15;
    index=0;
    array = new Cell[15];
}

UnsortedArray::UnsortedArray(int newSize)
{
    size = newSize;
    index=0;
    array = new Cell[size];
}

UnsortedArray::~UnsortedArray() { delete [] array;}

int UnsortedArray::USearch(const string& s) //s=wordGiven
{
    for (int i= 0; i < index; i++)         //Linear Search to the array
        if(array[i].getS() == s)           // if the word searched is equal to the word in array[i]
            return array[i].getK();         //  return its frequency
    return 0; // if the word isn't found frequency equals to 0
}

bool UnsortedArray::UInsert(const string& s) //s=wordGiven
{
    if(USearch(s)) // searching if the word already exists
    {
        int position=0;
        for (int i = 0; i < index; i++) //Linear Search to the array
        {
            if(array[i].getS()==s)
            {
                position=i;
                break;
            }
        }
        array[position].Exists(); // if a word is already inserted first find its position then increase frequency
        return true;
    }

    if(isFull()) // if the array if full then a new array is created with his size doubled
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

    array[index].setS(s); // setting the word to the index
    index++; // increasing index
    return true;
}

bool UnsortedArray::isFull() const
{
    return (size==index);
}

void UnsortedArray::UDelete(const string& s) //s=wordGiven
{
    int position = 0;
    for (int i = 0; i < index; i++) // Linear search
    {
        if(array[i].getS()==s)
        {
            position=i; // finding the word for deletion
            break;
        }
    }

    if (array[position].getK() == 0)// if the word has 0  appearances, delete it
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