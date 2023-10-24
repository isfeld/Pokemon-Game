using namespace std;
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>

//Floraburn: Grass Fire Shockfin: Water Electric Frostmoth: Ice Bug Shadowmind: Dark Physic Voltbrawler: Electric Fighting Terrafey: Rock Fairy Ironcladore Rock Steel 
string Mons[10] = {"Floraburn","Shockfin","Frostmoth", "Shadowmind", "Voltbrawler" , "Terrafey" , "Ironcladore", "Spectrake", "Toxiwarrior", "Metatuff"};
int * picker(int seed)
{
    srand(seed);
    int mon[3];
    int Mon1 = rand() % 9;
    int Mon2 = rand() % 9;
    int Mon3 = rand() % 9;
    while (true)
    {
        bool same = false;
        if (Mon1 == Mon2)
        {
            Mon2 = rand() % 9;
            cout << Mon2;
    
            same = true;
        } 
        if (Mon1 == Mon3)
        {
            Mon3 = rand() % 9;
            same = true;
        }
        if (Mon2 == Mon3)
        {
            Mon3 = rand() % 9;
            same = true;
        }
        if (same == false)
        {
            break;
        }
        
    }
    static int team[3] = {Mon1, Mon2, Mon3};;
    return team;
}




int main()
{
    int * team1;
    int * team2;
    srand(time(0));
    int seed = rand();
    team1 = picker(seed);
    seed = rand();
    team2 = picker(seed);
    string roster1[3] = {Mons[team1[1]], Mons[team1[2]], Mons[team1[3]]};
    string roster2[3] = {Mons[team2[1]], Mons[team2[2]], Mons[team2[3]]};
    cout << "Team 1: \n";
    for (int i = 0; i < 3; i++)
    {
        cout << roster1[i] << "\n";
    }
    cout << "Team 2: \n";
     for (int i = 0; i < 3; i++)
    {
        cout << roster2[i] << "\n";
    }
}