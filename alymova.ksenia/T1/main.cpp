#include <iostream>
#include <map>
#include <functional>
#include <limits>
#include "note-bd-commands.hpp"

int main() {
  using namespace alymova;
  using namespace std::placeholders;

  std::map< std::string, std::function< void(std::istream&, NoteBd&) > > commands;
  commands.emplace("note", note);
  commands.emplace("line", line);
  commands.emplace("show", std::bind(show, _1, std::ref(std::cout), _2));
  commands.emplace("drop", drop);
  commands.emplace("link", link);
  commands.emplace("halt", halt);
  commands.emplace("mind", std::bind(mind, _1, std::ref(std::cout), _2));
  commands.emplace("expired", std::bind(expired, _1, std::ref(std::cout), _2));
  commands.emplace("refresh", refresh);

  NoteBd bd;

  std::string command;
  while (std::cin >> command) {
    try
    {
      commands.at(command)(std::cin, bd);
      if (command == "show" || command == "mind" || command == "expired")
      {
        std::cout << '\n';
      }
    }
    catch (const std::exception& e)
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
      std::cout << "<INVALID COMMAND>\n";
    }
  }
}
