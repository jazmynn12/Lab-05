/** 
 *Lab Number: 3
 *Name: Mira Haldar and Jazmyne Newman
 *This file defines the abstract Currency class 
 Changes from lab 2: 
 Made the class abstract by turning getCurrencyName() into a purely virtual method
 turned references to Currency objects into constant references to Currency objects 

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
    Currency(const Currency & other){ 
    	amountwhole = other.getAmountWhole(); 
        amountfrac = other.getAmountFrac(); 
        
    }
    virtual std::string getCurrencyName() const = 0;  //changed this to purely virtual, making currency an abstract class 
    int getAmountWhole() const { 
        return amountwhole; 
    } 
    int getAmountFrac() const{ 
        return amountfrac; 
    }
/**
 Adds the values of another Currency object to this Currency object.
 *
 * pre: other- Currency object
 * post: The amountwhole and amountfrac of this Currency object are increased
 *       by the amountwhole and amountfrac of the other Currency object.
 *       Throws invalid argument exception if the two objects are not of the same currency type
 * return: void
 */
    void add(const Currency& other) {
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
/**
Subtracts the values of another Currency object from this Currency object.
 *
 * pre: other- Currency object
 * post: The amountwhole and amountfrac of the other Currency object are subtracted from the amountwhole and amountfrac of the other Currency object.
 *       Throws invalid argument exception if the two objects are not of the same currency type OR if the subtraction results in a negative value
 * return: void
 */
    void subtract(const Currency & other) {
        if(!isSameType(other))
        { 
            throw std::invalid_argument("Invalid subtraction"); 
        }
        int otherwhole = other.getAmountWhole(); 
        int otherfrac = other.getAmountFrac(); 
        if(other.isGreater(*this)){
            throw std::invalid_argument("Invalid subtraction"); 
        }
        amountwhole -= other.getAmountWhole();
        amountfrac -= other.getAmountFrac(); 
        if(amountfrac < 0) { 
            amountwhole --; 
            amountfrac = 100 - amountfrac; 
        }
    }
/**
 Checks whether a Currency object matches the currency type of this one
 * pre: other- Currency object
 * post: 
 * return: true or false
 */
    bool isSameType( const Currency & other) const{  
        return other.getCurrencyName() == getCurrencyName(); 
    }
/**
Checks whether the values of another Currency object equals this one
 *
 * pre: other- Currency object
 * post: Throws invalid argument exception if the two objects are not of the same currency type
 * return: true or false
 */
    bool isEqual(const Currency & other) const{ 
        if (!isSameType(other) ) { 
            throw std::invalid_argument("Invalid comparison"); 
        }
        return (other.getAmountFrac() == amountfrac && other.getAmountWhole() == amountwhole); 
    }
/**
Compares a Currency object to identify which object is larger or smaller.
 *
 * pre: other- Currency object
 * post:Throws invalid argument exception if the two objects are not of the same currency type
 * return: true or false
 */
    bool isGreater(const Currency & other) const{ 
        bool isGreater = false; 
        if (!isSameType(other) ) { 
            throw std::invalid_argument("Invalid comparison"); 
        }
            isGreater = (other.getAmountWhole() <  amountwhole) || (other.getAmountFrac() <  amountfrac && other.getAmountWhole() == amountwhole ); 
        
        return isGreater; 
    }
    /* returns the name and value of the Currency object 
    pre: 
    post: 
    return: a string in the form "xx.yy" followed by the derived currency name 
    */
    std::string toString () const{ 
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

