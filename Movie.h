//
// Created by rohan on 25/03/2020.
//

#ifndef OFFLINEMOVIEDATABASE_CPP_MOVIE_H
#define OFFLINEMOVIEDATABASE_CPP_MOVIE_H

#include <string>
#include <fstream>
#include <iostream>


namespace movie
{
    class Movie
    {

    public:
        //nts* unsigned is used to make the variable only represent natural numbers
        std::string filmTitle;
        unsigned int releaseYear;
        std::string ageRating;
        std::string genre;
        unsigned int length;
        unsigned int viewerRating;


    public:
        //setter methods for title, release year, age rating, genre, length and viewer rating
        //nts*-inline function is a function that is expanded in line when it is called, they are faster cos no push and pop on and off the stack
        inline void setFilmTitle(std::string &newFilmTitle)
        {
            this->filmTitle = newFilmTitle;
        }

        inline void setReleaseYear(int &newReleaseYear)
        {
            this->releaseYear = newReleaseYear;
        }

        inline void setAgeRating(std::string &newAgeRating)
        {
            this->ageRating = newAgeRating;
        }

        inline void setGenre(std::string &newGenre)
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

        // getter methods for title, release year, age rating, genre, length and viewer rating
        inline std::string getFilmTitle()
        {
            return this->filmTitle;
        }

        inline const int getReleaseYear()
        {
            return this->releaseYear;
        }

        inline std::string getAgeRating()
        {
            return this->ageRating;
        }

        inline std::string getGenre()
        {
            return this->genre;
        }

        inline const int getLength()
        {
            return this->length;
        }

        inline const int getViewerRating()
        {
            return this->viewerRating;
        }

        //constructor for Movie class
        Movie(std::string newFilmTitle, int newReleaseYear, std::string newAgeRating, std::string newGenre,
              int newLength, std::string newViewerRating);

        //new constructor that takes the values of one movie object
        Movie(const Movie &newMovie);

        //nts*-the equivalent of a toString from Java in Cpp is the write() method
        std:: ostream write(std:: ostream &stream) const;
        //operator in ostream is like the override for Java's toString method. It is an overloading operator
        inline std:: ostream& operator<<(std:: ostream &stream, const Movie& movie)
        {
            return movie.write(stream);
        }
        //overloading the input operator
        //std:: istream& operator<< (std:: istream& stream, Movie& movie);
    };

}



#endif //OFFLINEMOVIEDATABASE_CPP_MOVIE_H
