#ifndef LFS_H
#define LFS_H


#include <atomic>
#include <memory> /// shared_ptr --> 


/// class for  lock_free_stack
template <typename T>
class LFS {
private:
  /// base element <--> next = nullptr
  /// else -- top element isn't single in stack
  typedef struct Node {
    std::shared_ptr<T> data;
    Node * next;
    Node (const T & other_data) 
	    : data(std::make_shared<T>(other_data)) {
    }
  } Node;

  std::atomic<Node *> top = nullptr;
  std::atomic<unsigned> threads_in_pop;
  std::atomic<Node *> to_be_deleted;

  static void delete_nodes(Node * nodes) {
    while (nodes) {
      Node * next = nodes -> next;
      delete nodes;
      nodes = next;
    }
  }

  void chain_pending_node(Node * node) {
    chain_pending_nodes(node, node);
  }

  void chain_pendong_nodes(Node * first, Node * last) {
    last -> next = to_be_deleted;
    while (!to_be_deleted.compare_exchamge_weak(last ->next, first));
  }

  void chain_pending_nodes(Node * nodes) {
    Node * last = nodes;
    while (Node * const next = last -> next) { /// go to the end
      last = next;                             /// of the list
    }
    chain_pending_nodes(nodes, last);
  }

  void try_utilize(Node * old_top) {
    if (threads_in_pop == 1) {
      Node * nodes_to_delete = to_be_deleted.exchange(nullptr);
      if (!--threads_in_pop) { /// is it only thread with pop() ??
        delete_nodes(nodes_to_delete);
      } else if (nodes_to_delete) {
        chain_pending_nodes(nodes_to_delete);
      }
      delete old_top;
    } else {
      chain_pending_node(old_top);
      --threads_in_pop;
    }
  }


public:
  /// default constructor
  LFS() {};

  /// add new element to the top of stack
  void push (const T & data) {
    /// compare_exchange_weak : atomic operation has a
    /// nice feature : first argument is updated
    /// if "return code" is false, so new_node is
    /// always in right condition (updated value)
    /// (new_node -> next == head) --> stop, go further
    Node * const new_node = new Node(data);
    new_node->next = top.load(); 
    while (!top.compare_exchange_weak(new_node->next, new_node));
  }                                                                   

  /// extract top element
  std::shared_ptr<T> pop () {
    ++threads_in_pop;
    Node * old_top = top.load();
    while (old_top && !top.compare_exchange_weak(old_top, old_top->next));
    std::shared_ptr<T> res;
    if (old_top) {
      res.swap(old_top); /// when counter in shared_ptr = 0 --> free resource automatically
    }
    try_utilize(old_top);
    return old_top ? old_top->data : std::shared_ptr<T>();
  }

  /// check if the stack is empty
  bool empty() const {
    return (top == nullptr);
  }
  ~LFS() {};
};

#endif
