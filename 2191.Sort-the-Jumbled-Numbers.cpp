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
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = mapping.size();
        map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[i]=mapping[i];
        }

        vector<pair<int,int>> temp;

        for(int i=0; i<nums.size(); i++){
            string val = to_string(nums[i]);
            int new_num = 0;
            for(auto ch:val){
                int idx = ch-'0';
                new_num = new_num*10 + mp[idx];
            }
            temp.push_back({new_num,i});
        }

        sort(temp.begin(), temp.end());

        vector<int> ans;
        for(int i=0; i<temp.size(); i++){
            ans.push_back(nums[temp[i].second]);
        }
        return ans;
    }
};


class Solution { // time limit exceeded 
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n= nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]= finnd(nums[i], mapping);
        }
        
        sort(nums.begin(),nums.end(), [&](int &a, int &b){
            return mp[a]<mp[b];
        });
        return nums;
    }
    int finnd(int num, vector<int>&mapping){
        if(num==0){
            return mapping[0];
        }
        int r=0;
        vector<int> arr;
        while(num!=0){
            r=num%10;
            arr.push_back(r);
            num=num/10;
        }
        reverse(arr.begin(),arr.end());
        int out =0;
        for(int x:arr){
            out= out*10+mapping[x];
        }
        return out;
    }
};

class Solution0 {
public:
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]= finnd(nums[i], mapping);
        }
        
        sort(nums.begin(),nums.end(), [&](int &a, int &b){
            return mp[a]<mp[b];
        });
        return nums;
    }
    int finnd(int num, vector<int>&mapping){
        if(num==0){
            return mapping[0];
        }
        int r=0;
        vector<int> arr;
        while(num!=0){
            r=num%10;
            arr.push_back(r);
            num=num/10;
        }
        reverse(arr.begin(),arr.end());
        int out =0;
        for(int x:arr){
            out= out*10+mapping[x];
        }
        return out;
    }
};

int main(){
    
    return 0;
}