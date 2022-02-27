//Given a square matrix. Convert it to its transpose without
//using any extra space.

#include <iostream>
#include <vector>
#include <algorithm>

void transpose(std::vector< std::vector<int> >& vec, int n)
{
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			std::swap(vec[i][j], vec[j][i]);
		}
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

    std::vector< std::vector<int> > vec(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		std::cin >> vec[i][j];
    	}
    }

    transpose(vec, n);

    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		std::cout << vec[i][j] << " ";
    	}
    	std::cout << "\n";
    }

    return 0;

}
