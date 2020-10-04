//
// Created by hacker on 27.09.2020.
//

#ifndef PARSER_TABLE_HPP
#define PARSER_TABLE_HPP

#include <vector>
#include <string>

#include "Student.hpp"

//class Tester;

class Table {
 public:
  explicit Table(const std::string& s);
  explicit Table(const json& j);
  ~Table();

  //void print(std::ostream& out) const;

  static Table parse(const std::string& s);
  static Table parseFile(const std::string& s);
  size_t w_name, w_group, w_avg, w_debt, w_space;

  void print();

  std::vector<Student> m_students;
  std::vector<size_t> m_w;

};

/*class Tester {
 public:
  void dump(const Table& table) {
    std::cout << "=== Dump ===" << std::endl;
    std::cout << "Total student count: " << table.m_students.size() << std::endl;
    for (size_t i = 0; i < table.m_students.size(); ++i) {
      table.m_students[i].print_name();
      std::cout << "(" << table.m_students[i].length_name() << ") ";
      table.m_students[i].print_group();
      std::cout << " ";
      table.m_students[i].print_avg();
      std::cout << " ";
      table.m_students[i].print_debt();
      std::cout << std::endl;
    }
  }
};*/

#endif  // PARSER_TABLE_HPP
