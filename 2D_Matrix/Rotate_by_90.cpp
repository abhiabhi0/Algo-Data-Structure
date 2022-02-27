//Given a square matrix. Rotate it by 90 degree in clockwise direction
// without using any extra space.

#include <iostream>
#include <vector>
#include <algorithm>

void rotate_90(std::vector< std::vector<int> >& vec, int n)
{
	int l = 0, r = n-1;

	while (l <= r)
	{
		int t = l, b = r;

		for (int i = t; i < b; ++i)
		{
			int tmp = vec[t][l+i];
			vec[t][l+i] = vec[b-i][l];
			vec[b-i][l] = vec[b][r-i];
			vec[b][r-i] = vec[t+i][r];
			vec[t+i][r] = tmp;
		}
		l++;
		r--;
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

    rotate_90(vec, n);

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
