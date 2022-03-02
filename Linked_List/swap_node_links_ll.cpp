#include <iostream>
#include <string>

template<class T>
class LinkedList
{
struct Node{
  T data;
  Node * next;
  Node(T val): data(val), next(nullptr){}
};

Node* head;

public:

  LinkedList() : head(nullptr) {}

  void insert(T val)
  {
    Node* node = new Node(val);
    Node* tmp  = head;

    if(tmp == nullptr)
    {
      head = node;
    }
    else
    {
      while(tmp->next != nullptr)
      {
        tmp = tmp->next;
      }
      tmp->next = node;
    }
  }

  void swapLinks(T val1, T val2)
  {
    Node* prevNode1 = nullptr;
    Node* prevNode2 = nullptr;
    Node* nextNode1 = nullptr;
    Node* nextNode2 = nullptr;
    Node* node      = head;
    Node* node1     = search(val1);
    Node* node2     = search(val2);
    Node* tmp;
    //if val1 is head node
    if(node1 == head)
    {
      nextNode1 = node1->next;

      while(node->next != node2)
      {
        node = node->next;
      }
      if(node->next == node2)
      {
        prevNode2 = node;
        nextNode2 = node2->next;
      }

      tmp             = node1;
      head            = node2;
      node2->next     = nextNode1;
      prevNode2->next = node1;
      node1->next     = nextNode2;
    }
    //if val2 is head node
    else if(node2 == head)
    {
      nextNode2 = node2->next;

      while(node->next != node1)
      {
        node = node->next;
      }
      if(node->next == node1)
      {
        prevNode1 = node;
        nextNode1 = node1->next;
      }

      tmp             = node2;
      head            = node1;
      node1->next     = nextNode2;
      prevNode1->next = node2;
      node2->next     = nextNode1;
    }
    //neirher val1 is head node nor val2
    else
    {
      while(node->next != node1)
      {
        node = node->next;
      }
      if(node->next == node1)
      {
        prevNode1 = node;
        nextNode1 = node1->next;
      }

      node = head;

      while(node->next != node2)
      {
        node = node->next;
      }
      if(node->next == node2)
      {
        prevNode2 = node;
        nextNode2 = node2->next;
      }

      prevNode1->next = node2;
      tmp             = node2->next;
      node2->next     = node1->next;
      prevNode2->next = node1;
      node1->next     = tmp;
    }
  }

  friend std::ostream & operator <<(std::ostream & os, LinkedList<T>& ll)
  {
    ll.display(os);
    return os;
  }

private:

  struct Node *search(T val)
  {
    Node* node = head;
    while(node != nullptr)
    {
      if(node->data == val)
      {
        return node;
      }
      node = node->next;
    }
    std::cerr << "No such element in the List \n";
    return nullptr;
  }

  void display(std::ostream& out = std::cout) const
  {
    Node* node = head;
    while(node != nullptr)
    {
      out << node->data <<" ";
      node = node->next;
    }
  }
};

int main()
{
  LinkedList<int> ll1;
  ll1.insert(10);
  ll1.insert(15);
  ll1.insert(12);
  ll1.insert(13);
  ll1.insert(28);
  ll1.insert(14);
  ll1.insert(16);
  std::cout << "LinkedList1 : "<< ll1 <<"\n";
  ll1.swapLinks(12, 16);
  std::cout << ll1 <<"\n";
  LinkedList<char> ll2;
  ll2.insert('t');
  ll2.insert('r');
  ll2.insert('f');
  ll2.insert('x');
  ll2.insert('a');
  ll2.insert('y');
  ll2.insert('n');
  std::cout << "LinkedList2 : "<< ll2 <<"\n";
  ll2.swapLinks('t', 'a');
  std::cout << ll2 <<"\n";
  LinkedList<std::string> ll3;
  ll3.insert("apple");
  ll3.insert("dog");
  ll3.insert("car");
  ll3.insert("code");
  std::cout << "LinkedList3 : "<< ll3 <<"\n";
  ll3.swapLinks("apple", "car");
  std::cout << ll3 <<"\n";
  return 0;
}
