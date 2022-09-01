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
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n= nums.size();
        int m= queries.size();

        sort(nums.begin(), nums.end());

        vector<int> ans(m,0);
        vector<int> pref;

        int sum=0;
        for(int i=0; i<n; i++){
            sum+= nums[i];
            pref.push_back(sum);
        }
        
        for(int i=0; i<m; i++){
            for(int j=0;j<n; j++){
                if(pref[j] <= queries[i]){
                    ans[i] = j+1;
                }
                else 
                    break;
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}