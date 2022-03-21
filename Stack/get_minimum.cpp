#include <iostream>
#include <climits>

#define max 1000
class Stack
{
    int top;
    int top_min;
    int mn_val = INT_MAX;

 public:
    int a[max];
    int min_stack[max];

    Stack()
    {
        top = -1;
        top_min = -1;
    }

    bool stack_empty();
    void push(int x);
    int pop();
    int get_min();
    void display();
};

bool Stack::stack_empty()
{
    if(top == -1)
        return true;
    else
        return false;
}

void Stack::push(int x)
{
    int s = max-1;
    if(top < s)
    {
        top = top+1;
        a[top] = x;

        if (x <= mn_val)
        {
            mn_val = x;
            top_min++;
            min_stack[top_min] = mn_val;
        }
    }
    else
        std::cout << "overflow" << "\n";
}

int Stack::pop()
{
    if (stack_empty())
    {
        std::cout << "Underflow" << "\n";
    }
    else
    {
        --top;

        if (min_stack[top_min] == a[top + 1])
        {
            top_min--;
            mn_val = min_stack[top_min];
        }
        return a[top + 1];
    }
}

int Stack::get_min()
{
    return mn_val;
}

void Stack::display()
{
    for(int i = top; i >= 0; i--)
    {
        std::cout << a[i] << " ";
    }
}

int main()
{
    #ifndef FILE_INOUT
 
        freopen("in.txt", "r", stdin);
    
        freopen("out.txt", "w", stdout);
   
    #endif

    Stack stack1;
    stack1.push(3);
    stack1.push(5);
    std::cout << "curr min : " << stack1.get_min() << "\n";
    stack1.push(2);
    std::cout << "curr min : " << stack1.get_min() << "\n";
    stack1.push(7);
    stack1.push(1);
    std::cout << "curr min : " << stack1.get_min() << "\n";
    stack1.push(4);
    stack1.pop();
    stack1.pop();
    std::cout << "curr min : " << stack1.get_min() << "\n";
    return 0;
}
