#include <iostream>

#define max 1000
class Stack{
  int top;

 public:
   int a[max];
     Stack(){
      top=-1;
      }
      bool stack_empty();
      void push(int x);
      int pop();
      void display();
};

bool Stack::stack_empty(){
if(top==-1)
    return true;
else
    return false;
}

void Stack::push(int x){
  int s=max-1;
if(top<s){
top=top+1;
a[top]=x;
}
else
    std::cout<<"overflow"<<"\n";
}

int Stack::pop(){
if (stack_empty()==true)
    std::cout<<"Underflow"<<"\n";
else{
    --top;
    return a[top+1];
}
}

void Stack::display(){
for(int i=0;i<=top;i++){
    std::cout<<a[i]<<" ";
}
}

int main()
{
    Stack stack1;
    stack1.push(15);
    stack1.push(6);
    stack1.push(2);
    stack1.push(9);
    stack1.push(3);
    stack1.display();
    std::cout<<"\n";
    std::cout<<stack1.pop()<<"\n";
    stack1.display();
    return 0;
}
