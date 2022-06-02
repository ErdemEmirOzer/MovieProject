#include <iostream>
#include "Movie.h"
#include "MovieList.h"

using namespace std;


int main()
{


    MovieList list;

    list.loadFile("sampleInput.txt");

    list.printByName();

    list.printByRate();

    list.printByYear();

    list.update("Interstellar",8);
    cout << "Interstellar rate has been updated" <<endl;

    list.printByName();

    list.remove("Interstellar");
    cout << "Interstellar  has been removed" <<endl;

    list.printByName();
    list.printByRate();
    list.printByYear();


    list.saveToFileByName("sampeoutputbyname.txt");
    list.saveToFileByRate("sampeoutputbyrate.txt");
    list.saveToFileByYear("sampeoutputbyyear.txt");

    cout <<" ------------------- List has been saved ---------------------" <<endl;
    cout <<"output filenames "<<endl;
    cout <<"sampeoutputbyname.txt"<<endl;
    cout <<"sampeoutputbyrate.txt"<<endl;
    cout <<"sampeoutputbyyear.txt"<<endl;

    return 0;
}

void manueltest()
{



}
