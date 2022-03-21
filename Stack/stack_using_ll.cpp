#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class LinkedList
{
    struct Node
    {
        int data;
        Node * next = nullptr;
        Node(int value)   : data(value), next(nullptr) {}
    };
    Node *head;

  public:
    LinkedList() : head(nullptr) {}
    ~LinkedList()
    {
        Node *tmp = nullptr;
        while (head)
        {
            tmp = head;
            head = head->next;
            delete tmp;
        }
        head = nullptr;
    }

    void push(int);
    int pop();
    int top();
    void printList() const;
};

void LinkedList::push(int value)
{
    Node *node = new Node(value);
    Node *tmp = head;
    if (head == nullptr)
    {
        head = node;
    }
    else
    {
        node->next = head;
        head = node;
    }
}

int LinkedList::pop()
{
    Node* node = head;
    head = head->next;
    node->next = nullptr;

    return node->data;
}

int LinkedList::top()
{
    return head->data;
}

void LinkedList::printList() const
{
    if (head == nullptr)
    {
        std::cout << "Empty List \n";
        return;
    }

    Node *node = head;

    while (node != nullptr)
    {
        std::cout << node->data << " ";
        node = node->next;
    }

    std::cout << "\n";
}

int main()
{
    #ifndef FILE_INOUT
 
        freopen("in.txt", "r", stdin);
    
        freopen("out.txt", "w", stdout);
   
    #endif

    LinkedList stack;
    stack.push(3);
    stack.push(1);
    std::cout << "Top : " << stack.top() << "\n";
    stack.push(7);
    std::cout << "Pop : " << stack.pop() << "\n";
    std::cout << "Top : " << stack.top() << "\n";
    stack.push(9);
    std::cout << "Stack : ";
    stack.printList();
}
