//
// Created by bryhe on 11/25/2020.
//

#include "Film.h"


Film::Film() {
    _name = "";
    _year = "";
    _nomination = "";
    _rating = "";
    _duration = "";
    _genre1 = "";
    _genre2 = "";
    _releaseMonth = "";
    _metacritic = "";
    _synopsis = "";
}

Film::Film(string name, string year, string nomination, string rating, string duration, string genre1, string genre2, string releaseMonth, string metacritic, string synopsis ){
    _name = name;
    _year = year;
    _nomination = nomination;
    _rating = rating;
    _duration = duration;
    _genre1 = genre1;
    _genre2 = genre2;
    _releaseMonth = releaseMonth;
    _metacritic = metacritic;
    _synopsis = synopsis;


}

void readInMovies(vector<Film>& movieList) {
    ifstream in("pictures.csv");
    string name, year, nomination, rating, duration, genre1, genre2, releaseMonth, metacritic, synopsis;
    Film tempMovie;
    //read in the header
    int record=0;
    getline(in, name, ',');
    getline(in, year, ',');
    getline(in, nomination, ',');
    getline(in, rating, ',');
    getline(in, duration, ',');
    getline(in, genre1, ',');
    getline(in, genre2, ',');
    getline(in, releaseMonth, ',');
    getline(in, metacritic, ',');
    getline(in, synopsis);

    //cout<<"Name\t\tYear\t\tNomination\tRating\tDuration\tGenre1\tGenre2\tRelease Month\t\tMetacritic\t\t\tSynopsis"<<endl;
    while (!in.eof()) {
        record++;
        getline(in, name, ',');
        getline(in, year, ',');
        getline(in, nomination, ',');
        getline(in, rating, ',');
        getline(in, duration, ',');
        getline(in, genre1, ',');
        getline(in, genre2, ',');
        getline(in, releaseMonth, ',');
        getline(in, metacritic, ',');
        getline(in, synopsis);
        tempMovie = Film(name, year, nomination, rating, duration, genre1, genre2, releaseMonth, metacritic, synopsis);
        movieList.push_back(tempMovie);

    }
    in.close();
    cout<<"Read in "<<record<< " records from pictures.csv"<<endl;
}

void printMovies(vector<Film>& movieList) {
    int records = 1;
    cout << "\tName\tYear\tNomination\tRating\tDuration\tGenre 1\tGenre 2\tRelease Month\tMetacritic\tSynopsis" << endl;
    for (int i = 0; i < movieList.size(); i++) {
        cout << records;
        cout << ".\t" << movieList[i].getName() << "\t" << movieList[i].getYear() << "\t";
        cout << movieList[i].getNomination() << "\t" << movieList[i].getRating() << "\t" << movieList[i].getDuration()
             << "\t";
        cout << movieList[i].getGenre1() << "\t" << movieList[i].getGenre2() << "\t" << movieList[i].getReleaseMonth();
        cout << "\t" << movieList[i].getMetaCritic() << "\t" << movieList[i].getSynopsis() << endl;
        records++;
    }
}

    void addNewRecord(vector<Film>& movieList) {
        string name, year, nomination, rating, duration, genre1, genre2, releaseMonth, metacritic, synopsis;
        Film newFilm;
        cin.ignore();
        cout<<"Add a new film to the list"<<endl;
        cout<<"What is the name of the film?"<<endl;
        getline(cin, name);
        cout<<"What is the release year of the film?"<<endl;
        getline(cin, year);
        cout<<"How many nominations did the film get?"<<endl;
        getline(cin, nomination);
        cout<<"What is the rating?"<<endl;
        getline(cin, rating);
        cout<<"What is the duration?"<<endl;
        getline(cin, duration);
        cout<<"What is the first genre of the film?"<<endl;
        getline(cin, genre1);
        cout<<"What is the second genre of the film?"<<endl;
        getline(cin, genre2);
        cout<<"What month was the film released in?"<<endl;
        getline(cin, releaseMonth);
        cout<<"What is the metacritic rating?"<<endl;
        getline(cin, metacritic);
        cout<<"What is a synopsis of the film?"<<endl;
        getline(cin, synopsis);

        newFilm = Film(name, year, nomination, rating, duration, genre1, genre2, releaseMonth, metacritic, synopsis);

        movieList.push_back(newFilm);

        cout<<name<< " has been added to the movie database!"<<endl;


}

