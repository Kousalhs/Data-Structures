#include <iostream>
#include <fstream>
#include <cctype>
#include "UnsortedArray.h"
#include "SortedArray.h"
#include "OpenAddressHashTable.h"

using namespace std;

int main() {
    UnsortedArray a(15);
    //SortedArray b(20);
    //OpenAddressHashTable c(20);

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
            for (int i = 0; i < buffer.size(); i++)
            {
                if (ispunct(buffer[i])) {
                    buffer.erase(i--, 1);
                    buffer.size();
                }
            }
            //cout << "Clean word: " << buffer << endl << endl << endl << endl;


            a.UInsert(buffer);



            if (rand()%10+1 == 5 && index <= 999)
            {
                Q[index] = buffer;
                cout<<buffer;
            }


            buffer[0] = '\0';
            index++;

            cout << "going to next word" << endl << endl << endl << endl << endl << endl;

        }
    }
        else
        {
            cout << "File error" << endl;
        }

        cout<<1<<endl;
    for (int i = 0; i < index ; i++)
    {
        a.USearch(Q[i]);
        cout << Q[i] << " "<<endl;
    }
        return 0;
}