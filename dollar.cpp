/** 
 *Lab Number: 2
 *Name: Mira Haldar and Jazmyne Newman
 *This file defines the Dollar class, which inherits from Currency
 */
#include "currency.cpp"
class Dollar : public Currency {
private: 
    std::string currencyName = "Dollar"; 
public: 
    Dollar(double amount) : Currency(amount) {} 
    std::string getCurrencyName() override { return currencyName; } 
}; 