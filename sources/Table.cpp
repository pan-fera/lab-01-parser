//
// Created by hacker on 27.09.2020.
//
#include <iostream>
#include "Table.hpp"
#include <fstream>

Table::Table(const std::string& s) :
m_students(0), m_w(0){
w_name = 4;
w_group = 4;
w_avg = 3;
w_debt = 4;
w_space = 2;

m_w.push_back(w_name);
m_w.push_back(w_group);
m_w.push_back(w_avg);
m_w.push_back(w_debt);

std::cout<<s;
}
Table::Table(const json& j):
  m_students(0), m_w(0){

  w_name = 4;
  w_group = 5;
  w_avg = 3;
  w_debt = 4;
  w_space = 2;

  m_w.push_back(w_name+w_space);
  m_w.push_back(w_group+w_space);
  m_w.push_back(w_avg+w_space);
  m_w.push_back(w_debt+w_space);

  for (json::const_iterator it = j.at("items").begin(); it != j.at("items").end(); ++it) {

    Student student;
   Student::from_json(it.value(), student);
  m_students.push_back(student);
  }

 for (size_t i =0; i < m_students.size(); i++)
  {
   /*m_students[i].print_name();
    std::cout<<m_students[i].length_name()<<"\n";
    m_students[i].print_group();
    std::cout<<m_students[i].length_group()<<"\n";
    m_students[i].print_avg();
    std::cout<<m_students[i].length_avg()<<"\n";
    m_students[i].print_debt();
    std::cout<<m_students[i].length_debt()<<"\n";*/

  m_w[0] = (m_students[i].length_name()+w_space>m_w[0])? (m_students[i].length_name()+w_space):m_w[0];
   m_w[1] = (m_students[i].length_group()+w_space>m_w[1])? (m_students[i].length_group()+w_space):m_w[1];
    m_w[2] = (m_students[i].length_avg()+w_space>m_w[2])? (m_students[i].length_avg()+w_space):m_w[2];
    m_w[3] = (m_students[i].length_debt()+w_space>m_w[3])? (m_students[i].length_debt()+w_space):m_w[3];
  }

}
Table Table::parse(const std::string& s) {
  Table table(s);
  return table;
}

Table Table::parseFile(const std::string& s) {
  std::ifstream file;

  file.open(s, std::ios::in);
  json j;
  file>>j;
  Table table(j);
  return table;
}

void Table::print()
{
  int column = 4;


  std::cout << "| name ";
  for (size_t i = 0; i < m_w[0] - w_name - w_space; i++)
    std::cout << " ";
  std::cout << "| group ";
  for (size_t i = 0; i < m_w[1] - w_group - w_space; i++)
    std::cout << " ";
  std::cout << "| avg ";
  for (size_t i = 0; i < m_w[2] - w_avg - w_space; i++)
    std::cout << " ";
  std::cout << "| debt ";
  for (size_t i = 0; i < m_w[3] - w_debt - w_space; i++)
    std::cout << " ";
  std::cout << "|" << std::endl;
    std::string stick  = "|";
    for (int i = 0; i < column; ++i) {

        for (size_t j = 0; j < m_w[i]; ++j)
            stick += "-";
        stick += "|";
    }
    std::cout<<stick<<std::endl;


  for(size_t m =0; m<m_students.size(); m++)
  {
    std::cout << "| ";
    m_students[m].print_name();
    for (size_t i = 0; i < m_w[0] - m_students[m].length_name() - w_space; i++) {
      std::cout << " ";
    }
    std::cout << " | ";
    m_students[m].print_group();
    std::cout << " ";
    for (size_t i = 0; i < m_w[1] - m_students[m].length_group() - w_space; i++)
      std::cout << " ";
    std::cout << "| ";
    m_students[m].print_avg();
    std::cout << " ";
    for (size_t i = 0; i < m_w[2] - m_students[m].length_avg() - w_space; i++)
      std::cout << " ";
    std::cout << "| ";
    m_students[m].print_debt();
    std::cout << " ";
    for (size_t i = 0; i < m_w[3] - m_students[m].length_debt() - w_space; i++)
      std::cout << " ";
    std::cout << "|" << std::endl << stick << std::endl;
  }
}

Table::~Table(){

}