class Node {
public:
    int data;
    Node* next;
    //  constructor for class node 
    Node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtTail(Node* & head, int val){
    Node* n= new Node(val);
    if(head==NULL)
        head=n;
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
 
// to print list 

void display (Node* head){ // passing by value
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

void insertAtHead(Node* &head,int val){
    Node n= new Node(val);
    n->next=head;
    head=n;
}

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};

ListNode* createList(vi a){
    int n = a.size();
    if(!n) return NULL;
    ListNode *head = new ListNode(a[0]);
    ListNode *cur = head;
    for(int i=1; i<n; ++i){
        cur->next = new ListNode(a[i]);
        cur = cur->next;
    }
    return head;
}

void printList(ListNode* head){
    ListNode* cur = head;
    while(cur){
        cout<<cur->val<<" ";
        cur=cur->next;
    }
    cout<<endl;
}

// 1,2,3,4 -> 3
ListNode* findMid(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
};

// 1,2,3,4 -> 2
ListNode* findMid2(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
};


ListNode* reverseList(ListNode *head){
		ListNode *cur, *prev, *nx, *temp;
		prev = NULL;
		cur = head;

		while(cur){
			nx = cur->next;
			cur->next = prev;
			prev = cur;
			cur = nx;
		}
		return prev;		
	}

ListNode* reverseListRec(ListNode* head){
    if(!head || !head->next) return head;

    ListNode *end = reverseListRec(head->next);
    head->next->next = head;
    head->next = NULL;

    return end;	
}

// 1->2->3->4->5->6
// 2->1->4->3->6->5 
Node* reverseKNumbers(Node* &head, int k){
    Node* prev= NULL;
    Node* curr= head;
    Node* next=;
    int count=0;
    while(curr!=NULL && count<k){
        next= curr->next;
        curr->next= prev;
        prev= curr;
        curr= next;
        count++;
    }
    if(next!=NULL){
        head->next = reverseKNumbers(next,k);
    }
    return prev;
}


void deletion(Node* &head , int val){
    if(head==NULL){
        return;
    }
    if(head->next=NULL){
        deleteAtHead(head);
    }
    Node* temp= head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    Node* todelete = temp->next;
    temp->next= temp->next->next;

    delete todelete;
}

// delete only head 
void deleteAtHead(Node* & head){
    Node* todelete= head;
    head= head->next;
    delete todelete;
}


bool detectCycle(Node* & head){
    Node* slow= head;
    Node* fast= head;
    while(fast!= NULL && fast->next!=NULL){
        slow= slow->next;
        fast= fast->next->next;
        if(fast==slow)
            return true;
    }
    return false;
}


// make a cycle
void makeCycle(Node* & head, int pos){
    Node* temp = head;
    Node* start;
    int count =1;
    while(temp->next!=NULL){
        if(count== pos){
            start= temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next= start;
}

//  remove a cycle 
void removeCycle(Node* & head){
    Node* slow= head;  
    Node* fast=head;
    do{ // check if cycle present 
        slow=slow->next;
        fast= fast->next->next;
    }while(fast!=slow); 

    fast= head; // move fast again to head
    while(slow->next != fast->next){ // when both next is same
        slow=slow->next;
        fast= fast->next;
    }
    slow->next= NULL; // break cycle by changing the slow ptr
}

// ...................................................................................................

//  doubley linked list 

class Node{
public:
    int data;
    int next;
    int prev;
    Node(int val){
        data= val;
        next=NULL;
        prev=NULL;
    }
}

void insertAtHead(Node* &head, int val){
    //  no node in double list
    Node* n= new Node(val);
    n->next=head;
    if(head!=NULL){
        head->prev=n;
    }
    head=n;
}



void inserAtTail(Node* & head, int val){
    Node* n= new Node(val);
    Node* temp= head;
    if(head==NULL){
        insertATHead(head,val);
        return ;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

void deleteAtHead(Node* &head,int pos){
    Node* todelete = head;
    head = head->next;
    head->prev= NULL;

    delete todelete;
}

void deletion(Node* &head,int pos){
    Node* temp=head;
    int count=1;
    if(pos==1){
        deleteAtHead(head);
        return ;
    }
    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev = temp->prev;
    }
    delete temp;
}

void display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

// ..........................................................................

//  append last k nodes of linked list 
// 1-2-3-4-5-6  k=3 
// 4-5-6-1-2-3

int lenght(Node* &head){
    int l=0;
    Node* temp= head;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}

Node* kappend(Node* &head, int k){
    Node* newHead;
    Node* newTail;
    Node* temp= head;
    int l= lenght(head);
    int count=1;
    k=k%l;
    while(temp->next!=NULL){
        if(count==l-k){ // reached 3
            newTail = temp;
        }
        if(count== l-k+1){ // reached 4
            newHead = temp;
        }
        temp=temp->next;
        count++;
    }
    newTail->next=NULL;
    temp->next=head;
    return newTail;
}


//  find intersection point of two lists

int intersection(Node* &head1,Node* &head2){
    int l1= lenght(head1);
    int l2= lenght(head2);
    int diff=0;
    Node* ptr1;
    Node* ptr2;
    if(l1>l2){
        diff=l1-l2;
        ptr1= head1;
        ptr2= head2; 
    }else {
        diff= l2-l1;
        ptr1= head2;
        ptr2= head1;
    }
    while(diff){
        ptr1=ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        diff--;
    }
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2= ptr2->next;
    }
    return -1;
}

//  merge two sorted list 

Node* merge(Node* &head1 , Node* &head2){
    Node* temp= new Node(-1);
    Node* ptr1=head1;
    Node* ptr2 = head2;
    Node* ptr3= temp;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data <ptr2->data){
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        } else{
            ptr3->next= ptr2;
            ptr2=ptr2->next;
        }
        ptr3= ptr3->next;
        while(ptr1!=NULL){
            ptr3->next=ptr1;
            ptr1=ptr1->next;
            ptr3=ptr3->next;
        }
        while(ptr2!=NULL){
            ptr3->next= ptr2;
            ptr2=ptr2->next;
            ptr3=ptr3->next;
        }
        return temp->next;
    }
}

// ..........................................................

//  circular linked list 

boid insertAtHead(Node* &head, int val){
    Node* n= new Node(val);
    Node* temp=head;
    if(head==NULL){
        n->next=n;
        head=n;
        return ; 
    }
    while(temp->next!= head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}

void insetAtTail(Node* &head, int val){
    if(head==NULL){ // if list already empty
        insetAtHead(head,val);
        return ;
    }
    Node* n= new Node(val);
    Node* temp= head;
    while(temp->next!= head){
        temp=temp->next;
    }
    temp->next=n;
    n->next= head;
}

void deleteAtHead(Node* &head){
    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    Node* todelete =head;
    temp->next= temp->next->next;
    head= head->next;
    delete todelete;
}

void deletion(Node* &head, int pos){
    Node* temp= head;
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    int count=1;
    while(count!= pos-1){
        temp=temp->next;
        count++;
    }
    Node* todelete= temp->next;
    temp->next= temp->next->next;
    delete todelete;
}

void display(Node* &head){
    Node* temp=head;
    do{
        cout<<temp->data<<"";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
}


//  put even elements after odd elements in list 
void evenAfterOdd(Node* &head){
    Node* odd= head;
    Node* even = head->next;
    Node* evenStart = even;
    while(odd->next!=NULL && even->next!=NULL){
        odd->next= even->next;
        odd= odd->next;
        even->next= odd->next;
        even = even->next;
    }
    odd->next= evenStart;
    if(odd->next!=NULL){
        even->next=NULL;
    }
}



int main(){
    Node* head =NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    display(head);
}