#ifndef WARRIOR_H
#define WARRIOR_H

#include "character.h"
#include <string>
#include <iostream>

using namespace std;

struct weapon{
    string name = "";
    int damage, stamina_cost;
};

class Warrior : public Character{
    private:
        int stamina;
        weapon active_weapon;
    public:
        Warrior(string n, string r, int l, int h, int s);
        ~Warrior();

        int getStamina() const;
        void SetStamina(int s);

        void EquipWeapon(string n, int d, int s);
        void Attack(Character *target);
        void Print();
};

#endif