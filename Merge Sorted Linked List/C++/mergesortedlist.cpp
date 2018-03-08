//www.programmercave.blogspot.com
#include <iostream>
#include <utility>
#include <cassert>

template<class T>
class LinkedList
{
  struct Node
  {
    T data;
    Node * next = nullptr;
    Node()          : data(), next(nullptr) {}
    Node(T value)   : data(std::move(value)), next(nullptr) {}
  };

  Node *head;

public:
  LinkedList() : head(nullptr) {}
  LinkedList(const LinkedList& ll) = delete; //copy constructor
  LinkedList& operator=(const LinkedList& ll) = delete; //copy assignment
  ~LinkedList()
  {
    Node *tmp = nullptr;
    while(head)
    {
      tmp = head;
      head = head->next;
      delete tmp;
    }
    head = nullptr;
  }

  void insert(T);
  void mergeSortedList(LinkedList<T>&);
  void printList() const;

private:
  static void advance(Node*& node)
  {
    assert(node != nullptr);
    node = node->next;
  }

  Node* getLastNode(Node*& node)
  {
    while(node->next != nullptr)
      node = node->next;

    return node;
  }
};

template <class T>
void LinkedList<T>::insert(T value)
{
 Node *node = new Node(std::move(value));
 Node *tmp = head;
 if(tmp == nullptr)
 {
   head = node;
 }
 else
 {
   tmp = getLastNode(tmp);
   tmp->next = node;
 }
}

template <class T>
void LinkedList<T>::mergeSortedList(LinkedList<T>& ll2)
{
  if(ll2.head == nullptr)
    return;

  if(head == nullptr)
  {
    head = ll2.head;
    ll2.head = nullptr;
    return;
  }

  Node *head1 = head;
  Node *head2 = ll2.head;

  Node *node;

  if(head1->data <= head2->data)
  {
    node = head1;
    advance(head1);
  }
  else if(head2->data <= head1->data)
  {
    node = head2;
    advance(head2);
  }

  Node *tmp = nullptr;
  tmp = node;

  while(head1 != nullptr && head2 != nullptr)
  {
    if(head1->data <= head2->data)
    {
      tmp->next = head1;
      advance(head1);
    }
    else
    {
      tmp->next = head2;
      advance(head2);
    }

    advance(tmp);
  }

  //if there are extra nodes in either list
  if(head1 != nullptr)
    tmp->next = head1;

  if(head2 != nullptr)
     tmp->next = head2;

  head = node;
  ll2.head = nullptr;
}

template <class T>
void LinkedList<T>::printList() const
{
  if(head == nullptr)
  {
    std::cout << "Empty List \n";
    return;
  }

  Node *node = head;

  while(node != nullptr)
  {
    std::cout << node->data << " ";
    advance(node);
  }

  std::cout << "\n";
}

int main()
{
  LinkedList<int> ll1;
  ll1.insert(5);
  ll1.insert(10);
  ll1.insert(18);
  ll1.insert(25);
  std::cout << "List 1 : ";
  ll1.printList();

  LinkedList<int> ll2;
  ll2.insert(6);
  ll2.insert(8);
  ll2.insert(11);
  ll2.insert(20);
  ll2.insert(23);
  ll2.insert(28);
  ll2.insert(40);
  std::cout << "List 2 : ";
  ll2.printList();

  ll1.mergeSortedList(ll2);
  std::cout << "Merged List : ";
  ll1.printList();
}