void modifyFilm(vector<Film>& movieList) {
    printMovies(movieList);
    cout<<endl;
    int selectedMovieRecord;
    cout<<"Please select a record number to modify."<<endl;
    cin>>selectedMovieRecord;
    cin.ignore();
    string name, year, nomination, rating, duration, genre1, genre2, releaseMonth, metacritic, synopsis;
    Film newFilm;
    cout<<"What is the new name of the film?"<<endl;
    getline(cin, name);
    cout<<"What is the new release year of the film?"<<endl;
    getline(cin, year);
    cout<<"How many nominations did the film get?"<<endl;
    getline(cin, nomination);
    cout<<"What is the rating?"<<endl;
    getline(cin, rating);
    cout<<"What is the duration?"<<endl;
    getline(cin, duration);
    cout<<"What is the first genre of the film?"<<endl;
    getline(cin, genre1);
    cout<<"What is the second genre of the film?"<<endl;
    getline(cin, genre2);
    cout<<"What month was the film released in?"<<endl;
    getline(cin, releaseMonth);
    cout<<"What is the metacritic rating?"<<endl;
    getline(cin, metacritic);
    cout<<"What is a synopsis of the film?"<<endl;
    getline(cin, synopsis);
    newFilm = Film(name, year, nomination, rating, duration, genre1, genre2, releaseMonth, metacritic, synopsis);
    movieList[selectedMovieRecord-1]= newFilm;


}

void sortFilm(vector<Film>& movieList) {
    int chosenSortParameter;
    cout<<"Please choose a field to sort by."<<endl;
    cout<<"1. name"<<endl;
    cout<<"2. year"<<endl;
    cout<<"3. nomination"<<endl;
    cout<<"4. rating"<<endl;
    cout<<"5. duration"<<endl;
    cout<<"6. genre 1"<<endl;
    cout<<"7. genre 2"<<endl;
    cout<<"8. release month"<<endl;
    cout<<"9. metacritic"<<endl;
    cout<<"10. synopsis"<<endl;
    cin>>chosenSortParameter;
    cin.ignore();
    switch(chosenSortParameter) {
        case 1:
            sort(movieList.begin(), movieList.end(), sortByNameHelper);
            break;
        case 2:
            sort(movieList.begin(), movieList.end(), sortByYearHelper);
            break;
        case 3:
            sort(movieList.begin(), movieList.end(), sortByNominationHelper);
            break;
        case 4:
            sort(movieList.begin(), movieList.end(), sortByRatingHelper);
            break;
        case 5:
            sort(movieList.begin(), movieList.end(), sortByDurationHelper);
            break;
        case 6:
            sort(movieList.begin(), movieList.end(), sortByGenre1Helper);
            break;
        case 7:
            sort(movieList.begin(), movieList.end(), sortByGenre2Helper);
            break;
        case 8:
            sort(movieList.begin(), movieList.end(), sortByReleaseMonthHelper);
            break;
        case 9:
            sort(movieList.begin(), movieList.end(), sortByMetacriticHelper);
            break;
        case 10:
            sort(movieList.begin(), movieList.end(), sortBySynopsisHelper);
            break;
        default:
            cout << "Please choose a valid menu option." << endl;
            sortFilm(movieList);
            break;
    }
    printMovies(movieList);

    cout<<endl<<"Movies have been sorted."<<endl;



    }

bool sortByNameHelper(Film& lhs, Film& rhs) {return lhs.getName()<rhs.getName();}
bool sortByYearHelper(Film& lhs, Film& rhs) {return lhs.getYear()<rhs.getYear();}
bool sortByNominationHelper(Film& lhs, Film& rhs) {return lhs.getNomination()<rhs.getNomination();}
bool sortByRatingHelper(Film& lhs, Film& rhs) {return lhs.getRating()<rhs.getRating();}
bool sortByDurationHelper(Film& lhs, Film& rhs) {return lhs.getDuration()<rhs.getDuration();}
bool sortByGenre1Helper(Film& lhs, Film& rhs) {return lhs.getGenre1()<rhs.getGenre1();}
bool sortByGenre2Helper(Film& lhs, Film& rhs) {return lhs.getGenre2()<rhs.getGenre2();}
bool sortByReleaseMonthHelper(Film& lhs, Film& rhs) {return lhs.getReleaseMonth()<rhs.getReleaseMonth();}
bool sortByMetacriticHelper(Film& lhs, Film& rhs) {return lhs.getMetaCritic()<rhs.getMetaCritic();}
bool sortBySynopsisHelper(Film& lhs, Film& rhs) {return lhs.getSynopsis()<rhs.getSynopsis();}

