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
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for(auto num:nums){
            mp[num]++;
        }
        int sz = mp.size();

        int i =0;
        int j =0;
        int cnt =0;

        map<int,int> mp1;

        while(j<n){
            mp1[nums[j]]++;
            
            while(mp1.size()==sz && i<=j){
                mp1[nums[i]]--;
                if(mp1[nums[i]]==0)
                    mp1.erase(nums[i]);
                i++;
                cnt += n-j; // all the remining will also have the rest of the elements
            }
            j++;
        }
        return cnt;
    }
};

class Solution { //O(N^2)
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        set<int> s;
        for(int num:nums){
            s.insert(num);
        }
        int dis = s.size();
        int cnt =0;

        for(int i=0; i<n; i++){
            set<int> track;
            for(int j=i; j<n; j++){
                track.insert(nums[j]);
                if(track.size()==dis){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main(){

    return 0;
}