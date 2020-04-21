//
// Created by rohan on 25/03/2020.
//

#ifndef OFFLINEMOVIEDATABASE_CPP_MOVIEDATABASE_H
#define OFFLINEMOVIEDATABASE_CPP_MOVIEDATABASE_H

#include <vector>
#include <algorithm>
#include "Movie.h"

//nts*- allows to create new names for types
namespace movie{
    class MovieDatabase
    {
    private:
        vector<movie::Movie> moviesVector;
        //constructor for MovieDatabase
        // one with file name
        // open file read bits out, make movies and put in a vector
    public:
        MovieDatabase()
        {
        }
        MovieDatabase(string fileName)
        {
            //reads in the file
            ifstream file(fileName);

            string titleToken;
            string yearToken;
            string ageToken;
            string genreToken;
            string lengthToken;
            string viewToken;

            while (!file.eof())
            {
                //getline take a string variable and a delimiter. ot goes from where you are in the file to what you have specified
                //it will store everything between that in the variable you give it
                //skips  first "
                getline(file, titleToken, '"');
                //gets the name of the film/everything between "
                getline(file, titleToken, '"');

                getline(file, yearToken, ',');
                getline(file, yearToken, ',');

                getline(file, ageToken, '"');
                getline(file, ageToken, '"');

                getline(file, genreToken, '"');
                getline(file, genreToken, '"');

                getline(file, lengthToken, ',');
                getline(file, lengthToken, ',');

                getline(file, viewToken);

                //adds the movie to the back of the vector
                moviesVector.push_back(movie::Movie(titleToken, stoi(yearToken), ageToken,
                                                    genreToken, stoi(lengthToken), stoi(viewToken)));

                if(file.peek() == '\n')
                    file.get();
            }
        }

        inline void addMovie(Movie movie)
        {
            moviesVector.push_back(movie);
        }

        friend inline std::ostream& operator<<(std::ostream &stream, movie::MovieDatabase &movieDB)
        {
            for(movie::Movie movie1 : movieDB.moviesVector)
                stream << movie1;
            return stream;
        }


        //sorting functions

        // sort in chronological order (asc and desc but only use asc)
        inline void sortChronologyAsc()
        {
            sort(moviesVector.begin(), moviesVector.end(), [](Movie a, Movie b){return a.getReleaseYear() < b.getReleaseYear();});
        }

        inline void sortChronologyDesc()
        {
            sort(moviesVector.begin(), moviesVector.end(), [](Movie a, Movie b){return a.getReleaseYear() > b.getReleaseYear();});
        }

        // sort by title length
        inline void sortTitleLengthAsc()
        {
            sort(moviesVector.begin(), moviesVector.end(), [](Movie a, Movie b){return a.getFilmTitle().length() < b.getFilmTitle().length();});
        }

        inline void sortTitleLengthDesc()
        {
            sort(moviesVector.begin(), moviesVector.end(), [](Movie a, Movie b){return a.getFilmTitle().length() > b.getFilmTitle().length();});
        }

        // sort by film length
        inline void sortLengthOfFilmAsc()
        {
            sort(moviesVector.begin(), moviesVector.end(), [](Movie a, Movie b){return a.getLength() < b.getLength();});
        }

        inline void sortLengthOfFilmDesc()
        {
            sort(moviesVector.begin(), moviesVector.end(), [](Movie a, Movie b){return a.getLength() > b.getLength();});
        }

        //sort by viewer rating
        inline void sortViewerRatingAsc()
        {
            sort(moviesVector.begin(), moviesVector.end(), [](Movie a, Movie b){return a.getViewerRating() < b.getViewerRating();});
        }

        inline void sortViewerRatingDesc()
        {
            sort(moviesVector.begin(), moviesVector.end(), [](Movie a, Movie b){return a.getViewerRating() > b.getViewerRating();});
        }

        movie::MovieDatabase getByReleaseYear(int releaseYear);
        movie::MovieDatabase getByGenre(string genre);
        movie::MovieDatabase getByViewerRating(int viewerRating);
        movie::MovieDatabase getByAgeRating(string ageRating);

        movie::Movie indexOfVector(int vectorIndex)
        {
            return moviesVector.at(vectorIndex);
        }
    };


}
void testMovieDatabase();







#endif //OFFLINEMOVIEDATABASE_CPP_MOVIEDATABASE_H
