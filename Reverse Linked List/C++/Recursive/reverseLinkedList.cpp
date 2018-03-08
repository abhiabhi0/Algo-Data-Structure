#include <iostream>
#include <utility>

template <class T>
class LinkedList
{
  struct Node
  {
    T data;
    Node * next;
    Node(T value) : data(std::move(value)), next(nullptr) {}
  };
  Node *head;

public:
  LinkedList() : head(nullptr) {}
  LinkedList(const LinkedList& ll) = delete; //copy constructor
  LinkedList(const LinkedList&& ll) = delete; //move constructor
  LinkedList& operator=(const LinkedList& ll) = delete; //copy assignment
  LinkedList& operator=(const LinkedList&& ll) = delete; //move assignment
  ~LinkedList();
  void insert(T);
  void printList();
  void recursiveReverse()
  {
    head = recursiveReverse(head);
  }
private:
  Node* recursiveReverse(Node* head)
  {
    if(head == nullptr)
      return nullptr;

    if(head->next == nullptr)
      return head;

    Node *firstElement = head;
    Node *secondElement = firstElement->next;
    head = firstElement->next;
    firstElement->next = nullptr; //unlink first node
    Node *remainingList = recursiveReverse(head);
    secondElement->next = firstElement;
    return remainingList;
  }
};

template <class T>
void LinkedList<T>::insert(T data)
{
  Node *node = new Node(std::move(data));
  Node *tmp = head;
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

template <class T>
void LinkedList<T>::printList()
{
  Node *node = head;
  while(node)
  {
    std::cout << node->data << " ";
    node = node->next;
  }
  std::cout<<"\n";
}
template <class T>
LinkedList<T>::~LinkedList()
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

int main()
{
  LinkedList<int> ll1;
  ll1.insert(2);
  ll1.insert(3);
  ll1.insert(4);
  ll1.insert(5);
  ll1.insert(6);
  ll1.printList();
  ll1.recursiveReverse();
  ll1.printList();
}
