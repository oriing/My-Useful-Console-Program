#include <stdio.h>
#include <Windows.h>
#include <string.h>

int main(){
	char a[100000]="\"";
	int nowp=1;
	while(1){
		char imsi[100]={};
		printf("%s", a);
		scanf("%s", &imsi);
		strcpy(a+nowp, imsi);
		nowp=strlen(a);
		strcpy(a+nowp, "\", \"");
		nowp+=4;
		system("cls");
	}
	
	return 0;
}
