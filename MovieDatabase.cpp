//
// Created by rohan on 25/03/2020.
//

#include "MovieDatabase.h"

using namespace std;

movie::MovieDatabase movie::MovieDatabase::getByReleaseYear(int releaseYear)
{
    // getting all the movies release in the specified year
    MovieDatabase subMovieDatabase = MovieDatabase();
    for(Movie movie : moviesVector)
        if(movie.getReleaseYear() == releaseYear)
            subMovieDatabase.addMovie(movie);
    return subMovieDatabase;
}

//get genre using getline to split the slashes and then search for the genre we are specified
movie::MovieDatabase movie::MovieDatabase::getByGenre(string genreSearch)
{
    MovieDatabase subMovieDatabase = MovieDatabase();
    for(Movie movie : moviesVector)
    {
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

movie::MovieDatabase movie::MovieDatabase::getByViewerRating(int viewerRating)
{
    MovieDatabase subMovieDatabase = MovieDatabase();
    for(Movie movie : moviesVector)
        if(movie.getViewerRating() == viewerRating)
            subMovieDatabase.addMovie(movie);
    return subMovieDatabase;
}

movie::MovieDatabase movie::MovieDatabase::getByAgeRating(string ageRating)
{
    MovieDatabase subMovieDatabase = MovieDatabase();
    for(Movie movie : moviesVector)
        if(movie.getAgeRating() == ageRating)
            subMovieDatabase.addMovie(movie);
    return subMovieDatabase;
}

void testMovieDatabase()
{
    movie::MovieDatabase movieDatabase = movie::MovieDatabase("C:\\Users\\rohan\\CLionProjects\\OfflineMovieDatabase_Cpp\\films.txt");
    movieDatabase.sortChronologyAsc();
    movieDatabase.sortTitleLengthDesc();
    cout << movieDatabase;
}