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
    string help(int num, vector<string>& ones, vector<string>& tens, vector<string>& thousands){
        if(num<20){
            return ones[num]; // print directly 
        }

        if(num<100){ 
            // 98 -> ninenty eight 
            // nienty -> tens will handle 
            // eight -> with recursion in ones array 
            // seperate single number from total num
            int rem = num%10; // 8
            int val = num/10; // 9
            return tens[val] + help(rem, ones, tens, thousands);
        }

        if(num<1000){
            // eg = 100 
            // 100/100 = 1 
            // [num/100] + hundred + rem= num%100
            // 222 -> 2 + hundred +  help(rem = 22)
            return help(num/100,ones, tens, thousands) + " Hundred" + help(num%100, ones, tens, thousands);
        }
        
        // rest all the remaining groups would be made using thousands 
        for(int i=3; i>=0; i--){
            if(num>=pow(1000, i)){
                // now to divide with what will depend on the length 
                return help(num/pow(1000, i), ones, tens, thousands) + thousands[i] + help(num%(int)pow(1000,i), ones, tens, thousands);
            }
        }
        return  "";
    }

    string numberToWords(int num) {
        vector<string> ones = {""," One", " Two", " Three", " Four"," Five"," Six", " Seven"," Eight"," Nine"," Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};

        vector<string> tens = {"", " Ten", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
        vector<string> thousands = {"", " Thousand", " Million", " Billion"};

        if(num==0)
            return "Zero";
        // we added spaces infront of each char so to remove space from begining of the string in our answer 
        return help(num, ones, tens, thousands).substr(1);

        // 10 lakh = 1 million
        // 100 million = 1 billion 
    }
};

int main(){

    return 0;
}