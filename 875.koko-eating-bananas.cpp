/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
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
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int ans = 0;
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        while(left<=right){
            int mid = left + (right-left)/2;
            if(isPossible(mid, h, piles)){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
    bool isPossible(int mid, int h, vector<int>& piles){
        long long hours =0;
        for(int i=0; i<piles.size(); i++){
            hours += ceil(piles[i]/ (double)mid);
            // hours += (piles[i] % mid == 0) ? piles[i]/mid : (piles[i]/mid)+1;
        }
        return hours<=h;
    }
};

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //time = dist /speed -> piles[i] / h
        int n= piles.size();
        
        int low= 1;
        int high = 1000000000;
        int ans = 0;
        while(low <= high){
            int speed = low + (high-low)/2;
            int hours = calculate(piles,speed);

            if(hours > h){
                low = speed+1; // increase the speed
            }
            else if( hours <= h){
                ans = speed;
                high = speed-1;
            }        
        }
        return ans;
    }
    int calculate(vector<int>& piles, int speed){
        
        int time = 0;
        for(int i=0;i<piles.size();i++){
            time += (piles[i] % speed == 0) ? piles[i] / speed : (piles[i]/ speed)+1;
        }
        return time;
    }
};


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n= piles.size();
        int l= 1;
        int r = 1000000000;
        int ans;
        while(l <r){
            int mid = l+(r-l)/2;
            int count=0;
            for(int pile:piles){
                count += ceil(1.0 * pile / mid);
            }
            if(count >h)
                l= mid+1;
            else 
                r= mid;
        }
        return l;
    }
};


// @lc code=end


int main(){
    Solution sol;
    vector<int> piles={3,6,7,11};
    int h=8;
    int ans= sol.minEatingSpeed(piles,h);
    cout<<ans;
    return 0;
}