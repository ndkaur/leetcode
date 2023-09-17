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
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int mx =0;
        for(auto metal:composition){
            int cnt = search(metal,budget,stock,cost);
            mx = max(mx, cnt);
        }
        return mx;
    }

    int search(vector<int>& metal, int budget, vector<int>& stock, vector<int>& cost){
        long l=0;
        long r = (long)1e9;
        long cnt=0;

        while(l<=r){
            long mid = l+(r-l)/2;
            if(possible(mid,metal,budget, stock, cost)){
                cnt = mid;
                l = mid +1;
            }
            else 
                r= mid-1;
        }
        return (int)cnt;
    }

    bool possible(long mid, vector<int>& metal,int budget, vector<int>&stock, vector<int>& cost){
        long sum =0;

        for(int i=0; i<metal.size(); i++){
            // toal we have = mid * metal[i]
            // present in stock = stock[i]
            long need = mid*metal[i] - stock[i];
            if(need>0)
                sum += need * cost[i];

            if(sum>budget)
                return false; 
        }
        return sum<=budget;
    }
};

// values of mid 
// for composition[0]
500000000
249999999
124999999
62499999
31249999
15624999
7812499
3906249
1953124
976561
488280
244139
122069
61034
30516
15257
7628
3813
1906
952
475
237
118
58
28
13
6
2
4
3
// composition[1]
500000000
249999999
124999999
62499999
31249999
15624999
7812499
3906249
1953124
976561
488280
244139
122069
61034
30516
15257
7628
3813
1906
952
475
237
118
58
28
13
6
2
0
1

int main(){

    return 0;
}