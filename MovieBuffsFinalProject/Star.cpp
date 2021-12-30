//
// Created by bryhe on 11/25/2020.
//

#include "Star.h"

Star::Star(){
    _year = "";
    _award = "";
    _winner = "";
    _name = "";
    _film = "";
}

Star::Star(string year, string award, string winner, string name, string film){
    _year = year;
    _award = award;
    _winner = winner;
    _name = name;
    _film = film;
}

void readInStars(vector<Star>& stars){
    ifstream infile("actor-actress.csv");
    string year, award, winner, name, film;
    Star tempStar;
    //read in the header
    int record=0;
    getline(infile, year, ',');
    getline(infile, award, ',');
    getline(infile, winner, ',');
    getline(infile, name, ',');
    getline(infile, film);

    //cout<<"Year\tAward\t\tWinner\tName\t\tFilm"<<endl;
    while (!infile.eof()) {
        record++;
        getline(infile, year, ',');
        getline(infile, award, ',');
        getline(infile, winner, ',');
        getline(infile, name, ',');
        getline(infile, film);
        tempStar = Star(year, award, winner, name, film);
        stars.push_back(tempStar);

    }

    cout<<"Read in "<<record<< " records from actor-actress.csv"<<endl;
    infile.close();
}

void printStars(vector<Star>& starList) {
    int records = 1;
    cout<<"  Year\tAward\t\t\t\tWinner\tName\t\t\tFilm"<<endl;
    for(int i = 0; i < starList.size(); i++) {
        cout<<records<<". "<<starList[i].getYear()<<"\t"<<starList[i].getAward()<<"   \t"<<starList[i].getWinner()<<"\t"<<starList[i].getName()<<"\t\t"<<starList[i].getFilm()<<endl;
        records++;
    }

}

void addNewStar(vector<Star>& starList) {
    string year, award, winner, name, film;
    Star newStar;
    cin.ignore();

    cout<<"Add a new record to the actor-actress database."<<endl;
    cout<<"What is the year of the star?"<<endl;
    getline(cin, year);
    cout<<"What is the award of the star?"<<endl;
    getline(cin, award);
    cout<<"Did they win? 1 for yes 0 for no"<<endl;
    getline(cin, winner);
    cout<<"What is the star's name?"<<endl;
    getline(cin, name);
    cout<<"What is the name of the film?"<<endl;
    getline(cin, film);

    newStar = Star(year, award, winner, name, film);
    starList.push_back(newStar);

    cout<<newStar.getName()<< " has been added to the database."<<endl;
}

void modifyStar(vector<Star>& starList) {
    printStars(starList);
    int selectedStar;
    cout<<endl<<"Please select a record to modify."<<endl;
    cin>>selectedStar;
    cin.ignore();
    string year, award, winner, name, film;
    Star newStar;
    cout<<"What is the new year of the star?"<<endl;
    getline(cin, year);
    cout<<"What is the new award of the star?"<<endl;
    getline(cin, award);
    cout<<"Did they win? 1 for yes 0 for no"<<endl;
    getline(cin, winner);
    cout<<"What is the new star's name?"<<endl;
    getline(cin, name);
    cout<<"What is the new name of the film?"<<endl;
    getline(cin, film);
    newStar = Star(year, award, winner, name, film);
    starList[selectedStar-1] = newStar;
    cout<<"Record "<<selectedStar<< " has been modified."<<endl;

}

void sortStars(vector<Star>& starList) {
    cout<<"Please choose a field to sort by."<<endl;
    cout<<"1. year"<<endl;
    cout<<"2. award"<<endl;
    cout<<"3. winner"<<endl;
    cout<<"4. name"<<endl;
    cout<<"5. film"<<endl;
    int menuOption;
    cin>>menuOption;
    cin.ignore();
    switch(menuOption) {
        case 1:
            sort(starList.begin(), starList.end(), sortByYearHelper);
            break;
        case 2:
            sort(starList.begin(), starList.end(), sortByAwardHelper);
            break;
        case 3:
            sort(starList.begin(), starList.end(), sortByWinnerHelper);
            break;
        case 4:
            sort(starList.begin(), starList.end(), sortByNameHelper);
            break;
        case 5:
            sort(starList.begin(), starList.end(), sortByFilmHelper);
            break;
        default:
            cout<<"Please choose a valid menu option."<<endl;
            sortStars(starList);
    }

    printStars(starList);
    cout<<endl<<"Star list has been sorted."<<endl;

}

bool sortByYearHelper(Star& lhs, Star& rhs) {return lhs.getYear()<rhs.getYear();}
bool sortByAwardHelper(Star& lhs, Star& rhs) {return lhs.getAward()<rhs.getAward();}
bool sortByWinnerHelper(Star& lhs, Star& rhs) {return lhs.getWinner()<rhs.getWinner();}
bool sortByNameHelper(Star& lhs, Star& rhs) {return lhs.getName()<rhs.getName();}
bool sortByFilmHelper(Star& lhs, Star& rhs) {return lhs.getFilm()<rhs.getFilm();}

