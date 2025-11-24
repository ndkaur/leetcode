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
    void findBinary(int n, vector<int>& temp){
        if(n==0){
            temp.push_back(0);
            return;
        }
        while(n>0){
            if(n&1){
                temp.push_back(1);
            }
            else 
                temp.push_back(0);
            n= n>>1;
        }
    }
    int minimumFlips(int n) {
        vector<int> temp;
        findBinary(n, temp);
        
        vector<int> rev= temp;
        reverse(temp.begin(), temp.end());
        
        int cnt = 0;
        for(int i=0; i<temp.size(); i++){
            if(temp[i]!=rev[i])
                cnt++;
        }
        return cnt;
    }
};


int main(){

    return 0;
}