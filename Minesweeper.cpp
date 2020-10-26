#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define loop(i, n) for(int i=1;i<=(n);i++)
#define remove() system("cls")

const int mineMax=40;
const int m=20;//map size

char map[m+2][m+2];//map_set
char mapOpen[m+2][m+2];//map_shown

int lessBomb=mineMax;

char checkNum(int x, int y){
	char a=0;
	if(map[x-1][y-1]=='@') a++;
	if(map[x-1][y]=='@') a++;
	if(map[x-1][y+1]=='@') a++;
	if(map[x][y-1]=='@') a++;
	if(map[x][y+1]=='@') a++;
	if(map[x+1][y-1]=='@') a++;
	if(map[x+1][y]=='@') a++;
	if(map[x+1][y+1]=='@') a++;

	return a;
}

void startSet(){
	int x=0, y=0;
	loop(i, mineMax){
		do{
			x=rand()%20+1;
			y=rand()%20+1;
		} while(map[x][y]=='@');
		map[x][y]='@';
	}

	loop(i, m){
		loop(j, m){
			if(map[i][j]=='@') continue;
			map[i][j]= checkNum(i, j)+'0';
		}
	}
	/*
    */
}

void showMap(){
    remove();
    printf("   ");
	loop(i, m){printf("%2d ", i);}
	loop(i, m){
		printf("\n");
	    printf("%2d ", i);
		loop(j, m){
			if(mapOpen[i][j]==1) printf(" %c ", map[i][j]);
			else printf("   ");
		}
    }
}

void charge(int x, int y){
    mapOpen[x][y]=1;
    if(map[x][y]!='0') return;
	if(mapOpen[x-1][y-1]==0) { charge(x-1, y-1); }
	if(mapOpen[x-1][y]==0) { charge(x-1, y);}
	if(mapOpen[x-1][y+1]==0) { charge(x-1, y+1);}
	if(mapOpen[x][y-1]==0) { charge(x, y-1);}
	if(mapOpen[x][y+1]==0) { charge(x, y+1);}
	if(mapOpen[x+1][y-1]==0) { charge(x+1, y-1);}
	if(mapOpen[x+1][y]==0) { charge(x+1, y);}
	if(mapOpen[x+1][y+1]==0) { charge(x+1, y+1);}
}

void startGame(){
    int x, y;
    do{
        scanf("%d %d", &x, &y);
    } while(mapOpen[x][y]==1);

    if(map[x][y]=='@') {
        lessBomb=-1;
        return;
    }
    if(map[x][y]=='0') {
        charge(x, y);
    } else {
        mapOpen[x][y]=1;
    }
    lessBomb=0;
    loop(i, m){
		loop(j, m){
		    if(mapOpen[i][j]==0) lessBomb++;
		}
    }
    showMap();
}

int main(){
	srand(time(NULL));
	startSet();
	while(lessBomb>20){
        startGame();
	}
	remove();
	if(lessBomb!=20){
        printf("다음 기회를!");
        loop(i, m){
            printf("\n");
            loop(j, m){
                printf("%c  ", map[i][j]);
            }
        }
	}
	else {
        printf("승리!");
        loop(i, m){
            printf("\n");
            loop(j, m){
                printf("%c  ", map[i][j]);
            }
        }
	}

	return 0;
}
