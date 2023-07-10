/*
 * @lc app=leetcode id=2024 lang=cpp
 *
 * [2024] Maximize the Confusion of an Exam
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
    int maxConsecutiveAnswers(string answerKey, int k) {
        // we replace that which has smaller cnt in the current window 
        int n = answerKey.size();
        int tcnt = 0;
        int fcnt = 0;
        int left = 0;
        int right = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(answerKey[i]=='T')
                tcnt++;
            if(answerKey[i]=='F')
                fcnt++;
            // we will change that ele which is smaller in cnt 
            //but if even the smaller cnt gets greater than k range 
            // then we need to change the window size
            while(min(tcnt,fcnt)>k){
                if(answerKey[left]=='T')
                    tcnt--;
                if(answerKey[left]=='F')
                    fcnt--;
                left++;
            }
            right++;
            ans = max(ans, right-left);
        }
        return ans;
    }
};

class Solution0 { // slicding window 
public:
    int maxConsecutiveAnswers(string key, int k) {
        int n= key.size();
        int tcnt=0;
        int fcnt=0;
        int start=0,end=0;
        int ans =0;
        for(int i=0;i<n;i++){
            if(key[i]=='T')
                tcnt++;
            if(key[i]=='F')
                fcnt++;
            end++;
            while(min(tcnt, fcnt)> k){
                if(key[start]=='T')
                    tcnt--;
                if(key[start]=='F')
                    fcnt--;
                start++;
            }
            ans= max(ans,end-start);
        }
        return ans;
    }
};


class Solution { // binary search
public:
    int maxConsecutiveAnswers(string key, int k) {
        int n= key.size();
        int l= 0;
        int h=n;
        int ans=0;
        while(l<=h){
            int mid= l+(h-l)/2;
            if(possible(key,k,mid)){
                ans = mid;
                l=mid+1;
            } else{
                h=mid-1;
            }
        }
        return ans;
    }
    bool possible(string key, int k,int mid){
            int n= key.size();
            int tcnt=0;
            int fcnt=0;
            for(int i=0;i<mid;i++){
                if(key[i]=='T')
                    tcnt++;
                else 
                    fcnt++;
            }
            if(min(tcnt,fcnt)<=k) return true;
            for(int i=mid;i<n;i++){
                if(key[i]=='T') 
                    tcnt++;
                else fcnt++;
                if(key[i-mid]=='T')
                    tcnt--;
                else 
                    fcnt--;
                if(min(tcnt,fcnt)<=k){
                    return true;
                    break;
                }
            }
            return false;
        }
};
// @lc code=end


int main(){
    Solution sol;
    string key = "TTFF";
    int k=2;
    int ans= sol.maxConsecutiveAnswers(key, k);
    cout<<ans;
    return 0;
}