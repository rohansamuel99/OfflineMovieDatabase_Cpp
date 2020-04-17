//
// Created by rohan on 25/03/2020.
//

#ifndef OFFLINEMOVIEDATABASE_CPP_MOVIEDATABASE_H
#define OFFLINEMOVIEDATABASE_CPP_MOVIEDATABASE_H

#include <string>
#include <vector>
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
        MovieDatabase(string fileName)
        {
            //reads in the file
            ifstream file(fileName);
            //getline take a string variable and a delimiter. ot goes from where you are in the file to what you have specified
            //it will store everything between that in the variable you give it
            string titleToken;
            string yearToken;
            string ageToken;
            string genreToken;
            string lengthToken;
            string viewToken;

            while (!file.eof())
            {
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
        friend inline std::ostream& operator<<(std::ostream &stream, movie::MovieDatabase &movieDB)
        {
            for(movie::Movie movie1 : movieDB.moviesVector)
                stream << movie1;
            return stream;
        }
        //sorting functions
    };
}







#endif //OFFLINEMOVIEDATABASE_CPP_MOVIEDATABASE_H
