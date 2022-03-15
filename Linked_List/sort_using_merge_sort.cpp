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
    void merge_sort();
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

    Node* merge_(Node* h1, Node* h2)
    {
        if (h1 == nullptr)
            return h2;

        if (h2 == nullptr)
            return h1;

        Node* new_head;

        if (h1->data <= h2->data)
        {
            new_head = h1;
            h1 = h1->next;
        }
        else
        {
            new_head = h2;
            h2 = h2->next;
        } 
        Node* node = new_head;

        while(h1 != nullptr && h2 != nullptr)
        {
            if (h1->data <= h2->data)
            {
                node->next = h1;
                h1 = h1->next;
                node = node->next;
            }
            else   
            {
                node->next = h2;
                h2 = h2->next;
                node = node->next;
            }
        }

        if (h1 != nullptr)
        {
            node->next = h1;
        }

        if (h2 != nullptr)
        {
            node->next = h2;
        }

        return new_head;
    }

    Node* merge_sort_(Node* head_)
    {
        if (head_ == nullptr || head_->next == nullptr)
            return head_;

        Node* mid = find_first_middle_node_(head_);
        Node* h2 = mid->next;
        mid->next = nullptr;

        Node* h1 = merge_sort_(head_);
        h2 = merge_sort_(h2);

        return merge_(h1, h2);
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

void LinkedList::merge_sort()
{
    head = merge_sort_(head);
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
    ll1.insert(222);
    ll1.insert(12);
    ll1.insert(4);
    ll1.insert(55);
    ll1.insert(6);
    std::cout << "Original List : ";
    ll1.printList();

    ll1.merge_sort();
    ll1.printList();
}
