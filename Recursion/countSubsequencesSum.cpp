#include <bits/stdc++.h>
using namespace std;

int printS(int ind, int s, int sum, int arr[], int n ){
    // condition not satisfied (for opimizability purpose only)
    // strictly done if array contains positive numbers only
    if( s > sum) return 0;
    
    if(ind == n){
        // condition satisfied
        if(s==sum){
            return 1;
        }
        // condition not satisfied
        else return 0;
    }
    // take or pick the particular index into the subsequece
    s += arr[ind];
    int l = printS(ind+1, s, sum, arr, n);
    s -= arr[ind];

    // not take or not pick condition, this element is not added to your subsequence
    int r = printS(ind+1, s, sum, arr,n);

    return l + r;
}

int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    cout << printS(0,0,sum,arr,n);
    return 0;
}
