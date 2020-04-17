//
// Created by rohan on 25/03/2020.
//

#include "MovieDatabase.h"

using namespace std;

int main()
{
    movie::MovieDatabase movieDatabase = movie::MovieDatabase("C:\\Users\\rohan\\CLionProjects\\OfflineMovieDatabase_Cpp\\films.txt");
    cout << movieDatabase;
}