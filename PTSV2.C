	#include<graphics.h>
	#include<process.h>
	#include<dos.h>
	#include<conio.h>


	void main()
	{

	int SCORE[1];
	int x=300,y=365,hrzntl=0,vrtkl=0,i=250,ch,bomb=0;

	//graphics initialization
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	setbkcolor(13);

	starting:
	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	outtextxy(60,240,"PRESS Y TO START GAME");
	ch=getch();
	if(ch==89||ch==121)
	goto proceed;
	if(ch==27)
	return(0);
	if(ch==110||ch==78)
	return(0);
	else
	goto starting;
	proceed:
	i=250;
	x=300;
	y=365;
	hrzntl=0;
	vrtkl=0;
	while(1)
	{

	 //bomb
	 setcolor(BROWN);
	 circle(x,y,15);
	 circle(x,y,13);
	 circle(x,y,11);
	 circle(x,y,9);
	 circle(x,y,8);
	 circle(x,y,7);
	 circle(x,y,5);
	 circle(x,y,2);
	 circle(x,y,1);


	//tank making starts

	// bigger wheel and axel
	setcolor(BROWN);
	circle(i+10,430,10);
	circle(i+10,430,2);
	circle(i+30,430,10);
	circle(i+30,430,2);
	circle(i+50,430,10);
	circle(i+50,430,2);
	circle(i+70,430,10);
	circle(i+70,430,2);
	circle(i+90,430,10);
	circle(i+90,430,2);

	//smaller wheels
	circle(i,420,5);
	circle(i,420,1);
	circle(i+20,420,5);
	circle(i+20,420,1);
	circle(i+40,420,5);
	circle(i+40,420,1);
	circle(i+60,420,5);
	circle(i+60,420,1);
	circle(i+80,420,5);
	circle(i+80,420,1);
	circle(i+100,420,5);
	circle(i+100,420,1);

	//wheel chain
	setcolor(GREEN);
	line(i-5,415,i+105,415);
	line(i,414,i+100,414);
	line(i-5,440,i+105,440);
	arc(i-5,428,90,270,12);
	arc(i+105,428,-90,90,12);

	//tank structure
	line(i+50,400,i+50,410);
	line(i+70,400,i+70,410);
	line(i+30,400,i+30,410);
	line(i+90,400,i+90,410);
	line(i+10,400,i+10,410);
	rectangle(i,400,i+100,410);
	rectangle(i+25,390,i+75,400);
	line(i+50,385,i+50,390);
	line(i+47,385,i+47,390);
	line(i+53,385,i+53,390);
	ellipse(i+50,385,295,320,65,10);
	ellipse(i+50,388,295,320,65,10);

	//deflector
	ellipse(i+50,375,220,320,65,10);


	//war zone boundary
	setcolor(BLUE);
	line(10,20,getmaxx()-10,20);
	line(10,20,10,getmaxy()-20);
	line(getmaxx()-10,20,getmaxx()-10,getmaxy()-20);
	line(10,getmaxy()-20,getmaxx()-10,getmaxy()-20);

	//gameplay display instruction
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(10,10,"ESC");
	outtextxy(200,467,"DEFLECT THE BOMB TO SURVIVE");

	//deflection mechanism
	if(x>=614||x<=25)
	hrzntl=!hrzntl;
	if(hrzntl)
	x=x-1;
	else
	x=x+1;
	if((y>=370&&x<=i+100&&x>=i)||y<=35)
	vrtkl=!vrtkl;
	if(vrtkl)
	y=y+1;
	else
	y=y-1;
	if(y==370&&x<=i+100&&x>=i)
	bomb++; //score increment
	moveto(520,10);
	sprintf(SCORE,"%d",bomb);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtext("DEFLECTIONS-");
	outtext(SCORE);
	if(y>=444)
	goto finishing;

	//tank movement mechanism
	if(kbhit())
	{
	ch=getch();
	if(ch==75) //move 1 step left
	{
		i=i-5;
	}
	if(ch==77) //move 1 step right
	{
		i=i+5;
	}
	if(ch==27) //quit
	exit(0);
	}
	delay(3); //bomb movement speed
	cleardevice();
	ch=0;
	}
	finishing:
	setcolor(RED);
	outtextxy(240,240,"!!!GAME OVER!!!");
	outtextxy(220,260,"PRESS Y TO PLAY AGAIN");
	ch=getch();
	if(ch==89||ch==121)
	goto proceed;
	if(ch==27)
	return(0);
	if(ch==110||ch==78)
	return(0);
	else
	{
	cleardevice();
	goto starting;
	}
	}