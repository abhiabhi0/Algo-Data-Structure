//using Dynamic Programming
//A = n, B = r and C = m (mod) where C is not prime
int nCr_mod_m_DP(int A, int B, int C) {
    if (B == 1) return A % C;

    if (B == A || B == 0) return 1;

    vector< vector<int> > mat(A+1, vector<int>(B+1, 0));

    for (int i = 0; i <= A; ++i)
    {
        mat[i][0] = 1;
    }

    for (int i = 1; i <= A; ++i)
    {
        for (int j = 1; j <= B; ++j)
        {
            mat[i][j] = (mat[i-1][j] + mat[i-1][j-1]) % C;
        }
    }

    return mat[A][B] % C;
}
