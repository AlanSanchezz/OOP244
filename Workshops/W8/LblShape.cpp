

#include <iostream>
#include <cstring>
#include "LblShape.h"
#include "Utils.h"

namespace seneca {

    const char* LblShape::label() const {
        return m_label;
    }
    
    LblShape::LblShape() : m_label(nullptr) {}

    LblShape::LblShape(const char* label) : m_label(nullptr) {
        ut.alocpy(m_label, label);
    }

    LblShape::~LblShape() {
        delete[] m_label;
    }

    void LblShape::getSpecs(std::istream& is) {
        char temp[81];
        is.getline(temp, 81, ',');
        ut.alocpy(m_label, temp);
    }

}