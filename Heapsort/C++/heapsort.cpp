#include <iostream>
#include <vector>
#include <algorithm>

void max_heapify(std::vector<int>& arr, int i, int size_)
{
    int largest, l = (2*i) + 1, r = l + 1;

    if(l < size_ && arr[l] > arr[i])
        largest = l;
    else
        largest = i;

    if(r < size_ && arr[r] > arr[largest])
        largest = r;

    if(largest != i)
    {
        std::swap(arr[i], arr[largest]);
        max_heapify(arr, largest, size_);
    }
}

void build_max_heap(std::vector<int>& arr)
{
    for(int i = (arr.size() / 2); i >= 0; i--)
    max_heapify(arr, i, arr.size());
}

void heap_sort(std::vector<int>& arr)
{
   build_max_heap(arr);
   int sz = arr.size();
   for(int i = arr.size() - 1; i > 0; i--)
   {
        std::swap(arr[0], arr[i]);
        sz--;
        max_heapify(arr, 0, sz);
    }
}

int main()
{
    std::vector<int> arr = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    heap_sort(arr);
    
    for(int i = 0; i < arr.size(); i++)
    {
         std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    return 0;
}
