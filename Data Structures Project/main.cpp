#include <iostream>
#include <fstream>
#include <cctype>
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
    //srand (time(0));
    const int qSize = 10000;

    string Q[qSize];
    unsigned long int QIndex = 0;

    UnsortedArray unsortedArray(qSize);
    SortedArray sortedArray(qSize);
    BinarySearchTree bst;
    AVLTree avl;
    OpenAddressHashTable hashTable(qSize);

    ifstream ifs;
    ifs.open("large.txt");
    if (ifs.is_open()) // We open the file successfully
    {
        string buffer;
        cout<<"Opened"<<endl;
        while (!ifs.eof()) // While the file isn't ending
        {
            ifs >> buffer; // Untouched word is inserted
            string word = "";
            for (unsigned long int i = 0; i < buffer[i]; ++i) // First we lowercase the word
                buffer[i] = (char) tolower(buffer[i]);

            for (int i = 0; i < buffer.size(); ++i)
            {
                if ((buffer[i] >= 'a' && buffer[i] <= 'z') || (buffer[i] >= 'A' && buffer[i] <= 'Z') || (buffer[i] >= '0' && buffer[i]<='9')) {
                    word = word + buffer[i];
                }
            }

            if(!word.empty()) {

                // Insertion to structures

                //sortedArray.Insert(buffer);
                //unsortedArray.UInsert(buffer);
                bst.insertLeaf(word);
                //avl.insertLeaf(buffer);

                //hashTable.insert(buffer);


                // Function for random words inserted to Q
                if ((rand() % 10 + 1 == 5) && (QIndex < qSize)) {
                    Q[QIndex] = word;
                    QIndex++;
                }
            }
            word[0] = '\0';
        }

        cout<<"Insertion completed"<<endl;
        ofstream ofs;
        ofs.open("output.txt");


/*
        // Search method for unsorted array is started
        high_resolution_clock::time_point unsortedStart = high_resolution_clock::now();
        duration<double> unsortedTimer = duration_cast<duration<double>>(unsortedStart - unsortedStart); // We set unsorted timer to 0
        for (int i = 0; i < QIndex ; i++) // We search all the words from Q array for unsorted array
        {
            unsortedStart = high_resolution_clock::now(); // Word timer is starting for search
            int appearances = unsortedArray.USearch(Q[i]);
            high_resolution_clock::time_point unsortedEnd = high_resolution_clock::now(); // Word timer ended
            unsortedTimer += duration_cast<duration<double>>(unsortedEnd - unsortedStart); // Whole timer is the subtraction of unsortedEnd minus unsortedStart

            ofs<<Q[i]<<" : "<< appearances << endl; // We write words and their appearances to output.txt
        }
        ofs<<endl;
        ofs << "Unsorted array search time: " << unsortedTimer.count() << " seconds." << endl<<endl<<endl;

        // Search method for sorted array is started
        high_resolution_clock::time_point sortedStart = high_resolution_clock::now();
        duration<double> sortedTimer = duration_cast<duration<double>>(sortedStart - sortedStart); // We set sorted timer to 0
        for (int i = 0; i < QIndex ; i++) // We search all the words from Q array for sorted array
        {
            sortedStart = high_resolution_clock::now(); // Word timer is starting for search
            int appearances = sortedArray.Search(Q[i]);
            high_resolution_clock::time_point sortedEnd = high_resolution_clock::now(); // Word timer ended
            sortedTimer += duration_cast<duration<double>>(sortedEnd - sortedStart); // Whole timer is the subtraction of sortedEnd minus sortedStart

            ofs<<Q[i]<<" : "<< appearances << endl; // We write words and their appearances to output.txt
        }
        ofs<<endl;
        ofs << "Sorted array search time: " << sortedTimer.count() << " seconds." << endl<<endl<<endl; */

        // Search method for binary search tree is started
        high_resolution_clock::time_point binaryStart = high_resolution_clock::now();
        duration<double> binaryTimer = duration_cast<duration<double>>(binaryStart - binaryStart); // We set binary timer to 0
        for (int i = 0; i < QIndex ; i++) // We search all the words from Q array for binary search tree
        {
            binaryStart = high_resolution_clock::now(); // Word timer is starting for search
            int appearances = bst.search(bst.getNode(), Q[i]);
            high_resolution_clock::time_point binaryEnd = high_resolution_clock::now(); // Word timer ended
            binaryTimer += duration_cast<duration<double>>(binaryEnd - binaryStart); // Whole timer is the subtraction of binaryEnd minus binaryStart

            ofs<<Q[i]<<" : "<< appearances << endl; // We write words and their appearances to output.txt
        }
        ofs<<endl;
        ofs << "Binary search tree search time: " << binaryTimer.count() << " seconds." << endl<<endl<<endl;
/*
        // Search method for avl tree is started
        high_resolution_clock::time_point avlStart = high_resolution_clock::now();
        duration<double> avlTimer = duration_cast<duration<double>>(avlStart - avlStart); // We set avl timer to 0
        for (int i = 0; i < QIndex ; i++) // We search all the words from Q array for avl tree
        {
            avlStart = high_resolution_clock::now(); // Word timer is starting for search
            int appearances = avl.search(avl.getNode(), Q[i]);
            high_resolution_clock::time_point avlEnd = high_resolution_clock::now(); // Word timer ended
            avlTimer += duration_cast<duration<double>>(avlEnd - avlStart); // Whole timer is the subtraction of avlEnd minus avlStart

            ofs<<Q[i]<<" : "<< appearances << endl; // We write words and their appearances to output.txt
        }
        ofs<<endl;
        ofs << "AVL tree search time: " << avlTimer.count() << " seconds." << endl<<endl<<endl;

        // Search method for open address hash table array is started
        high_resolution_clock::time_point hashTableStart = high_resolution_clock::now();
        duration<double> hashTableTimer = duration_cast<duration<double>>(hashTableStart - hashTableStart); // We set hashTable timer to 0
        for (int i = 0; i < QIndex ; i++) // We search all the words from Q array for hashTable
        {
            hashTableStart = high_resolution_clock::now(); // Word timer is starting for search
            int appearances = hashTable.search(Q[i]);
            high_resolution_clock::time_point hashTableEnd = high_resolution_clock::now(); // Word timer ended
            hashTableTimer += duration_cast<duration<double>>(hashTableEnd - hashTableStart); // Whole timer is the subtraction of hastTableEnd minus hastTableStart

            ofs<<Q[i]<<" : "<< appearances << endl;
        }
        ofs<<endl;
        ofs << "Open address hashTable search time: " << hashTableTimer.count() << " seconds." << endl<<endl<<endl; */

    }
    else // Failed to open the file
    {
        cout << "File error" << endl;
    }
    return 0;
}