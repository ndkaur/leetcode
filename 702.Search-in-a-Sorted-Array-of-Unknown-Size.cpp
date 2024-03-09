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


/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int find(ArrayReader reader, int target, int l, int r){
        while(l<=r){
            int mid = l+(r-l)/2;
            if(reader.get(mid)>target){
                r = mid-1;
            }
            else if(reader.get(mid)<target){
                l = mid+1;
            }
            else 
                return mid;
        }
        return -1;
    }
    int search(const ArrayReader& reader, int target) {
        int l = 0;
        int r = 1;

        while(reader.get(r)<target){
            l = r;
            r = 2*r;
        }
        return find(reader, target, l, r);
    }
};


int main(){

    return 0;
}