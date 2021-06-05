#include "Cell.h"

Cell::Cell(string newS)
{
    s = newS;
    k = 1;
}

Cell::Cell()
{
    s = "";
    k=0;

}

const string &Cell::getS() const { return s; }

void Cell::setS(const string &s)
{
    this->s = s;
    k=1;
}

int Cell::getK() const { return k; }

void Cell::setK(int k) { this->k = k; }

Cell &Cell::operator=(const Cell &right)
{
    if(this==&right) return *this;
    s=right.s;
    k=right.k;
    return *this;
}

void Cell::Exists()
{
    k++;
}

void Cell::minusExists()
{
    k--;
}

bool Cell::isOccupied() { return !this->s.empty(); }

void Cell::setS(const string &word, int frequency)
{
    s = word;
    k = frequency;
}
