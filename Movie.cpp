/**
* Created by rohan on 25/03/2020.
**/

#include "Movie.h"
/*
 * Movie.h and Movie.cpp - A Movie object describes the information stored about a particular film,
 * such that there will be a separate Movie object for each film held in the
 * database. The class should have a suitable collection of constructors, accessor methods
 * etc. and the stream I/O and relational operators should be implemented.
 */

// create a movie object for each film
/* movie object should contain :
  1. Title
  2. Year of Release
  3. Age rating
  4. Genre
  5. Length of film (in minutes?)
  6. User Rating maybe
*/

// make an array of fixed size 6 and then once the file is read in assign array[0] to title and so on
using namespace std;
    // initialising Movie constructor method from .h file
    movie::Movie::Movie(string newFilmTitle, int newReleaseYear, string newAgeRating, string newGenre, int newLength,
                        int newViewerRating)
    {
        this->filmTitle = newFilmTitle;
        this->releaseYear = newReleaseYear;
        this->ageRating = newAgeRating;
        this->genre = newGenre;
        this->length = newLength;
        this->viewerRating = newViewerRating;
    }

void testMovie()
{
    movie::Movie newMovie = movie::Movie("Hello", 1990, "UG", "Adventure", 120, 0);
    std::cout << newMovie << endl;
}