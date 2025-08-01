#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;

public:
    List(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* new_node = new Node(val); //dynamic
        if(head == NULL){
            head = tail = new_node;
            return;
        }
        else{
            new_node->next = head;
            head = new_node;
        }
    }

    void printLL(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL" <<endl;
    }

    void push_back(int val){
        Node* new_node = new Node(val);
        if(head == NULL){
            head = tail = new_node;
            return;
        }
        else{
            tail->next = new_node;
            tail = new_node;
        }
    }

    void pop_front(){
        if(head == NULL){
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
        if(head == NULL){
            return;
        }
        if(head == tail){ 
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    
    void insert(int val, int pos){
        if(pos<0){
            return;
        }
        if(pos == 0){
            push_front(val);
            return;
        }
        Node* temp = head;
        for(int i = 0; i < pos - 1; i++){
            if(temp == NULL) return;
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    int search(int key){
        Node* temp = head;
        int idx = 0;
        while(temp != NULL){
            if(temp->data == key){
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }
};
int main(){
    List ll;
    int arr[5] = {1, 2, 3, 4, 5};
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        ll.push_back(arr[i]);
    }
    ll.printLL();
}
