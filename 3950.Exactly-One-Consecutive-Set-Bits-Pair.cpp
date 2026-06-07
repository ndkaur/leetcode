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
    bool consecutiveSetBits(int n) {
        string bin="";
        if(n==0)
            return false;
        while(n>0){
            int bit = n%2;
            bin.push_back('0'+bit);
            n = n/2;
        }
        reverse(bin.begin(), bin.end());

        int cnt = 0;
        for(int i=0; i<bin.size()-1; i++){
            if(bin[i]=='1' &&  bin[i+1]=='1'){
                cnt++;
            }
        }
        if(cnt==1)
            return true;
        return false;
    }
};


class Solution {
public:
    bool consecutiveSetBits(int n) {
        int set =0;
        int cnt =0;
        while(n>0){
            int bit = n&1;
            n= n>>1;
            if(bit==1)
                set++;
            else 
                set=0;
            if(set>=2)
                cnt++;
            
        }
        return cnt==1;
    }
};



int main(){

    return 0;
}