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

// Time complexity: O(N*26)
// Space complexity: O(26)
class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.size();
        vector<int> arr(26,-1);
        int cnt = 0;

        for(int i=0; i<n; i++){
            int idx_in_arr = word[i]-'a';
            // alreeady that char exist then find if the length is greater than 4 , curr idx -previdx stored in arr +1 = len >=4
            if(arr[idx_in_arr]!=-1 && i-arr[idx_in_arr]+1>=4){
                cnt++;
                // cnacel out all the prev visited indexed which we have stored in array so that we can ignore the intersecting subarrys
                for(int j=0; j<26; j++){
                    arr[j]=-1;
                }
            }
            else{ // idx not already marked then mark it save it 
                if(arr[idx_in_arr]==-1)
                    arr[idx_in_arr] = i;
            }
        }
        return cnt;
    }
};



int main(){

    return 0;
}