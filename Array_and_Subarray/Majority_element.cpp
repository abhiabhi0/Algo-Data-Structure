//Finf majority element in an array which is occurring more than
// n/2 times

#include <iostream>
#include <vector>
#include <algorithm>

int majority_element(std::vector<int>& vec, int n)
{
	int maj = -1, freq = 0;

	for (int i = 0; i < n; ++i)
	{
		if (maj == -1)
		{
			maj = vec[i];
			freq++;
		}
		else  
		{
			if (vec[i] == maj)
			{
				freq++;
			}
			else 
			{
				freq--;

				if (freq == 0)
				{
					maj = -1;
				}
			}
		}
	}

	int count = 0;

	for (int i = 0; i < n; ++i)
	{
		if (vec[i] == maj)
			count++;
	}

	if (count > n/2)
		return maj;

	return -1;
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

    std::cout << majority_element(vec, n) << "\n";

    return 0;

}
