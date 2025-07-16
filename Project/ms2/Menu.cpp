/***************************************************************
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

using namespace seneca;

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

Menu::Menu(const char* title, const char* exitOption, unsigned int indent, unsigned int indentSize)
  : m_indent(indent), m_indentSize(indentSize), m_numItems(0),
    m_title(title, indent, indentSize, -1),
    m_exitOption(exitOption, indent, indentSize, 0),
    m_prompt("> ", indent, indentSize, -1)
{
  for (unsigned int i = 0; i < MaximumNumberOfMenuItems; ++i) {
    m_items[i] = nullptr;
  }
}

Menu::~Menu() {
  for (unsigned int i = 0; i < MaximumNumberOfMenuItems; ++i) {
    delete m_items[i];
    m_items[i] = nullptr;
  }
}

Menu& seneca::Menu::operator<<(const char* menuItemContent) {
  if (m_numItems < MaximumNumberOfMenuItems && menuItemContent && menuItemContent[0] != '\0') {
    m_items[m_numItems] = new MenuItem(menuItemContent, m_indent, m_indentSize, static_cast<int>(m_numItems + 1));
    ++m_numItems;
  }
  return *this;
}

size_t Menu::select() const {
  if (m_title) {
    m_title.display(std::cout) << std::endl;
  }
  for (unsigned int i = 0; i < m_numItems; ++i) {
    if (m_items[i]) {
      m_items[i]->display(std::cout) << std::endl;
    }
  }
  m_exitOption.display(std::cout) << std::endl;
  m_prompt.display(std::cout);

  int selection = ut.getInt(0, static_cast<int>(m_numItems));
  return static_cast<size_t>(selection);
}

size_t seneca::operator<<(std::ostream& ostr, const Menu& m) {
  if (&ostr == &std::cout) {
    return m.select();
  } else {
    return 0;
  }
}

