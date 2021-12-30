//
// Created by bryhe on 11/25/2020.
//

#ifndef MOVIEBUFFS_FINALPROJECT_STAR_H
#define MOVIEBUFFS_FINALPROJECT_STAR_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;


class Star {

    string _year;
    string _award;
    string _winner;
    string _name;
    string _film;
public:
    Star();
    Star(string year, string award, string winner, string name, string film);

    string getYear(){return _year;}
    void setYear(int year){_year = year;}
    string getAward(){return _award;}
    void setAward(string award){_award = award;}
    string getWinner(){return _winner;}
    void setWinner(bool win){_winner = win;}
    string getName(){return _name;}
    void setName(string name){_name = name;}
    string getFilm(){return _film;}
    void setFilm(string film){_film = film;}


};

void readInStars(vector<Star>& stars);
void printStars(vector<Star>&);
void addNewStar(vector<Star>&);
void modifyStar(vector<Star>&);

//sort helpers
bool sortByYearHelper(Star& lhs, Star& rhs);
bool sortByAwardHelper(Star& lhs, Star& rhs);
bool sortByWinnerHelper(Star& lhs, Star& rhs);
bool sortByNameHelper(Star& lhs, Star& rhs);
bool sortByFilmHelper(Star& lhs, Star& rhs);

void sortStars(vector<Star>&);
void searchStars(vector<Star>&);
void partialSearchStars(vector<Star>&);
void saveStars(vector<Star>&);

#endif //MOVIEBUFFS_FINALPROJECT_STAR_H
