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
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        set<int>s1,s2;
        for(int i:nums1){
            s1.insert(i);
        }
        for(int i:nums2){
            s2.insert(i);
        }
        vector<int> ans;
         int cnt1 =0;
        for(int i=0; i<n; i++){
           
            if(s2.find(nums1[i])!=s2.end()){
                cnt1++;
            }
        }
        
        int cnt2=0;
        for(int i=0; i<m; i++){
            if(s1.find(nums2[i])!=s1.end()){
                cnt2++;
            }
        }
        ans.push_back(cnt1);
        ans.push_back(cnt2);
        return ans;
    }
};

int main(){

    return 0;
}