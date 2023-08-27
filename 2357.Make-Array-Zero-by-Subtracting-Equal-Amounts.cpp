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
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> pq;
        // [1,5,0,3,5]
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(nums[i]!=0){
                if(pq.empty()){
                    pq.push(nums[i]);
                }
                else{
                    if(pq.top()==nums[i]){ // duplicate elems
                        continue;
                    }
                    else{
                        pq.push(nums[i]);
                    }
                }
            }
        }
        return pq.size();
    }
};

class Solution1 {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        // [1,5,0,3,5]
        sort(nums.begin(), nums.end());
        int cnt =0;

        for(int i=0; i<n; i++){
            if(nums[i]>0){
                int num = nums[i];
                cnt++;
                for(int j=i; j<n; j++){
                    nums[j] = nums[j]-num;
                }
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<n; i++){
            if(nums[i]>0)
                pq.push(nums[i]);
        }

        int cnt =0;
        int ans =0;
        while(pq.size()){
            int num = pq.top();
            vector<int> temp;
            while(pq.size()){
                if(pq.top()-num==0){
                    ans = cnt+1;
                    pq.pop();
                }
                else{
                    temp.push_back(pq.top()-num);
                    pq.pop();
                }
            }
            for(int t:temp){
                pq.push(t);
            }
            temp.clear();
            cnt = ans;
        }
        return cnt;
    }
};


int main(){

    return 0;
}