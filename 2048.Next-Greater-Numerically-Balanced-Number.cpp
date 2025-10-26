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
    bool check(int num){
        string s = to_string(num);
        vector<int> freq(10,0);
        for(auto ch:s){
            freq[ch-'0']++;
            if(ch=='0')
                return false;
        }

        for(int i=1; i<=9; i++){
            if(freq[i]>0 && freq[i]!=i)
                return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        const int mx = 1224444;
        for(int i=n+1; i<=mx; i++){
            if(check(i))
                return i;
        }
        return -1;
    }
};



class Solution {
public:
    bool check(const vector<int>& freq){
        for(int i=1; i<=7; i++){
            if(freq[i]!=0 && freq[i]!=i)
                return false;
        }
        return true;
    }
    void generate(long num, vector<int>& freq, vector<int>& list){
        if(num>0 && check(freq)){
            list.push_back((int)num);
        }
        if(num>1224444)
            return;
        
        for(int i=1; i<=7; i++){
            if(freq[i]<i){
                freq[i]++;
                generate(num*10+i, freq, list);
                // backtrack 
                freq[i]--;
            }
        }
    }
    int nextBeautifulNumber(int n) {
        vector<int> list;
        vector<int> freq(10,0);
        generate(0, freq, list);
        sort(list.begin(), list.end());
        for(int num:list){
            if(num>n)
                return num;
        }
        return -1;
    }
};


//10000000
//44443331 <- max 
//13334444 

//3000
//3331 <- max
//3133

// 10^5 = 1000000
// 1000000
// 4444122 -> greater than 10^5 
// making it small 
// 1224444


int main(){

    return 0;
}

