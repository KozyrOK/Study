#include "Werewolf.h"

Werewolf::Werewolf(int unitType, std::string name, int hitPoints, int damage,
    int unitType2, std::string name2, int hitPoints2, int damage2):
    Unit::Unit(unitType, name, hitPoints, damage) {
        this->altState = new State(unitType2, name2, hitPoints2, damage2);
    }

Werewolf::~Werewolf() {}

void Werewolf::attack(Unit* enemy, bool isAttack) {
    this->werewolfAttack = new Attack(this, enemy, isAttack);
    delete werewolfAttack;
}

void Werewolf::makeWerewolf(SpellCaster* unit, std::string newName) {
    if ( unit->getUnitType() != 4 && unit->getUnitType() != 5 ) {
        unit->setUnitType(5);
        unit->setName(newName);
        unit->setMana(0);
        unit->setManaLimit(0);
        unit->createAltState(6, "Wolf", 150, 15);
    }
}

void Werewolf::makeWerewolf(Unit* unit, std::string newName) {
    if ( unit->getUnitType() != 4 && unit->getUnitType() != 5 ) {
        unit->setUnitType(5);
        unit->setName(newName);
        unit->createAltState(6, "Wolf", 150, 15);
    }
}

std::ostream& operator<<(std::ostream& out, const Werewolf& unit) {
    out << unit.getName() << " HP: " << unit.getHitPoints() << "|" << unit.getHitPointsLimit() << " DMG: " << unit.getDamage();
    return out;
}