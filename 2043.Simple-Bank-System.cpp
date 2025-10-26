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


class Bank {
public:
    vector<long long> accounts; // 1 based indexing
    int numAccounts;

    Bank(vector<long long>& balance) {
       int n = balance.size();
       accounts.resize(n+1);

        for(int i=1; i<=n; i++){
            accounts[i] = balance[i-1];
        }
        numAccounts = n;
    }   
    
    bool transfer(int account1, int account2, long long money) {
        if(!withdraw(account1, money))
            return false;
        if(!deposit(account2, money)){ // the account in which money is to be added if that  doesnot exist then we have alredy withdrawn so we have to rool back and deposit the withdrawn amount
            deposit(account1, money);
            return false;
        }
        return true;

    }
    
    bool deposit(int account, long long money) {
        if(account>numAccounts){ // checking if its valid ie the account exist 
            return false;
        }
        accounts[account]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        // not vald or the money not present 
         if (account > numAccounts || accounts[account] < money) {
            return false;
        }

        accounts[account] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */


int main(){

    return 0;
}