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
    int find(vector<int>& arr){
        // eg ->{0,1,2,3} more than 3 indexes then we want min of all 
        // and we cant take idx like  {0,1,3}
        int diff=INT_MAX;
        if(arr.size()>3){
            for(int i=0; i<arr.size()-2; i++){
                diff = min(diff,(abs(arr[i]-arr[i+1]) + abs(arr[i+1]-arr[i+2]) + abs(arr[i+2]-arr[i])));
            }
        }
        else if(arr.size()==3)
            diff = min(diff,(abs(arr[0]-arr[1])+abs(arr[1]-arr[2])+abs(arr[2]-arr[0])));
        return diff;
    }
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)
            return -1;
        map<int, vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        int mn = INT_MAX;
        bool check = false; // if no one with 3 freq exist 
        for(auto itr:mp){
            vector<int> arr = itr.second;
            if(arr.size()>=3){
                int diff = find(arr);
                check= true;
                mn = min(mn, diff);
            }
        }
        return check==true? mn: -1;
    }
};



int main(){

    return 0;
}