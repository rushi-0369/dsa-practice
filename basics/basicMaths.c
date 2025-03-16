#include<stdio.h>

int min(int a, int b) {
    if (a < b) {
      return a;
    } else {
      return b;
    }
}
void printDivisorsBFA(int n){
    for(int i = 0; i < n; i++){
        if(n%i==0){
            printf("%d",i);
        }
    }
}

void printDivisorsOA(int n){
    for(int i = 0; i <= sqrt(n); i++){
        if(n%i == 0){
            printf("%d",i);
            if(n/i != i){
                printf("%d",n/i);
            }
        }
    }
}

void primeBFA(int n){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(n%i == 0){
            cnt++;
        }
    }
    if(cnt==2){
        printf("Prime\n");
    }
    else{
        printf("Not Prime\n");
    }
}

void primeOA(int n)
{
    int cnt = 0;
    for(int i = 0; i < sqrt(n); i++){
        if(n%i == 0){
            cnt++;
            if(n/i != i){
                cnt++;
            }
        }
    }
    if(cnt==2){
        printf("Prime\n");
    }
    else{
        printf("Not Prime\n");
    }
}

int gcdBFA(int n1, int n2){
    int gcd = 1;
    for(int i = 1; i < min(n1, n2); i++){
        if(n1%i==0 && n2%i==0){
            gcd = i;
        }
    }
    return gcd;
}

int gcdBA(int n1, int n2){
    for(int i = min(n1, n2); i > 0; i--){
        if(n1%i==0 && n2%i==0){
            return i;
        }
    }
    return 1;
}

int gcdOA(int n1, int n2){
    while(n1>0 && n2>0){
        if(n1>n2){
            n1 = n1 % n2;
        }
        else{
            n2 = n2 % n1;
        }
    }
    if(n1 == 0){
        return n2;
    }
    else{
        return n1;
    }
}
