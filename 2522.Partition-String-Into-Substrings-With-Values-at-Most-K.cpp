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
    int minimumPartition(string s, int k) {
        int n = s.size();
        long long prev = -1;
        long long curr = 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            prev= curr;
            curr = curr * 10 + (s[i]-'0'); // taking out num one by one 
            if(curr <= k) // if less than k and condition not breeched 
                continue;
            else if(curr > k){ 
                if(prev > k ) // if our prev is greter than k the means no continous split possible 
                    return -1;
                // if our prev is smaller than k that means we will make a partititon 
                cnt++;
                curr = s[i] - '0'; // after partition the new curr will be formed 
            }
        }
        return cnt+1;
    }
};

// s = "165462", k = 60

// cnt = 
//  prev = 0 , 1 , 16
//  curr = 1 , 1 < 60 ok 
        // 16 , 13 < 60 ok
        // 165 , 165 !< 60  not ok -> so change cnt , make partition , change curr to i 
//  cnt = 1
//  prev = 16, 54
//  curr = 5 , 54 < 60 ok 
        // 546 !<60 not om -> so cnt++, make partiton , change curr to i 

//  cnt = 2 
//  prev = 54 , 6
//  curr = 6 , 6<60 
    //    62 !< 60  , so change 

//  cnt = 3
//  prev = 6 
// curr = 2 

// cnt++  = cnt = 4

int main(){

    return 0; 
}