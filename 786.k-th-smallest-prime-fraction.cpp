/*
 * @lc app=leetcode id=786 lang=cpp
 *
 * [786] K-th Smallest Prime Fraction
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
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n= arr.size();
        double low=(arr[0] * 1.0)/arr[n-1];
        double high= 1;
        if(k==1) return {arr[0],arr[n-1]};
        while(low<=high){
            double mid= low+(high-low)/2;
            vector<int> count = help(arr,mid);
            if(k<count[0])
                high = mid;
            else if(k>count[0])
                low=mid;
            else 
                return {count[1],count[2]};// num, den
        } 
        return {};
    }
    static vector<int> help(vector<int>& arr, double mid){
        int n= arr.size();
        int count=0;
        int i=0;
        int num = arr[0];
        int den = arr[n-1];
        for(int j=1;j<n;j++){ 
            //  arr[i]/arr[j] <=mid // behind mid all are small so i++
            while(arr[i]<= mid*arr[j]) 
                i++;
            count+=i; 
            // arr[i-1] / arr[j] > num /den
            if(i>0 && arr[i-1]*den >= num*arr[j]){
                num= arr[i-1];
                den= arr[j];
            }
        }
        return {count,num,den};
    }
};


// Time complexity: O(n * n)

// Space complexity: O(n)
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        // max heap
        priority_queue<pair<double,pair<int,int>>> pq;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                pq.push( {{(double)arr[i]/arr[j]},{arr[i], arr[j]}} );
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        return {pq.top().second.first, pq.top().second.second};
    }
};


// binary search 
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        // max heap
        double left = 0;
        double right = 1;
        vector<int> ans;

        while(left<=right){
            double mid = left + (right-left)/2;
            int j = 1;
            int total = 0;
            int num = 0;
            int den =0;
            double mxFrac =0;
            for(int i=0; i<n; i++){
                while(j<n && arr[i]>=arr[j]*mid){
                    j++;
                }
                total += n-j;
                if(j<n && mxFrac < arr[i]*1.0/arr[j]){
                    mxFrac = arr[i]*1.0/arr[j];
                    num = i;
                    den = j;
                }
            }

            if(total==k){
                ans={arr[num], arr[den]};
                break;
            }

            if(total>k){
                right = mid;
            }
            else {
                left = mid;
            }
        }
        return ans;
    }
};



// @lc code=end


int main(){
    Solution sol;
    vector<int> arr={1,2,3,5};
    int k= 3;
    vector<int> ans= sol.kthSmallestPrimeFraction(arr,k);
    print(ans);
    return 0;
}