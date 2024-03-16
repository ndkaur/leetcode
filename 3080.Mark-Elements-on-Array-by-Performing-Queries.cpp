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


class Solution0 {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        long long sum = 0;
        for(int num:nums){
            sum += num;
        }
        
        unordered_set<int> st;
        
        vector<long long> ans;
        
        vector<pair<int,int>> temp;
        for(int i=0; i<n; i++){
            temp.push_back({nums[i],i});
        }
        // sorting temp on samll value
        sort(temp.begin(), temp.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            return a.first<b.first || (a.first==b.first && a.second < b.second);
        });
        
        int pos = 0;
        
        for(auto q:queries){
            int idx = q[0];
            int to_mark =  q[1];
            // mark visited in set
            if(st.find(idx)==st.end()){
                st.insert(idx);
                sum -= nums[idx];
            }
            
            while(to_mark>0 && pos<n){
                while(pos<n && st.find(temp[pos].second)!=st.end()){
                    pos++;
                }
                if(pos<n){
                    st.insert(temp[pos].second);
                    sum -= temp[pos].first;
                    pos++;
                    to_mark--;
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};


class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        long long sum = 0;
        for(int num:nums){
            sum += num;
        }
        vector<long long> ans;
        unordered_set<int> visited; // ti keep check of visited nums 
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // pq itself stores the smalles first 
        for(int i=0; i<n; i++){
            pq.push({nums[i], i});
        }
        
        for(auto q:queries){
            int idx = q[0];
            int to_mark = q[1];

            if(!visited.contains(idx)){ // marking visited the num 
                visited.insert(idx);
                sum -= nums[idx]; 
            }

            int cnt = 0; // this gonna keep check that we have marked k smallest nums 
            while(pq.size() && cnt!=to_mark){
                auto [val,idx] = pq.top();
                if(!visited.contains(idx)){
                    sum -= val;
                    cnt++;
                    visited.insert(idx);
                }
                pq.pop();
            }
            ans.push_back(sum);
        }
        return ans;
    }
};

int main(){

    return 0;
}