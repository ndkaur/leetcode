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
    int splitNum(int num) {
        vector<int> arr;
        while(num){
            int rem = num%10;
            arr.push_back(rem);
            if(num>0){
                num = num/10;
            }
        }
        sort(arr.begin(), arr.end());
        int n = arr.size();
        // 2 3 4 5 ->
        // 6 7 8 ->
        int n1=0;
        int n2 =0;
        for(int i=0; i<n; i+=2){
            n1 = n1 * 10 + arr[i];
        }
        for(int i=1; i<n; i+=2){
            n2 = n2 *10+arr[i];
        }
        return n1+n2;
    }
};


int main(){

    return 0;
}