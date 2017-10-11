#include "category.h"

std::set<Category*> Category::categories;

Category::Category(const std::string& title) : title(title) {
    categories.insert(this);
}

Category::Category(const Category& originalCategory) {
    categories.insert(this); 
}

const std::string& Category::getTitle() const {
    return title;
}

const std::set<Item*>& Category::getItems() const {
    return items;
}

const std::set<Category*>& Category::getCategories() {
    return categories;
}

void Category::addItem(Item* newItem) {
    if ( newItem == NULL ) {
        throw WrongItemCategoryException();
    }
    items.insert(newItem);
}

void Category::removeItem(Item* oldItem) {
    if ( oldItem == NULL ) {
        throw WrongItemCategoryException();
    }
    items.erase(oldItem);
}

Category::~Category() {
    for ( std::set<Item*>::iterator it = items.begin(); it != items.end(); it++ ) {
        Item* oldItem = *it;
        items.erase(it);
        delete oldItem;
    }
    categories.erase(this);
}

std::ostream& operator<<(std::ostream& out, const Category& category) {
    out << category.getTitle();
    
    return out;
}