#include "MovieList.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


MovieList::~MovieList()
{

    for (MovieNode *p; !isEmpty(); )
    {
        p = headname->nextname;
        delete headname->movie;
        delete headname;
        headname = p;
    }
    headrate=NULL;
    headyear=NULL;

}

void MovieList::add(string name, double rate, int year)
{
    Movie* m= new Movie(name,rate,year);

    MovieNode* mnode= new MovieNode(m);

    MovieNode* temp;
    MovieNode* pre;

    if( headname==NULL)
    {
        headname=headrate=headyear= mnode;
    }
    else
    {

        // add to sorted namelist
        pre=NULL;
        temp=headname;
        while( temp!=NULL && name>temp->movie->name)
        {
            pre=temp;
            temp=temp->nextname;
        }

        if( pre==NULL) // add to head
        {
            mnode->nextname = temp;
            headname=mnode;
        }
        else if( temp==NULL) // add to last
        {
            pre->nextname = mnode;
        }
        else
        {
            pre->nextname = mnode;
            mnode->nextname= temp;

        }

//
//        // add to sorted ratelist
        pre=NULL;
        temp=headrate;
        while( temp!=NULL && rate>temp->movie->rate)
        {
            pre=temp;
            temp=temp->nextrate;
        }

        if( pre==NULL) // add to head
        {
            mnode->nextrate = temp;
            headrate=mnode;
        }
        else if( temp==NULL) // add to last
        {
            pre->nextrate = mnode;
        }
        else
        {
            pre->nextrate = mnode;
            mnode->nextrate= temp;

        }

//         // add to sorted yearlist
        pre=NULL;
        temp=headyear;

        while( temp!=NULL && year > temp->movie->year)
        {

            pre=temp;
            temp=temp->nextyear;

        }

        if( pre==NULL) // add to head
        {
            mnode->nextyear = headyear;
            headyear=mnode;
        }
        else if( temp==NULL) // add to last
        {
            pre->nextyear = mnode;
        }
        else
        {
            pre->nextyear = mnode;
            mnode->nextyear= temp;

        }

    }



}

bool MovieList::remove(string name)
{
    MovieNode* tempName= headname;
    MovieNode* preName= NULL;

    while(tempName!=NULL && tempName->movie->name!=name)
    {
        preName=tempName;
        tempName=tempName->nextname;
    }

    if( tempName!=NULL)
    {
        MovieNode* tempRate= headrate;
        MovieNode* preRate= NULL;
        while(tempRate->movie->name!=name)
        {
            preRate=tempRate;
            tempRate=tempRate->nextrate;
        }


        MovieNode* tempYear= headyear;
        MovieNode* preYear= NULL;
        while(tempYear->movie->name!=name)
        {
            preYear=tempYear;
            tempYear=tempYear->nextyear;
        }

        if(preName==NULL)
        {
            headname=headname->nextname;
        }
        else
        {
            preName->nextname = tempName->nextname;
        }

        if(preRate==NULL)
        {
            headrate= headrate->nextrate;
        }
        else
        {
            preRate->nextrate = tempRate->nextrate;
        }

        if(preYear==NULL)
        {

            headyear=headyear->nextyear;
        }
        else
        {
            preYear->nextyear = tempYear->nextyear;
        }



        delete tempName->movie;
        delete tempName;

    }



}

void MovieList::update(string name, double rate)
{
    MovieNode* temp= headname;


    while(temp!=NULL && temp->movie->name!=name)
    {


        temp=temp->nextname;
    }

    if( temp!=NULL)
    {
        temp->movie->rate = rate;

    }


}

void MovieList::printByYear()
{
    MovieNode* temp= headyear;

    cout << "Printing by Year" << endl;
    cout << "----------------" << endl;

    if( temp!=NULL)
    {
        while(temp!=NULL)
        {
            cout <<left <<setw(20)<< temp->movie->name << " " << setw(4)<< temp->movie->rate << " " << setw(4)<< temp->movie->year <<endl;
            temp=temp->nextyear;
        }
    }
    else
    {
        cout <<" list is empty" <<endl;
    }
    cout <<"----------------------------------" <<endl;
}

void MovieList::printByName()
{
    MovieNode* temp= headname;
    cout << "Printing by Name" << endl;
    cout << "----------------" << endl;
    if( temp!=NULL)
    {
        while(temp!=NULL)
        {
            cout <<left<<setw(20)<< temp->movie->name << " " << setw(4)<< temp->movie->rate << " " << setw(4)<< temp->movie->year <<endl;
            temp=temp->nextname;
        }
    }
    else
    {
        cout <<" list is empty" <<endl;
    }
    cout <<"----------------------------------" <<endl;
}

void MovieList::printByRate()
{

    MovieNode* temp= headrate;

    cout << "Printing by Rate" << endl;
    cout << "----------------" << endl;

    if( temp!=NULL)
    {
        while(temp!=NULL)
        {
            cout<<left <<setw(20)<< temp->movie->name << " " << setw(4)<< temp->movie->rate << " " << setw(4)<< temp->movie->year <<endl;
            temp=temp->nextrate;
        }
    }
    else
    {
        cout <<" list is empty" <<endl;
    }


    cout <<"----------------------------------" <<endl;
}

void MovieList::loadFile(string filename)
{

    ifstream ifs;

    ifs.open(filename, std::ifstream::in);
    string name;
    double rate;
    int year;
    while( ifs.good() )
    {
        ifs>>std::quoted(name);
        if( name!="")
        {
            ifs>> rate;
            ifs>>year;
            // cout << name <<" " << rate <<" " << year << endl;
            add(name,rate,year);
        }
        name="";

    }
    ifs.close();

}

void MovieList::saveToFileByYear(string filename)
{
    ofstream ofs;
    ofs.open(filename, std::ifstream::out);

    MovieNode* temp= headyear;
    while(temp!=NULL)
    {
        ofs <<  std::quoted(temp->movie->name) <<  " " << temp->movie->rate << " " << temp->movie->year<<endl;

        temp=temp->nextyear;
    }

    ofs.close();


}

void MovieList::saveToFileByName(string filename)
{

    ofstream ofs;
    ofs.open(filename, std::ifstream::out);

    MovieNode* temp= headname;
    while(temp!=NULL)
    {
        ofs <<  std::quoted(temp->movie->name) <<  " " << temp->movie->rate << " " << temp->movie->year<<endl;

        temp=temp->nextname;
    }

    ofs.close();

}

void MovieList::saveToFileByRate(string filename)
{
    ofstream ofs;
    ofs.open(filename, std::ifstream::out);

    MovieNode* temp= headrate;
    while(temp!=NULL)
    {
        ofs <<  std::quoted(temp->movie->name) <<  " " << temp->movie->rate << " " << temp->movie->year<<endl;

        temp=temp->nextrate;
    }

    ofs.close();
}
