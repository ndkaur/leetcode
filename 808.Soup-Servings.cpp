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
    double f(double A , double B, vector<pair<int,int>>& serve, vector<vector<double>>& dp){
        if(A<=0 && B<=0)
            return 0.5;
        if(A<=0)
            return 1;
        if(B<=0)
            return 0.0;

        if(dp[A][B]!=-1.0){
            return dp[A][B];
        }

        double prob = 0.0;
        for(auto s:serve){
            int a = s.first;
            int b = s.second;
            prob += f(A-a, B-b, serve,dp);
        }

        return dp[A][B]=0.25*prob;
    }
    double soupServings(int n) {
        if(n>=5000)
            return 1;
        vector<pair<int,int>> serve = {{100,0},{75,25},{50,50},{25,75}};
        // even if we simply memoize it will be O(N^2) , and will give memory limit exceeded 
        // but if e notice that all the value of the N is increasing more are the chances of A getting empty fast as compared to B. 
        // cause in one case A can be 100 but B can never be 100 
        // so we directly take rough idea for large value of N and hardcode it be returning 1
        vector<vector<double>>dp(n+1, vector<double>(n+1, -1.0));
        return f(n,n, serve, dp);
    }
};

// the main answer only depends on prob of A being empty 
// when A is empty -> probability =1 
// when A and B both are empty-> pobaability = 1/2 = 0.5
// when B is empty -> probabailty = 0.0 
// ans = 0.25 *(p1+p2+p3+p4)


int main(){

    return 0;
}