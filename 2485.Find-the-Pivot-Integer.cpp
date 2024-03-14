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
    int pivotInteger(int n) {
        int sum = n*(n+1)/2;
        int lsum = 0;
        for(int i=1; i<=n; i++){
            lsum += i;
            if(lsum ==sum)
                return i;
            sum -= i;
        }
        return -1;
    }
};  


class Solution0 {
public:
    int pivotInteger(int n) {
        int ans ;
        int sum = 0;
        for(int i=1; i<=n; i++){
            sum+= i;
            int temp = 0;
            for(int j=i; j<=n; j++){
                temp += j;
            }
            if(sum==temp){
                return i;
            }
        }
        return -1;
    }
};


class Solution1 {
public:
    int pivotInteger(int n) {
        int l = 1;
        int r = n;
        int sum = (n*(n+1))/2;
       
        while(l<=r){
            int mid = l+(r-l)/2;
            int sum1 = (mid*(mid+1))/2;
            // mid num is used in both sides 
            int sum2 = sum - sum1 + mid;

            if(sum1==sum2){
                return mid;
            }
            else if(sum1 < sum2){
                l = mid+1;
            }
            else 
                r = mid-1;
        }
        return -1;
    }
};


class Solution {
public:
    int pivotInteger(int n) {
        if(n==1) 
            return n;

        vector<int> v;
        int sum = 0;

        for(int i=1; i<=n; i++) {
            v.push_back(i);
        }

        vector<int> res;

        for(int i=0; i<n; i++) {
            sum += v[i];
            res.push_back(sum);
        }

        int totalSum = sum; 
        sum = 0;

        for(int i=0; i<n; i++) {
            if(sum==totalSum-sum-v[i]) {
                return i + 1; 
            }
            sum += v[i];
        }

        return -1;  
    }
};

int main(){

    return 0;
}