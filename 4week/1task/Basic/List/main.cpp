#include <iostream>
#include "List.h"

int main() {
    List* com1 = new List();
    List* com2 = new List();
    
    
    std::cout << com2->size() << std::endl;
    std::cout << com2->max_size() << std::endl;
    
    com2->push_back(5);
    com2->push_back(4);
    com2->push_back(3);
    com2->push_back(2);
    com2->push_back(1);
    com1->push_back(1);
    com1->push_back(2);
    com1->push_back(3);
    com1->push_back(4);
    com1->push_back(5);
    
    std::cout << *com1 << std::endl;
    std::cout << *com2 << std::endl;
    
    com2->erase(0);
    std::cout << "erase:     " << *com2 << std::endl;

    com2->insert(0, 3);
    std::cout << "insert:    " << *com2 << std::endl;
        
    std::cout << com2->find(0) << std::endl;
    
    com2->push_back(5);
    std::cout << "push_back: " << *com2 << std::endl;
    
    com2->pop_back();
    std::cout << "pop_back:  " << *com2 << std::endl;

    com2->sort();
    std::cout << "sort:      " << *com2 << std::endl;

    std::cout << (*com2)[1] << std::endl;

    return 0;
}
