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


class Solution0 { // O(N^2)
public:
    int setBitCount(int num){
        int cnt = 0;
        while(num){
            if(num&1){
                cnt++;
            }
            num = num>>1;
        }
        return cnt;
    }
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        // must be adjacetn and have same set bit then only we can swap 
        // brute force like bubble sort
        for(int i=1; i<n; i++){
            for(int j=0; j<n-i; j++){
                if(nums[j]<=nums[j+1]) // already sorted
                    continue;
                else{
                    if(setBitCount(nums[j])==setBitCount(nums[j+1])){
                        swap(nums[j], nums[j+1]);
                    }
                    else
                        return false;
                }
            }
        }
        return true;
    }
};

// all the same bit cnt number if placed together ie adjacent then only they can be swapped

// divide into segements based on the setbit cnt  
// if the prev segment mx is greter than the curr segment min that means the swap or sorting isnt possible so return false. eg -> 3 2 

class Solution { 
public:
    int setBitCnt(int num){
        int cnt = 0;
        while(num){
            if(num&1){
                cnt++;
            }
            num = num>>1;
        }
        return cnt;
    }
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int curmx = nums[0];
        int curmn = nums[0];
        int prevBitCnt = setBitCnt(nums[0]);
        int prevmx = INT_MIN;

        int i = 1;
        while(i<n){
            // till the set bit cnt is equal for the adjacent elemts 
            while(i<n && setBitCnt(nums[i])==prevBitCnt){
                curmx = max(curmx, nums[i]);
                curmn = min(curmn, nums[i]);
                i++;
            }

            if(prevmx > curmn) // no swap can be done its false
                return false;
            else if(i<n){ // now shift to the next segment 
                prevmx = curmx;
                curmx = nums[i];
                curmn = nums[i];
                prevBitCnt = setBitCnt(nums[i]);
            }
        }
        return true;
    }
};

int main(){

    return 0;
}