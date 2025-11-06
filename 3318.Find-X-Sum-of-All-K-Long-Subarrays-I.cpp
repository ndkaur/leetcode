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
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int>ans;
        for(int i=0; i<n-k+1; i++){
            map<int,int> mp;
            for(int j=i; j<i+k; j++){
                mp[nums[j]]++;
            }
            vector<pair<int,int>> freq;
            for(auto itr:mp){
                freq.push_back({itr.second, itr.first});
            }
            sort(freq.begin(), freq.end(), [](const auto& a, const auto& b){
                if(a.first==b.first) // both freq equal return greater num
                    return a.second>b.second;
                return a.first>b.first; // greater freq first
            }); 
            // take top k elm 
        
            int sum =0;
        
            for(int idx=0; idx<x; idx++){
                if(idx>=freq.size())
                    break;
                sum += freq[idx].first * freq[idx].second;

            }
            ans.push_back(sum);
        }
        return ans;
    }
};


// Time complexity: O(n⋅klogk)
// Space complexity: O(n+k)
class Solution {
public:
    int calculate(map<int,int>& freq, int x){
        priority_queue<pair<int,int>> pq; // max heap 
        for(auto itr:freq){
            pq.push({itr.second, itr.first});
        }

        int sum =0;
        for(int i=0; i<x && pq.size(); i++){
            auto mx = pq.top();
            pq.pop();
            sum += mx.second * mx.first;
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int>ans;
        map<int,int> freq;

        for(int i=0; i<k; i++){
            freq[nums[i]]++;
        }

        ans.push_back(calculate(freq, x));

        for(int i=1; i<=n-k; i++){
            freq[nums[i-1]]--;
            if(freq[nums[i-1]]==0)
                freq.erase(nums[i-1]);
            
            freq[nums[i+k-1]]++;
            ans.push_back(calculate(freq,x));
        }
        return ans;
    }
};


int main(){

    return 0;
}