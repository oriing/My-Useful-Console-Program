//제작자: 박정식(충남과학고등학교)

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <Windows.h>

float m[27][27];

void setMol(char *a, float mo){
	if(a[1]==0) m[a[0]-'A'+1][0]=mo;
	else m[a[0]-'A'+1][a[1]-'a'+1]=mo;
}
float getMol(char *a){
	if(a[1]==0) return m[a[0]-'A'+1][0];
	else return m[a[0]-'A'+1][a[1]-'a'+1];
}

void setting(){
	FILE *in = fopen("periodic.txt", "r");
	char ims[3]; float imf;
	if(in == NULL) {
		printf("ERROR");
		exit(0);
	}
	while(!feof(in)){
		fscanf(in, "%s %f", ims, &imf);
		setMol(ims, imf);
	}
	fclose(in); 
}

int main(){
	char str[10000];
	double ans;
	int N;
	int num=0;
	char now[3]={};
	int nowpt=0;
	int atofirst=0;
	
	setting();
	printf("예시: NaCl, CH3COOH\n");
	printf("입력: ");
	scanf("%s", str);
	N=strlen(str);
	
	for(int i=0;i<N;i++){
		if(str[i]>='0'&&str[i]<='9'){
			if(nowpt==0){
				printf("ERROR");
				exit(0);
			}
			num*=10;
			num+=str[i]-'0';
		}
		
		else if(str[i]>='A'&&str[i]<='Z'){
			if(atofirst) {
				if(num) ans+=getMol(now)*num;
				else ans+=getMol(now);
			}
			nowpt=0;
			num=0;
			now[0]=0; now[1]=0;
			now[nowpt++]=str[i];
			atofirst=1;
		}
		else if(str[i]>='a'&&str[i]<='z'&&nowpt==1){
			now[nowpt++]=str[i];
		}
		else {
			printf("ERROR");
			exit(0);
		}
	}
	if(atofirst) {
		if(num) ans+=getMol(now)*num;
		else ans+=getMol(now);
	}
	printf("%lf\n\n", ans);
	
	system("pause");
	return 0;
}
