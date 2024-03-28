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
    int brokenCalc(int start, int target) {
        int cnt = 0;
        while(start<target){
            cnt++;
            if(target%2==0){
                target = target/2;
            }
            else{
                target+=1;
            }
        }
        cnt += start-target;
        return cnt;
    }
};

// 2<3, cnt=1  3+1= 4 , cnt=2 , 4/2 = 2 , cnt = 2-2 = 0
// 5<8, cnt=1 , 8/2 = 4, 5>4 ,  cnt = 1 + 5-4 = 2
// 3<10, cnt=1 10/2= 5, cnt=2, 5+1 = 6, cnt=3 6/2 = 3 ,  3-3 = 0 cnt=3 

int main(){

    return 0;
}