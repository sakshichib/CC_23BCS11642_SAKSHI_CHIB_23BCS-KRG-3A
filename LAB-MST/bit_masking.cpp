#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &arr, int n)
{
    int result = 0;
    for(int i=0;i<32;i++)
    {
        int sum = 0;
        for(int nums:arr)
        { 
            sum += nums >> i & 1;
            sum %= 3;
            result |= sum << i;
        }

        return result;
    }
}

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    cout<<singleNumber(arr, n);
}