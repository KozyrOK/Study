#include "Vampire.h"

Vampire::Vampire(int unitType, std::string name, int hitPoints, int damage):
    Unit::Unit(unitType, name, hitPoints, damage) {}

Vampire::~Vampire() {}

void Vampire::attack(Unit* enemy, bool isAttack) {
    this->vampireAttack = new VampireAttack(this, enemy, isAttack);
    delete vampireAttack;
}

void Vampire::makeVampire(SpellCaster* unit, std::string newName) {
    if ( unit->getUnitType() != 4 && unit->getUnitType() != 5 ) {
        unit->setUnitType(4);
        unit->setName(newName);
        unit->setMana(0);
        unit->setManaLimit(0);
    }
}

void Vampire::makeVampire(Unit* unit, std::string newName) {
    if ( unit->getUnitType() != 4 && unit->getUnitType() != 5 ) {
        unit->setUnitType(4);
        unit->setName(newName);
    }
}

std::ostream& operator<<(std::ostream& out, const Vampire& unit) {
    out << unit.getName() << " HP: " << unit.getHitPoints() << "|" << unit.getHitPointsLimit() << " DMG: " << unit.getDamage();
    return out;
}