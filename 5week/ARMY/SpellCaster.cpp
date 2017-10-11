#include "SpellCaster.h"

SpellCaster::SpellCaster(int unitType, std::string name, int hitPoints, int damage, int mana) {
    this->state = new State(unitType, name, hitPoints, damage, mana);
    }

SpellCaster::~SpellCaster() {}

void SpellCaster::attack(Unit* enemy, bool isAttack) {}

void SpellCaster::cast(Unit* enemy) {}

void SpellCaster::heal(Unit* unit) {}

int SpellCaster::getMana() const {
    return this->state->getMana();
}

int SpellCaster::getManaLimit() const {
    return this->state->getManaLimit();
}

void SpellCaster::setMana(int mana) {
    this->state->setMana(mana);
}

void SpellCaster::setManaLimit(int manaLimit) {
    this->state->setManaLimit(manaLimit);
}

void SpellCaster::addMana(int mana) {
    this->state->addMana(mana);
}

void SpellCaster::subtractMana(int mana) {
    this->state->subtractMana(mana);
}

std::ostream& operator<<(std::ostream& out, const SpellCaster& unit) {
    out << unit.getName() << " HP: " << unit.getHitPoints() << "|" << unit.getHitPointsLimit() << " DMG: " << unit.getDamage()
    << " MANA: " << unit.getHitPoints() << "|" << unit.getHitPointsLimit();
    return out;
}