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
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        map<int,int> mp; 
        for(int arr:arr1){
            mp[arr]++;
        }
        for(int arr:arr2){
            mp[arr]++;
        }
        for(int arr:arr3){
            mp[arr]++;
        }
        vector<int> ans;
        for(auto itr:mp){
            if(itr.second==3)
                ans.push_back(itr.first);
        }
        return ans;
    }
};


class Solution {
public:
    bool BinarySearch(vector<int>& arr, int target){
        int start=0,end=arr.size()-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(arr[mid]==target) return true;
            else if(arr[mid]>target) end=mid-1;
            else start=mid+1;
        }
        return false;
    }
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ans;
        for(int i:arr1){
            if(BinarySearch(arr2, i)&&BinarySearch(arr3, i))
                ans.push_back(i);
        }
        return ans;
    }
};


int main(){

    return 0;
}