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
    bool check(int num1, int num2){
        string val1 = to_string(num1);
        string val2 = to_string(num2);

        // case :- 3 , 30 , one less length , add 0 
        // add 0 the times the length is smaller
        while(val1.size()<val2.size()){
            val1 = "0" + val1;
        }
        while(val2.size()<val1.size()){
            val2 = "0" + val2;
        }

        // for the swap to be done and make the nums equal 
        // only two integers must be at unequal positions
        int diff = 0;
        int first = -1;
        int second = -1;

        for(int i=0; i<val1.size(); i++){
            if(val1[i]!=val2[i]){
                diff++;
                if(diff==1){
                    first = i;
                }
                else if(diff==2){
                    second = i;
                }
                else{// more than one diff then not possible to satisfy the condition
                    return false;
                }
            }
        }

        // swap in one number to check with another number 
        if(diff==2){
            swap(val1[first], val1[second]);
        }

        return val1==val2;
    }
    int countPairs(vector<int>& nums) {
        // one pair counts as one 
        int n = nums.size();
        
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i]==nums[j] || check(nums[i], nums[j])){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main(){

    return 0;
}