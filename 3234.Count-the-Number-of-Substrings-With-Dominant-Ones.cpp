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


class Solution { // o(n^2)
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        // we can precompute the no of 1 so to save time 
        vector<int> oneCnt(n,0);
        oneCnt[0] = (s[0]=='1') ? 1 : 0;
        for(int i=1; i<n; i++){
            oneCnt[i] = oneCnt[i-1] + ((s[i]=='1') ? 1 : 0);
        }

        // no of one's inbetween 2 particular indexes i->j
        // oneCnt[j]-oneCnt[i-1];

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int one = oneCnt[j] - (i-1>=0 ? oneCnt[i-1] : 0);
                int zero = (j-i+1) - one; // total lenght - ones

                // 1st case not possible then skip
                if((zero*zero> one)){
                    int skip = (zero*zero)-one;
                    j+= skip-1; // doing -1 cause the j loop also gonna do j++ after this if condition 
                }
                else if((zero*zero)==one){ // 2nd case when exactly equal
                    ans++;
                }
                else{ // 3rd case, when greater and check how far it stays valid
                    ans++;
                    int k = sqrt(one)-zero;
                    int next = j+k;

                    if(next>=n){ // valid upto last index , then take all remaining elmts
                        ans += n-j-1;
                        break; // this will save us some iterations         
                    }
                    else {
                        ans+=k;
                    }

                    j= next;
                }
            }
        }
        return ans;
    }
};

//  we have three cases 
// 1. zero^2 > onecnt ...not possible then simply skip those values of j 
//2 zero^2 == onecnt -> ans++
// 3.  zero^2 < onecnt , this is possible but we try to check that how much more we can extend j till it stays possible under condition 
// zero*zero <= onecnt
// zerocnt <= SqrtRoot(onecnt)
// now how much can we add for still condition to be valid 
// zerocnt + k <= SqrtRoot(onecnt)
// k = SqrtRoot(onecnt)- zerocnt



int main(){

    return 0;
}