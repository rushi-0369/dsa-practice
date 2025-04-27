#include<stdio.h>
#include <stdbool.h>
#include<string.h>
void reverseArrayS1(int a[], int n,int i){
    if(i>=n/2){
        return;
    }
    int temp = a[i];
    a[i] = a[n-i-1];
    a[n-i-1] = temp;
    reverseArrayS1(a,n,i+1);
}

void reverseArrayS2(int a[], int l, int n){
    if(l>=n){
        return;
    }
    int temp = a[l];
    a[l] = a[n];
    a[n] = temp;
    reverseArrayS2(a, l+1, n-1);
}

bool stringPalindrome(int i, char* s){
    int n = strlen(s);
    if(i>=n/2){
        return true;
    }
    if(s[i]!=s[n-i-1]){
        return false;
    }
    return stringPalindrome(i+1, s);

}
int main(){
    int n = 5;
    int a[5] = {1,2,3,4,5};
    char s[] = "MADAM";
    printf("%d\n", stringPalindrome(0, s));
}