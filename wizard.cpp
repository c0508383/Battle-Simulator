#include "wizard.h"

Wizard::Wizard(string n, string r, int l, int h, int m){
    SetName(n);
    SetRace(r);
    SetLevel(l);
    SetHealth(h);
    mana = m;
}

Wizard::~Wizard(){}

int Wizard::getMana() const {return mana;}
void Wizard::SetMana(int m) {mana = m;}

int Wizard::AddSpell(string n, int d, int m){
    spell nSpell;
    nSpell.name = n;
    nSpell.damage = d;
    nSpell.mana_cost = m;

    if(numOfSpells < 10){
        spells[numOfSpells++] = nSpell;
    }
    else cout << "Spell limits reached!" << endl;

    return numOfSpells;
}

void Wizard::Attack(Character *target){
    if(numOfSpells == 0){
        cout << "This wizard has no spells!" << endl;
    }
    else if(mana < spells[0].mana_cost){
        cout << "Insufficient mana points!" << endl;
    }
    else{
        mana -= spells[0].mana_cost;
        target->SetHealth(target->getHealth() - spells[0].damage);
        cout << getName() << " attacked " << target->getName() << " with spell: " << spells[0].name << ", dealing " << spells[0].damage << " damage." << endl;
    }
}

void Wizard::Attack(Character *target, int spell_num){
    if(spell_num < 0 || spell_num >= numOfSpells){
        cout << "Invalid spell number!" << endl;
    }
    else if(numOfSpells == 0){
        cout << "This wizard has no spells!" << endl;
    }
    else if(mana < spells[spell_num].mana_cost){
        cout << "Insufficient mana points!" << endl;
    }
    else{
        mana -= spells[spell_num].mana_cost;
        target->SetHealth(target->getHealth() - spells[spell_num].damage);
        cout << getName() << " attacked " << target->getName() << " with spell: " << spells[spell_num].name << ", dealing " << spells[spell_num].damage << " damage." << endl;
    }
}

void Wizard::Print(){
    cout << "Character Status: " << endl;
    cout << "Name: " << getName() << endl;
    cout << "Race: " << getRace() << endl;
    cout << "Level: " << getLevel() << endl;
    cout << "Health: " << getHealth() << endl;
    cout << "Spells: " << endl;
    for(int a = 0; a < numOfSpells; a++){
        cout << spells[a].name << endl;
    }
}