/**
 * Created by Rohan on 25/03/2020.
 * Last Edited on 25/4/2020. Added comments.
**/

#ifndef OFFLINEMOVIEDATABASE_CPP_MOVIEDATABASE_H
#define OFFLINEMOVIEDATABASE_CPP_MOVIEDATABASE_H

#include <vector>
#include <algorithm>
#include "Movie.h"

using namespace std;

// nts*- allows to create new names for types
namespace movie{
    class MovieDatabase
    {
    private:
        // vectors are the c++ equivalent of an arraylist in java
        // creating a vector called moviesVector to store all the different movies from films.txt
        vector<movie::Movie> moviesVector;

    public:
        // empty MovieDatabase constructor
        MovieDatabase()
        {
        }

        // read in the file and use getline to split the the line with the delimiter specified and the push it into the vector.
        MovieDatabase(string fileName)
        {
            // reads in the file
            ifstream file(fileName);

            string titleToken;
            string yearToken;
            string ageToken;
            string genreToken;
            string lengthToken;
            string viewToken;

            // while loop to keep going till we reach the reach the end of the file
            while (!file.eof())
            {
                // getline take a string variable and a delimiter. ot goes from where you are in the file to what you have specified
                // it will store everything between that in the variable you give it
                // skips  first "
                getline(file, titleToken, '"');
                //gets the name of the film/everything between "
                getline(file, titleToken, '"');

                // in this case we skip the first comma and get everything after it until the next comma.
                getline(file, yearToken, ',');
                getline(file, yearToken, ',');

                getline(file, ageToken, '"');
                getline(file, ageToken, '"');

                getline(file, genreToken, '"');
                getline(file, genreToken, '"');

                getline(file, lengthToken, ',');
                getline(file, lengthToken, ',');

                // we do not need a delimiter here as this is the last item on the line.
                getline(file, viewToken);

                // push_back adds the movie to the back of the vector
                // stoi is use to convert a string to an int
                moviesVector.push_back(movie::Movie(titleToken, stoi(yearToken), ageToken,
                                                    genreToken, stoi(lengthToken), stoi(viewToken)));

                // if there is an empty line anywhere in the file it skips said line.
                if(file.peek() == '\n')
                    file.get();
            }
        }

        // addMovie method adds movie to the vector
        inline void addMovie(Movie movie)
        {
            moviesVector.push_back(movie);
        }

        // overloading the output operator by going through each movie in the vector and send it to the stream
        friend inline ostream& operator<<(ostream &stream, movie::MovieDatabase &movieDB)
        {
            for(movie::Movie movie1 : movieDB.moviesVector)
                stream << movie1;
            return stream;
        }


        // Sorting Functions
        // using lambdas to sort the movies
        // lambdas are anonymous functions that can capture the local variables of the scope in which they are enclosed

        // sort in chronological order (ascending and descending but will only be using ascending in this case)
        inline void sortChronologyAsc()
        {
            sort(moviesVector.begin(), moviesVector.end(), [](Movie a, Movie b){return a.getReleaseYear() < b.getReleaseYear();});
        }
        inline void sortChronologyDesc()
        {
            sort(moviesVector.begin(), moviesVector.end(), [](Movie a, Movie b){return a.getReleaseYear() > b.getReleaseYear();});
        }

        // sort by title length (ascending and  descending)
        inline void sortTitleLengthAsc()
        {
            sort(moviesVector.begin(), moviesVector.end(), [](Movie a, Movie b){return a.getFilmTitle().length() < b.getFilmTitle().length();});
        }
        inline void sortTitleLengthDesc()
        {
            sort(moviesVector.begin(), moviesVector.end(), [](Movie a, Movie b){return a.getFilmTitle().length() > b.getFilmTitle().length();});
        }

        // sort by film length in minutes (ascending and descending)
        inline void sortLengthOfFilmAsc()
        {
            sort(moviesVector.begin(), moviesVector.end(), [](Movie a, Movie b){return a.getLength() < b.getLength();});
        }
        inline void sortLengthOfFilmDesc()
        {
            sort(moviesVector.begin(), moviesVector.end(), [](Movie a, Movie b){return a.getLength() > b.getLength();});
        }

        //sort by viewer rating (ascending and descending)
        inline void sortViewerRatingAsc()
        {
            sort(moviesVector.begin(), moviesVector.end(), [](Movie a, Movie b){return a.getViewerRating() < b.getViewerRating();});
        }
        inline void sortViewerRatingDesc()
        {
            sort(moviesVector.begin(), moviesVector.end(), [](Movie a, Movie b){return a.getViewerRating() > b.getViewerRating();});
        }

        // defining the getBy methods that will be used to get different items in the film
        movie::MovieDatabase getByReleaseYear(int releaseYear);
        movie::MovieDatabase getByGenre(string genre);
        movie::MovieDatabase getByViewerRating(int viewerRating);
        movie::MovieDatabase getByAgeRating(string ageRating);

        // indexOfVector is used to get the movie at the index that is specified in main.cpp
        movie::Movie indexOfVector(int vectorIndex)
        {
            return moviesVector.at(vectorIndex);
        }

        //overloading the input operator but not used here.
        friend  inline ifstream& operator>>(ifstream& file, MovieDatabase movieDatabase1);
    };
}
void testMovieDatabase();







#endif //OFFLINEMOVIEDATABASE_CPP_MOVIEDATABASE_H
