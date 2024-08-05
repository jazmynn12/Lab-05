/** 
 *Lab Number: 2
 *Name: Mira Haldar and Jazmyne Newman
 *This file defines the abstract Currency class 
 */
#include <iostream> 
#include <string> 
#include <stdexcept> 
#pragma once
class Currency { 
    private: 
        int amountwhole, amountfrac; 
    public: 
    Currency(){
        amountwhole = 0; 
        amountfrac = 0; 
    }
    Currency(double amount) { 
        if(amount < 0) { 
            throw std::invalid_argument("Currency cannot have negative value");
        }
            amountwhole = int(amount);
            double a = 100*(amount-amountwhole); 
            
            amountfrac = stoi(std::to_string(a)) ; //attempting to prevent round down error 
    }
    Currency(Currency & other){ 
        amountwhole = other.getAmountWhole(); 
        amountfrac = other.getAmountFrac(); 
        
    }
    virtual std::string getCurrencyName(){return " ";}
    int getAmountWhole() const { 
        return amountwhole; 
    } 
    int getAmountFrac() const{ 
        return amountfrac; 
    }
    //add exception handling instead of if statements lol 
    void add(Currency& other) {
        if(!isSameType(other)){ 
            throw std::invalid_argument("Invalid addition");
        } 
        amountwhole += other.getAmountWhole();
        amountfrac += other.getAmountFrac(); 
        if(amountfrac>100){ 
            amountfrac = amountfrac%100; 
            amountwhole++; 
        }
    }
    void subtract(Currency& other) {
        if(!isSameType(other))
        { 
            throw std::invalid_argument("Invalid subtraction"); 
        }
        int otherwhole = other.getAmountWhole(); 
        int otherfrac = other.getAmountFrac(); 
        if(otherwhole > amountwhole || otherwhole == amountwhole && otherfrac> amountfrac){
            throw std::invalid_argument("Invalid subtraction"); 
        }
        amountwhole -= other.getAmountWhole();
        amountfrac -= other.getAmountFrac(); 
        if(amountfrac < 0) { 
            amountwhole --; 
            amountfrac = 100 - amountfrac; 
        }
    }
    bool isSameType( Currency& other) {  
        return other.getCurrencyName() == getCurrencyName(); 
    }
    bool isEqual(Currency & other){ 
        if (!isSameType(other) ) { 
            throw std::invalid_argument("Invalid comparison"); 
        }
        return (other.getAmountFrac() == amountfrac && other.getAmountWhole() == amountwhole); 
    }
    bool isGreater(Currency & other){ 
        bool isEqual = false; 
        if (isSameType(other) ) { 
            throw std::invalid_argument("Invalid comparison"); 
        }
            isEqual = (other.getAmountWhole() <  amountwhole) || (other.getAmountFrac() <  amountfrac && other.getAmountWhole() == amountwhole ); 
        
        return isEqual; 
    }
    std::string toString(){ 
        std::string info; 
        if(amountfrac< 10){ 
            info = std::to_string(amountwhole) + ".0" + std::to_string(amountfrac) + " " + getCurrencyName(); 
        }
        else{ 
            return std::to_string(amountwhole) + "." + std::to_string(amountfrac) + " " + getCurrencyName(); 
        }
        return info; 
    }
    ~Currency() { 
        delete &amountfrac;
        delete &amountwhole; 
    }
 }; 

