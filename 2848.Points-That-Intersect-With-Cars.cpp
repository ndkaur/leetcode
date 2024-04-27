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

// line sweep

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> arr(102, 0);
        for(auto num:nums){
            arr[num[0]]++;
            arr[num[1]+1]--;
        }
        int ans = 0;
        int sum = 0;
        for(int i=1; i<=100; i++){
            sum += arr[i];
            if(sum)
                ans++;
        }
        return ans;
    }   
};


class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
       
        int cnt =0;
        vector<vector<int>> arr;
        arr.push_back(nums[0]);
        int j =0;
        
        for(int i=1; i<n; i++){
            if(arr[j][1] >= nums[i][0]){
                arr[j][1] = max(arr[j][1], nums[i][1]);
            }
            else {
                j++;
                arr.push_back(nums[i]);
            }
        }
        for(auto num:arr){
            cnt += num[1]-num[0]+1;
        }
        return cnt;
    }
};

int main(){

    return 0;
}