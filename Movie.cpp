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

namespace movie
{
    class Movie
    {
    public:
        //setter methods for title, release year, age rating, genre, length and viewer rating
        //nts*-inline function is a function that is expanded in line when it is called, they are faster cos no push and pop on and off the stack
        inline void setFilmTitle(std:: string& newFilmTitle)
        {
            this->filmTitle = newFilmTitle;
        }

        inline void setReleaseYear(int &newReleaseYear)
        {
            this->releaseYear = newReleaseYear;
        }

        inline void setAgeRating(std:: string& newAgeRating)
        {
            this->ageRating = newAgeRating;
        }

        inline void setGenre(std:: string& newGenre)
        {
            this->genre = newGenre;
        }

        inline void setLength(int &newLength)
        {
            this->length = newLength;
        }

        inline void setViewerRating(int &newViewerRating)
        {
            this->viewerRating = newViewerRating;
        }

        // getter mehtods for title, release year, age rating, genre, length and viewer rating
        inline std:: string getFilmTitle()
        {
            return this->filmTitle;
        }

        inline int& getReleaseYear()
        {
            return this->releaseYear;
        }

        inline std:: string getAgeRating()
        {
            return this->ageRating;
        }

        inline std:: string getGenre()
        {
            return this->genre;
        }

        inline int& getLength()
        {
            return this->length;
        }

        inline int& getViewerRating()
        {
            return this->viewerRating;
        }

    };

    //string[] filmsHelp = lines.split(csv);
}