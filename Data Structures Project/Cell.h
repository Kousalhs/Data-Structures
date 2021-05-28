#ifndef DATA_STRUCTURES_PROJECT_CELL_H
#define DATA_STRUCTURES_PROJECT_CELL_H


#include <string>

using namespace std;

class Cell
{
private:
    string s; // s = wordGiven
    int k;    // k = wordFrequency
public:
    //constructors
    Cell(string);
    Cell();

    //accessors
    const string &getS() const;
    void setS(const string &s);
    int getK() const;
    void setK(int k);
    void setS(const string &,int);

    //overloaded operator
    Cell &operator=(const Cell &right);

    //auxiliary methods
    void Exists();
    void minusExists();
    bool isOccupied();



};

#endif //DATA_STRUCTURES_PROJECT_CELL_H
