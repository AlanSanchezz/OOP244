#include <iostream>
#include "Rectangle.h"
#include "Utils.h"

namespace seneca {

Rectangle::Rectangle() : LblShape(), m_width(0), m_height(0) {}

Rectangle::Rectangle(const char* label, int width, int height)
    : LblShape(label) {
    m_width = (width < (int)ut.strlen(label) + 2) ? (int)ut.strlen(label) + 2 : width;
    m_height = (height < 3) ? 3 : height;
}

void Rectangle::getSpecs(std::istream& is) {
    LblShape::getSpecs(is);
    char comma;
    is >> m_width >> comma >> m_height;
    is.ignore(1000, '\n');
}

void Rectangle::draw(std::ostream& os) const {
    if (m_width > 0 && m_height > 0 && label() != nullptr) {
        // Top border
        os << '+';
        for (int i = 0; i < m_width - 2; ++i) os << '-';
        os << '+' << std::endl;
        // Label line
        os << "| ";
        os << label();
        int labelLen = ut.strlen(label());
        for (int i = 0; i < m_width - 3 - labelLen; ++i) os << ' ';
        os << '|' << std::endl;

        // Empty lines
        for (int i = 0; i < m_height - 3; ++i) {
            os << '|';
            for (int j = 0; j < m_width - 2; ++j) os << ' ';
            os << '|' << std::endl;
        }

        // Bottom border
        os << '+';
        for (int i = 0; i < m_width - 2; ++i) os << '-';
        os << '+' << std::endl;
    }
}

}