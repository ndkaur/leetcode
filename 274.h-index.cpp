/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 */
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

// @lc code=start



class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),greater<int>());
        int answer=0;
        for(int i=0;i<citations.size();i++){
            if(citations[i]>=i+1){
                answer=i+1;
            }
            else{
                break;
            }
        }
        return answer;
    }
};

// 0 1 2 3 4
// 6 5 3 1 0 

class Solution {
public:
    int hIndex(vector<int>& cit) {
        int n= cit.size();
        // sort(cit.begin(), cit.end());
        int l = 0;
        int r = n;
        int ans=0;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(isPossible(cit, mid)){
                ans =mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        return ans;
    }
    bool isPossible(vector<int>& cit, int mid){
        int cnt =0;
        int  n= cit.size();
        for(int i=0;i<n;i++){
            if(cit[i]>=mid)
                cnt++;
        }
        return cnt>=mid;
    }
};
// @lc code=end


int main(){

    return 0;
}