/***************************************************************
// Final Project Milestone 1
// Module: Menu
// File: Menu.h
// Version 1.0
// Author: Alan Sanchez, StNo: 121720247, Email: aygarduno-sanchez@myseneca.ca
// -----------------------------------------------------------
// Date        Reason
// 2025/07/06  Initial implementation
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include <iostream>
#include "constants.h"
namespace seneca {

   class Menu;

   class MenuItem {
      char* m_content;
      unsigned int m_indent;
      unsigned int m_indentSize;
      int m_row;

      friend class Menu;

      // Constructor
      MenuItem(const char* content = nullptr, unsigned int indent = 0, unsigned int indentSize = 0, int row = -1);

      // Destructor
      ~MenuItem();

      // Copy constructor and assignment are deleted
      MenuItem(const MenuItem&) = delete;
      MenuItem& operator=(const MenuItem&) = delete;

      // Conversion to bool
      operator bool() const;

      // Display method
      std::ostream& display(std::ostream& os = std::cout) const;
   };

   class Menu {
      unsigned int m_indent;
      unsigned int m_indentSize;
      unsigned int m_numItems;
      MenuItem m_title;
      MenuItem m_exitOption;
      MenuItem m_prompt;
      MenuItem* m_items[MaximumNumberOfMenuItems];

   public:
      Menu(const char* title, const char* exitOption = "Exit", unsigned int indent = 0, unsigned int indentSize = 3);
      Menu& operator<<(const char* menuItemContent);
      size_t select() const;

      Menu(const Menu&) = delete;
      Menu& operator=(const Menu&) = delete;
      ~Menu();
   };

   size_t operator<<(std::ostream& ostr, const Menu& m);

}

#endif // !SDDS_MENU_H