#include <iostream>
#include <vector>

template<class T>
void merge(std::vector<T>& v, int p, int q, int r)
{
    int size1 = q-p+1;
    int size2 = r-q;
    std::vector<T> L(size1);
    std::vector<T> R(size2);

    for(int i = 0; i < size1; i++)
    {
        L[i] = v[p+i];
    }
    for(int j = 0; j < size2; j++)
    {
        R[j]=v[q+j+1];
    }

    int i=0,j=0;
    int k;
    for(k = p; k <= r && i < size1 && j < size2; k++)
    {
        if(L[i] <= R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k] = R[j];
            j++;
        }
    }
    for(i = i; i < size1; ++i)
    {
        v[k] = L[i];
        k++;
    }

    for(j = j; j < size2; j++)
    {
        v[k] = R[j];
        k++;
    }
}

template<class T>
void merge_sort(std::vector<T>& v, int p, int r)
{
    if(p < r)
    {
        int q = (p+r)/2;
        merge_sort(v, p, q);
        merge_sort(v, q+1, r);
        merge(v, p, q, r);
    }
}

int main()
{
    std::vector<int>vec;
    vec.push_back(13);
    vec.push_back(5);
    vec.push_back(7);
    vec.push_back(7);
    vec.push_back(4);
    vec.push_back(2);
    vec.push_back(10);
    int sz = vec.size();
    std::cout << "Entered array : ";
    for(int n = 0; n < sz; n++)
    {
        std::cout << vec[n] <<" ";
    }
    std::cout << "\n";
    std::cout << "Sorted array : ";
    merge_sort(vec, 0, sz-1);
    for(int n = 0; n < sz; n++)
    {
        std::cout << vec[n] << " ";
    }
    std::cout << "\n\n";

    std::vector<char> c;
    c.push_back('d');
    c.push_back('y');
    c.push_back('h');
    c.push_back('l');
    c.push_back('e');
    c.push_back('a');
    int sz1 = c.size();
    std::cout << "Entered array : ";
    for(int n = 0; n < sz1; n++)
    {
        std::cout << c[n] <<" ";
    }
    std::cout << "\n";
    std::cout << "Sorted array : ";
    merge_sort(c, 0, sz1-1);
    for(int n = 0; n < sz1; n++)
    {
        std::cout << c[n] << " ";
    }
    std::cout << "\n\n";

    std::vector<std::string> str;
    str.push_back("car");
    str.push_back("dog");
    str.push_back("apple");
    str.push_back("ball");
    str.push_back("tree");
    int sz2 = str.size();

    std::cout << "Entered array : ";
    for(int n = 0; n < sz2; n++)
    {
        std::cout << str[n] <<" ";
    }
    std::cout << "\n";
    std::cout << "Sorted array : ";
    merge_sort(str, 0, sz2-1);
    for(int n = 0; n < sz2; n++)
    {
        std::cout << str[n] << " ";
    }
    std::cout << "\n";

    return 0;
}
