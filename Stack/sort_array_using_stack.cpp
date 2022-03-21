#include <iostream>
#include <vector>

#define max 1000
class Stack
{
    int top;

 public:
    int a[max];
    Stack()
    {
        top=-1;
    }
    bool stack_empty();
    void push(int x);
    int pop();
    int get_top();
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
        return a[top + 1];
    }
}

int Stack::get_top()
{
    if (top == -1)
    {
        std::cout << "Underflow\n";
    }
    return a[top];
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
        
    std::vector<int> vec = {9, 5, 7, 3, 8, 2, 6, 1};
    
    Stack stack;
    Stack tmp;

    for (int x : vec)
    {
        if (stack.stack_empty())
        {
            stack.push(x);
        }
        else  
        {
            if (stack.get_top() < x)
            {
                while (stack.get_top() < x)
                {
                    tmp.push(stack.pop());
                }

                stack.push(x);
                while (!tmp.stack_empty())
                {
                    stack.push(tmp.pop());
                }
            }
            else  
            {
                stack.push(x);
            }
        }
    }

    stack.display();  
    return 0;
}
