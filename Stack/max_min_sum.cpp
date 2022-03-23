/** Given an array. Find sum of max-min for every subarray **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

void clear_stack(std::stack<int>& st)
{
	while (!st.empty())
	{
		st.pop();
	}
}

int min_max_sum(std::vector<int>& arr)
{
	int n = arr.size();
	int mod = 1000000007;
	std::vector<int> min_val_idx_L(n), min_val_idx_R(n), max_val_idx_L(n), max_val_idx_R(n);

	std::stack<int> index_st;

	for (int i = 0; i < arr.size(); i++)
	{
		while (!index_st.empty() && arr[index_st.top()] <= arr[i])
		{
			index_st.pop();
		}

		if (index_st.empty())
		{
			max_val_idx_L[i] = -1;
		}
		else if (arr[index_st.top()] > arr[i])
		{
			max_val_idx_L[i] = index_st.top();
		}
		index_st.push(i);
	}

	clear_stack(index_st);

	for (int i = 0; i < arr.size(); i++)
	{
		while (!index_st.empty() && arr[index_st.top()] >= arr[i])
		{
			index_st.pop();
		}

		if (index_st.empty())
		{
			min_val_idx_L[i] = -1;
		}
		else if (arr[index_st.top()] < arr[i])
		{
			min_val_idx_L[i] = index_st.top();
		}
		index_st.push(i);
	}
	clear_stack(index_st);

	for (int i = arr.size()-1; i >= 0; i--)
	{
		while (!index_st.empty() && arr[index_st.top()] <= arr[i])
		{
			index_st.pop();
		}

		if (index_st.empty())
		{
			max_val_idx_R[i] = n;
		}
		else if (arr[index_st.top()] > arr[i])
		{
			max_val_idx_R[i] = index_st.top();
		}
		index_st.push(i);
	}

	clear_stack(index_st);

	for (int i = arr.size()-1; i >= 0; i--)
	{
		while (!index_st.empty() && arr[index_st.top()] >= arr[i])
		{
			index_st.pop();
		}

		if (index_st.empty())
		{
			min_val_idx_R[i] = n;
		}
		else if (arr[index_st.top()] < arr[i])
		{
			min_val_idx_R[i] = index_st.top();
		}
		index_st.push(i);
	}

	int mx_sum = 0, mn_sum = 0;

	for (int i = 0; i < arr.size(); ++i)
	{
		int sum = arr[i];

		sum = (sum * (((max_val_idx_R[i] - i) * (i - max_val_idx_L[i])) % mod)) % mod;

		mx_sum = (mx_sum + sum) % mod;

		sum = arr[i];

		sum = (sum * (((min_val_idx_R[i] - i) * (i - min_val_idx_L[i])) % mod)) % mod;

		mn_sum = (mn_sum + sum) % mod;
	}	

	return (mx_sum - mn_sum);
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::vector<int> arr = {2, 5, 3};
    std::cout << min_max_sum(arr);

    return 0;
}
