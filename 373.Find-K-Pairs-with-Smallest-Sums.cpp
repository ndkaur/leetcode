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

class Solution {  // tle // O(n*m log(k))
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        priority_queue<pair<int,pair<int,int>>>pq;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int sum = nums1[i]+nums2[j];

                if(pq.size()<k){
                    pq.push({sum, {nums1[i], nums2[j]}});
                }
                else if(sum < pq.top().first){
                    pq.pop();
                    pq.push({sum, {nums1[i], nums2[j]}});
                }
                else {
                    break;
                }
            }
        }

        vector<vector<int>> ans;
        while(pq.size()){
            int a = pq.top().second.first;
            int b = pq.top().second.second;
            ans.push_back({a,b});
            pq.pop();
        }
        return ans;
    }
};



class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        // we making pq min heap as vi ->{sum, value of nums1, idx of number taken from nums2}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        
        for(int i=0; i<n && i<k; i++){
            // firstly we add sum of all nums1[i] with the first number in nums2
            pq.push({nums1[i]+nums2[0], nums1[i], 0}); // sum, nums1 val, idx of nums2
        }

        vector<vector<int>> ans;

        while(pq.size() && k--){
            auto arr = pq.top();
            pq.pop();
            // top elem will always be the smaller sum 
            ans.push_back({arr[1], nums2[arr[2]]});

            if(arr[2]==m-1) // reached last idx of nums2
                continue; 
            
            // adding the sum of remaing nums of nums2
            int newSum = arr[1] + nums2[arr[2]+1]; //  nums2[idx+1]
            pq.push({newSum, arr[1], arr[2]+1});
        }
        return ans;
    }
};

int main(){

    return 0;
}