#include "Edge.h"
#include "Node.h"
#include "Graph.h"

#include <ostream>

namespace DotWriter {

Edge::Edge(Node *src, Node *dst, std::string label) : _src(src),
  _dst(dst), _label(label) {
}

Edge::Edge(Node *src, std::string src_port, std::string dst_port, std::string label) : _src(src),
  _dst(src), _src_port(src_port), _dst_port(dst_port), _label(label) {
}

Edge::Edge(Node *src, Node *dst, std::string src_port, std::string dst_port, std::string label) : _src(src),
  _dst(dst), _src_port(src_port), _dst_port(dst_port), _label(label) {
}

void Edge::Print(bool isDirected, std::ostream& out) {
  out << _src->GetId() << (_src_port.size() ? ":" + _src_port : "");
  out << (isDirected ? "->" : "--") << _dst->GetId() << (_dst_port.size() ? ":" + _dst_port : "");

  if (!_attributes.Empty()) {
    out << " [";
    _attributes.Print(out);
    out << "]";
  }

  out << ";\n";
}

}  // namespace DotWriter
