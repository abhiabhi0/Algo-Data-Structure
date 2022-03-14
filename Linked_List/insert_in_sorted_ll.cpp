//Given a LL, sorted in ascending order. Insert a value 
//maintaing the sorted order

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
    void insert_in_sorted(int);
    void printList() const;
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

void LinkedList::insert_in_sorted(int k)
{
	Node* new_node = new Node(k);

	if (head == nullptr)
	{
		head = new_node;
		return;
	}

	if (k <= head->data)
	{
		new_node->next = head;
		head = new_node;
		return;
	}

	Node* tmp = head;

	while(tmp->next != nullptr && tmp->next->data < k)
	{
		tmp = tmp->next;
	}

	new_node->next = tmp->next;
	tmp->next = new_node;
	return;
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
    // ll1.insert(1);
    // ll1.insert(2);
    // ll1.insert(3);
    // ll1.insert(4);
    // ll1.insert(5);
    // ll1.insert(6);
    // ll1.insert(7);
    std::cout << "Original List : ";
    ll1.printList();

    ll1.insert_in_sorted(1);
    std::cout << "New List : ";
    ll1.printList();
}
