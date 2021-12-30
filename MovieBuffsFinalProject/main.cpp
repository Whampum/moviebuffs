#include <iostream>
#include <vector>
#include "Star.h"
#include "Film.h"

void printMenu(int&);

int main() {
    int menuOption;

    vector<Star> starList;
    vector<Film> movieList;

    cout<<"Hi, welcome to movie and star database!"<<endl;
    do{
        cout<<"1. Read in data from actor-actress.csv"<<endl;
        cout<<"2. Read in data from movie.csv"<<endl;
        cout<<"3. Add record to actor-actress list"<<endl;
        cout<<"4. Add record to Movie list"<<endl;
        cout<<"5. Choose a record in the star database and modify it."<<endl;
        cout<<"6. Choose a record in the movie database and modify it."<<endl;
        cout<<"7. Choose a field in the star database and sort by it."<<endl;
        cout<<"8. Choose a field in the movie database and sort by it."<<endl;
        cout<<"9. Choose a field in star database and search by it."<<endl;
        cout<<"10. Choose a field in movie database and search by it."<<endl;
        cout<<"11. Choose a field in star database and partial search by it."<<endl;
        cout<<"12. Choose a field in movie database and partial search by it."<<endl;
        cout<<"13. Print out star database and save to specified file."<<endl;
        cout<<"14. Print out movie database and save to specified file."<<endl;
        cout<<"15. Print out star list to console"<<endl;
        cout<<"16. Print out movie list to console"<<endl;
        cout<<"17. Quit"<<endl;
        cin>>menuOption;


        switch(menuOption) {
            case 1:
                readInStars(starList);
                break;
            case 2:
                readInMovies(movieList);
                break;

            case 3:
                addNewStar(starList);
                break;
            case 4:
                addNewRecord(movieList);
                break;
            case 5:
                modifyStar(starList);
                break;
            case 6:
                modifyFilm(movieList);
                break;
            case 7:
                sortStars(starList);
                break;
            case 8:
                sortFilm(movieList);
                break;
            case 9:
                searchStars(starList);
                break;
            case 10:
                completeFilmSearch(movieList);
                break;
            case 11:
                partialSearchStars(starList);
                break;
            case 12:
                partialFilmSearch(movieList);
                break;


            case 13:
                saveStars(starList);
                //printStars(starList);
                break;
            case 14:
                saveFilms(movieList);
                //printMovies(movieList);
                break;
            case 15:
                printStars(starList);
                break;
            case 16:
                printMovies(movieList);
                break;
            default:
                cout<<"Please make a valid Menu Selection"<<endl;
                break;

        }

    }while(menuOption != 17);



}


