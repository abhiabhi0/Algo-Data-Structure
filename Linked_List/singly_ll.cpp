#include <iostream>

template <class T>
class LinkedList
{
    struct Node
    {
        T data;
        Node * next;
        Node(T val): data(val), next(nullptr){}
    };
    Node *head;

 public:
     LinkedList() : head(nullptr){}
     LinkedList(const LinkedList<T> & ll) = delete;
     LinkedList& operator=(LinkedList const&) = delete;
    ~LinkedList();
     void insert(T);
     void display(std::ostream& out = std::cout) const
     {
          Node *node = head;
          while(node != nullptr)
          {
              out << node->data << " ";
              node = node->next;
          }
      }
      
     void deleteNode(T);
     template <class U>
     friend std::ostream & operator<<(std::ostream & os, const LinkedList<U> & ll);

 private:
    struct Node *search(T n)
    {                            //returns node of the given value
        Node *node = head;
        while(node != nullptr)
        {
            if(node->data == n)
                 return node;
            node = node->next;
        }

        std::cerr << "No such element in the list \n";
        return nullptr;
    }

};

template <class U>
std::ostream & operator<<(std::ostream & os, const LinkedList<U>& ll)
{
    ll.display(os);
    return os;
}

template <class T>
void LinkedList<T>::insert(T data)
{
    Node *t = new Node(data);
    Node *tmp = head;
    if (tmp == nullptr)
    {
        head = t;
    }
    else
    {
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = t;
    }
}

template <class T>
void LinkedList<T>::deleteNode(T data)
{
    Node *node=search(data);
    Node *tmp = head;

    if(tmp == node)
    {
        head=tmp->next;
    }
    else if (node != nullptr)
    {
        while(node != nullptr)
        {
            if(tmp->next==node)
            {
                tmp->next=node->next;
                return ;
            }
            tmp=tmp->next;
        }
        delete tmp;
    }
}

template <class T>
LinkedList<T>::~LinkedList()
{
    Node *tmp = nullptr;
    while (head)
    {
        tmp = head;
        head = head->next;
        delete tmp;
    }
    head =nullptr;
}

int main()
{
    LinkedList<int> ll1;
    ll1.insert(5);
    ll1.insert(6);
    ll1.insert(7);
    ll1.insert(8);
    std::cout<<ll1<<std::endl;
    ll1.deleteNode(11);
    std::cout<<ll1<<std::endl;
    LinkedList<char> ll2;
    ll2.insert('a');
    ll2.insert('r');
    ll2.insert('d');
    ll2.insert('y');
    std::cout<<ll2<<std::endl;
    return 0;
}
