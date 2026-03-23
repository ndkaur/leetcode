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
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        map<int,int> mp1, mp2;

        for(int i=0; i<n; i++){
            mp1[nums1[i]]++;
            mp2[nums2[i]]++;
        }
        map<int,int> total; // num, freq

        for(auto itr:mp1){
            total[itr.first]+= itr.second;
        }
        for(auto itr:mp2){
            total[itr.first] += itr.second;
        }


        int ans = 0;

        for(auto itr:total){
            if(itr.second%2==1)
                return -1;
            int num = itr.first;
            int val = itr.second; // 4
            int req = val/2; // 2
            int actual = -1;
            if(mp1.find(num)!=mp1.end()){
                int freq = mp1[num]; // 3, 1
                actual = abs(req-freq); // 3-2 =1 , 1-2=1
            }
            else{
                int freq = mp2[num];
                actual = abs(req-freq);
            }
            ans+=actual;
        }
        return ans/2;
    }
};


// map for nums1, nums2 
// freq arr = total freq store
// check, odd freq -> return -1
// even freq, check whats required, what we have and find diff




int main(){

    return 0;
}