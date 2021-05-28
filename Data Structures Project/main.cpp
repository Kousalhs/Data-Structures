#include <iostream>
#include <fstream>
#include <cctype>
#include "UnsortedArray.h"
#include "SortedArray.h"
#include "OpenAddressHashTable.h"

using namespace std;

int main() {
    //UnsortedArray a(15);
    //SortedArray b(20);
    OpenAddressHashTable c(20);

    string *array;

    cout << "Array created" << endl;
    char fn[50];

    cin >> fn;

    ifstream ifs;
    ifs.open(fn);
    if (ifs.is_open())
    {
        string buffer;

        while (!ifs.eof()) {
            ifs >> buffer;
            // cout << "Untouched word: " << buffer << endl << endl;
            for (int i = 0; i < buffer[i]; ++i)
                buffer[i] = (char) tolower(buffer[i]);
            //cout << "Lowercased string" << endl;
            for (int i = 0; i < buffer.size(); i++) {
                if (ispunct(buffer[i])) {
                    buffer.erase(i--, 1);
                    buffer.size();
                }
            }


            c.insert(buffer);
            int appearances = c.search(buffer);
            if (!appearances) {
                cout << "Not found" << endl;
                exit(-1);
            }

            cout << buffer << ": " << appearances << endl;
            buffer[0] = '\0';

            cout << "going to next word" << endl << endl << endl << endl << endl << endl;
        }
    }
        else
        {
            cout << "File error" << endl;
        }
        return 0;
}