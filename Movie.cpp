/**
* Created by rohan on 25/03/2020.
**/

#include "Movie.h"


// creat a movie object for each film
/* movie object should contain :
  1. Title
  2. Year of Release
  3. Age rating
  4. Genre
  5. Length of film (in minutes?)
  6. User Rating maybe
*/

// make an array of fixed size 6 and then once the file is read in assign array[0] to title and so on

namespace movie {
    // initialising Movie constructor method from .h file
    Movie::Movie(std::string newFilmTitle, int newReleaseYear, std::string newAgeRating, std::string newGenre,
                 int newLength,
                 int newViewerRating)
    {
        this->filmTitle     = newFilmTitle;
        this->releaseYear   = newReleaseYear;
        this->ageRating     = newAgeRating;
        this->genre         = newGenre;
        this->length        = newLength;
        this->viewerRating  = newViewerRating;
    }

    std:: ostream &Movie::write(std::ostream &stream) const
    {
        stream  << "Film Title: " << this->filmTitle << " | "
                << "Year of Release: " << this->releaseYear << " | "
                << "Age Rating: " << this->ageRating << " | "
                << "Genre: " << this->genre << " | "
                << "Length of Film: " << this->length << " | "
                << "Viewer Rating: " << this->viewerRating << " | \n";
        return stream;
    }
}