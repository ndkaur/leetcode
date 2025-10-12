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
    int maximumEnergy(vector<int>& energy, int k) {
        int n= energy.size();
        int sum =0;
        int mx = -1e9;
        vector<int> visited(n,0);
        for(int i=0; i<n; i++){
            if(visited[i])
                continue;
            int j = i;
            sum=0;
            while(j<n){
                visited[j]=1;
                sum += energy[j];
                sum = max(sum, energy[j]);
                j+=k;
            }
            mx = max(mx, sum);
        }
        return mx; 
    }
};


int main(){

    return 0;
}