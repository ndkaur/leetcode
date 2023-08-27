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
    long long minimumPossibleSum(int n, int target) {
        set<long long> s1;
        long long sum =0;
        int i =1;
        while(s1.size()<n){
            long long diff = target-i;
            if(s1.find(diff)==s1.end()){
                s1.insert(i);
               sum += i;
            }
            i++;
        }
        
        return sum;
    }
};

int main(){

    return 0;
}