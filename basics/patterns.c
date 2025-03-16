#include<stdio.h>
#include<stdlib.h>

void pattern1(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j<n-i; j++){
            printf("* ");
        }
        printf("\n");
    }
}

void pattern2(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            printf(" ");
        }
        for(int k = 0; k < 2*i+1; k++){
            printf("*");
        }
        for(int j = 0; j < n-i-1; j++){
            printf(" ");
        }
        printf("\n");
    }
}

void pattern3(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            printf(" ");
        }
        for(int k = 0; k < 2*n - (2*i+1); k++){
            printf("*");
        }
        for(int j = 0; j < i; j++){
            printf(" ");
        }
        printf("\n");
    }
}

void pattern4(int n){
    for(int i = 1; i < 2*n;i++){
        int stars = i;
        if(i > n){
            stars = 2*n - i;
        }
        for(int j = 0; j < stars; j++){
            printf("*");
        }
        printf("\n");
    }
}

void pattern5(int n){
    int start;
    for(int i = 0; i < n;i++){
        if(i%2 == 0){
            start = 1;
        }
        else{
            start = 0;
        }
        for(int j = 0; j <= i; j++){
            printf("%d", start);
            start = 1 - start;
        }
        printf("\n");
    }
}

int main(){
    int n;
    scanf("%d",&n);
    pattern1(n);
    pattern2(n);
    pattern3(n);
    pattern4(n);
    pattern5(n);
}