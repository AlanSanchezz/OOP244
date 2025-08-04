#ifndef SDDS_ORDERING_H
#define SDDS_ORDERING_H

#include "Food.h"
#include "Drink.h"
#include "Utils.h"
#include "Billable.h"
#include "constants.h"

namespace seneca {

class Ordering {
    Food* m_foodItems{};                   // Dynamic array of Food loaded from file
    Drink* m_drinkItems{};                 // Dynamic array of Drink loaded from file
    Billable* m_billItems[MaximumNumberOfBillItems]{};  // Pointers to ordered items

    unsigned m_foodCount{};                // Number of foods loaded
    unsigned m_drinkCount{};               // Number of drinks loaded
    unsigned m_billCount{};                // Number of bill items added
    unsigned m_billSerial{1};              // Bill serial number starting at 1

public:
    Ordering(const char* drinksFilename, const char* foodsFilename); // constructor
    ~Ordering();                                                    // destructor

    operator bool() const;  // returns true if object is in valid state
    unsigned noOfBillItems() const;      // returns number of items in bill
    bool hasUnsavedBill() const;          // true if there are items in bill
    void listFoods() const;                // list available food items
    void listDrinks() const;               // list available drink items
    void orderFood();                     // order a food item
    void orderDrink();                    // order a drink item
    void printBill(std::ostream& os) const; // print current bill
    void resetBill();                     // save and reset current bill

private:
    void printBillTitle(std::ostream& os) const; // print bill header
    void printTotals(std::ostream& os, double total) const; // print totals and tax
    size_t countRecords(const char* file) const;  // count lines in a file
};

}

#endif // SDDS_ORDERING_H