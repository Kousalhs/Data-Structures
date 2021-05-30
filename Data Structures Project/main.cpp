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
    const int qSize = 100000;
    UnsortedArray a(qSize);
    SortedArray b(qSize);
    OpenAddressHashTable e(qSize);
    AVLTree d;
    BinarySearchTree c;


    cout << "Array created" << endl;

    char fn[50];

    string Q[qSize];

    unsigned long int index = 0;

    cin >> fn;

    ifstream ifs;
    ifs.open(fn);
    if (ifs.is_open())
    {
        string buffer;

        while (!ifs.eof())
        {
            ifs >> buffer; // Untouched word

            for (unsigned long int i = 0; i < buffer[i]; ++i) // Lowercased word
                buffer[i] = (char) tolower(buffer[i]);

            for (unsigned long int i = 0; i < buffer.size(); i++) // Punctuation remove
            {
                if (ispunct(buffer[i]))
                {
                    buffer.erase(i--, 1);
                    buffer.size();
                }
            }


            a.UInsert(buffer); // unsorted
            b.Insert(buffer); // sorted
            c.insertLeaf(buffer); // bst
            d.insertLeaf(buffer); // avl
            e.insert(buffer); // hashtablr


            if ((rand() % 10 + 1 == 5) && (index < qSize))
            {
                Q[index] = buffer;
                index++;
                //cout <<"Randomly selected: "<< buffer<<endl;
            }

            buffer[0] = '\0';

            //cout << "going to next word" << endl << endl << endl << endl << endl << endl;

        }


        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(t1-t1); //

        for (int i = 0; i < index ; i++)
        {
            t1 = high_resolution_clock::now();
            int appearances = a.USearch(Q[i]);
            high_resolution_clock::time_point t2 = high_resolution_clock::now();
            time_span += duration_cast<duration<double>>(t2-t1);

            //cout<<Q[i]<<" : "<< appearances << endl;
        }

        cout<<"Unsorted array search time: "<<time_span.count() << " seconds." <<endl;

        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double> time_span1 = duration_cast<duration<double>>(t2-t2); //

        for (int i = 0; i < index ; i++)
        {
            t2 = high_resolution_clock::now();
            int appearances = b.Search(Q[i]);
            high_resolution_clock::time_point t3 = high_resolution_clock::now();
            time_span1 += duration_cast<duration<double>>(t3-t2);

            //cout<<Q[i]<<" : "<< appearances << endl;
        }

        cout<<"Sorted array search time: "<<time_span1.count() << " seconds." <<endl;

        high_resolution_clock::time_point t3 = high_resolution_clock::now();
        duration<double> time_span2 = duration_cast<duration<double>>(t3-t3); //

        for (int i = 0; i < index ; i++)
        {
            t3 = high_resolution_clock::now();
            int appearances = c.search(c.getNode(),Q[i]);
            high_resolution_clock::time_point t4 = high_resolution_clock::now();
            time_span2 += duration_cast<duration<double>>(t4-t3);

            //cout<<Q[i]<<" : "<< appearances << endl;
        }

        cout<<"Binary search tree search time: "<<time_span2.count() << " seconds." <<endl;

        high_resolution_clock::time_point t4 = high_resolution_clock::now();
        duration<double> time_span3 = duration_cast<duration<double>>(t4-t4); //

        for (int i = 0; i < index ; i++)
        {
            t4 = high_resolution_clock::now();
            int appearances = d.search(d.getNode(),Q[i]);
            high_resolution_clock::time_point t5 = high_resolution_clock::now();
            time_span3 += duration_cast<duration<double>>(t5-t4);

            //cout<<Q[i]<<" : "<< appearances << endl;
        }

        cout<<"AVL tree search time: "<<time_span3.count() << " seconds." <<endl;

        high_resolution_clock::time_point t5 = high_resolution_clock::now();
        duration<double> time_span4 = duration_cast<duration<double>>(t5-t5); //

        for (int i = 0; i < index ; i++)
        {
            t5 = high_resolution_clock::now();
            int appearances = e.search(Q[i]);
            high_resolution_clock::time_point t6 = high_resolution_clock::now();
            time_span4 += duration_cast<duration<double>>(t6-t5);

            //cout<<Q[i]<<" : "<< appearances << endl;
        }

        cout<<"Open address hash table search time: "<<time_span4.count() << " seconds." <<endl;

    }
    else
    {
        cout << "File error" << endl;
    }
    return 0;
}