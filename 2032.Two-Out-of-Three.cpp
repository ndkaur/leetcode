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
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int>ans;
        map<int,int>mp;
        set<int>s1(nums1.begin(),nums1.end());  //Appending into set to eliminate duplicate values
        set<int>s2(nums2.begin(),nums2.end());
        set<int>s3(nums3.begin(),nums3.end());
        for(int i : s1){
                mp[i]++;
        }
        for(int i : s2){
                mp[i]++;
        }
        for(int i : s3){
                mp[i]++;
        }
        for(auto it:mp){
            if(it.second>=2){   //if the element present more than 2 array
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

// bits
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> temp(110,0);
        for(int num:nums1){
            temp[num] = temp[num] | 1<<0; // 1<<0
        } 
        for(int num:nums2){
            temp[num] = temp[num] | 1<<1; // 1<<1
        }
        for(int num:nums3){
            temp[num] = temp[num] | 1<<2; // 1<<2
        }
        // 011 = 3 = number 1 and 2nd array 
        // 101 = 5 = number in 3 and 1st array
        // 110 = 6 = number in 3rd and 2nd array
        // 111 = 7, num in all arays 
        vector<int> ans;
        for(int i=1; i<=100; i++){
            if(temp[i]==3 || temp[i]>=5)
                ans.push_back(i);
        }
        return ans;
    }
}; 


int main(){

    return 0;
}