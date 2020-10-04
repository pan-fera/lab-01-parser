//
// Created by hacker on 27.09.2020.
//

#ifndef PARSER_STUDENT_HPP
#define PARSER_STUDENT_HPP
#include "json_any.hpp"
using nlohmann::json;
class Student {
 public:

  size_t length_name() const;
  size_t length_group() const;
  size_t length_avg() const;
  size_t length_debt() const;

  void print_name() const;
  void print_group() const;
  void print_avg() const;
  void print_debt() const;

  static void from_json(const json& j, Student& s);
 private:
  std::any name;
  std::any group;
  std::any avg;
  std::any debt;

};

#endif  // PARSER_STUDENT_HPP
