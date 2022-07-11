/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

// @lc code=start
class MyCircularQueue {
    vector<int> arr;
    int size;
    int front;
    int back;
public:
    MyCircularQueue(int k) {
        arr.clear();
        arr.resize(k,-1);
        size=k;
        front= back=-1;
    }
    // push
    bool enQueue(int value) {
        if(isFull())
            return false;
            // first element
        if(front==-1){
            arr[0]= value;
            front=0;
            back=0;
            return true;
        }
        //  last ele
        if(back==size-1){
            back=0; // circular queue
            arr[back]= value;
            return true;
        }
        else{
            back++;
            arr[back]= value;
            return true;
        }
    }
    //  pop in q is from front 
    bool deQueue() {
        if(isEmpty())
            return false;
        //  only one ele present at starting position
        if(front==back){
            front=-1;
            back=-1;
            return true;
        }
        // last element
        if(front==size-1){
            front=0; // circular queue
            return true;
        }
        else{
            front++;
            return true;
        }
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        else{
            return arr[front];
        }
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        else 
            return arr[back];
    }
    
    bool isEmpty() {
        if(front==-1)
            return true;
        else 
            return false;
    }
    
    bool isFull() {
        if(back==size-1) // back reached end 
            return front==0;
        else 
            return back==front-1; // one circle completed of back and is one ele behind front
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

