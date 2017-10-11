#include "Observable.h"

Observable::Observable(Unit* observer) {
    this->observer = observer;
    lst = new std::set<Unit*>();
}

Observable::~Observable() {}

void Observable::addObservable(Unit& unit) {
    lst->insert(&unit);
    unit.addObserver(*observer);
}

void Observable::removeObservable(Unit& unit) {
    lst->erase(&unit);
}

void Observable::observerIsDead() {
    std::set<Unit*>::iterator it;
    for ( it = lst->begin(); it != lst->end(); it++ ) {
        (**it).removeObserver(*observer);
    }
    if ( lst != NULL )
        delete lst;
}