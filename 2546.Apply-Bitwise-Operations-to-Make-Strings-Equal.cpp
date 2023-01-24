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
    bool makeStringsEqual(string s, string target) {
        if(s == target)
            return true;
        // if all digits are 0 and there is no count of 1 
        // so we cnat convert any 0 into 1
        int s_cnt_zero = 0;
        int s_cnt_one = 0;
        int tar_cnt_zero = 0;
        int tar_cnt_one = 0;

        for(auto itr:s){
            if(itr == '0')
                s_cnt_zero++;
            else 
                s_cnt_one++;
        }

        for(auto itr:target){
            if(itr == '0')
                tar_cnt_zero++;
            else 
                tar_cnt_one++;
        }
        // 0's are present and 1's are not present 
        if((s_cnt_zero && !s_cnt_one) || (tar_cnt_zero && !tar_cnt_one))
            return false;
        return true;
    }
};

int main(){

    return 0;
}