void completeFilmSearch(vector<Film>& movieList) {
    int chosenSortParameter;
    vector<Film> selectedFilms;
    string name, year, nomination, rating, duration, genre1, genre2, releaseMonth, metacritic, synopsis;
    cout << "Please choose a field to search by." << endl;
    cout << "1. name" << endl;
    cout << "2. year" << endl;
    cout << "3. nomination" << endl;
    cout << "4. rating" << endl;
    cout << "5. duration" << endl;
    cout << "6. genre 1" << endl;
    cout << "7. genre 2" << endl;
    cout << "8. release month" << endl;
    cout << "9. metacritic" << endl;
    cout << "10. synopsis" << endl;
    cin >> chosenSortParameter;
    cin.ignore();
    switch (chosenSortParameter) {
        case 1:
            cout << "Please type in a film name." << endl;
            getline(cin, name);
            for (int i = 0; i < movieList.size(); i++) {
                if (movieList[i].getName() == name)
                    selectedFilms.push_back(movieList[i]);
            }
            cout << "The search results:" << endl;
            printMovies(selectedFilms);

            break;
        case 2:
            cout << "Please type in a film year." << endl;
            getline(cin, year);
            for (int i = 0; i < movieList.size(); i++) {
                if (movieList[i].getYear() == year)
                    selectedFilms.push_back(movieList[i]);
            }
            cout << "The search results:" << endl;
            printMovies(selectedFilms);

            break;
        case 3:
            cout << "Please type in a film nomination." << endl;
            getline(cin, nomination);
            for (int i = 0; i < movieList.size(); i++) {
                if (movieList[i].getNomination() == nomination)
                    selectedFilms.push_back(movieList[i]);
            }
            cout << "The search results:" << endl;
            printMovies(selectedFilms);

            break;
        case 4:
            cout << "Please type in a film rating." << endl;
            getline(cin, rating);
            for (int i = 0; i < movieList.size(); i++) {
                if (movieList[i].getRating() == rating)
                    selectedFilms.push_back(movieList[i]);
            }
            cout << "The search results:" << endl;
            printMovies(selectedFilms);

            break;
        case 5:
            cout << "Please type in a film duration." << endl;
            getline(cin, duration);
            for (int i = 0; i < movieList.size(); i++) {
                if (movieList[i].getDuration() == duration)
                    selectedFilms.push_back(movieList[i]);
            }
            cout << "The search results:" << endl;
            printMovies(selectedFilms);
            break;
        case 6:
            cout << "Please type in a film genre 1." << endl;
            getline(cin, genre1);
            for (int i = 0; i < movieList.size(); i++) {
                if (movieList[i].getGenre1() == genre1)
                    selectedFilms.push_back(movieList[i]);
            }
            cout << "The search results:" << endl;
            printMovies(selectedFilms);
            break;
        case 7:
            cout << "Please type in a film genre 2." << endl;
            getline(cin, genre2);
            for (int i = 0; i < movieList.size(); i++) {
                if (movieList[i].getGenre2() == genre2)
                    selectedFilms.push_back(movieList[i]);
            }
            cout << "The search results:" << endl;
            printMovies(selectedFilms);
            break;
        case 8:
            cout << "Please type in a film release month." << endl;
            getline(cin, releaseMonth);
            for (int i = 0; i < movieList.size(); i++) {
                if (movieList[i].getReleaseMonth() == releaseMonth)
                    selectedFilms.push_back(movieList[i]);
            }
            cout << "The search results:" << endl;
            printMovies(selectedFilms);
            break;
        case 9:
            cout << "Please type in a film metacritic." << endl;
            getline(cin, metacritic);
            for (int i = 0; i < movieList.size(); i++) {
                if (movieList[i].getMetaCritic() == metacritic)
                    selectedFilms.push_back(movieList[i]);
            }
            cout << "The search results:" << endl;
            printMovies(selectedFilms);
            break;
        case 10:
            cout << "Please type in a film synopsis." << endl;
            getline(cin, synopsis);
            for (int i = 0; i < movieList.size(); i++) {
                if (movieList[i].getSynopsis() == synopsis)
                    selectedFilms.push_back(movieList[i]);
            }
            cout << "The search results:" << endl;
            printMovies(selectedFilms);
            break;
        default:
            cout << "Please choose a valid menu option." << endl;
            completeFilmSearch(movieList);
            break;

    }


}

