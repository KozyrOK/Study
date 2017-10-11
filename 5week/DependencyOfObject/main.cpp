#include <iostream>
#include "category.h"
#include "item.h"
#include "order.h"
#include "customer.h"
#include "templates.cpp"

int main() {
    Category* mobile = new Category("Mobile");
    Category* laptops = new Category("Laptops");
    
    Item* nokia = new Item("Nokia", mobile);
    Item* lenovo = new Item("Lenovo", laptops);
    
    Customer* artem = new Customer("Petro");
    Customer* kirill = new Customer("Andry");
     
    return 0;
}