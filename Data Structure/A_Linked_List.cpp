#include<bits/stdc++.h>
using namespace std;

// creating node for LL 
class Node{
    public:
    int data; // the data value
    Node* next; // the pointer to the next value

    public:
    // constructor
    Node (int data1, Node* next1){
        data=data1;  // Initialize data with the provided value
        next=next1;  // Initialize next with the provided
    }

    public:
    Node (int data1){
        data=data1;  // Initialize data with the provided value
        next=NULL; // Initialize next as null since it's the end of the list
    }
};

// array to linked list 
Node* convertArr2LL(vector<int>arr){
    Node * head= new Node(arr[0]);
    Node * mover= head;
    for(int i=1;i<arr.size();i++){
        Node* tmp= new Node(arr[i]);
        mover->next=tmp;
        mover=mover->next;
    }
    return head;
}

//print the Linked List
void printLL(Node * head){
    Node* tmp=head;
    while(tmp){
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
}

// length of LL 
int lengthOfLL(Node * head){
    int cnt=0;
    Node * tmp=head;
    while(tmp){
        cnt++;
        tmp=tmp->next;
    }
    return cnt;
}


// deletion 

Node * deleteHead(Node * head){
    // Case 1 : empty LL 
    if(head == NULL) return head;

    // Case 2: normal case 
    Node *tmp =head;
    head= head->next;   //this line can solve without free the space
    delete tmp;

    return head;
}

Node * deleteTail(Node* head){
    // Case 1: empty LL or one element LL
    if(head==NULL or head->next==NULL) return NULL;

    // Case 2 : Normal case. Stop before tail and set it to NULL and delete the tail. 
    Node* tmp=head;
    while(tmp->next->next){
        tmp=tmp->next;
    }
    delete tmp->next;
    tmp->next=NULL;
    
    return head;
}

Node* deleteKthElement(Node* head, int k){
    // Case 1: empty LL 
    if(head==NULL) return head;

    // Case 2: k=1 
    if(k==1){
        Node * tmp=head;
        head=head->next;
        delete tmp;
        return head;
    }

    // Case 3 : Normal case. I have to track the previous of kth element and move the pointer to the next of k th element
    Node* tmp=head;
    Node* prev=NULL;
    int cnt=0;
    while(tmp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            delete tmp;
            break;
        }
        prev=tmp;
        tmp=tmp->next;
    }
    return head;
}

// delete an element from LL (very similar like delete kth element)  
Node* deleteAnElement(Node* head, int x){
    // Case 1 : empty LL 
    if(head==NULL) return head;

    // Case 2 : Value is the first element 
    if(head->data==x){
        Node* tmp=head;
        head=head->next;
        delete tmp;
        return head;
    }

    // Case 3 : Normal case. I have to track the previous of the element and move the pointer to the next of the element 
    Node* tmp=head;
    Node* prev=NULL;
    while(tmp!=NULL){
        if(tmp->data==x){
            prev->next=prev->next->next;
            delete tmp;
            break;
        }
        prev=tmp;
        tmp=tmp->next;
    }
    return head;
}


// insertion 
// insert a value to head 
Node* insertHead(Node* head, int x){
    Node* tmp=new Node(x);
    tmp->next=head;
    head=tmp;
    return head;

    // return new Node(100,head);  // single line works the same
}

// insert to tail 
Node* insertTail(Node* head, int x){
    // Case 1: empty ll 
    if(head==NULL) return new Node(x);

    // Case 2 : Normal case. Stop at the last element and then add 
    Node* tmp=head;
    while(tmp->next){
        tmp=tmp->next;
    }
    Node *cur=new Node(x);
    tmp->next=cur;

    return head;
}

// inserting at k th position  
Node* insertKthPos(Node* head, int x,int k){
    // Case 1 : empty ll 
    if(head==NULL){
        if(k==1) return new Node(x);
        else return NULL;
    }

    // Case 2 : inserting at head 
    if(k==1){
        Node* tmp= new Node(x);
        tmp->next=head;
        head=tmp;
    }

    // Case 3 : Normal case. Stop before the k th position and add node to that position 
    int cnt=0;
    Node* tmp=head;
    while(tmp!=NULL){
        cnt++;
        if(cnt==k-1){  //stop before 
            Node* cur=new Node(x);
            cur->next=tmp->next;
            tmp->next=cur;
            break;
        }
        else tmp=tmp->next;  //go forward
    }

    return head;
}

// insert before a specific value (first occurance of that value) - (similar to insertKthPos)
Node* insertBeforeVal(Node* head, int x,int val){
    // Case 1: empty ll 
    if(head==NULL) return NULL;

    // Case 2 : value is in head 
    if(head->data==val){
        return new Node(x,head);
    }

    // Case 3: Normal case. Stop before the value and add the element 
    Node* tmp=head;
    while(tmp->next!=NULL){
        if(tmp->next->data==val){
            Node* cur=new Node(x);
            cur->next=tmp->next;
            tmp->next=cur;
            break;
        }
        tmp=tmp->next;
    }

    return head;
}



int main(){
    vector<int> arr={2,5,8,7};
    Node * head=convertArr2LL(arr);
    head=insertBeforeVal(head,100,2);
    printLL(head);
}