#include "note-bd-commands.hpp"
#include "note-bd.hpp"
#include <iomanip>
#include <istream>
#include <ostream>
#include <stdexcept>
#include <string>

void alymova::note(std::istream& in, NoteBd& bd)
{
  std::string name;
  in >> name;
  if (name.empty()) {
    throw std::logic_error("<NOTE> incorrect parameteres");
  }
  bd.createNote(name);
}
void alymova::line(std::istream& in, NoteBd& bd)
{
  std::string name, line;
  in >> name >> std::quoted(line);
  if (name.empty() || line.empty()) {
    throw std::logic_error("<LINE> incorrect parameteres");
  }
  bd.addLine(name, line);
}
void alymova::show(std::istream& in, std::ostream& out, const NoteBd& bd)
{
  std::string name;
  in >> name;
  if (name.empty()) {
    throw std::logic_error("<SHOW> incorrect parameteres");
  }
  bd.show(out, name);
}
void alymova::drop(std::istream& in, NoteBd& bd)
{
  std::string name;
  in >> name;
  if (name.empty()) {
    throw std::logic_error("<DROP> incorrect parameteres");
  }
  bd.drop(name);
}
void alymova::link(std::istream& in, NoteBd& bd)
{
  std::string note_from, note_to;
  in >> note_from >> note_to;
  if (note_to.empty() || note_from.empty()) {
    throw std::logic_error("<LINK> incorrect parameteres");
  }
  bd.addLink(note_from, note_to);
}
void alymova::halt(std::istream& in, NoteBd& bd)
{
  std::string note_from, note_to;
  in >> note_from >> note_to;
  if (note_from.empty() || note_to.empty()) {
    throw std::logic_error("<HALT> incorrect parameteres");
  }
  bd.halt(note_from, note_to);
}
void alymova::mind(std::istream& in, std::ostream& out, const NoteBd& bd)
{
  std::string name;
  in >> name;
  if (name.empty()) {
    throw std::logic_error("<MIND> incorrect parameteres");
  }
  bd.mind(out, name);
}
void alymova::expired(std::istream& in, std::ostream& out, const NoteBd& bd)
{
  std::string note_from;
  in >> note_from;
  if (note_from.empty()) {
    throw std::logic_error("<EXPIRED> incorrect parameteres");
  }
  bd.expired(out, note_from);
}
void alymova::refresh(std::istream& in, NoteBd& bd)
{
  std::string note_from;
  in >> note_from;
  if (note_from.empty()) {
    throw std::logic_error("<REFRESH> incorrect parameteres");
  }
  bd.refresh(note_from);
}
