#include <fstream>
#include <iomanip>
#include <iostream>
#include "Ordering.h"
#include "Menu.h"

using namespace std;

namespace seneca {

// Constructor
Ordering::Ordering(const char* drinksFilename, const char* foodsFilename) {
    m_foodCount = countRecords(foodsFilename);
    m_drinkCount = countRecords(drinksFilename);

    ifstream din(drinksFilename);
    ifstream fin(foodsFilename);

    if (din && fin) {
        m_drinkItems = new Drink[m_drinkCount];
        m_foodItems = new Food[m_foodCount];

        unsigned dcount = 0;
        for (; dcount < m_drinkCount && m_drinkItems[dcount].read(din); ++dcount);
        unsigned fcount = 0;
        for (; fcount < m_foodCount && m_foodItems[fcount].read(fin); ++fcount);

        if (dcount != m_drinkCount || fcount != m_foodCount) {
            delete[] m_drinkItems;
            delete[] m_foodItems;
            m_drinkItems = nullptr;
            m_foodItems = nullptr;
            m_drinkCount = 0;
            m_foodCount = 0;
        }
    }
}

// Destructor
Ordering::~Ordering() {
    delete[] m_foodItems;
    delete[] m_drinkItems;

    for (unsigned i = 0; i < m_billCount; ++i) {
        delete m_billItems[i];
        m_billItems[i] = nullptr;
    }
}

unsigned Ordering::noOfBillItems() const {
    return m_billCount;
}

bool Ordering::hasUnsavedBill() const {
    return m_billCount > 0;
}

void Ordering::listFoods() const {
    cout << "List Of Avaiable Meals" << endl;
    cout << "========================================" << endl;
    for (unsigned i = 0; i < m_foodCount; ++i) {
        m_foodItems[i].print(cout) << endl;
    }
    cout << "========================================" << endl;
}

void Ordering::listDrinks() const {
    cout << "List Of Avaiable Drinks" << endl;
    cout << "========================================" << endl;
    for (unsigned i = 0; i < m_drinkCount; ++i) {
        m_drinkItems[i].print(cout) << endl;
    }
    cout << "========================================" << endl;
}

void Ordering::orderFood() {
    seneca::Menu foodMenu("Food Menu", "Back to Order", 2);
    for (unsigned i = 0; i < m_foodCount; ++i) {
        foodMenu << static_cast<const char*>(m_foodItems[i]);
    }

    size_t selection = foodMenu.select();
    if (selection > 0) {
        Billable* newFood = new Food(m_foodItems[selection - 1]);
        if (newFood->order()) {
            m_billItems[m_billCount++] = newFood;
        } else {
            delete newFood;
        }
    }
}

void Ordering::orderDrink() {
    seneca::Menu drinkMenu("Drink Menu", "Back to Order", 2);
    for (unsigned i = 0; i < m_drinkCount; ++i) {
        drinkMenu << static_cast<const char*>(m_drinkItems[i]);
    }

    size_t selection = drinkMenu.select();
    if (selection > 0) {
        Billable* newDrink = new Drink(m_drinkItems[selection - 1]);
        if (newDrink->order()) {
            m_billItems[m_billCount++] = newDrink;
        } else {
            delete newDrink;
        }
    }
}

void Ordering::printBill(std::ostream &os) const {
    double total = 0.0;
    printBillTitle(os);
    for (unsigned i = 0; i < m_billCount; ++i) {
        m_billItems[i]->print(os) << std::endl;
        total += m_billItems[i]->price();
    }
    printTotals(os, total);
}

void Ordering::resetBill()
{
    char filename[50] = {0};
    ut.makeBillFileName(filename, m_billSerial);

    std::ofstream ofs(filename);
    if (ofs) {
        printBill(ofs);
        ofs.close();
        std::cout << "Saved bill number " << m_billSerial << std::endl;
        m_billSerial++;
        std::cout << "Starting bill number " << m_billSerial << std::endl;

        // Delete all dynamically created Billable items
        for (unsigned i = 0; i < m_billCount; ++i) {
            delete m_billItems[i];
            m_billItems[i] = nullptr;
        }

        m_billCount = 0;
    }
}

// Count Records Helper
size_t Ordering::countRecords(const char* file) const {
    ifstream in(file);
    size_t count = 0;
    char ch;
    while (in.get(ch)) {
        if (ch == '\n') count++;
    }
    return count;
}

// Print Bill Title
void Ordering::printBillTitle(std::ostream& os) const {
    os << "Bill # " << setw(3) << setfill('0') << m_billSerial
       << " =============================" << endl;
    os << setfill(' '); // Reset fill
}

// Print Totals
void Ordering::printTotals(std::ostream& os, double total) const {
    const double tax = total * Tax;
    os << setw(27) << right << fixed << setprecision(2)
       << "Total:" << setw(13) << total << endl;
    os << setw(25) << "Tax:" << setw(15) << tax << endl;
    os << setw(23) << "Total+Tax:" << setw(10) << (total + tax) << endl;
    os << "========================================" << endl;
}

Ordering::operator bool() const {
    return m_foodItems != nullptr && m_drinkItems != nullptr;
}

}
