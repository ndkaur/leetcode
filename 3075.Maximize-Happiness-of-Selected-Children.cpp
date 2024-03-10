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
    long long maximumHappinessSum(vector<int>& hap, int k) {
        int n = hap.size();
        long long ans = 0;
        sort(hap.begin(), hap.end(), greater<int>());
        int j=0;
        for(int i=0; i<k; i++){
            if(j<hap[i])
               ans+= hap[i]-j;
            j++;
        }
        return ans;
    }
};

// everytime j is reducing the not chossen hapines values 
// 

int main(){

    return 0;
}