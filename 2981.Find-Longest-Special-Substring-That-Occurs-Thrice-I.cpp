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

// tc -> o(n) + o(n*n) + O(n)
class Solution { 
public:
    int maximumLength(string s) {
        int n = s.size();
        int cntLen = 0;
        // {substring , length} -> count if at least k 
        // fill the map 
        // mp -> char cause special substring has same char repeated again n again 
        map<pair<char, int>, int> mp;
        for(int i=0; i<n; i++){
            cntLen = 1;
            mp[{s[i], cntLen}]++; // including the len cnt of single char also 
            for(int j=i; j<n; j++){
                if(s[j]==s[j+1]){ // one more new element added so cnt of length increases
                    cntLen++;
                    mp[{s[i], cntLen}]++;           
                }
                else 
                    break;
            } 
        }

        int ans = -1;
        for(auto itr:mp){
            if(itr.second>=3){ // freq atleaast 3 
                ans = max(ans, itr.first.second); // return max ;ength of sequence
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}