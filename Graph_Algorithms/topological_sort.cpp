vector<int> solve(int A, vector<vector<int> > &B) {
    map<int, int> indegree;

    vector<vector<int>> adj_list;
    adj_list.resize(A+1);

    for (int i = 1; i <= A; ++i)
    {
        indegree.insert({i, 0});
    }

    for (int i = 0; i < B.size(); ++i)
    {
        adj_list[B[i][0]].push_back(B[i][1]);
        indegree[B[i][1]]++;
    }
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> q;

    for (auto [k, v] : indegree)
    {
        if (v == 0)
        {
            q.push(k);
        }
    }

    while (!q.empty())
    {
        int u = q.top();
        
        if (indegree[u] == 0)
        {
            ans.push_back(u);
        }
        
        q.pop();
        vector<int> arr;

        for (int v : adj_list[u])
        {
            if (indegree[v] > 0)
            {
                indegree[v]--;
                if (indegree[v] == 0)
                {
                    arr.push_back(v);
                }
            }   
        }
        sort(arr.begin(), arr.end());
        for (int x : arr)
        {
            q.push(x);
        }
    }
    return ans;
}
