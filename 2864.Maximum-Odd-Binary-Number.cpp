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
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int cnt1 =0;
        int cnt0=0;
        for(int i=0; i<n; i++){
            if(s[i]=='1')
                cnt1++;
            else 
                cnt0++;
        }
        //eg-> 0101 cnt1 =2 , cnt0 =2,   1001 
        // eg-> 010, cnt1=1 , cnt0 =2 , 001
        string ans = string(cnt1-1, '1') + string(cnt0, '0') + '1';
        return ans;
    }
};


class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.rbegin(),s.rend());
        for(int i = s.size()-1;i>=0;i--){
            if(s[i]=='1')swap(s[i],s[s.size()-1]);
        }
        return s;
    }
};

// 0101 -> sort descending order-> 1100 , swap , 1001


class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int cnt =0;
        string ans = "";
        for(int i=0; i<n; i++){
            if(s[i]=='1')
                cnt++;
            ans+= '0';
        }
        // put 1 in the staring and save 1 to add at the end 
        for(int i=0; i<cnt-1; i++){
            ans[i] ='1';
        }
        ans[n-1]= '1';
        return ans;
    }
};

int main(){

    return 0;
}