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
    int totalMoney(int n) {
        int mon=1;
        int ans = 0;
        int val = n/7;
        int rem = n%7;
        while(val){
            for(int i=mon; i<=mon+6; i++){
                ans += i;
            }
            val--;
            mon++;
        }
        int i=mon;
        while(rem--){
            ans+=i;
            i++;
        }
        
        return ans;
    }
};


class Solution {
public:
    int totalMoney(int n) {
        int res = 0;
        for (int i = 1, c = 1; i <= n; i++, c++) {
            res += c;
            c = i % 7 ? c : (i / 7);
        }
        return res;
    }
};
// i=1 , c= 1  n =10
// res = 1  , c= 1
//  i=2 , c=2, res = 1+2 , 
//i=3, c=3, res = 1+2+3  
//i=4 c=4 res = 1+2+3+4
//i=5 c=5 res = 1+2+3+4+5
//i=6 c=6 res =1+2+3+4+5+6
// i=7 c=7 res = 1+2+3+4+5+6+7   7%7 ==0 so c=i/7 = 7/7 = c=1 
// i= 8 , c=2 , res = (1+2+3+4+5+6+7) + (2)
//i=9 , c= 3  res = (1+2+3+4+5+6+7) + (2+3)
//i=10 , c= 4 res = (1+2+3+4+5+6+7) + (2+3+4) =37



class Solution0 {
public:
    int totalMoney(int n) {
        int week_count = n / 7;
        int remaining_days = n % 7;
        
        int total = ((week_count * (week_count - 1)) / 2) * 7; // Contribution from complete weeks
        total += week_count * 28; // Contribution from complete weeks (additional on Mondays)
        total += ((remaining_days * (remaining_days + 1)) / 2) + (week_count * remaining_days); // Contribution from remaining days
        
        return total;
    }
};

// n = 10 
// wc = 10/7= 1 
// rd = 10%7 = 3 
// t = 1*0 = 0 
// t = 1 *28 = 28
// t +=  3*2 + 1*3 = 6+3 = 9
// 28+9 =37 


int main(){

    return 0;
}