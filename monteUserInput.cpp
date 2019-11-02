#include <iostream>
#include <ctime>
using namespace std;


int chooseGoodDoor();
int chooseBadDoor(int, int);
void choiceCorrector(int &);
int changeChoice(int, int );

int main(){
    srand(time(NULL));
    int choice;

    cout << "Enter intial door to be chosen (1, 2, or 3): " ;
    cin >> choice;
    choiceCorrector(choice);

    int good = chooseGoodDoor();
    int showBad = chooseBadDoor(good, choice);
    
    bool change;
    cout << "Will you change your choice to the remaining unopened door? Enter 0 (no) or 1 (yes) ";
    cin >> change;

    if (change){
        cout << endl << "You have decided to change your door" << endl;
        choice = changeChoice(showBad, choice);
        if (choice == good) cout << "You win the prize!";
        else cout << "You didn't win the prize :(";
    } 
    else
    {
        cout << endl << "You have decided to keep your door" << endl;
        if (choice == good) cout << "You win the prize!";
        else cout << "You didn't win the prize :(";
    }
}

int changeChoice(int showBad, int choice){
    int remDoor;

    do{
        remDoor = rand() % 3+1;
    }while (remDoor == choice || remDoor == showBad);

    return remDoor;
}

int chooseBadDoor(int good, int choice){
    int toShow = rand()%3 +1;
    while ((toShow == good) || (toShow == choice)){
        toShow = rand()%3 +1;
    }
    cout << "Door number " << toShow << " is a bad door" << endl;
}

int chooseGoodDoor(){
    return (rand() % 3) + 1;
}

void choiceCorrector(int &inNum){
    while (inNum != 1 && inNum != 2 && inNum != 3)
    {
        cout << "The number that you have entered sucks, enter either 1, 2 or 3: " ;
        cin >> inNum;
    }
}
