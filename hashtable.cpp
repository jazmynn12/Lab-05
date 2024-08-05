#include <iostream> 
#include <vector> 
#include <cmath> 
#include "dollar.cpp"




class HashTable { 
    private: std::vector<Dollar*> table; 
    int size; 
    int collisions; 
    
    public: 
    HashTable(int s) : size(s), collisions(0) { 
        table.resize(size, nullptr); 
    } 
    
    int hashFunction(int whole, int fraction) { 
        int m = 2, n = 3; 
        return (m * whole + n * fraction) % size; 
    } 
    void insert(Dollar* dollar) { 
        int index = hashFunction(dollar->amountwhole, dollar->fraction);
        int i = 0; 
        
        while (table[index] != nullptr) { 
            collisions++; 
            i++; 
            index = (index + i * i) % size; 
        } 
        table[index] = dollar; 
    } 
    
    int search(int whole, int fraction) { 
        int index = hashFunction(whole, fraction); 
        int i = 0; 
        
        while (table[index] != nullptr) { 
            if (table[index]->whole == whole && table[index]->fraction == fraction) { 
                return index; 
            } 
            i++; 
            index = (index + i * i) % size; 
        } 
        return -1; 
    }
    int getCollisions() { 
        return collisions; 
    } 
    int getSize() { 
        return size; 
    } 
    int getLoadFactor() { 
        int count = 0; 
        for (auto dollar : table) { 
            if (dollar != nullptr) count++; 
        } return count; 
    } 
}; 