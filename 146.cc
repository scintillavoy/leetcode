#include <unordered_map>
using namespace std;

class LRUCache {
 public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    if (!key_to_node.contains(key)) {
      return -1;
    }
    Node* node = key_to_node[key];
    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
    return node->value;
  }

  void put(int key, int value) {
    Node* node;
    if (key_to_node.contains(key)) {
      node = key_to_node[key];
      node->prev->next = node->next;
      node->next->prev = node->prev;
      node->value = value;
    } else {
      if (key_to_node.size() == capacity) {
        Node* least_recent_node = tail->prev;
        key_to_node.erase(least_recent_node->key);
        tail->prev = tail->prev->prev;
        tail->prev->next = tail;
        delete least_recent_node;
      }
      node = new Node();
      node->key = key;
      node->value = value;
      key_to_node[key] = node;
    }
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
  }

 private:
  struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
  };

  int capacity;
  unordered_map<int, Node*> key_to_node;
  Node* head = new Node();
  Node* tail = new Node();
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
