//
// Created by hacker on 27.09.2020.
//

#include "Student.hpp"
#include <iostream>
#include <cstdlib> // для system
#include <sstream>
#include <string>
#include <iomanip> // для std::setprecision()


void Student::from_json(const json& j, Student& s) {

  j.at("name").get_to(s.name);
  j.at("group").get_to(s.group);
  j.at("avg").get_to(s.avg);
  j.at("debt").get_to(s.debt);
}

void Student::print_name() const
{
  if (name.type() == typeid(std::string))
    std::cout<< std::any_cast<std::string>(name) ;
  else
    std::cout << "ERR";
}
void Student::print_group() const
{
  if (group.type() == typeid(int))
    std::cout << std::any_cast<int>(group);
  else if (group.type() == typeid(std::string))
    std::cout << std::any_cast<std::string>(group);
  else
    std::cout << "ERR";
}
void Student::print_avg() const
{
  if (avg.type() == typeid(int))
    std::cout << std::any_cast<int>(avg);
  else if (avg.type() == typeid(std::string))
    std::cout << std::any_cast<std::string>(avg);
  else if (avg.type() == typeid(double))
    std::cout << std::any_cast<double>(avg);
    else
        std::cout << "ERR";
}
void Student::print_debt() const
{
  if (debt.type() == typeid(std::string))
    std::cout << std::any_cast<std::string>(debt);
  else if (debt.type() == typeid(nullptr))
    std::cout << "null";
  else if (debt.type() == typeid(std::vector <std::string>))
    std::cout<<std::any_cast<std::vector<std::string>>(debt).size()<<" items";
  else
    std::cout << "ERR";
}

size_t Student::length_name() const
{
  if (name.type() == typeid(std::string))
    return (std::any_cast<std::string>(name).length());
  else
    return 0;
}
size_t Student::length_group() const
{
  if (group.type() == typeid(int))
   return (std::to_string(std::any_cast<int>(group)).length());
  else if (group.type() == typeid(std::string))
    return (std::any_cast<std::string>(group)).length();
  else
    return 0;
}
size_t Student::length_avg() const
{
  if (avg.type() == typeid(int))
    return (std::to_string(std::any_cast<int>(avg)).length());
  else if (avg.type() == typeid(std::string))
    return (std::any_cast<std::string>(avg)).length();
  else if (avg.type() == typeid(double)) {
    double b = std::any_cast<double>(avg);
    int k = (int) b;
    int count = 1;
    do {
      count++;
      k/=10;
    }while(k!=0);

    while((int)b-b != 0){
      count++;
      b*=10;
    }
    return count;
  }
    else
    return 0;

}
size_t Student::length_debt() const
{
  if (debt.type() == typeid(std::string))
    return (std::any_cast<std::string>(debt)).length();
  else if (debt.type() == typeid(nullptr))
    return 4;
  else if (debt.type() == typeid(std::vector <std::string>))
    return (std::to_string((std::any_cast<std::vector<std::string>>(debt)).size()).length()+6);
  else
    return 0;
}