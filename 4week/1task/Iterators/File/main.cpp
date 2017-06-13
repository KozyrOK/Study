#include <iostream>
#include <fstream>
#include <cstdlib>
#include "FileIterator.cpp"

int main() {
    std::ifstream file;

    file.open("task.in", std::ios::out | std::ios::app);
    
    FileIterator<int>("task.in");

    file.close();

    return 0;
}
