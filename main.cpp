#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int max_incremental_order(const vector<int>& v,int max_elem)
{
    int last_elem = v[v.size() - 1];
    if(v.size() == 1)
    {
        if(last_elem <= max_elem)
            return 1;
        return 0;
    }
    vector<int> vec(v.begin(),v.end() - 1);
    if(last_elem < max_elem)
    {
        return max(max_incremental_order(vec,last_elem) + 1, max_incremental_order(vec,max_elem));
    }
    else if(last_elem == max_elem)
    {
        return max_incremental_order(vec,last_elem) + 1;
    }
    else
    {
        return max_incremental_order(vec,max_elem);
    }
}

int max_incremental_order(const vector<int>& v)
{
    if(v.empty())
        return 0;
    if(v.size() == 1)
        return 1;

    int max_elem = *max_element(v.begin(),v.end());
    return max_incremental_order(v,max_elem);


}

int main(int argc, char *argv[])
{
    int arr[] = {7,2,3,1,5,8,9,6};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    cout << max_incremental_order(v) << endl;
    return 0;
}
