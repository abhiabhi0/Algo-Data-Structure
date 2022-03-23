#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <climits>

void clear_stack(std::stack<int>& st)
{
	while (!st.empty())
	{
		st.pop();
	}
}

int largest_rectangle_area(std::vector<int> &A) {

    int n = A.size();

    std::vector<int> NSL(n), NSR(n);

    std::stack<int> st;

    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && A[st.top()] >= A[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            NSL[i] = -1;
        }
        else if (A[st.top()] < A[i])
        {
            NSL[i] = st.top();
        }

        st.push(i);
    }

	clear_stack(st);

    for (int i = n-1; i >= 0; --i)
    {
        while (!st.empty() && A[st.top()] >= A[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            NSR[i] = n;
        }
        else if (A[st.top()] < A[i])
        {
            NSR[i] = st.top();
        }

        st.push(i);
    }

    int mx = INT_MIN;

    for (int i = 0; i < n; ++i)
    {
        int wd = NSR[i] - NSL[i] - 1;
        mx = std::max(mx, (wd*A[i])); 
    }
    return mx;
}


int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::vector<int> arr = {6, 2, 5, 4, 5, 1, 6};
    std::cout << largest_rectangle_area(arr);

    return 0;
}
