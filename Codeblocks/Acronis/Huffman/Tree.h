
using Node = struct Node;
using Element = class Element;


/// the node of tree
struct Node {
    unsigned left;       ///  for Huffman algorithm we need
    unsigned right;      ///  to know indexes of children and
    unsigned parent;     ///  parent, also we need to know
    bool branch;    ///
    char c;

    Node() {}
    Node(unsigned left, unsigned right, unsigned parent, bool branch, char c) :
                        left(left), right(right), parent(parent), branch(branch), c(c) {}

    /// the "rule of three"
    Node(const Node& x);
    void operator = (const Node& y);
    ~Node() {}
};


/// fot creating tree, element of ground
class Element {
public:
    unsigned sum;
    unsigned index;

    Element() {}
    Element(unsigned sum, unsigned index) : sum(sum), index(index) {}

    /// the "rule of three"
    void operator = (const Element& y);
    Element(const Element& x); /// copy constructor
    ~Element() {}
};

bool operator < (const Element& lhs, const Element& rhs);
