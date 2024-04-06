#ifndef DOTWRITER_NODE_H_
#define DOTWRITER_NODE_H_

#include <ostream>
#include <string>

#include "AttributeSet.h"
#include "Idable.h"

namespace DotWriter {

/**
 * Represents a node in a graph.
 */
class Node : public Idable {
private:
  std::string _label;
  bool _is_html_like;
  NodeAttributeSet _attributes;

public:
  Node(const std::string &id, std::string label = "", bool is_html_like = false)
      : Idable(id), _label(label), _is_html_like(is_html_like) {}
  virtual ~Node(){};

  void Print(std::ostream &out);

  /** Simple getters / setters **/
  const std::string &GetLabel() { return _label; }

  void SetLabel(std::string label) { _label = label; };

  NodeAttributeSet &GetAttributes() { return _attributes; }
};

} // namespace DotWriter

#endif
