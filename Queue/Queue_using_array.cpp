#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define max 5

class Queue
{
	int f, r, sz;
  public:
  	int arr[max];
  	Queue()
  	{
  		f = -1;
  		r = -1;
  		sz = 0;
  	}

  	void enqueue(int);
  	void dequeue();
  	int front();
  	int back();
  	bool is_empty();
};

void Queue::enqueue(int x)
{
	if (sz == max)
	{
		std::cout << "Queue is Full\n";
		return;
	}
	r = (r + 1) % max;
	arr[r] = x;
	sz++;
}

void Queue::dequeue()
{
	if (sz == 0)
	{
		std::cout << "Queue is Empty\n";
		return;
	}
	f = (f + 1) % max;
	sz--;
}

int Queue::front()
{
	if (sz == 0)
	{
		std::cout << "Queue is Empty\n";
		return -1;
	}
	
	return arr[(f + 1) % max];
}

int Queue::back()
{
	if (sz == 0)
	{
		std::cout << "Queue is Empty\n";
		return -1;
	}
	
	return arr[r];
}

bool Queue::is_empty()
{
	if (sz == 0)
	{
		return true;
	}
	return false;
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
    std::cout << "front " << queue.front() << "\n";
    queue.dequeue();
    std::cout << "front " << queue.front() << "\n";
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7);
    return 0;
}
