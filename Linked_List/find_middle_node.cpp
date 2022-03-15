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
    int find_first_middle_node();
    int find_second_middle_node();
    void printList() const;
    Node* find_first_middle_node_(Node* head_)
    {
        Node* slow_ptr = head_;
        Node* fast_ptr = head_;

        while (fast_ptr->next != nullptr 
            && fast_ptr->next->next != nullptr)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        return slow_ptr;
    }

    Node* find_second_middle_node_(Node* head_)
    {
        Node* slow_ptr = head_;
        Node* fast_ptr = head_;

        while (fast_ptr != nullptr 
            && fast_ptr->next != nullptr)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        return slow_ptr;
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

int LinkedList::find_first_middle_node()
{
    Node* node = find_first_middle_node_(head);
    return node->data;
}

int LinkedList::find_second_middle_node()
{
    Node* node = find_second_middle_node_(head);
    return node->data;
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
    std::cout << "Original List : ";
    ll1.printList();

    std::cout << ll1.find_first_middle_node() << " ";
    std::cout << ll1.find_second_middle_node() << " ";
    //ll1.printList();
}
