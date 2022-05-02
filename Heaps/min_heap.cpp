#include <iostream>
#include <vector>
#include <algorithm>

class Min_heap
{
	int *arr;
	int heap_sz = -1;
	int capacity;

   public:
   	Min_heap(int sz)
   	{
   		capacity = sz;
   		arr = new int[sz];
   	}
   	void insert(int val);
   	void delete_min();
   	void print()
   	{
   		for (int i = 0; i <= heap_sz; ++i)
   		{
   			std::cout << arr[i] << " ";
   		}
   		std::cout << "\n";
   	}
};

//TC : O(logN)
void Min_heap::insert(int val)
{
	heap_sz++;
	int i = heap_sz;
	arr[i] = val;

	while (i > 0)
	{
		int p_idx = (i-1)/2;
		if (arr[p_idx] > arr[i])
		{
			std::swap(arr[p_idx], arr[i]);
			i = p_idx;
		}
		else  
		{
			break;
		}
	}
}

void Min_heap::delete_min()
{
	std::swap(arr[heap_sz], arr[0]);
	heap_sz--;
	int i = 0;

	while (i < capacity)
	{
		int min = i;
		int l = 2*i + 1;
		int r = 2*i + 2;

		if (l < capacity && arr[l] < arr[min])
		{
			min = l;
		}

		if (r < capacity && arr[r] < arr[min])
		{
			min = r;
		}

		if (i == min)
		{
			break;
		}

		std::swap(arr[i], arr[min]);
		i = min;
	}
}

int main()  
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

	Min_heap obj(100);
	obj.insert(2);
	obj.insert(4);
	obj.insert(6);
	obj.insert(9);
	obj.insert(12);
	obj.insert(10);
	obj.insert(20);
	obj.insert(11);
	obj.insert(3);
	obj.delete_min();
	obj.print();
}
