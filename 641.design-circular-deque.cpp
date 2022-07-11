/*
 * @lc app=leetcode id=641 lang=cpp
 *
 * [641] Design Circular Deque
 */

// @lc code=start
class node{
public:
    int val;
    node* next =nullptr;
    node* prev = nullptr;
};
class MyCircularDeque {
public:
    node* front;
    node* rear;
    int n , m;
    MyCircularDeque(int k) {
        n= k; // n= actual size
        m=0;  // m= the current size of list
        front = rear= NULL;
    }
    
    bool insertFront(int value) {
        if(front==NULL){ // no element in list fully empty 
            node* n= new node();
            front = n;
            rear= n;
            n->val= value;
            ++m;
            return true;
        }
        else if(m<n){ // some elements are there but not equal to actual size
            node* n= new node();
            n->val= value;
            n->next=front;
            front->prev= n;
            front= n; // front gets updated 
            ++m;
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(rear==NULL){ // no item in list fully empty 
            node* n= new node();
            front= n; 
            rear= n;
            n->val= value;
            ++m;
            return true;
        }
        else if(m<n){ // already some elements are there in list 
            node* n= new node();
            n->val= value;
            n->prev= rear;
            rear->next=n;
            rear =n;
            ++m;
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(m==0) return false; // no item in list
        --m; // reduce the curr size 
        node* toDelete = front;
        front= front->next;
        if(m==0) 
            rear = nullptr;
        else 
            front->prev=nullptr;
        toDelete-> next= nullptr;
        delete toDelete;
        return true;
    }
    
    bool deleteLast() {
        if(m==0) return false;
        --m;
        node* toDelete= rear;
        rear= rear->prev;
        if(m==0)
            front =nullptr;
        else 
            rear->next=nullptr;
        toDelete->prev= nullptr;
        delete toDelete;
        return true;
    }
    
    int getFront() {
        if(m==0) 
            return -1;
        return front->val;
    }
    
    int getRear() {
        if(m==0)
            return -1;
        return rear->val;
    }
    
    bool isEmpty() {
        return (m==0);
    }
    
    bool isFull() {
        return (m==n);
    }
};


class MyCircularDeque {
    deque<int> result;
    int size;
public:
   
    MyCircularDeque(int k) {
        size=k;
    }
    
    bool insertFront(int value) {
        if(result.size()>= size) 
            return false;
        result.push_front(value);
        return true;
    }
    
    bool insertLast(int value) {
        if(result.size()>= size)
            return false;
        result.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if(result.size()==0) 
            return false;
        result.pop_front();
        return true;
    }
    
    bool deleteLast() {
        if(result.size()==0)
            return false;
        result.pop_back();
        return true;
    }
    
    int getFront() {
        if(result.size()==0)
            return -1;
        return result.front();
    }
    
    int getRear() {
        if(result.size()==0)
            return -1;
        return result.back();
    }
    
    bool isEmpty() {
        if(result.size()==0) return true;
        return false;
    }
    
    bool isFull() {
        if(result.size()==size) 
            return true;
        return false;
    }
};


//  using array 
class MyCircularDeque {
    vector<int> arr;
    int size;
    int front=-1;
    int back=-1;
public:
   
    MyCircularDeque(int k) {
        arr.resize(k);
        size=k;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        //  first ele to be inserted
        if(isEmpty())  
            front= back=0;
        else
            front=(front-1+size)%size;
        arr[front]= value;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        if(isEmpty()) 
            front= back=0;
        else 
            back= (back+1)%size;
        arr[back]= value;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        else if(front==back) 
            front= back=-1;
        else 
            front =(front+1)%size;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        else if(front==back)
            front= back= -1;
        else    
            back= (back-1+size)%size;
        return true;
    }
    
    int getFront() {
        if(isEmpty())
            return -1;
        return arr[front];
    }
    
    int getRear() {
        if(isEmpty())
            return -1;
        return arr[back];
    }
    
    bool isEmpty() {
        if(front==-1 && back==-1)
            return true;
        return false;
    }
    
    bool isFull() {
        if((back+1)%size == front)
            return true;
        return false;
    }
};


/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

