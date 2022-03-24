#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

class Queue
{
  public:
  	std::stack<int> st1, st2;
	Queue() {}

  	void enqueue(int);
  	void dequeue();
};

void Queue::enqueue(int x)
{
	st1.push(x);
}

void Queue::dequeue()
{
	if (st2.empty())
	{
		while (!st1.empty())
		{
			st2.push(st1.top());
			st1.pop();
		}
	}

	if (!st2.empty())
	{
		st2.pop();
	}
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.dequeue();
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7);
    return 0;
}
