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
    bool isPrime(int n){
        if(n<=1)
            return false;
        for(int i=2; i<=sqrt(n); i++){
            if(n%i==0)
                return false;
        }
        return true;
    }
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int n= mat.size();
        int m= mat[0].size();
        unordered_map<int,int> mp;
        vector<pair<int,int>> dirs ={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(auto dir:dirs){
                    int val = mat[i][j];
                    int ni = i + dir.first;
                    int nj = j + dir.second;
                    while(ni>=0 && ni<n && nj>=0 && nj<m){
                        val = val*10 + mat[ni][nj];
                        if(val>10){
                            if(isPrime(val)){
                                mp[val]++;
                            }
                        }
                        ni = ni+dir.first;
                        nj = nj+dir.second;
                    } 
                }
            }
        }
        if(mp.size()==0)
            return -1;
        
        int freq =0;
        int ans;
        for(auto itr:mp){
            if(itr.second>=freq){
                if(freq==itr.second) // smae nums have sam freq use the greater num
                    ans = max(ans, itr.first); 
                else{
                    freq = itr.second;
                    ans = itr.first;
                }
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}