#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>

using namespace std;

class Movie
{
public:
    Movie();
    Movie(string name, double rate, int year);
    string name;
    double rate;
    int year;

};

#endif // MOVIE_H
