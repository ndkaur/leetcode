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


class Solution0 {
public:
    bool isunique(int num){
        set<int> st;
        while(num){ 
            int rem = num%10;
            if(st.find(rem)!=st.end()){ // val already exist in set
                return false;
                break;
            }
            st.insert(rem);
            num = num/10;
        }
        return true;
    }
    int numberCount(int a, int b) {
        int cnt= 0;
        for(int i=a; i<=b; i++){
            if(isunique(i)){
                cnt++;
            }
        }
        return cnt;
    }
};



class Solution {
public:
    bool isunique(int num){
        set<int> st;
        while(num){ 
            int rem = num%10;
            if(st.find(rem)!=st.end()){ // val already exist in set
                return false;
                break;
            }
            st.insert(rem);
            num = num/10;
        }
        return true;
    }
    int numberCount(int a, int b) {
        vector<int> dp(b+1);

        for(int i=1; i<=b; i++){
            if(isunique(i)){
                dp[i] = dp[i-1]+1;
            }
            else{
                dp[i] =  dp[i-1];
            }
        }
        return dp[b] - dp[a-1];
    }
};

// 11, 22, 33 , ...999
// 111,112,..120, 
// 100, 200,..... 1000

int main(){

    return 0;
}