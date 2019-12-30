#include "character.h"

Character::Character(){
    name = "";
    race = "";
    level = -1;
    health = -1;    
}
Character::Character(string name_, string race_, int level, int health){
    name = name_;
    race = race_;
    this->level = level;
    this->health = health;
}

Character::~Character(){}

string Character::getName() const{return name;}
string Character::getRace() const{return race;}
int Character::getLevel() const{return level;}
int Character::getHealth() const{return health;}

void Character::SetName(string name){this->name = name;}
void Character::SetRace(string name){race = name;}
void Character::SetLevel(int level){this->level = level;}
void Character::SetHealth(int health){this->health = health;}

void Character::Print(){
    cout << "Character Status:" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Race: " << getRace() << endl;
    cout << "Level: " << getLevel() << endl;
    cout << "Health: " << getHealth() << endl;
}