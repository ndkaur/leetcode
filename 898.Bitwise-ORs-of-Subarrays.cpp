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


// time complexity -> O(N)-> N can be the size of 32 bits
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> all_possible;
        unordered_set<int> or_prev;
        unordered_set<int> or_ending_here;

        for(int i=0; i<n; i++){
            or_ending_here.clear();
            // the indival number also is the or 
            or_ending_here.insert(arr[i]);
            
            // doing or of the curr value with the prev stored values
            for(int val:or_prev){
                or_ending_here.insert(val|arr[i]);
            }

            all_possible.insert(or_ending_here.begin(), or_ending_here.end());
            or_prev = or_ending_here;
        }
        return all_possible.size();
    }
};

// property of or -> when e or two nubers the resulting value only increases 
// prev OR contribute next OR 
// 1 2 4

// or_ending_here =  1 .. 2,3.. 4, 6,7
// or_prev = 1..2,3.... 4,6,7
// all_ possible_or = 1,2,3, 4,6,7
// so in the end the set size is 6 



int main(){

    return 0;
}