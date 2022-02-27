//Print upper triangle in a square matrix

#include <iostream>
#include <vector>

void print(std::vector< std::vector<int>>& vec, int n)
{
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			std::cout << vec[i][j] << " ";
		}
		std::cout << "\n";
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

    print(vec, n);

    return 0;

}
