#ifndef MOVIELIST_H
#define MOVIELIST_H

#include "Movie.h"
#include <iostream>

using namespace std;

class MovieNode
{
public:
    MovieNode()
    {
        nextname = nextrate=nextyear=NULL;
    }
    MovieNode(Movie* el)
    {
        movie = el;
        nextname = nextrate=nextyear=NULL;
    }

    Movie* movie;
    MovieNode *nextname;
    MovieNode *nextrate;
    MovieNode *nextyear;
};


class MovieList
{
public:
    MovieList()
    {
        headname=headrate=headyear=NULL;
        tailname=tailrate=tailyear=NULL;
    }
    virtual ~MovieList();
    int isEmpty()
    {
        return headname == NULL;
    }

    void add(string name, double rate, int year);
    bool remove(string name);
    void update(string name, double rate);
    void printByYear();

    void printByName();
    void printByRate();
    void loadFile(string filename);
    void saveToFileByYear(string filename);
    void saveToFileByName(string filename);
    void saveToFileByRate(string filename);


protected:

private:
    MovieNode *headname,*headrate, *headyear;
    MovieNode *tailname,*tailrate, *tailyear;
};

#endif // MOVIELIST_H




