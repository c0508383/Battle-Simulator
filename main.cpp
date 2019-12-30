#include <iostream>
#include <fstream>
#include <string>

#include "character.h"
#include "warrior.h"
#include "wizard.h"
#include "game.h"

using namespace std;


int main()
{
	string filename;
	cin >> filename;
	ifstream input(filename);

	Game game;
	if (!input.is_open()) {
		cout << "file not found!" << endl;
		exit(0);
	}
	
    string inS;

    string type, name, race;
    int level, health;

    string wepName;
    int stamina, wepDamage, wepStamCost;
    
    string spName;
    int mana, numSpells, spDamage, spMana;

    while(!input.eof()){
        getline(input,type);

        getline(input, name);
        getline(input, race);
        getline(input, inS);
        level = stoi(inS);
        getline(input, inS);
        health = stoi(inS);

        if(type == "Warrior"){//Warrior creation
            getline(input,inS);
            stamina = stoi(inS);

            Warrior *w = new Warrior(name,race,level,health,stamina);

            getline(input,wepName); //Gathering weapon info
            getline(input,inS);
            wepDamage = stoi(inS);
            getline(input,inS);
            wepStamCost = stoi(inS);

            w->EquipWeapon(wepName,wepDamage,wepStamCost);//Adding weapon
            
            game.AddCharacter(w);
        }
        else if(type == "Wizard"){//Wizard creation
            getline(input,inS);
            mana = stoi(inS);
            Wizard *w = new Wizard(name,race,level,health,mana);

            getline(input,inS);
            numSpells = stoi(inS);

            for(int a = 0; a < numSpells; a++){
                getline(input,spName);
                getline(input,inS);
                spDamage = stoi(inS);
                getline(input,inS);
                spMana = stoi(inS);

                w->AddSpell(spName,spDamage,spMana);
            }

            game.AddCharacter(w);
        }
        getline(input, inS);
    }
	
	int option = -1;
	do {
		cout << "Please choose an option: " << endl
			<< "1 - Next Turn" << endl
			<< "2 - Print All Characters" << endl
			<< "3 - Exit" << endl;

		cin >> option;
		cout << endl;

		switch (option) {
			case 1: game.NextTurn(); break;
			case 2: game.Print(); break;
			case 3: exit(0);
			default:
				cout << "Invalid Option!" << endl;
		}
		cout << endl;
	}while (option != 3);
    

	return 0;
}


