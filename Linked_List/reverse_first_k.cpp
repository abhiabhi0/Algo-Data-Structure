//Reverse first k nodes of a LL

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

    void insert(int);
    void reverse_first_k(int);
    void printList() const;
    Node* reverse_first_k_(Node* head, int k)
    {
        if (head == nullptr || k <= 1)
        {
            return head;
        }

        Node* next_node = head;
        Node* h2 = nullptr;

        while (k > 0 && next_node != nullptr)
        {
            Node* tmp = next_node;
            next_node = next_node->next;
            tmp->next = h2;
            h2 = tmp;
            k--;
        }
        head->next = next_node;
        return h2;
    }
};

void LinkedList::insert(int value)
{
    Node *node = new Node(value);
    Node *tmp = head;
    if (tmp == nullptr)
    {
        head = node;
    }
    else
    {
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = node;
    }
}

void LinkedList::reverse_first_k(int k)
{
    head = reverse_first_k_(head, k);   
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

    LinkedList ll1;
    ll1.insert(1);
    ll1.insert(2);
    ll1.insert(3);
    ll1.insert(4);
    ll1.insert(5);
    ll1.insert(6);
    ll1.insert(7);
    std::cout << "Original List : ";
    ll1.printList();

    ll1.reverse_first_k(9);
    std::cout << "New List : ";
    ll1.printList();
}
