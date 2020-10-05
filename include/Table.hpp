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
  explicit Table(const json& j);
  ~Table();

  //void print(std::ostream& out) const;


  static Table parseFile(const std::string& s);
  size_t w_name, w_group, w_avg, w_debt, w_space;

  void print(std::ostream& out) const;

  std::vector<Student> m_students;
  std::vector<size_t> m_w;
// std::cout - это объект std::ostream

};

//std::ostream& operator<< (std::ostream &out, const Table &table);



#endif  // PARSER_TABLE_HPP
