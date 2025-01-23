#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;
    
    Node(int data){
        this->data = data;
        next=NULL;
        back=NULL;
    }

    Node(int data, Node* next1, Node* back1){
        this->data = data;
        next=next1;
        back=back1;
    }
};

Node* arrayToDLL(vector<int>&arr){
    Node* head=new Node(arr[0]);
    Node* cur=head;
    for(int i=1;i<arr.size();i++){
        Node* tmp=new Node(arr[i],NULL,cur);
        cur->next=tmp;
        cur=cur->next;
    }
    return head;
}

void printDLL(Node* head){
    Node* tmp=head;
    while(tmp){
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
}

Node* deleteFromHead(Node* head){
    // Case 1 & 2: empty and one lement DLL 
    if(head==NULL or head->next==NULL) return NULL; 

    // Case 3 : normal case. 
    Node* prev=head;
    head=head->next;
    head->back=NULL;
    prev->next=NULL;
    delete prev;

    return head;
}

Node* deleteFromTail(Node* head){
    // Case 1 & 2: empty and one lement DLL 
    if(head==NULL or head->next==NULL) return NULL;

    // Case 3 : normal case. 
    Node* tmp=head;
    while(tmp->next->next!=NULL){
        tmp=tmp->next;
    }
    Node* N=tmp->next;
    tmp->next=NULL;
    N->back=NULL;
    delete N;

    return head;
}

int main()
{
    vector<int> arr={2,5,8,7};
    Node * head=arrayToDLL(arr);
    head=deleteFromTail(head);
    printDLL(head);
    return 0;
}