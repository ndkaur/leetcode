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
    bool isPrime(int num){
        if(num<=1)
            return false;
        for(int i=2; i<=num/2; i++){
            if(num%i==0)
                return false;
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size();
       
        int first = -1;
        int  last = -1;

        for(int i=0; i<n; i++){
            if(isPrime(nums[i])){
                if(first==-1){
                    first=i;
                }
                last = i;
            }
        }

        return last-first;
    }
};


int main(){

    return 0;
}