#include <iostream>
#include "hashtable.cpp"
#include "dollar.cpp"
#include "currency.cpp"
#pragma once






int main() { 
    HashTable hashTable(29); 
    std::vector<Dollar> seedData = {{57.12}, {23.44}, {87.43}, {68.99}, {111.22}, {44.55}, {77.77}, {18.36}, {543.21}, {20.21}, {345.67}, {36.18}, {48.48}, {101.00}, {11.00}, {21.00}, {51.00}, {1.00}, {251.00}, {151.00}}; 
    for (auto& dollar : seedData) { 
        hashTable.insert(&dollar); 
    } 
    
    std::cout << "Number of data items loaded: " << hashTable.getLoadFactor() << std::endl; 
    std::cout << "Load factor: " << static_cast<float>(hashTable.getLoadFactor()) / hashTable.getSize() << std::endl; 
    std::cout << "Number of collisions: " << hashTable.getCollisions() << std::endl;
     
    while (true) { 
        int whole, fraction; 
        std::cout << "Enter Dollar to search for (whole fraction): "; 
        std::cin >> whole >> fraction; 
        
        int index = hashTable.search(whole, fraction); 
        if (index != -1) { 
            std::cout << "Dollar found at index: " << index << std::endl; 
        } else { 
            std::cout << "Invalid Data" << std::endl; 
        } 
        char choice; 
        std::cout << "Do you want to check again? (y/n): "; 
        std::cin >> choice; 
        if (choice == 'n' || choice == 'N') break; 
        } 
        return 0; 
} 