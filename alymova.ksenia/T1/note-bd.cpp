#include "note-bd.hpp"
#include <exception>
#include <iostream>
#include <cassert>
#include <string>
#include <memory>
#include <stdexcept>

alymova::NoteBd::NoteBd():
  bd_()
{}
void alymova::NoteBd::createNote(const std::string& name)
{
  try {
    bd_.at(name);
  } catch (const std::exception& e) {
    bd_.emplace(name, std::make_shared< Note >(name));
    return;
  }
  throw std::logic_error("<NOTE> existed note");
}
void alymova::NoteBd::addLine(const std::string& name, const std::string& line)
{
  bd_.at(name)->addLine(line);
}
void alymova::NoteBd::show(std::ostream& out, const std::string& name) const
{
  bd_.at(name)->show(out);
}
void alymova::NoteBd::drop(const std::string& name)
{
  assert(bd_.at(name).use_count() == 1 && "drop owner problems");
  bd_.at(name).reset();
  bd_.erase(name);
}
void alymova::NoteBd::addLink(const std::string& note_from, const std::string& note_to)
{
  bd_.at(note_from)->addLink(bd_.at(note_to));
}
void alymova::NoteBd::mind(std::ostream& out, const std::string& name) const
{
  bd_.at(name)->mind(out);
}
void alymova::NoteBd::halt(const std::string& note_from, const std::string& note_to)
{
  bd_.at(note_from)->halt(bd_.at(note_to));
}
void alymova::NoteBd::expired(std::ostream& out, const std::string& name) const
{
  bd_.at(name)->expired(out);
}
void alymova::NoteBd::refresh(const std::string& name)
{
  bd_.at(name)->refresh();
}

