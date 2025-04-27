#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int value, Node* next1){
        data = value;
        next = next1;
    }

    public:
    Node(int value){
        data = value;
        next = nullptr;
    }
};
// class List{
//     Node* head;
//     Node* tail;
//     public:
//     List(){
//         head = tail = nullptr;
//     }
// };
Node* push_front(Node* head,int val){
    Node* new_node = new Node(val);
    if(head == nullptr){
        head = new_node;
    }
    else{
        new_node->next = head;
        head = new_node;
    }
    return head;
}

Node* push_back(Node* head,int val){
    Node* new_node = new Node(val);
    if(head==nullptr){
        head = new_node;
    }
    else{
        tail->next = new_node;
        tail = new_node;
    }
    return head;
}
int main(){
    
}