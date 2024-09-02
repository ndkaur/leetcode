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


class ParkingSystem {
public:
    vector<int>vehicle;
    ParkingSystem(int big, int medium, int small) {
        vehicle = {big, medium, small};
        //         0      1      2
    }
    
    bool addCar(int carType) {
        if(vehicle[carType-1]!=0){ // 0 base indexing 
            vehicle[carType-1]--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */


int main(){

    return 0;
}