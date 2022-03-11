#include <iostream>
#include <vector>
#include <algorithm>

void insertion_sort(std::vector<int>& vec)
{
	for(auto it = vec.begin(); it != vec.end(); it++)
 	{
   		// Search
   		auto const insertion_point = std::upper_bound(vec.begin(), it, *it);

   		//insert
   		std::rotate(insertion_point, it, it+1);
 	}
}

void print(std::vector<int> const& vec)
{
	for( int x : vec)
  		std::cout << x << " ";
	std::cout << '\n';
}

int main()
{
	std::vector<int> arr = {5, 2, 4, 6, 1, 3};
 	insertion_sort(arr);
 	print(arr);
}
