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

class Solution0 {
public:
    
    long long flowerGame(int n, int m) {
        long long oddcntn = (n+1)/2;
        long long oddcntm = (m+1)/2;
        
        long long evencntn = n/2;
        long long evencntm = m/2;
        
        long long ans = oddcntn * evencntm + evencntn * oddcntm;
        return ans;
    }
};

// n=3, m=2
// oddn = 2 , oddm=1
// evenn = 1, evenm = 1
//  ans = 2*1+1*1=2+1=3

class Solution {
public:
    
    long long flowerGame(int n, int m) {
        long long a = m;
        long long b = n;
        long long s = a*b;
        return s/2;
    }
};

// clock = 1 , anti = 3 ,   bob will win 
// anti= 4, clock = 1 ,  alice will win 
//  anti =2, clock = 2,   bob will win  
//  so we can see that when sum is odd eg 4+1 = 5 , odd sum = alice win 
// even sum = bob win (2+2 , 3+1) 
//  to find total possiblitities of alice winning ie odd sum cases 
//  eg n=3, m=3  odd cases (1,2),(2,1),(3,2),(2,3)  = 4 ans =4 
// so total cases /2   , n*m/2



class Solution0 { // brute force // tle 
public:
    long long flowerGame(int n, int m) {
        int cnt =0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if((i+j)%2!=0)
                    cnt++;
            }
        }
        return cnt;
    }
};

// so alice start and pick one flower form any lane, 
// winner is the person who picks the flower and after he picks both the lanes are empty 
// n= 3, m=2  totalsum = 5
// (1,1)->2   (1,2)->3
// (2,1)->3   (2,2)->4
// (3,1)->4   (3,2)->5 

// valid pairs = (1,2) (3,2) (2,1) all have odd sum , so when sum of the pair is odd then only alice will win

// n=1, m=1  sum = 2
// pair = (1,1)->2   alice pick, bob pick, then epty and bob wins
 


class Solution {  
public:
    long long flowerGame(long long n, long long m) {
        return m*n/2;
    }
};


//odd sum will be made (even odd) (odd even)
// when value is even then its exact half of total = total/2
// when value is odd then -> total/2 + total%2 
// eg= 5 (1,2,3,4,5) even =2 , odd=3
// ans = even*odd + odd*even
// n/2 * (m/2 + m%2) + (n%2 + n/2) * m/2
// reducing it to (n*m)/2

int main(){

    return 0;
}