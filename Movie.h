/**
 * Created by Rohan on 25/03/2020.
 * Last Edited on 25/4/2020. Added comments.
**/

#ifndef OFFLINEMOVIEDATABASE_CPP_MOVIE_H
#define OFFLINEMOVIEDATABASE_CPP_MOVIE_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <ostream>

using namespace std;
namespace movie
{
    class Movie
    {

    public:
        //nts* unsigned is used to make the variable only represent natural numbers
        string filmTitle;
        int releaseYear;
        string ageRating;
        string genre;
        int length;
        int viewerRating;


    public:
        //setter methods for title, release year, age rating, genre, length and viewer rating
        //nts*-inline function is a function that is expanded in line when it is called, they are faster cos no push and pop on and off the stack
        inline void setFilmTitle(string &newFilmTitle)
        {
            this->filmTitle = newFilmTitle;
        }

        inline void setReleaseYear(int &newReleaseYear)
        {
            this->releaseYear = newReleaseYear;
        }

        inline void setAgeRating(string &newAgeRating)
        {
            this->ageRating = newAgeRating;
        }

        inline void setGenre(string &newGenre)
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
        inline string getFilmTitle()
        {
            return this->filmTitle;
        }

        inline const int getReleaseYear()
        {
            return this->releaseYear;
        }

        inline string getAgeRating()
        {
            return this->ageRating;
        }

        inline string getGenre()
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
        Movie(string newFilmTitle, int newReleaseYear, string newAgeRating, string newGenre,
              int newLength, int newViewerRating);

        //nts*-the equivalent of a toString from Java in Cpp is the write() method

        //operator in ostream is like the override for Java's toString method. It is an overloading operator
        //change so that it prints like the .txt file
        friend inline ostream& operator<<(ostream &stream, movie::Movie &movie1)
        {
            stream  << "Film Title: " << movie1.filmTitle << " | "
                    << "Year of Release: " << movie1.releaseYear << " | "
                    << "Age Rating: " << movie1.ageRating << " | "
                    << "Genre: " << movie1.genre << " | "
                    << "Length of Film: " << movie1.length << " | "
                    << "Viewer Rating: " << movie1.viewerRating << " | " << endl;
            return stream;
        }

        //overloading the input operator
        friend inline istream& operator>> (istream& stream, Movie movie1);
    };
}

void testMovie();


#endif //OFFLINEMOVIEDATABASE_CPP_MOVIE_H
