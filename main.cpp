//
// Created by rohan on 25/03/2020.
//

#include <iostream>
#include <fstream>
#include <string>

//read in the file and print out its contents
int main()
{
    //read in the file and print out its contents
    std::ifstream file("C:\\Users\\rohan\\CLionProjects\\OfflineMovieDatabase_Cpp\\films.txt");
    std::string str;
    while (std::getline(file, str)) {
        std::cout << str << "\n";
    }

}