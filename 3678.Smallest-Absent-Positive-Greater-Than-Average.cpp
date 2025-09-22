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
    int smallestAbsent(vector<int>& nums) {
        int n = nums.size();
        double sum = 0;
        for(int num: nums){
            sum+=num;
        }
        double avg = sum/n;
        int val = 1;
        while(true){
            if(val>avg && find(nums.begin(), nums.end(), val)==nums.end()){
                return val;
            }
            val++;
        }
    }
};


int main(){

    return 0;
}