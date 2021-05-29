#include <iostream>
#include <fstream>
#include <cctype>

#include "AVLTree.h"
#include "BinarySearchTree.h"
#include "UnsortedArray.h"
#include "SortedArray.h"
#include "OpenAddressHashTable.h"

using namespace std;

int main() {
    UnsortedArray a(30);
    SortedArray b(30);
    OpenAddressHashTable c(30);


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
            ifs >> buffer;
            //cout << "Untouched word: " << buffer << endl << endl;

            for (int i = 0; i < buffer[i]; ++i)
                buffer[i] = (char) tolower(buffer[i]);

            //cout << "Lowercased string: " <<buffer<< endl<< endl<< endl<< endl;
            for (int i = 0; i < buffer.size(); i++) {
                if (ispunct(buffer[i])) {
                    buffer.erase(i--, 1);
                    buffer.size();
                }
            }
            //cout << "Clean word: " << buffer << endl << endl << endl << endl;


            a.UInsert(buffer);
            b.Insert(buffer);
            c.insert(buffer);


            if ((rand() % 10 + 1 == 5) && (index <= 999))
            {
                Q[index] = buffer;
                index++;
                cout <<"Randomly selected: "<< buffer<<endl;
            }

            buffer[0] = '\0';

            //cout << "going to next word" << endl << endl << endl << endl << endl << endl;

        }
        

    }
    else
    {
        cout << "File error" << endl;
    }
    return 0;
}