// Copyright 2018 Your Name <your_email>
#include <gtest/gtest.h>
#include <iostream>
#include "Table.hpp"
#include <fstream>
TEST(Example, EmptyTest) {

    EXPECT_TRUE(true);
}

TEST(Parse, FromJson){
  std::cout << "KEK!" << std::endl;
  std::string test_json=\
R"({
  "items": [
    {
      "name": "Ivanov Petr",
      "group": "1",
      "avg": "4.25",
      "debt": null
    },
    {
      "name": "Sidorov Ivan",
      "group": 31,
      "avg": 4,
      "debt": "C++"
    },
    {
      "name": "Petrov Nikita",
      "group": "IU8-31",
      "avg": 33.03,
      "debt": [
        "C++",
        "Linux",
        "Network",
        "SPO"
      ]
    }
  ],
  "_mea": {
    "count": 3
  }
})";

std::ofstream file_json;

file_json.open("file_json.json");
file_json<<test_json;
file_json.close();
Table table = Table::parseFile("file_json.json");
  //Tester t;
// t.dump(table);
table.print();

}


