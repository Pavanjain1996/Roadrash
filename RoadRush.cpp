#include<iostream>
#include<conio.h>
#include<windows.h>
#include<time.h>
using namespace std;
bool gameOver;
int length=20;
int breadth=9;
int x,y,score,carX1,carY1,carX2,carY2,carX3,carY3,carX4,carY4;
enum Direction{STOP=0,LEFT,RIGHT};
Direction dir;
void Setup(){
	gameOver=false;
	x=length-1;
	y=5;
	carX1=2;
	carX2=6;
	carX3=10;
	carX4=14;
	carY1=rand()%8;
	while(carY1!=3 && carY1!=5 && carY1!=7)
		carY1=rand()%8;
	carY2=rand()%8;
	while(carY2!=3 && carY2!=5 && carY2!=7)
		carY2=rand()%8;
	if(carY1!=carY2)
		carY3=15-carY1-carY2;
	carY3=rand()%8;
	while(carY3!=3 && carY3!=5 && carY3!=7)
		carY3=rand()%8;
	carY4=rand()%8;
	while(carY3!=3 && carY4!=5 && carY4!=7)
		carY4=rand()%8;
	dir=STOP;
	score=0;
}
void Draw(){
	system("cls");
	int i,j;
	for(j=1;j<=breadth;j++)
		cout<<"~";
	cout<<endl;
	for(i=1;i<=length;i++){
		for(j=1;j<=breadth;j++){
			if(j==1 || j==breadth)
				cout<<"|";
			else if(i==x && j==y)
				cout<<(char)178;
			else if(i==carX1 && j==carY1)
				cout<<(char)31;
			else if(i==carX2 && j==carY2)
				cout<<(char)31;
			else if(i==carX3 && j==carY3)
				cout<<(char)31;
			else if(i==carX4 && j==carY4)
				cout<<(char)31;
			else
				cout<<" ";	
		}
		cout<<endl;
	}
	carX1=(carX1+1)%21;
	carX2=(carX2+1)%21;
	carX3=(carX3+1)%21;
	carX4=(carX4+1)%21;
	for(j=1;j<=breadth;j++)
		cout<<"~";
	cout<<endl;
	cout<<"\nScore = "<<score;
}
void Direction(){
	if(_kbhit()){
		switch(_getch()){
			case 'a':
				dir=LEFT;
				break;
			case 'd':
				dir=RIGHT;
				break;
		}
	}
}
void Logic(){
	switch(dir){
		case LEFT:
			if(y-2>2)
				y-=2;
			break;
		case RIGHT:
			if(y+2<8)
			y+=2;
			break;
		default:
			break;
	}
	if(carX1==20 && carY1==y){
		Beep(500,50);
		gameOver = true;
	}
	if(carX1==20 && carY1!=y){
		score+=10;
		Beep(2500,50);
	}
	if(carX2==20 && carY2==y){
		Beep(500,50);
		gameOver = true;
	}
	if(carX2==20 && carY2!=y){
		score+=10;
		Beep(2500,50);
	}
	if(carX3==20 && carY3==y){
		Beep(500,50);
		gameOver = true;
	}
	if(carX3==20 && carY3!=y){
		score+=10;
		Beep(2500,50);
	}
	if(carX4==20 && carY4==y){
		Beep(500,50);
		gameOver = true;
	}
	if(carX4==20 && carY4!=y){
		score+=10;
		Beep(2500,50);
	}
}
main(){
	cout<<"\n\n\tPlease wait while the game is loading....\n\n\t";
	for(int i=1;i<=40;i++){
		cout<<(char)178;
		Sleep(100);
	}
	cout<<"\n\n\tPress any key to continue....";
	getch();
	system("cls");
	srand(time(NULL));
	Setup();
	while(!gameOver){
		dir=STOP;
		Draw();
		Direction();
	  	Logic();
	  	Sleep(100);
		if(carX1==20){
			carY1=rand()%8;
		while(carY1!=3 && carY1!=5 && carY1!=7)
			carY1=rand()%8;
		carY2=rand()%8;
		while(carY2!=3 && carY2!=5 && carY2!=7)
			carY2=rand()%8;
		carY3=rand()%8;
		while(carY3!=3 && carY3!=5 && carY3!=7)
			carY3=rand()%8;
		carY4=rand()%8;
		while(carY4!=3 && carY4!=5 && carY4!=7)
			carY4=rand()%8;
		}
	}
	cout<<"\n\nYour game is over...";
	cout<<"\n\nYour Final score is "<<score<<endl<<endl;
	getch();
}