void partialFilmSearch(vector<Film>& movieList){
    int chosenSortParameter;
    vector<Film> selectedFilms;
    string name, year, nomination, rating, duration, genre1, genre2, releaseMonth, metacritic, synopsis;
    cout << "Please choose a field to search by." << endl;
    cout << "1. name" << endl;
    cout << "2. year" << endl;
    cout << "3. nomination" << endl;
    cout << "4. rating" << endl;
    cout << "5. duration" << endl;
    cout << "6. genre 1" << endl;
    cout << "7. genre 2" << endl;
    cout << "8. release month" << endl;
    cout << "9. metacritic" << endl;
    cout << "10. synopsis" << endl;
    cin >> chosenSortParameter;
    cin.ignore();
    switch (chosenSortParameter) {
        case 1:
            cout << "Please type in a film name." << endl;
            getline(cin, name);
            for (int i = 0; i < movieList.size(); i++) {
                if (movieList[i].getName().find(name) != string::npos)
                    selectedFilms.push_back(movieList[i]);
            }
            cout << "The search results:" << endl;
            printMovies(selectedFilms);

            break;
        case 2:
            cout << "Please type in a film year." << endl;
            getline(cin, year);
            for (int i = 0; i < movieList.size(); i++) {
                if (movieList[i].getYear().find(year) != string::npos)
                    selectedFilms.push_back(movieList[i]);
            }
            cout << "The search results:" << endl;
            printMovies(selectedFilms);

            break;
        case 3:
            cout << "Please type in a film nomination." << endl;
            getline(cin, nomination);
            for (int i = 0; i < movieList.size(); i++) {
                if (movieList[i].getNomination().find(nomination) != string::npos)
                    selectedFilms.push_back(movieList[i]);
            }
            cout << "The search results:" << endl;
            printMovies(selectedFilms);

            break;
        case 4:
            cout << "Please type in a film rating." << endl;
            getline(cin, rating);
            for (int i = 0; i < movieList.size(); i++) {
                if (movieList[i].getRating().find(rating) != string::npos)
                    selectedFilms.push_back(movieList[i]);
            }
            cout << "The search results:" << endl;
            printMovies(selectedFilms);

            break;
        case 5:
            cout << "Please type in a film duration." << endl;
            getline(cin, duration);
            for (int i = 0; i < movieList.size(); i++) {
                if (movieList[i].getDuration().find(duration) != string::npos)
                    selectedFilms.push_back(movieList[i]);
            }
            cout << "The search results:" << endl;
            printMovies(selectedFilms);
            break;
        case 6:
            cout << "Please type in a film genre 1." << endl;
            getline(cin, genre1);
            for (int i = 0; i < movieList.size(); i++) {
                if (movieList[i].getGenre1().find(genre1) != string::npos)
                    selectedFilms.push_back(movieList[i]);
            }
            cout << "The search results:" << endl;
            printMovies(selectedFilms);
            break;
        case 7:
            cout << "Please type in a film genre 2." << endl;
            getline(cin, genre2);
            for (int i = 0; i < movieList.size(); i++) {
                if (movieList[i].getGenre2().find(genre2) != string::npos)
                    selectedFilms.push_back(movieList[i]);
            }
            cout << "The search results:" << endl;
            printMovies(selectedFilms);
            break;
        case 8:
            cout << "Please type in a film release month." << endl;
            getline(cin, releaseMonth);
            for (int i = 0; i < movieList.size(); i++) {
                if (movieList[i].getReleaseMonth().find(releaseMonth) != string::npos)
                    selectedFilms.push_back(movieList[i]);
            }
            cout << "The search results:" << endl;
            printMovies(selectedFilms);
            break;
        case 9:
            cout << "Please type in a film metacritic." << endl;
            getline(cin, metacritic);
            for (int i = 0; i < movieList.size(); i++) {
                if (movieList[i].getMetaCritic().find(metacritic) != string::npos)
                    selectedFilms.push_back(movieList[i]);
            }
            cout << "The search results:" << endl;
            printMovies(selectedFilms);
            break;
        case 10:
            cout << "Please type in a film synopsis." << endl;
            getline(cin, synopsis);
            for (int i = 0; i < movieList.size(); i++) {
                if (movieList[i].getSynopsis().find(synopsis) != string::npos)
                    selectedFilms.push_back(movieList[i]);
            }
            cout << "The search results:" << endl;
            printMovies(selectedFilms);
            break;
        default:
            cout << "Please choose a valid menu option." << endl;
            completeFilmSearch(movieList);
            break;

    }
}

void saveFilms(vector<Film>& movieList){
    cout<<"Please specify the name of a file to output to."<<endl;
    string fileName;
    getline(cin, fileName);
    ofstream out(fileName);
    for(int i = 0 ; i < movieList.size();i++) {
        out<<movieList[i].getName()<<','<<movieList[i].getYear()<<','<<movieList[i].getNomination()<<','<<movieList[i].getRating()<<',';
        out<<movieList[i].getDuration()<<','<<movieList[i].getGenre1()<<','<<movieList[i].getGenre2()<<','<<movieList[i].getReleaseMonth()<<',';
        out<<movieList[i].getMetaCritic()<<','<<movieList[i].getSynopsis()<<endl;
    }
    cout<<"Movie list has been written to "<<fileName<<endl;
    out.close();
}