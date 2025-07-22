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
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        sort(folder.begin(), folder.end());
        vector<string> ans;
        ans.push_back(folder[0]);

        string prev= ans.back();

        for(int i=1; i<n; i++){
            string s = folder[i];
            // find function return the first index where the string occured in other string 
            // if the find function returns 0 that mean that string occurs at idx 0 and is a subfolder . 
            // but if the find function returns !=0 means some other index that means its not sub folder
            if(s.find(prev+'/')!=0){
                ans.push_back(s);
                prev = s;
            }
        }
        return ans;
    }
};


// folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
// Output: ["/a","/c/d","/c/f"]
// /a , /a/b, c/d,  c/d/e, c/f
// ans = /a , c/d, c/f


int main(){

    return 0;
}