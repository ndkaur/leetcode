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
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        arr[0]=1; // 1st condition 

        for(int i=1; i<n; i++){
            if(abs(arr[i-1]-arr[i])<=1) // second condition
                continue;
            else 
                arr[i] = arr[i-1]+1; // matching the 2nd condition 
        }
        return arr.back();
    }
};

int main(){

    return 0;
}