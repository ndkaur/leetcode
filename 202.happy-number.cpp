/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */
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

// @lc code=start

class Solution0 { //O(logn)  O(logn)
public:
    bool isHappy(int n) {
        set<int> seen;
        while(n!=1 && seen.find(n)==seen.end()){
            seen.insert(n);
            n= getNext(n);
        }
        return n==1;
    }
    int getNext(int n){
        int sum=0;
        while(n>0){
            int rem = n%10;
            n= n/10;
            sum += rem*rem;
        }
        return sum;
    }
};

class Solution { //O(logn)  O(1)
public:
    bool isHappy(int n) {
        while(n!=1 && n!=4){
            n= getNext(n);
        }
        return n==1;
    }
    int getNext(int n){
        int sum=0;
        while(n>0){
            int rem = n%10;
            n= n/10;
            sum += rem*rem;
        }
        return sum;
    }
};


class Solution { //O(logn)  O(1)
public:
    bool isHappy(int n) {
        int slow=n;
        int fast= getNext(n);
        while(fast!=1 && slow!=fast){
            slow= getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast==1;
    }
    int getNext(int n){
        int sum=0;
        while(n>0){
            int rem = n%10;
            n= n/10;
            sum += rem*rem;
        }
        return sum;
    }
};
// @lc code=end


int main(){

    return 0;
}