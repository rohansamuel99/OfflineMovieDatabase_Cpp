/**
* Created by rohan on 25/03/2020.
**/

#include "Movie.h"
#include <string>
#include <iostream>


// creat a movie object for each film
/* movie object should contain :
  1. Title
  2. Year of Release
  3. Age rating
  4. Genre
  5. Length of film (in minutes?)
  6. User Rating maybe
*/

class Movie
{
    public:
        string filmTitle;
        int releaseYear;
        string ageRating;
        string genre;
        int lengthMinutes;
        int viewerRating;
};