void searchStars(vector<Star>& starList) {
    int menuOption, record;
    string year, award, winner, name, film;
    cout<<"Please choose a field to complete search"<<endl;
    cout<<"1. year"<<endl;
    cout<<"2. award"<<endl;
    cout<<"3. winner"<<endl;
    cout<<"4. name"<<endl;
    cout<<"5. film"<<endl;
    cin>>menuOption;
    cin.ignore();
    vector<Star> starSearch;

    switch (menuOption) {
        case 1:
            cout<<"Please enter a search parameter"<<endl;
            getline(cin, year);
            for(int i = 0; i < starList.size(); i ++) {
                if(starList[i].getYear() == year)
                    starSearch.push_back(starList[i]);
            }
            cout<<"The search results: "<<endl;
            printStars(starSearch);
            break;
        case 2:
            cout<<"Please enter a search parameter"<<endl;
            getline(cin,award);
            for(int i = 0; i < starList.size(); i ++) {
                if(starList[i].getAward() == award)
                    starSearch.push_back(starList[i]);
            }
            cout<<"The search results: "<<endl;
            printStars(starSearch);
            break;
        case 3:
            cout<<"Please enter a search parameter"<<endl;
            getline(cin, winner);
            for(int i = 0; i < starList.size(); i ++) {
                if(starList[i].getWinner() == winner)
                    starSearch.push_back(starList[i]);
            }
            cout<<"The search results: "<<endl;
            printStars(starSearch);
            break;
        case 4:
            cout<<"Please enter a search parameter"<<endl;
            getline(cin, name);
            for(int i = 0; i < starList.size(); i ++) {
                if(starList[i].getName() == name)
                    starSearch.push_back(starList[i]);
            }
            cout<<"The search results: "<<endl;
            printStars(starSearch);
            break;
        case 5:
            cout<<"Please enter a search parameter"<<endl;
            getline(cin, film);
            for(int i = 0; i < starList.size(); i ++) {
                if(starList[i].getFilm() == film)
                    starSearch.push_back(starList[i]);
            }
            cout<<"The search results: "<<endl;
            printStars(starSearch);
            break;
        default:
            cout<<"Please select a valid menu option.";
            searchStars(starList);
    }
}

void partialSearchStars(vector<Star>& starList){
    int menuOption, record;
    string year, award, winner, name, film;
    cout<<"Please choose a field to complete search"<<endl;
    cout<<"1. year"<<endl;
    cout<<"2. award"<<endl;
    cout<<"3. winner"<<endl;
    cout<<"4. name"<<endl;
    cout<<"5. film"<<endl;
    cin>>menuOption;
    cin.ignore();
    vector<Star> starSearch;

    switch (menuOption) {
        case 1:
            cout<<"Please enter a search parameter"<<endl;
            getline(cin, year);
            for(int i = 0; i < starList.size(); i ++) {
                if(starList[i].getYear().find(year) != string::npos)
                    starSearch.push_back(starList[i]);
            }
            cout<<"The search results: "<<endl;
            printStars(starSearch);
            break;
        case 2:
            cout<<"Please enter a search parameter"<<endl;
            getline(cin,award);
            for(int i = 0; i < starList.size(); i ++) {
                if(starList[i].getAward().find(award) != string::npos)
                    starSearch.push_back(starList[i]);
            }
            cout<<"The search results: "<<endl;
            printStars(starSearch);
            break;
        case 3:
            cout<<"Please enter a search parameter"<<endl;
            getline(cin, winner);
            for(int i = 0; i < starList.size(); i ++) {
                if(starList[i].getWinner().find(winner) != string::npos)
                    starSearch.push_back(starList[i]);
            }
            cout<<"The search results: "<<endl;
            printStars(starSearch);
            break;
        case 4:
            cout<<"Please enter a search parameter"<<endl;
            getline(cin, name);
            for(int i = 0; i < starList.size(); i ++) {
                if(starList[i].getName().find(name) != string::npos)
                    starSearch.push_back(starList[i]);
            }
            cout<<"The search results: "<<endl;
            printStars(starSearch);
            break;
        case 5:
            cout<<"Please enter a search parameter"<<endl;
            getline(cin, film);
            for(int i = 0; i < starList.size(); i ++) {
                if(starList[i].getFilm().find(film) != string::npos)
                    starSearch.push_back(starList[i]);
            }
            cout<<"The search results: "<<endl;
            printStars(starSearch);
            break;
        default:
            cout<<"Please select a valid menu option.";
            searchStars(starList);
    }
}

void saveStars(vector<Star>& starList){
    string fileName;
    cin.ignore();
    cout<<"Please specifiy a file to save the list of stars too"<<endl;
    getline(cin, fileName);
    ofstream out(fileName);
    for(int i = 0; i < starList.size();i++) {
        out<<starList[i].getYear()<<','<<starList[i].getAward()<<','<<starList[i].getWinner()<<','<<starList[i].getName()<<','<<starList[i].getFilm()<<endl;
    }
    out.close();
    cout<<"List has been saved to "<<fileName<<endl;
}