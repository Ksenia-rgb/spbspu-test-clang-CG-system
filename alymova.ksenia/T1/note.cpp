#include "note.hpp"
#include <iostream>
#include <algorithm>

alymova::Note::Note(const std::string& name):
  name_(name),
  lines_(),
  refs_()
{}
void alymova::Note::addLine(const std::string& line)
{
  lines_.push_back(line);
}
void alymova::Note::show(std::ostream& out) const
{
  if (lines_.size() == 0) {
    return;
  }
  out << lines_[0];
  for (size_t i = 1; i < lines_.size(); i++) {
    out << '\n' << lines_[i];
  }
}
void alymova::Note::addLink(const std::shared_ptr< Note > note_to)
{
  if (findNote(note_to->name_) != refs_.end()) {
    throw std::logic_error("<LINK> exited link");
  }
  refs_.push_back(std::weak_ptr< Note >(note_to));
}
void alymova::Note::mind(std::ostream& out) const
{
  if (refs_.size() == 0) {
    return;
  }
  auto iter = refs_.begin();
  while (iter != refs_.end() && iter->expired()) {
    ++iter;
  }
  if (iter != refs_.end()) {
    std::shared_ptr< Note > shared(*iter);
    out << shared->name_;
  } else {
    return;
  }
  for (++iter; iter != refs_.end(); ++iter) {
    if (!iter->expired()) {
      std::shared_ptr< Note > shared(*iter);
      out << '\n' << shared->name_;
    }
  }
}
void alymova::Note::halt(const std::shared_ptr< Note > note_to)
{
  std::vector< std::weak_ptr< Note > >::const_iterator iter = findNote(note_to->name_);
  if (iter == refs_.end()) {
    throw std::logic_error("<HALT> not existed note");
  }
  refs_.erase(iter);
}
void alymova::Note::expired(std::ostream& out) const
{
  size_t cnt = 0;
  for (auto iter = refs_.begin(); iter != refs_.end(); ++iter) {
    if (iter->expired()) {
      cnt++;
    }
  }
  out << cnt;
}
void alymova::Note::refresh()
{
  auto iter = refs_.begin();
  while (iter != refs_.end()) {
    if (iter->expired()) {
      iter = refs_.erase(iter);
    } else {
      ++iter;
    }
  }
}
std::vector< std::weak_ptr< alymova::Note > >::const_iterator alymova::Note::findNote(const std::string& name) const
{
  for (auto iter = refs_.begin(); iter != refs_.end(); ++iter) {
    if (!iter->expired()) {
      std::shared_ptr< Note > shared(*iter);
      if (shared->name_ == name) {
        return iter;
      }
    }
  }
  return refs_.end();
}
