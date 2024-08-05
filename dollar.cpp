/** 
 *Lab Number: 2
 *Name: Mira Haldar and Jazmyne Newman
 *This file defines the Dollar class, which inherits from Currency
 Changes from Lab 2: 
 Created a copy constructor inheriting from the one in the currency class
 */
#include "currency.cpp"
class Dollar : public Currency {
private: 
    std::string currencyName = "Dollar"; 
public: 
    Dollar(double amount) : Currency(amount) {} 
    Dollar( const Currency & other ) : Currency(other) {}; 
    
    virtual std::string getCurrencyName() const { return currencyName; } 
}; 
