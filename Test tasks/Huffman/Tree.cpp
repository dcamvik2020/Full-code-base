#include "Tree.h"

/// the "rule of three"
Node::Node(const Node& x) {
    left = x.left;
    right = x.right;
    parent = x.parent;
    branch = x.branch;
    c = x.c;
}

void Node::operator = (const Node& y) {
    left = y.left;
    right = y.right;
    parent = y.parent;
    branch = y.branch;
    c = y.c;
}

void Element::operator = (const Element& y) {
    sum = y.sum;
    index = y.index;
}

Element::Element(const Element& x) { /// copy constructor
    sum = x.sum;
    index = x.index;
}

bool operator < (const Element& lhs, const Element& rhs) {
    return lhs.sum < rhs.sum;
}
