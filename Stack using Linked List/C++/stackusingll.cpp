#include <iostream>

template<class T>
class Stack
{
    struct Node
    {
        T data;
        Node *next;
        Node(T val):data(val),next(nullptr) {}
    };
    Node *head; int top;

 public:
   Stack()
   {
        top=-1;
        head=nullptr;
    }
   ~Stack();
    bool stack_empty();
    void push(T);
    T pop();

   void display(std::ostream& out = std::cout) const
   {
        Node *node=head;
        while(node!=nullptr)
        {
            out<<node->data<<" ";
            node=node->next;
        }
    }
};

template<class T>
bool Stack<T>::stack_empty()
{
    if(top==-1)
        return true;
    else
        return false;
}

template<class T>
void Stack<T>::push(T val)
{
    top++;
    Node *node=new Node(val);
    node->next = head;
    head=node;
}

template<class T>
T Stack<T>::pop()
{
    if(stack_empty()==true)
    std::cout<<"Underflow"<<std::endl;
    else
    {
        top--;
        Node *node=head;
        head = node->next;
        T tmp = std::move(node->data);
        delete node;
        return tmp;
    }
}

template<class U>
std::ostream & operator <<(std::ostream& os, const Stack<U>& s)
{
    s.display(os);
    return os;
}

template<class T>
Stack<T>::~Stack()
{
    Node *tmp=nullptr;
    while(head)
    {
        tmp=head;
        head=head->next;
        delete tmp;
    }
    head=nullptr;
}

int main()
{
    Stack<int> stack1;
    stack1.push(3);
    stack1.push(4);
    stack1.push(11);
    stack1.push(30);
    std::cout<<stack1<<std::endl;
    std::cout<<stack1.pop()<<std::endl;
    return 0;
}
