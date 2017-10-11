#include "Unit.h"

Unit::Unit(int unitType, std::string name, int hitPoints, int damage) {
    this->state = new State(unitType, name, hitPoints, damage);
    this->altState = NULL;
    observers = new Observer(this);
    observables = new Observable(this);
}

Unit::~Unit() {
    if ( observers != NULL )
        delete observers;
    if ( observables != NULL )
        delete observables;
}

void Unit::ensureIsAlive() const {
    if ( this->getIsAlive() == false )
        throw UnitIsDeadException();
}

int Unit::getUnitType() const {
    return this->state->getUnitType();
}

std::string Unit::getName() const {
    return this->state->getName();
}

int Unit::getHitPoints() const {
    return this->state->getHitPoints();
}

int Unit::getHitPointsLimit() const {
    return this->state->getHitPointsLimit();
}

int Unit::getDamage() const {
    return this->state->getDamage();
}

void Unit::setUnitType(int unitType) {
    this->state->setUnitType(unitType);
}

void Unit::setName(std::string name) {
    this->state->setName(name);
}

void Unit::setHitPoints(int hitPoints) {
    this->state->setHitPoints(hitPoints);
}

void Unit::setHitPointsLimit(int hitPointsLimit) {
    this->state->setHitPointsLimit(hitPointsLimit);
}

void Unit::setDamage(int damage) {
    this->state->setDamage(damage);
}

void Unit::addHitPoints(int hitPoints) {
    this->state->addHitPoints(hitPoints);
}

void Unit::subtractHitPoints(int hitPoints) {
    this->state->subtractHitPoints(hitPoints);
    if ( this->state->getHitPoints() == 0 ) {
        if ( this->state->getUnitType() == 13 ) {
            observables->observerIsDead();
        } else {
            observers->observableIsDead();
        }
    }
}

bool Unit::getIsAlive() const {
    if ( this->state->getHitPoints() <= 0 )
        return false;
    return true;
}

void Unit::attack(Unit* enemy, bool isAttack) {}

void Unit::addObserver(Unit& unit) {
    observers->addObserver(unit);
}

void Unit::removeObserver(Unit& unit) {
    observers->removeObserver(unit);
}

void Unit::addObservable(Unit& unit) {
    observables->addObservable(unit);
}

void Unit::removeObservable(Unit& unit) {
    observables->removeObservable(unit);
}

void Unit::switchState() {
    Unit::ensureIsAlive();
    if ( this->altState == NULL )
        return;
    State* tempState = this->state;
    this->state = this->altState;
    this->altState = tempState;
}

void Unit::createAltState(int unitType, std::string name, int hitPoints, int damage) {
    this->altState = new State(unitType, name, hitPoints, damage);
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << unit.getName() << " HP: " << unit.getHitPoints() << "|" << unit.getHitPointsLimit() << " DMG: " << unit.getDamage();
    return out;
}