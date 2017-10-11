#include "State.h"

State::State(int unitType, std::string name, int hitPoints, int damage, int mana) {
    this->unitType = unitType;
    this->name = name;
    this->hitPointsLimit = hitPoints;
    this->hitPoints = hitPoints;
    this->damage = damage;
    this->manaLimit = mana;
    this->mana = mana;
}

State::~State() {}

int State::getUnitType() const {
    return this->unitType;
}

std::string State::getName() const {
    return this->name;
}

int State::getHitPoints() const {
    return this->hitPoints;
}

int State::getHitPointsLimit() const {
    return this->hitPointsLimit;
}

int State::getDamage() const {
    return this->damage;
}

int State::getMana() const {
    return this->mana;
}

int State::getManaLimit() const {
    return this->manaLimit;
}

void State::setUnitType(int unitType) {
    this->unitType = unitType;
}

void State::setName(std::string name) {
    this->name = name;
}

void State::setHitPoints(int hitPoints) {
    if ( hitPoints < 0 || hitPoints > this->hitPointsLimit )
        throw StateSetParameterException();
    this->hitPoints = hitPoints;
}

void State::setHitPointsLimit(int hitPointsLimit) {
    if ( hitPointsLimit <= 0 )
        throw StateSetParameterException();
    this->hitPointsLimit = hitPointsLimit;
}

void State::setDamage(int damage) {
    if ( damage <= 0 )
        throw StateSetParameterException();
    this->damage = damage;
}

void State::setMana(int mana) {
    if ( mana < 0 || mana > this->manaLimit )
        throw StateSetParameterException();
    this->mana = mana;
}

void State::setManaLimit(int manaLimit) {
    if ( manaLimit < 0 )
        throw StateSetParameterException();
    this->manaLimit = manaLimit;
}

void State::addHitPoints(int hitPoints) {
    int newHitPoints = this->hitPoints + hitPoints;
    if ( newHitPoints > this->hitPointsLimit ) {
        this->hitPoints = this->hitPointsLimit;
    } else if ( newHitPoints < 0 ) {
        this->hitPoints = 0;
    } else {
        this->hitPoints = newHitPoints;
    }
}

void State::subtractHitPoints(int hitPoints) {
    int newHitPoints = this->hitPoints - hitPoints;
    if ( newHitPoints < 0 ) {
        this->hitPoints = 0;
    } else if ( newHitPoints > this->hitPointsLimit ) {
        this->hitPoints = this->hitPointsLimit;
    } else {
        this->hitPoints = newHitPoints;
    }
}

void State::addMana(int mana) {
    int newMana = this->mana + mana;
    if ( newMana > this->manaLimit ) {
        this->mana = this->manaLimit;
    } else if ( newMana < 0 ) {
        this->mana = 0;
    } else {
        this->mana = newMana;
    }
}

void State::subtractMana(int mana) {
    int newMana = this->mana - mana;
    if ( newMana < 0 ) {
        this->mana = 0;
    } else if ( newMana > this->manaLimit ) {
        this->mana = this->manaLimit;
    } else {
        this->mana = newMana;
    }
}