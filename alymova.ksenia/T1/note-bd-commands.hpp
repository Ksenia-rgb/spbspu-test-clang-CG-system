#ifndef NOTE_BD_COMMANDS_HPP
#define NOTE_BD_COMMANDS_HPP
#include <istream>
#include <ostream>
#include "note-bd.hpp"

namespace alymova
{
  void note(std::istream& in, NoteBd& bd);
  void line(std::istream& in, NoteBd& bd);
  void show(std::istream& in, std::ostream& out, const NoteBd& bd);
  void drop(std::istream& in, NoteBd& bd);
  void link(std::istream& in, NoteBd& bd);
  void halt(std::istream& in, NoteBd& bd);
  void mind(std::istream& in, std::ostream& out, const NoteBd& bd);
  void expired(std::istream& in, std::ostream& out, const NoteBd& bd);
  void refresh(std::istream& in, NoteBd& bd);
}
#endif
