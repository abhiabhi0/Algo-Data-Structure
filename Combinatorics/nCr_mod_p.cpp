//A = n, B = r, p = mod, where p is prime

int iter_pow(int base, int exp, int mod)
{
    if (base == 1 || exp == 0)
    {
        return 1;
    }

    int ans = 1;

    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            ans = (ans * base) % mod;
        }

        exp = exp >> 1;

        base = (base * base) % mod;
    }
    return ans % mod;
}

int nCr_mod_p(int A, int B, int C) {
    int term1 = 1;

    for (int i = 2; i <= A; ++i)
    {
        term1 = (term1 * i) % C;
    }

    int A_B_fact = 1;

    for (int i = 2; i <= A-B; ++i)
    {
        A_B_fact = (A_B_fact * i) % C;
    }

    int B_fact = 1;

    for (int i = 2; i <= B; ++i)
    {
        B_fact = (B_fact * i) % C;
    }

    int term2 = iter_pow(A_B_fact, C-2, C);
    int temr3 = iter_pow(B_fact, C-2, C);

    return (term1 * term2 * temr3) % C;
}
