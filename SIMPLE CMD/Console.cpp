#include <stdio.h>
#include <windows.h>

int main(){
    char ma[10000];
    system("cls");
    system("title console alert");
    for(;;){
    	printf("> ");
        gets(ma);
        system("cls");
        printf("> %s\n\n", ma);
        system(ma);
        if(ma[0]=='e'&&ma[1]=='x'&&ma[2]=='i'&&ma[3]=='t') return 0;
    }
    return 0;
}
