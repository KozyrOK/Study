#include <iostream>
#include "Unit.h"

void Unit::ensureIsAlive() {
   if ( this->hitPoints == 0 ) {
        throw UnitIsDead();
   }
}

Unit::Unit(const std::string& name, int hp, int dmg) {
    this->damage = dmg;
    this->hitPoints = hp;
    this->hitPointsLimit = hp;
    this->name = name;
}

Unit::~Unit() {}

int Unit::getDamage() const {
    return this->damage;
}

int Unit::getHitPoints() const {
    return this->hitPoints;
}

int Unit::getHitPointsLimit() const{
    return this->hitPointsLimit;
}

const std::string& Unit::getName() const {
    return this->name;
}

void Unit::addHitPoints(int hp) {
    ensureIsAlive();
    this->hitPoints += hp;
    if (this->hitPoints > this->hitPointsLimit) {
        this->hitPoints = this->hitPointsLimit;
    }
}

void Unit::takeDamage(int dmg) {
    ensureIsAlive();
    this->hitPoints -= dmg;
    if (this->hitPoints < 0) {
        this->hitPoints = 0;
    }
}

void Unit::attack(Unit& enemy) {
    enemy.ensureIsAlive();
    enemy.takeDamage(this->damage);
    enemy.ensureIsAlive();
    enemy.counterAttack(*this);
}

void Unit::counterAttack(Unit& enemy) {
    ensureIsAlive();
    int damageUnit = this->damage;
    int damageCounterAttack = (damageUnit /= 2);
    enemy.hitPoints -= damageCounterAttack;
    if (enemy.getHitPoints() < 0) {
        enemy.hitPoints = 0;
    }
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << "Unit name: " << unit.getName() << ",\n"
    << "Hit points: " << unit.getHitPoints() << ",\n"
    << "Hit points limit: " << unit.getHitPointsLimit() << ",\n"
    << "Damage: " << unit.getDamage() << "." << std::endl;
    return out;
}
