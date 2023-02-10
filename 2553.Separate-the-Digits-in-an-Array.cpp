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
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<n; i++){
            vector<int> temp;
            seprate(nums[i],temp);
            for(int i=0; i<temp.size(); i++){
                ans.push_back(temp[i]);
            }
        }
        return ans;
    }
    void seprate(int n, vector<int>& temp){
        while(n>0){
            int rem = n % 10;
            temp.push_back(rem);
            if(n)
                n = n/10;
        }
        reverse(temp.begin(), temp.end());
    }
};

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(auto num: nums){
            vector<int> temp;
            while(num > 0){
                temp.push_back(num%10);
                num = num/10;
            }
            for(int i=temp.size()-1; i>=0; i--){
                ans.push_back(temp[i]);
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}