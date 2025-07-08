/***********************************************************************
// Final Project Milestone 1
// Module: Menu
// File: Menu.cpp
// Version 1.0
// Author: Alan Sanchez, StNo: 121720247, Email: aygarduno-sanchez@myseneca.ca
// -----------------------------------------------------------
// Date        Reason
// 2025/07/06  Initial implementation
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************/

#include <iostream>
#include "Menu.h"
#include "constants.h"
#include "Utils.h"

using namespace std;
using namespace seneca;

extern Utils ut;

MenuItem::MenuItem(const char* content, unsigned int indent, unsigned int indentSize, int row)
  : m_content(nullptr), m_indent(0), m_indentSize(0), m_row(-1)
{
  if (content && content[0] != '\0') {
    bool onlySpaces = true;
    for (size_t i = 0; content[i] != '\0'; ++i) {
      if (!ut.isspace(content[i])) {
        onlySpaces = false;
      }
    }
    if (!onlySpaces && indent <= 4 && indentSize <= 4 && row <= (int)MaximumNumberOfMenuItems) {
      m_content = new char[ut.strlen(content) + 1];
      ut.strcpy(m_content, content);
      m_indent = indent;
      m_indentSize = indentSize;
      m_row = row;
    }
  }
}

MenuItem::~MenuItem() {
  delete[] m_content;
}

MenuItem::operator bool() const {
  return m_content != nullptr;
}

std::ostream& MenuItem::display(std::ostream& os) const {
  if (*this) {
    for (unsigned int i = 0; i < m_indent * m_indentSize; ++i) {
      os << ' ';
    }
    if (m_row >= 0) {
      os.width(2);
      os << m_row << "- ";
    }
    const char* p = m_content;
    while (*p && ut.isspace(*p)) ++p; 
    os << p;
  } else {
    os << "??????????";
  }
  return os;
}