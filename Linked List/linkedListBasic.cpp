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
            Node* new_node = new Node(val);
            if(head == NULL){
                head = tail = NULL;
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
                head = tail = NULL;
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
