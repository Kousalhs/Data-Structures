#include <iostream>
#include <fstream>
#include <cctype>
#include <ctime>
#include <ratio>
#include <chrono>

#include "AVLTree.h"
#include "BinarySearchTree.h"
#include "UnsortedArray.h"
#include "SortedArray.h"
#include "OpenAddressHashTable.h"

using namespace std;
using namespace chrono;

int main()
{
    //UnsortedArray a(1000);
    //SortedArray b(1000);
    //OpenAddressHashTable c(1000);
    AVLTree d;
    //BinarySearchTree e;


    cout << "Array created" << endl;

    char fn[50];

    string Q[1000];

    int index = 0;

    cin >> fn;

    ifstream ifs;
    ifs.open(fn);
    if (ifs.is_open())
    {
        string buffer;

        while (!ifs.eof())
        {
            ifs >> buffer; // Untouched word

            for (int i = 0; i < buffer[i]; ++i) // Lowercased word
                buffer[i] = (char) tolower(buffer[i]);

            for (int i = 0; i < buffer.size(); i++) // Punctuation remove
            {
                if (ispunct(buffer[i]))
                {
                    buffer.erase(i--, 1);
                    buffer.size();
                }
            }


             //a.UInsert(buffer);
            //b.Insert(buffer);
            //c.insert(buffer);
            d.insertLeaf(buffer);


            if ((rand() % 10 + 1 == 5) && (index <= 99999))
            {
                Q[index] = buffer;
                index++;
                //cout <<"Randomly selected: "<< buffer<<endl;
            }

            buffer[0] = '\0';

            //cout << "going to next word" << endl << endl << endl << endl << endl << endl;

        }
        high_resolution_clock::time_point t3 = high_resolution_clock::now();
        for (int i = 0; i < index ; i++)
        {
            int appearances = a.USearch(Q[i]);
            cout<<Q[i]<<" : "<< appearances << endl;
        }
        high_resolution_clock::time_point t4 = high_resolution_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(t4-t3);
        cout<<"OpenAddressHashTable search time: "<<time_span.count() << " seconds." <<endl;

    }
    else
    {
        cout << "File error" << endl;
    }
    return 0;
}