#include <iostream>
#include <utility>

template <typename T>
class circular_doubly_linked_list
{
    struct Node
    {
        T data;
        Node * next;
        Node * prev;
        Node(T value) : data(std::move(value)),
                        next(nullptr),
                        prev(nullptr)
                        {}
    };
    Node *head, *tail;

  public:
    circular_doubly_linked_list() : head(nullptr),
                                    tail(nullptr)
                                    {}
    //copy constructor
    circular_doubly_linked_list(const circular_doubly_linked_list &);
    //copy assignment
    circular_doubly_linked_list& operator=(const circular_doubly_linked_list& cdll)
    {
        circular_doubly_linked_list  temp(cdll);
        temp.swap(*this);
        return *this;
    }
    //move constructor
    circular_doubly_linked_list(circular_doubly_linked_list&&) noexcept;
    //move assignment
    circular_doubly_linked_list& operator=(circular_doubly_linked_list&& cdll) noexcept
    {
        cdll.swap(*this);
        return *this;
    }
    ~circular_doubly_linked_list();

    void append_node(T);
    void delete_node(T);

    friend void swap(circular_doubly_linked_list& lhs, circular_doubly_linked_list& rhs)
    {
        std::swap(lhs.head, rhs.head);
    }

    template <typename U>
    friend std::ostream & operator<<(std::ostream & os, const circular_doubly_linked_list<U> & cdll)
    {
        cdll.print_list(os);
        return os;
    }

  private:

    struct Node *search(T value)
    {
        Node *node = head;
        while(node->next != head)
        {
            if(node->data == value)
            {
                return node;
            }
            node = node->next;
        }
        if(node->data == value)
        {
            return node;
        }
        std::cerr << "No such element in the list \n";
        return nullptr;
    }

  void print_list(std::ostream& os = std::cout) const
  {
      Node *tmp = head;
      while(tmp->next != head)
      {
          std::cout << tmp->data << ' ';
          tmp = tmp->next;
      }
      std::cout << tmp->data << '\n';
  }
};

template <typename T>
circular_doubly_linked_list<T>::circular_doubly_linked_list(const circular_doubly_linked_list & cdll)
{
    if(cdll.head == nullptr)
    {
        head = tail = nullptr;
    }
    else
    {
        head = new Node(cdll.head->data);
        Node *curr = head;
        Node *tmp = head;
        Node *obj_curr = cdll.head;

        while(obj_curr->next != cdll.head)
        {
            curr->next = new Node(obj_curr->next->data);
            obj_curr = obj_curr->next;
            curr = curr->next;
            curr->prev = tmp;
            tmp = tmp->next;
        }
        tail = curr;
        curr->next = head;
        head->prev = curr;
    }
}

template <typename T>
circular_doubly_linked_list<T>::circular_doubly_linked_list(circular_doubly_linked_list&& cdll) noexcept
{
    head = tail = nullptr;
    swap(*this, cdll);
}

template <typename T>
void circular_doubly_linked_list<T>::append_node(T value)
{
    Node *node = new Node(std::move(value));

    if(head == nullptr)
    {
        node->next = node;
        node->prev = node;
        head = node;
        tail = node;
    }

    tail = head->prev;
    tail->next = node;
    node->prev = tail;
    node->next = head;
    head->prev = node;
    tail = node;
}

template <typename T>
void circular_doubly_linked_list<T>::delete_node(T value)
{
    Node *node = search(value);
    if(node == nullptr)
    {
        std::cerr << "No such value in the list\n";
        return;
    }
    else
    {
        Node *tmp = head;
        Node *tail = head->prev;
        if(tmp == node)
        {
            tail->next = tmp->next;
            tmp->prev->next->prev = tail;
            head = tail->prev;
            delete tmp;
            return;
        }
        else if(tail == node)
        {
            Node *curr = tail;
            tmp = tail->prev;
            tmp->next = curr->next;
            head->prev = tmp;
            tail = tmp;
            delete curr;
            return;
        }
        else
        {
            while(tmp->next != head)
            {
                if(tmp == node)
                {
                    tmp->prev->next = tmp->next;
                    tmp->prev->next->prev = tmp->prev;
                    delete tmp;
                    return;
                }
                tmp = tmp->next;
            }
        }
    }
}

template <typename T>
circular_doubly_linked_list<T>::~circular_doubly_linked_list()
{
    if(head)
    {
        Node *tmp = head;
        while(tmp->next != head)
        {
            Node *t = tmp;
            tmp = tmp->next;
            delete t;
        }
        delete tmp;
        head = nullptr;
    }
}

int main()
{
    circular_doubly_linked_list<int> cdll1;
    cdll1.append_node(3);
    cdll1.append_node(4);
    cdll1.append_node(5);
    cdll1.append_node(6);
    cdll1.append_node(7);
    cdll1.append_node(8);
    std::cout << cdll1;
    cdll1.delete_node(6);
    std::cout << cdll1;
    circular_doubly_linked_list<int> cdll2(cdll1); // using copy constructor
    std::cout << "Linked List 2: " << cdll2;
    circular_doubly_linked_list<int> cdll3 = cdll1; //using copy assignment
    std::cout << "Linked List 3: " << cdll3;
    circular_doubly_linked_list<int> cdll4 = std::move(cdll2); //using move constructor
    std::cout << "Linked list 4: " << cdll4;
}
