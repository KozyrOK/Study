#include "Observer.h"

Observer::Observer(Unit* observable) {
    this->observable = observable;
    lst = new std::set<Unit*>();
}

Observer::~Observer() {}

void Observer::addObserver(Unit& unit) {
    lst->insert(&unit);
}

void Observer::removeObserver(Unit& unit) {
    lst->erase(&unit);
}

void Observer::observableIsDead() {
    std::set<Unit*>::iterator it;
    for ( it = lst->begin(); it != lst->end(); it++ ) {
        (**it).addHitPoints((int)((double)(observable->getHitPointsLimit()/10)));
        (**it).removeObservable(*observable);
    }
    if ( lst != NULL )
        delete lst;
}