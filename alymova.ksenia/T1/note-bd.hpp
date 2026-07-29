#ifndef NOTE_BD_HPP
#define NOTE_BD_HPP
#include "note.hpp"

namespace alymova
{
  class NoteBd
  {
  public:
    NoteBd();
    void createNote(const std::string& name);
    void addLine(const std::string& name, const std::string& line);
    void show(std::ostream& out, const std::string& name) const;
    void drop(const std::string& name);
    void addLink(const std::string& note_from, const std::string& note_to);
    void mind(std::ostream& out, const std::string& name) const;
    void halt(const std::string& note_from, const std::string& note_to);
    void expired(std::ostream& out, const std::string& name) const;
    void refresh(const std::string& name);
  private:
    std::map< std::string, std::shared_ptr< Note > > bd_;
  };
}
#endif
