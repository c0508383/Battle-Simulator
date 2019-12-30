#ifndef WIZARD_H
#define WIZARD_H

#include "character.h"
#include <string>
#include <iostream>

using namespace std;

struct spell{
    string name;
    int mana_cost, damage;
};

class Wizard : public Character{
    private:        
        int mana, numOfSpells;
        spell spells[10];
    public:
        Wizard(string n, string r, int l, int h, int m);
        ~Wizard();

        int getMana() const;
        void SetMana(int m);

        int AddSpell(string n, int d, int m);
        void Attack(Character *target);
        void Attack(Character *target, int spell_num);
        void Print();
};

#endif