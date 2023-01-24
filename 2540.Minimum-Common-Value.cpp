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


class Solution0 { // tle
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(nums1[i]==nums2[j])
                    return nums1[i];
            }
        }
        return -1;
    }
};

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        map<int,int> mp1,mp2;
        for(int num:nums1){
            mp1[num]++;
        }
        for(int num:nums2){
            mp2[num]++;
        }
        int mn = INT_MAX;
        for(int i=0; i<m; i++){
            if(mp1.find(nums2[i])!=mp1.end())
                return nums2[i];
        }
        return -1;
    }
};

int main(){

    return 0;
}