//Given an arry having positions of rooms where we can keep cows.
//Sorted in ascending order. K = number of cows
//Return the maximum vlue of minimum possible distance between any two cows

//Maximize the minimum distance

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool check_dist(std::vector<int>& vec, int n, int d, int num_cows)
{
	int last_pos = vec[0];
	int cows_placed = 1;

	for (int i = 1; i < n; ++i)
	{
		if ((vec[i] - last_pos) >= d)
		{
			cows_placed++;
			last_pos = vec[i];
		}

		if (cows_placed == num_cows)
			return true;
	}
	return false;
}

int maximize_min_dist(std::vector<int>& vec, int n, int num_cows)
{
	int l = 1, r = vec[n-1] - vec[0];
	int ans;

	while (l <= r)
	{
		int mid = (l+r)/2;

		if (check_dist(vec, n, mid, num_cows))
		{
			ans = mid;
			l = mid+1;
		}
		else  
		{
			r = mid - 1;
		}
	}
	return ans; 
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

    std::cout << maximize_min_dist(vec, n, 4);
 
    return 0;
}
