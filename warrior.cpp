#include "warrior.h"

Warrior::Warrior(string n, string r, int l, int h, int s){
    SetName(n);
    SetRace(r);
    SetLevel(l);
    SetHealth(h);
    stamina = s;
}

Warrior::~Warrior(){}

int Warrior::getStamina() const{
    return stamina;
}
void Warrior::SetStamina(int s){
    stamina = s;
}

void Warrior::EquipWeapon(string n, int d, int s){
    weapon nWep;
    nWep.name = n;
    nWep.damage = d;
    nWep.stamina_cost = s;

    active_weapon = nWep;
}

void Warrior::Attack(Character *target){
    if(stamina < active_weapon.stamina_cost){
        cout << "Insufficient stamina points!" << endl;
    }
    else if(active_weapon.name == ""){
        cout << "Warrior has no weapon!" << endl;
    }
    else {
        stamina -= active_weapon.stamina_cost;
        target->SetHealth(target->getHealth() - active_weapon.damage);
        cout << getName() << " attacked " << target->getName() << " with a " << active_weapon.name << ", dealing " << active_weapon.damage << " damage."<< endl;
    }
}

void Warrior::Print(){
    cout << "Character Status: " << endl;
    cout << "Name: " << getName() << endl;
    cout << "Race: " << getRace() << endl;
    cout << "Level: " << getLevel() << endl;
    cout << "Health: " << getHealth() << endl;
    cout << "Weapon: " << active_weapon.name << endl;
}