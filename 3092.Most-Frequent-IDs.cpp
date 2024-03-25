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
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();
        vector<long long> ans;
        map<long long,long long> mp;
        priority_queue<pair<long long,int>> pq;

        for(int i=0; i<n; i++){
            mp[nums[i]] += freq[i];
            pq.push({mp[nums[i]], nums[i]});
            // now we want max freq
            while(pq.size()){
                auto freq = pq.top().first;
                auto num = pq.top().second;
                //max freq will only change whent he pq top element value not same as in map , ie the map value either increased or reduced 
                if(mp[num]!=freq){
                    pq.pop();
                    if(mp[num]){ // if the values is not negative or greater than 0 ie if value exist 
                        pq.push({mp[num], num});
                    }
                }
                else{
                    break;
                }
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};

// 2 -> 3
// 3 -> 2 
// 

int main(){

    return 0;
}