#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void insertion_sort(std::vector<int>& vec, int n)
{
    for(std::size_t j = 1; j < n; j++)
    {
      int key = vec[j];
      int i = j-1;

      while(i >= 0 && vec[i] > key)
      {
         vec[i+1] = vec[i];
         i--;
      }
      vec[i+1] = key;
    }
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    int n;
    std::cin >> n;

    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i)
    {
    	std::cin >> vec[i];
    }

    insertion_sort(vec, n);

    for (int x : vec)
    {
    	std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}
