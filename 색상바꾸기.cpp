#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

char rands(){
    char a;
    int r;
    r=rand()%16;
    if(r<=9) a=r+'0';
    else a=r+'a'-10;
    return a;
}

int main(){
    char a[9]="color aa";
    printf("asfdasdf");
    srand(time(NULL));
    while(1){
        a[6]=rands();
        a[7]=rands();
        system(a);
        system("cls");
        Sleep(10);
    } 
}
