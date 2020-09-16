#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define getThisNum (thisNum?thisNum:1)
#define NI input[i]

int gnum(char str[], int much){
    int ans=0;
    int imsi=1;
    int i;
    for(i=much-1;i>=0;i--){
        ans += imsi * (str[i] - '0');
        imsi *= 10;
    }
    return ans;
}

int main(){
    char input[1000]={};//입력값
    int length;//입력값의 길이
    int xl=0, Xl=0, nl=0, xr=0, Xr=0, nr=0;//항의 숫자 총합
    int a, b, c, D;
    int timechecker=0;//기호: 1, 문자: -1 했음
    int thispm='+';//직전 플러스/마이너스
    int othertime;//항 구분 시 사용
    int thisNum=0;//현재숫자 임시저장
    int i, j, k, l;
    double answer[2]={0, };

    scanf("%s", input);
    length=strlen(input);

    //left
    for(i=0;i<length;i++){

        if(NI=='+'||NI=='-'){
            if(timechecker==1){
                printf("ERROR");
                return 0;
            }
            if(timechecker==0){
                if(thispm=='+'){
                    nl+=thisNum;
                } else {
                    nl-=thisNum;
                }
            }
            thispm=NI;
            thisNum=0;
            timechecker=1;
        }

        if(NI=='='){
            if(timechecker==0){
                if(thispm=='+'){
                    nl+=thisNum;
                } else {
                    nl-=thisNum;
                }
            }
            othertime=i+1;
            break;
        }

        if('0'<=NI&&NI<='9'){
            int imsi=i;
            if(timechecker==-1){
                printf("ERROR");
                return 0;
            }
            while('0'<=input[imsi]&&input[imsi]<='9'){
                imsi++;
            }
            thisNum=gnum(&input[i], imsi-i);
            i+=imsi-i-1;
            timechecker=0;
        }

        if(NI=='X'){
            if(timechecker==-1){
                printf("ERROR");
                return 0;
            }
            if(thispm=='+'){
                Xl+=getThisNum;
            } else {
                Xl-=getThisNum;
            }
            timechecker=-1;
        }

        if(NI=='x'){
            if(timechecker==-1){
                printf("ERROR");
                return 0;
            }
            if(thispm=='+'){
                xl+=getThisNum;
            } else {
                xl-=getThisNum;
            }
            timechecker=-1;
        }

    }
    timechecker=0;
    thispm='+';
    thisNum=0;

    if(othertime==0||othertime==length){
        printf("ERROR");
        return 0;
    }

    //right
    for(i=othertime;i<length;i++){

        if(NI=='+'||NI=='-'){
            if(timechecker==1){
                printf("ERROR");
                return 0;
            }
            if(timechecker==0){
                if(thispm=='+'){
                    nr+=thisNum;
                } else {
                    nr-=thisNum;
                }
            }
            thispm=NI;
            thisNum=0;
            timechecker=1;
        }

        if(NI=='='){
            printf("ERROR");
            return 0;
        }

        if('0'<=NI&&NI<='9'){
            int imsi=i;
            if(timechecker==-1){
                printf("ERROR");
                return 0;
            }
            while('0'<=input[imsi]&&input[imsi]<='9'){
                imsi++;
            }
            thisNum=gnum(&input[i], imsi-i);
            i+=imsi-i-1;
            timechecker=0;
        }

        if(NI=='X'){
            if(timechecker==-1){
                printf("ERROR");
                return 0;
            }
            if(thispm=='+'){
                Xr+=getThisNum;
            } else {
                Xr-=getThisNum;
            }
            timechecker=-1;
        }

        if(NI=='x'){
            if(timechecker==-1){
                printf("ERROR");
                return 0;
            }
            if(thispm=='+'){
                xr+=getThisNum;
            } else {
                xr-=getThisNum;
            }
            timechecker=-1;
        }
    }
    if(timechecker==0){
        if(thispm=='+'){
            nr+=thisNum;
        } else {
            nr-=thisNum;
        }
    }


    a=Xl-Xr;
    b=xl-xr;
    c=nl-nr;


    if(a!=0){
        printf("(%d)x²+(%d)x+(%d) = (%d)x²+(%d)x+(%d)\n", Xl, xl, nl, Xr, xr, nr);
        printf("(%d)x²+(%d)x+(%d) = 0\n", a, b, c);
        D=b*b-4*a*c;
        printf("D = %d\n", D);

        if(D==0){
            answer[0]=(double)(-b)/(2*a);
            printf("x= %lf (중근)", answer[0]);
        } else if(D>0){
            answer[0]=(double)(-b+sqrt(D))/(2*a);
            printf("x= %lf\n", answer[0]);
            answer[1]=(double)(-b-sqrt(D))/(2*a);
            printf("x= %lf", answer[1]);
        } else {
            answer[0]=(double)(-b)/(2*a);
            printf("x= (%lf)+(%lf)i\n", answer[0], sqrt(-D)/(2*a));
            answer[1]=(double)(-b)/(2*a);
            printf("x= (%lf)-(%lf)i", answer[1], sqrt(-D)/(2*a));
        }
    } else {
        printf("(%d)x+(%d) = (%d)x+(%d)\n", xl, nl, xr, nr);
        printf("(%d)x+(%d) = 0\n", b, c);
        answer[0]=-(double)c/b;
        printf("x= %lf", answer[0]);
    }

    printf("\n\n");


    return 0;
}
