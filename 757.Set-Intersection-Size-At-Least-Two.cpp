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
    static bool check(vector<int> a, vector<int> b){
        if(a[1]==b[1])
            return a[0]>b[0]; // descending order on first elem
        return a[1]<b[1]; // increasing order on second elem
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // sort on basis on second elme, when second elem same take the first greateer elem
        int cnt = 2; // starting limit have to take its last two elem to saet the first and second max range 
        sort(intervals.begin(), intervals.end(), check);

        vector<int> mx(2,0);
        // we take last two elem of the first range for our comparision of next range 
        mx[0] = intervals[0][1]-1; // second_max
        mx[1] = intervals[0][1]; // first_max

        for(int i=1; i<n; i++){
            // (s,e) -> the s is greater than first_max , so we have to add 2 new values and change first and second max
            if(mx[1]<intervals[i][0]){
                cnt+=2;
                mx[0] = intervals[i][1]-1;
                mx[1] = intervals[i][1];
            }
            else if(mx[0]<intervals[i][0]){ // (s,e)-> the s is smaller or equal than first_max, so we check wether it is also small then second_max, then its in the same range 
            // but if the s is greater than second_max, that means we have to add only one number cause one is alredy there in set 
                cnt+=1;
                // (s,e) , e is included but we have to one more val in set 
                mx[0]= mx[1];
                mx[1] = intervals[i][1];
            }
        }
        return cnt;
    }
};



int main(){

    return 0;
}