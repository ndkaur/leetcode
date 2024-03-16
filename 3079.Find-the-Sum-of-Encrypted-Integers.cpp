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
    int find(int num){
        int sum = 0;
        int len  = 0;
        int mx = 0;
        // 10 
        while(num){
            int rem = num%10;
            mx = max(mx, rem);
            num = num/10;
            len++;
        }
        int temp = 0;
        for(int i=1; i<=len; i++){
            temp  = temp*10+mx;
        }
        return temp;
    }
    int sumOfEncryptedInt(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            int lar = find(nums[i]);
            sum += lar;
        }
        return sum;
    }
};

int main(){

    return 0;
}