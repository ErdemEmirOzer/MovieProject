#include "Movie.h"

Movie::Movie()
{
    this->name = "";
    this->rate = 0;
    this->year= 0;
}

Movie::Movie(string name, double rate, int year)
{
    this->name = name;
    this->rate = rate;
    this->year= year;
}
