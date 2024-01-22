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
    int minimumPushes(string word) {
        int n = word.size();
        int ans=0;

        for(int i=0; i<n; i++){
            if(i<=7) // 8
                ans += 1;
            else if(i<=15){ // 16
                ans+=2;
            }
            else if(i<=23){ //24
                ans+=3;
            }
            else 
                ans+=4;
        }
        return ans;
    }
};


//total 8 places can be used
// if the length is less than or queal to 8 we can place each char at the start of each of the 8 keys 
// if it exceeds ie less than 16 , we need to double click to reach at that position of char 
// if the index exceeds 24 then we need to triple click to reach at that position of the char 
// but still we can see that some keys have 4 chars so needs to click 4 times  



int main(){

    return 0;
}