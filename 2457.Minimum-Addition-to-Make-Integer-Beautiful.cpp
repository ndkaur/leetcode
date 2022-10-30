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

// time limit exceedde
class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        long long original = n;
        if(n <= 9){
            if(n==target)
                return 0;
        }
        if(summ(n) == target)
            return 0;

        long long  total = summ(n);
        //467 -> 7 -> 3 467 + 3 = 470
        long long rem = n % 10;
        long long  toadd = 10 - rem ;
        n = n + toadd;
        // n= 470
        while(summ(n) > target){
            // 470+10 = 480 -> 12 >6
           if(summ(n+10) > target){
                // make the second num also zero 
                long long temp = n/10; // 480/10 = 48
                long long nrem = temp%10; // 48 % 10 = 8
                long long ntoadd = 10 - nrem; // 10 - 8 = 2
                temp = temp + ntoadd; // 48 +2 = 50
                n = temp * 10; // 500
           }
        }
        return n- original;
    }
    long long summ(long long n){
        long long  rem =0;
        long long  sum =0;
        while(n>0){
            rem = n%10;
            sum += rem;
            n = n/10;
        }
        return sum;
    }
};

class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        long long original = n;
        long long base = 1;
        // 467 -> 17 > 6 
        while(summ(n) > target){ // means have to make last digit 0 
            // 467 -> 470 -> 480 -> 490 -> 450
            // 46 + 1 = 47 -> actual this num is 470 but in sum last 0 doesnot matter 
            n = n/10 + 1; // last digit became zero  
            base = base * 10; // 1 * 10 = 10
            // 47/10 = 4+1 = 5 -> 500
        }
        return n*base - original;
    }
    long long summ(long long n){
        long long  rem =0;
        long long  sum =0;
        while(n>0){
            rem = n%10;
            sum += rem;
            n = n/10;
        }
        return sum;
    }
};



int main(){

    return 0;
}