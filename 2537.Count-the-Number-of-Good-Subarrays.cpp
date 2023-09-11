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
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        long long cnt = 0;
        long long ans = 0;
        
        int i=0;
        int j=0;
        map<int,int> mp;
        
        while(j<n){
            mp[nums[j]]++;
            // if mp[i]==0 then it will become 1 means new occurence of num
            // if mp[i]==1 then it will inc mp[i]++ = 2 , becomes a pair and inc cnt 
            cnt += mp[nums[j]]-1; 
            // mp[j] >1 lets say mp[j]=2 then cnt = 2-1 = 1 means 1 pair found 

            while(cnt >=k){
                ans +=(long long)n-j; // if k pairs in current window then also counted in remaining array nums
                //move the window
                mp[nums[i]]--;
                // if mp reduces a pair then cnt will also decrease
                cnt -= mp[nums[i]];
                if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};



class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        long long cnt_of_subary = 0;
        long long cnt_of_pair = 0;
        int left = 0;
        map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
            cnt_of_pair += mp[nums[i]] - 1; // freq - 1
            if(cnt_of_pair >= k){
                while(cnt_of_pair >= k && left <= i){
                    cnt_of_subary += (n-i);
                    mp[nums[left]]--;
                    cnt_of_pair -= mp[nums[left]];
                    if(mp[nums[left]] == 0)
                        mp.erase(nums[left]);
                    left++;
                }
            }
        }
        return cnt_of_subary;
    }
};


   //      0 1 2 3 4 5 6
// nums = [3,1,4,3,2,2,4], k = 2

// mp[3] = 2    pair = 1 (i=3)
// mp[1] = 1
// mp[4] = 1
// mp[2] = 2  pair = 2 (i=5)
// ans = n-i = 7-5 = 2 
// mp[nums[left]] , left=0  mp[3] = 1 pair =1
// i=6  mp[4] =2  , left =1  , pair =2
// ans = (n-i) = (7-6) =1  ->2+1 = 3 left++
//  mp[nums[left]] = mp[1] = 0 , pair = 2-0 = 2 
//  ans= (n-i) = (7-6) = 1  -> 3+1 = 4  left++
// left= 2  mp[nums[left]]-- = mp[4] = 1  pair= 2-1 =1 
// so  i at the end and return ans = 4.



int main(){

    return 0;
}