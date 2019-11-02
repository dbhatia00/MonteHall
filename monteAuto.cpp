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
    int iterations, inti;
    int good = chooseGoodDoor();
    cout << "How many times should we run the simulation? ";
    cin >> iterations;
    inti = iterations;
    double succWChange = 0, succWOChange = 0, changeCount = 0, stayCount = 0;
    do{
        //cout <<  endl << "Enter intial door to be chosen (1, 2, or 3): " ;
        choice = rand() % 3 + 1;
        choiceCorrector(choice);

        int showBad = chooseBadDoor(good, choice);
        
        bool change;
        //cout << "Will you change your choice to the remaining unopened door? Enter 0 (no) or 1 (yes) ";
        change = rand()%2;

        if (change){
            changeCount++;
            //cout << endl << "You have decided to change your door" << endl;
            choice = changeChoice(showBad, choice);
            if (choice == good){
                 //cout << "You win the prize!";
                 succWChange++;}
            //else cout << "You didn't win the prize :(";
        } 
        else
        {
            stayCount++;
            //cout << endl << "You have decided to keep your door" << endl;
            if (choice == good) {

                //cout << "You win the prize!";
                succWOChange++;}
            //else cout << "You didn't win the prize :(";
        }
        iterations--;
    }while(iterations > 0);

    cout << endl << "Times we changed door: " << changeCount << endl;
    cout << "Times we stayed: " << stayCount << endl;
    cout << endl << "Success rate with changing mind (Relative to total iterations): " << succWChange / inti << endl;
    cout << "Success rate without switching door (Relative to total iterations): " << succWOChange / inti << endl;
    cout << endl << "Success rate with changing mind (Relative to amount of times we changed): " << succWChange / changeCount << endl;
    cout << "Success rate without switching door (Relative to amount of times we didn't switch): " << succWOChange / stayCount << endl;
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
    //cout << "Door number " << toShow << " is a bad door" << endl;
    return toShow;
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