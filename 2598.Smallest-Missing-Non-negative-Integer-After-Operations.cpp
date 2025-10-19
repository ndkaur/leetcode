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
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        vector<int> freq(value+1,0); // 0 1, 2 

        for(int num:nums){
            int number = abs(num);
            int modd = number%value;
            // +ve num or the mod is 0(we keep cnt of 0 also)
            if(num>=0 || modd==0){
                freq[modd]++;
            }
            else{ // num is -ve  then mod val is val-modd
                freq[value-modd]++;
            }
        }

        // finding the missing +ve integer
        for(int i=0; i<n; i++){ // 0, 1, 2,3
            int modd = i%value;
            if(freq[modd]==0)
                return i;
            freq[modd]--;
        }
        return n;
    }
};

// 1 -10   7 13 6 8   val= 5
// 1  5,0  2 3  1 3    num%val; 
// if num is -ve => res = abs(num)%val  then  val-res 
// edge case when its -10  abs(10)%5= 0 so we will cnt 0 as well as (5-0)= 5 

// maintin a freq array that keep tracks of all mod value , then check one by one which mod value doesnot exist 


// [3,0,3,2,4,2,1,1,0,4]  val = 5, ans = 10
// if we loop dorectly like i->n , and freq[i] then ans = 5 which is wrong 
// but if we lopp i->n and freq[modd]  , modd = i%val then ans = 10 




int main(){

    return 0;
}