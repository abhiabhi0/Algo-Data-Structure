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
    void iterativeReverse()
    {
        head = iterativeReverse(head);
    }
  private:
    Node* iterativeReverse(Node* head)
    {
        Node *previous = nullptr;
        Node *nextNode = nullptr;
        while(head)
        {
            nextNode = head->next;
            head->next = previous;
            previous = head;
            head = nextNode;
        }
        return previous;
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
    LinkedList<char> ll1;
    ll1.insert('p');
    ll1.insert('r');
    ll1.insert('o');
    ll1.insert('g');
    ll1.insert('r');
    ll1.insert('a');
    ll1.insert('m');
    ll1.printList();
    ll1.iterativeReverse();
    ll1.printList();
}
