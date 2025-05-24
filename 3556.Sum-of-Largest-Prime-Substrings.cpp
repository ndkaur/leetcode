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
      bool checkPrime(long long n) {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for(long long i = 3; i*i<=n; i+=2) {
            if (n % i == 0) 
                return false;
        }
        return true;
    }

    long long sumOfLargestPrimes(string s) {
        int n = s.size();
        unordered_set<long long> st;
        for(int i=0; i<n; i++){
            string str="";
            for(int j=i; j<n; j++){
                str+=s[j];
                long long num = stoll(str);
                if(checkPrime(num)){
                    st.insert(num);
                }
            }
        }
        // for(auto num:temp){
        //     cout<<num<<" ";
        // }
        vector<long long> temp(st.begin(), st.end());
        sort(temp.rbegin(), temp.rend());
       
        long long sum =0;
        for(int i=0; i<min(3,(int)temp.size()); i++){
            sum+= temp[i];
        }
        return sum;
    }
};




int main(){

    return 0;
}