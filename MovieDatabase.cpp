/**
 * Created by Rohan on 25/03/2020.
 * Last Edited on 25/4/2020. Added comments.
**/

#include "MovieDatabase.h"
/**
 * MovieDatabase.h and MovieDatabase.cpp - A collection of Movie objects, one for
 * each film described in the data file. The class should provide overloaded I/O operators
 * for reading the data from file and displaying the database on the terminal and
 * for answering the database queries. Rather than writing a program that only implements the
 * current specifications, we should write maintainable programs that are easily extended
 * to answer a variety of database queries, without writing a lot of extra code (i.e. methods
 * that answer generic queries are better than methods that answer very specific queries).
**/

using namespace std;

// gets the movie that was released in the specified year
movie::MovieDatabase movie::MovieDatabase::getByReleaseYear(int releaseYear)
{
    // getting all the movies release in the specified year
    // create a temporary MovieDatabase to collect the movies that fulfil the condition
    MovieDatabase subMovieDatabase = MovieDatabase();
    // goes through the vector and if the the parameter, releaseYear is the same as the movie's release year
    // it returns all the movies where that condition is fulfilled
    for(Movie movie : moviesVector)
        if(movie.getReleaseYear() == releaseYear)
            subMovieDatabase.addMovie(movie);
    return subMovieDatabase;
}

//get genre using getline to split the slashes and then search for the genre we are specified
movie::MovieDatabase movie::MovieDatabase::getByGenre(string genreSearch)
{
    MovieDatabase subMovieDatabase = MovieDatabase();
    // goes through the vector and if the parameter, genreSearch is the same as the movie's genre
    // it returns all the movies where that condition is fulfilled
    for(Movie movie : moviesVector)
    {
        // because each movie has mutiple genres, we split the genre by the slash and then search
        string genre = movie.getGenre();
        istringstream iStringStream(genre);
        string genreToken;
        while(!iStringStream.eof())
        {
            getline(iStringStream, genreToken, '/');
            if (genreToken == genreSearch)
                subMovieDatabase.addMovie(movie);
        }
    }
    return subMovieDatabase;
}

// get the movie with the specified viewer rating
movie::MovieDatabase movie::MovieDatabase::getByViewerRating(int viewerRating)
{
    MovieDatabase subMovieDatabase = MovieDatabase();
    // goes through the vector and if the parameter, viewerRating is the same as the movie's viewer rating
    // it returns all the movies where that condition is fulfilled
    for(Movie movie : moviesVector)
        if(movie.getViewerRating() == viewerRating)
            subMovieDatabase.addMovie(movie);
    return subMovieDatabase;
}

// gets the movie with the specified age rating or certificate
movie::MovieDatabase movie::MovieDatabase::getByAgeRating(string ageRating)
{
    MovieDatabase subMovieDatabase = MovieDatabase();
    // goes through the vector and if the parameter, ageRating is the same as the movie's age rating/certificate
    // it returns all the movies where that condition fulfilled
    for(Movie movie : moviesVector)
        if(movie.getAgeRating() == ageRating)
            subMovieDatabase.addMovie(movie);
    return subMovieDatabase;
}

//test harness for MovieDatabase.h and MovieDatabase.cpp
void testMovieDatabase()
{
    movie::MovieDatabase movieDatabase = movie::MovieDatabase("films.txt");
    movieDatabase.sortChronologyAsc();
    movieDatabase.sortTitleLengthDesc();
    cout << movieDatabase;
}