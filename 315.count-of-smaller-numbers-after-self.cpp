/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */
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
// @lc code=start

// tle O(n^2)
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i=0; i<n-1; i++){
            int cnt =0;
            for(int j=i+1; j<n; j++){
                if(nums[i]> nums[j]){
                    cnt++;
                }
            }
            ans[i] = cnt;
        }
        ans[n-1] = 0;
        return ans;
    }
};


// merge sort 
//O(nlogn)  //O(n)
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        // make an arry to send for merge sort with num and its idx 
        vector<pair<int,int>> arr(n);
        for(int i=0; i<n; i++){
            arr[i] = {nums[i], i};
        }

        vector<int> count(n,0);
        mergeSort(count, arr, 0, n-1);
        return count;
    }

    void mergeSort(vector<int>& count, vector<pair<int,int>>& arr, int left, int right){
        if(left >= right)
            return;

        int mid = left + (right -left) /2;
        mergeSort(count, arr, left , mid);
        mergeSort(count, arr, mid+1, right);
        merge(count, arr, left, mid, right);
        
    }

    void merge(vector<int>& count, vector<pair<int,int>>& arr, int left, int mid, int right){
        // make a temp arr to store the merged descending order
        vector<pair<int ,int>> temp(right - left + 1);
        // left  mid   mid+1  right
        //  i           j 
        int i = left;
        int j = mid+1;
        int k = 0;

        while(i<=mid && j<=right){
            // decreasing num  num[i] > num[j]
            if(arr[i].first <= arr[j].first){ // opposite condition 
                // put the greater elem in the temp array 
                temp[k] = arr[j];
                k++;
                j++;
            }
            else{ // wen decreasing condition met then count++ at that idx 
                // 5    3 2 1   so 5 will be greter than all the ele in other array if its is greter than the starting elem
                // so find the len ie no of total elem present 
                count[arr[i].second] += right - j + 1;
                temp[k] = arr[i];
                k++;
                i++;
            }
        }

        // elemts remainig in left arr
        while(i <= mid){
            temp[k] = arr[i];
            k++;
            i++;
        }

        // elem remaining in right arr
        while(j <=right){
            temp[k] = arr[j];
            k++;
            j++;
        }
        // decresing arr temp formed in smaller divisons to be used further
        for(int i=left; i<=right; i++){
            arr[i] = temp[i-left];
        }

    }
};




// @lc code=end



int main(){

    return 0;
}