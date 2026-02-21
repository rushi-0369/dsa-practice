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

Node* addTwoNumbers(Node* l1, Node* l2){
    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;
    int carry = 0;
    Node* temp1 = l1;
    Node* temp2 = l2;
    while(temp1 != NULL || temp2 != NULL){
        int sum = carry;
        if(temp1!=NULL) sum = sum + temp1->data;
        if(temp2!=NULL) sum = sum + temp2->data;
        Node* newNode = new Node(sum%10);
        carry = sum / 10;
        curr->next = newNode;
        curr = curr->next;
        if(temp1!=NULL) temp1 = temp1->next;
        if(temp2!=NULL) temp2 = temp2->next;
    }
    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummyNode->next;
}

Node* reverseLL(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* middleOfLLBFA(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp!=NULL){
        temp = temp->next;
        cnt++;
    }
    int mid = cnt/2 + 1;
    temp = head;
    while(temp!=NULL){
        mid = mid - 1;
        if(mid==0){
            break;
        }
        temp = temp->next;
    }
    return temp;
}

Node* middleOfLLOA(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
//Reorder list
//base case, find middle of ll using hair and tortoise or floyd warshall method, reverse the second half from middle, start reordering
Node* reorderList(Node* head){
    if(head == NULL || head->next == NULL){
            return;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* prev = NULL;
    Node* curr = slow->next;
    slow->next = NULL;
    while(curr!=NULL){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    Node* first = head;
    Node* second = prev;
    while(second){
        Node* temp1 = first->next;
        Node* temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}
//remove elements
Node* removeElements(Node* head, int val){
    Node* dummyNode = new Node(-1);
    dummyNode->next = head;
    Node* curr = dummyNode;
    while(curr->next != NULL){
        if(curr->next->data == val){
            curr->next = curr->next->next; 
        }
        else{
            curr = curr->next;
        }
    }
    return dummyNode->next;
}

//palindrome linked list
//brute force stack implementation
bool palindromeList(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast != NULL){ //odd nodes
        slow = slow->next;
    }
    Node* prev = NULL;
    Node* curr = slow;
    Node* next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    slow = prev;
    fast = head;
    while(slow!=NULL){
        if(fast->data != slow->data){
            return false;
        }
        fast = fast->next;
        slow = slow->next;
    }
    return true;
}

//merge two sorted linked lists
//uses recursion by attaching heads and return head
Node* mergeTwoListsBA(Node* list1, Node* list2){
    Node* t1 = list1;
    Node* t2 = list2;
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(t1!=NULL && t2!=NULL){
        if(t1->data < t2->data){
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else{
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    if(t1){
        temp->next = t1;
    }
    else{
        temp->next = t2;
    }
    return dummyNode->next;
}
Node* mergeTwoListsOA(Node* list1, Node* list2){
    if(list1 == NULL){
        return list2;
    }
    if(list2 == NULL){
        return list2;
    }
    if(list1->data < list2->data){
        list1->next = mergeTwoListsOA(list1->next, list2);
        return list1;
    }
    else{
        list2->next = mergeTwoListsOA(list1, list2->next);
        return list2;
    }
}