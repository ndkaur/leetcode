#include "bits/stdc++.h"
using namespace std;
// #include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
//#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

class Solution {
public:
    int minOperations(int n) {
        int n1 =0;
        int n2 =0;
        vector<int> arr;
        arr.push_back(1);
        int val = 1;
        // pushing all the powers of 2 in a single arr 
        for(int i=1; i<=17; i++){
            if(val == n)
                return 1;
            val = val * 2;
            arr.push_back(val);
        }
        int cnt = 0;
        while(true){ 
            cnt++;
            // lower bound return idx so *it return value
            // lb given next greter or equal elem
            auto it = lower_bound(arr.begin(), arr.end(),n);
            if(*it == n)
                break;
            // num is odd or even
            // odd = num+1 or num-1 to make it even 
            int val1 = *it-n;
            int val2 = n - *(it-1); // making ihe num even then subtracting
            n = min(val1, val2);
            if(n<=0)
                break;
        }
        return cnt;
    }
};

int main(){

    return 0;
}