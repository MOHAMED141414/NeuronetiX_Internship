#include <bits/stdc++.h>
#include <ctime>
#include <conio.h>
#include"Pet_Game.h"
using namespace std;

//global variable
int hunger     = 50;
int happiness  = 50;
string Name;


//This function is responsible for feed
/*
Description:
                if the level of feed is lower than 90
                    add 10 for the level when the level
                    reaches 90 print is full
*/
void feed(void)
{
    if(hunger < 90)
    {
        hunger += 10;
        cout<<Name<<" has been fed."<<endl;
    }
    else
    {
        cout<<Name<<" is considered full, and no further increase is allowed."<<endl;
    }
}

//This function is responsible for happiness
/*
Description:
                if the happiness of feed is lower than 90
                    add 10 for the level when the level
                    reaches 90 print is full
*/
void play(void)
{
    if(happiness < 90)
    {
        happiness += 10;
        cout<<Name<<" played and is happier now"<<endl;
    }
    else
    {
        cout<<Name<<" is considered too happy, and no further increase is allowed."<<endl;
    }
}

//This function is responsible for show_status
void show_status(void)
 {
        cout << "Hunger level: " << hunger << endl;
        cout << "Happiness level: " << happiness << endl;
}

//This function is app of program include all function
void App(void)
{
    int choice;
    cout << "Enter the name of your pet: ";
    cin>>Name;
    do
    {
    cout<<"1. Adopt Pet"<<std::endl;
    cout<<"2. Feed Pet"<<std::endl;
    cout<<"3. Play with Pet"<<std::endl;
    cout<<"4. Check Status"<<std::endl;
    cout<<"5. End Game"<<std::endl;
    cout<<"Choose an option: ";


        clock_t start_time = clock();
        bool input_received = false;

        // Wait for user input or timeout just 5 secs
        while (clock() < start_time + 5 * CLOCKS_PER_SEC) {
            if (_kbhit()) { // Check if a key is pressed
                cin >> choice;
                input_received = true;
                break;
            }
        }
        //check if input_received is true or not
        if (!input_received) {
            cout << "\nNo input detected. Showing final status...\n";
            show_status();
            break;
        }

    switch(choice)
    {
    case 1: cout<<Name<<" has been adopted"<<endl;
        break;
    case 2:feed();
        break;
    case 3:play();
        break;
    case 4:show_status();
        break;
    case 5:cout << "End Game\nFinal status" << endl;
    show_status();
        break;
    default:
        cout << "Invalid choice" << endl;
    }
     cout<<endl;
    }while(choice != 5);

}
