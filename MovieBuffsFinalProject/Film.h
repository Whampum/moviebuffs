//
// Created by bryhe on 11/25/2020.
//

#ifndef MOVIEBUFFS_FINALPROJECT_FILM_H
#define MOVIEBUFFS_FINALPROJECT_FILM_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;


class Film {

    string _name;
    string _year;
    string _nomination;
    string _rating;
    string _duration;
    string _genre1;
    string _genre2;
    string _releaseMonth;
    string _metacritic;
    string _synopsis;
public:
    Film();
    Film(string name, string year, string nomination, string rating, string duration, string genre1, string genre2, string releaseMonth, string metacritic, string synopsis );

    string getName(){return _name;}
    void setName(string name){_name = name;}
    string getYear(){return _year;}
    void setYear(int year){_year = year;}
    string getNomination(){return _nomination;}
    void setNomination(int nomination){_nomination = nomination;}
    string getRating(){return _rating;}
    void setRating(float rating){_rating = rating;}
    string getDuration(){return _duration;}
    void setDuration(int duration){_duration = duration;}
    string getGenre1(){return _genre1;}
    void setGenre1(string genre){_genre1 = genre;}
    string getGenre2(){return _genre2;}
    void setGenre2(string genre){_genre2 = genre;}
    string getReleaseMonth(){return _releaseMonth;}
    void setReleaseMonth(string month){_releaseMonth = month;}
    string getMetaCritic(){return _metacritic;}
    void setMetaCritic(string metaCritic){_metacritic = metaCritic;}
    string getSynopsis(){return _synopsis;}
    void setSynopsis(string synopsis){_synopsis = synopsis;}




};



void readInMovies(vector<Film>&);
void printMovies(vector<Film>&);
void addNewRecord(vector<Film>&);
void modifyFilm(vector<Film>&);
void sortFilm(vector<Film>&);
//sorting helpers
bool sortByNameHelper(Film& lhs, Film& rhs);
bool sortByYearHelper(Film& lhs, Film& rhs);
bool sortByNominationHelper(Film& lhs, Film& rhs);
bool sortByRatingHelper(Film& lhs, Film& rhs);
bool sortByDurationHelper(Film& lhs, Film& rhs);
bool sortByGenre1Helper(Film& lhs, Film& rhs);
bool sortByGenre2Helper(Film& lhs, Film& rhs);
bool sortByReleaseMonthHelper(Film& lhs, Film& rhs);
bool sortByMetacriticHelper(Film& lhs, Film& rhs);
bool sortBySynopsisHelper(Film& lhs, Film& rhs);

void completeFilmSearch(vector<Film>&);
void partialFilmSearch(vector<Film>&);
void saveFilms(vector<Film>&);

#endif //MOVIEBUFFS_FINALPROJECT_FILM_H
