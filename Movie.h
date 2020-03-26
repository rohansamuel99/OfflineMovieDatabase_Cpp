//
// Created by rohan on 25/03/2020.
//

#ifndef OFFLINEMOVIEDATABASE_CPP_MOVIE_H
#define OFFLINEMOVIEDATABASE_CPP_MOVIE_H

#include <string>
#include <fstream>
#include <iostream>

struct Movie
{
public:
    //ntf* unsigned is used to make the variable only represent natural numbers
    std:: string filmTitle;
    unsigned int releaseYear;
    std:: string ageRating;
    std:: string genre;
    unsigned int length;
    unsigned int viewerRating;
    // string csv = ",";
};



#endif //OFFLINEMOVIEDATABASE_CPP_MOVIE_H
