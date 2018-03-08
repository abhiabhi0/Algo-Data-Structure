#include <iostream>
#include <utility>

template <class T>
class circular_linked_list
{
  struct Node
  {
    T data;
    Node * next;
    Node(T&& value) : data(std::move(value)), next(nullptr) {}
  };
  Node *head;

public:
  circular_linked_list() : head(nullptr) {}
   //copy constructor
  circular_linked_list(const circular_linked_list& cll) = delete;
  //move constructor
  circular_linked_list(circular_linked_list&& cll) = delete;
  //copy assignment
  circular_linked_list& operator=(const circular_linked_list& cll) = delete;
  //move assignment
  circular_linked_list& operator=(circular_linked_list&& cll) = delete;
  ~circular_linked_list();

  void insert_node(T&&);
  void split_list(circular_linked_list<T>&);
  void print_list();

private:

  Node *find_tail_node()
  {
    Node *tmp = head;
    while(tmp->next != head)
    {
      tmp = tmp->next;
    }
    return tmp;
  }

  Node *find_middle_node()
  {
    //slow pointer advances by 1
    Node *slow_ptr = head;
    //fast pointer advances by 2
    Node *fast_ptr = head;

    //If odd number of nodes then fast_ptr->next = head
    //If even number of nodes then fast_ptr->next->next = head
    while(fast_ptr->next != head && fast_ptr->next->next != head)
    {
      fast_ptr = fast_ptr->next->next;
      slow_ptr = slow_ptr->next;
    }
    return slow_ptr;
  }
  };

template <class T>
void circular_linked_list<T>::insert_node(T&& value)
{
  Node *node = new Node(std::move(value));
  if(head == nullptr)
  {
    node->next = node;
    head = node;
    return;
  }
  Node *tmp = head;
  while(tmp->next != head)
  {
    tmp = tmp->next;
  }
  tmp->next = node;
  node->next = head;
}

template <class T>
void circular_linked_list<T>::split_list(circular_linked_list<T>& second_half)
{
  Node *tail = find_tail_node();
  Node *mid = find_middle_node();

  second_half.head = mid->next;
  tail->next = second_half.head;

  mid->next = head;
}

template <class T>
void circular_linked_list<T>::print_list()
{
  Node *tmp = head;
  while(tmp->next != head)
  {
    std::cout << tmp->data << ' ';
    tmp = tmp->next;
  }
  std::cout << tmp->data << '\n';
}

template <class T>
circular_linked_list<T>::~circular_linked_list()
{
  Node *tmp = nullptr;
  Node *tail = head;
  while(tail->next != head)
  {
    tail = tail->next;
  }
  tail->next = nullptr;

  while(head != nullptr)
  {
    tmp = head;
    head = head->next;
    delete tmp;
  }
}

int main()
{
  circular_linked_list<int> original_list;
  original_list.insert_node(2);
  original_list.insert_node(3);
  original_list.insert_node(4);
  original_list.insert_node(1);
  original_list.insert_node(0);

  std::cout << "The original list is : ";
  original_list.print_list();

  circular_linked_list<int> second_half;
  original_list.split_list(second_half);

  //Original list becomes first half
  std::cout << "The first half : ";
  original_list.print_list();
  std::cout << "The second half : ";
  second_half.print_list();
}
