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
Node* converArrToLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 0; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
int lengthOfLL(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp != nullptr){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}
int checkIfPresent(Node* head, int val){
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == val) return true;
        temp = temp->next;
    }
}
int main(){
    vector<int> arr ={2, 3, 5, 7};
    //Convertion of array to linked list
    Node* head = converArrToLL(arr);
    cout << head->data << endl;

    //Traversal of linked list
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }

    //Length of Linked List
    cout << lengthOfLL(head) << endl;

    //Check if value present in Linked List
    cout << checkIfPresent(head, 5) << endl;
    
}