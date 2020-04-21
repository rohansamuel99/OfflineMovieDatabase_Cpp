//
// Created by rohan on 25/03/2020.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Movie.h"
#include "MovieDatabase.h"

using namespace std;

int main()
{
    movie::MovieDatabase movieDatabase = movie::MovieDatabase("films.txt");

    //testMovieDatabase();
    //testMovie();

    movieDatabase.sortChronologyAsc();
    cout << "Chronologically Ordered" << endl << movieDatabase << endl;

    // Displays the Third longest Film-Noir
    movie::MovieDatabase filmNoir = movieDatabase.getByGenre("Film-Noir");
    filmNoir.sortLengthOfFilmDesc();
    movie::Movie thirdLongest = filmNoir.indexOfVector(2);
    cout << "Third Longest Film-Noir" << endl << thirdLongest << endl;

    // Displays the Eight most recent UNRATED Film
    movie::MovieDatabase unrated = movieDatabase.getByAgeRating("UNRATED");
    unrated.sortChronologyDesc();
    movie::Movie eightMostRecent = unrated.indexOfVector(7);
    cout << "Eight Most Recent UNRATED Film" << endl << eightMostRecent << endl;

    // Displays the film with the Longest Title
    movieDatabase.sortTitleLengthDesc();
    movie::Movie longestTitle = movieDatabase.indexOfVector(0);
    cout << "Film with The Longest Title" << endl << longestTitle << endl;

}