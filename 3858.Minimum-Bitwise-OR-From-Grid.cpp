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


class Solution { //O(32*n*m)
public:
    int minimumOR(vector<vector<int>>& grid) {
        int ans = 0; // store of bits that cnt be made 0, and have to keep them
        int forbid = 0; // store for bits that we can make 0

        for(int bit=31; bit>=0; bit--){
            forbid = forbid | (1<<bit);
            bool unavoidable = false;
            // checking each elm of row
            for(auto row:grid){
                bool canReplace = false;
                for(int val:row){
                    // if the res of any num girves 0 then we can skip that bit     
                    if((forbid & val)==0){
                        canReplace = true;
                        break;
                    }
                }
                if(!canReplace){ // result of & is 1, have to take it
                    unavoidable = true;
                    break;
                }
            }
            // for the current bit we caheck each elm of each row, and if its not posisble to avoid it , then we have to take it in ans as 1 
            // forbid only keep those bits as set which need to be removed from ans , and if curr bit needs to be taken in ans we need to rmeove it from forbid
            if(unavoidable){
                // remove the curr bit from forbid
                // xor supports diff, forbid = 110 , bit 010
                // 110 ^ 010 = 100
                forbid = forbid ^ (1<<bit);
                // add that bit in ans
                ans = ans | (1<<bit);
            }
        }
        return ans;
    }
};

// we try to remove the msb which is not needed
// we take the forbiden bit and check with each elem of each row, and if that any of the elm  make it possible for us to not take it , gives us 0 when & then we keep it in forbid

// if it becomes necessary to take that bit , then we keep it in res 


int main(){

    return 0;
}