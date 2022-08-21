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
    int minimumRecolors(string blocks, int k) {
        int n= blocks.size();
        int mn=INT_MAX;
        for(int i=0; i<=n-k; i++){
            int cnt=0;
            for(int j=i; j<i+k; j++){
                if(blocks[j]=='W')
                    cnt++;
            }
            mn= min(mn, cnt);
        }
        return mn;
    }
};


class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n= blocks.size();
        int mn=INT_MAX;
        int i=0;
        int j=0;
        int cnt=0;
        while(j<n){
            if(blocks[j]=='W')
                cnt++;
            if(j-i+1 >= k){
                mn = min(mn, cnt);
                if(blocks[i]=='W')
                    cnt--;
                i++;
            }
            j++;
        }
        return mn;
    }
};

int main(){

    return 0;
}