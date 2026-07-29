#ifndef NOTE_HPP
#define NOTE_HPP
#include <map>
#include <vector>
#include <string>
#include <memory>

namespace alymova
{
  class Note
  {
  public:
    Note(const std::string& name);
    void addLine(const std::string& line);
    void show(std::ostream& out) const;
    void addLink(const std::shared_ptr< Note > note_to);
    void mind(std::ostream& out) const;
    void halt(const std::shared_ptr< Note > note_to);
    void expired(std::ostream& out) const;
    void refresh();
  private:
    std::string name_;
    std::vector< std::string > lines_;
    std::vector< std::weak_ptr< Note > > refs_;

    std::vector< std::weak_ptr< Note > >::const_iterator findNote(const std::string& name) const;
  };
}
#endif
