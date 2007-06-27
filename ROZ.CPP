#include<stdio.h>
#include<dos.h>
#include<iostream.h>
#include <math.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>
#include <time.h>
#include <string.h>
#include <dir.h>
#include <stdlib.h>
#include <io.h>

union REGS in,out;
void mouse();

int menu(){
 clrscr();
 flushall();
 setcolor(BLUE);
 setbkcolor(LIGHTGRAY);

 setfillstyle(1,LIGHTRED);
 bar3d(0,0,638,20,5,9);
 moveto(90,10);
 settextstyle(2, HORIZ_DIR,5);
 outtext("Designed by   Himan Zarza   &&   Fadel Hergholi");

 setfillstyle(8,BROWN);
 bar(540,0,638,20);
 outtextxy(540,10,"Screen Saver");

 setcolor(LIGHTGREEN);

 setfillstyle(1,BROWN);
 bar3d(0,25,100,40,4,6);
 moveto(30,30);
 settextstyle(2, HORIZ_DIR,5);
 outtext("FILE");

 setfillstyle(1,BROWN);
 bar3d(110,25,200,40,4,6);
 moveto(140,30);
 settextstyle(2, HORIZ_DIR,5);
 outtext("EDIT");

 setfillstyle(1,BROWN);
 bar3d(210,25,310,40,4,6);
 moveto(240,30);
 settextstyle(2, HORIZ_DIR,5);
 outtext("Folder");

 setfillstyle(1,BROWN);
 bar3d(320,25,420,40,4,6);
 moveto(330,30);
 settextstyle(2, HORIZ_DIR,5);
 outtext("Properties");

 setfillstyle(1,BROWN);
 bar3d(430,25,530,40,4,6);
 moveto(465,30);
 settextstyle(2, HORIZ_DIR,5);
 outtext("HELP");

 setfillstyle(1,RED);
 bar3d(540,25,630,40,4,6);
 moveto(568,30);
 settextstyle(2, HORIZ_DIR,5);
 outtext("EXIT");


 setfillstyle(1,MAGENTA);
 bar3d(540,43,630,58,0,0);
 moveto(545,49);
 settextstyle(2, HORIZ_DIR,5);
 outtext("Show  Hide");
 line(585,43,585,58);

 setfillstyle(1,RED);
 mouse();
 getch();
 closegraph();
return 0;
}
//****************
void initmouse();
void showmouse();
void hidemouse();
void getmouse(int &button,int &x,int &y) ;
void setplace_file(int p,int s) ;
void file_menu(int &c);
void edit_menu(int &c);
void folder_menu(int &c) ;
void property_menu(int &c);
void help_menu();
void screen_saver();
void content();
void pre_menu();
void win ( int a , int b  , int c , int d) ;
//*******************************************
void mouse()
{
 int p,s;
 static int c=0;
 showmouse();
 int b,x,y;
 win(0,0,639,479);
 while(1)
	 {

	 getmouse(b,x,y);
	 if(b==1)
		{
		if((x>0&&x<100)&&(y>25&&y<40))
					     { p=100  ;
					       s=1;
					       setplace_file(p,s);
					       pre_menu() ;
					       file_menu(c);
					       }

		else if((x>110&&x<200)&&(y>25&&y<40))
						    { p=198 ;
						      s=1;
						      setplace_file(p,s);
						      pre_menu()   ;
						      edit_menu(c);
						      }

		else if((x>210&&x<310)&&(y>25&&y<40))
						    { p=305 ;
						      s=1;
						      setplace_file(p,s);
						      pre_menu() ;
						      folder_menu(c);
						    }

		else if((x>320&&x<420)&&(y>25&&y<40))
						    { p=420;
						      s=1;
						      setplace_file(p,s);
						      pre_menu() ;
						      property_menu(c);
						      }

		else if((x>430&&x<530)&&(y>25&&y<40))
						    {
						      help_menu();
						     }

		else if((x>540&&x<638)&&y<20){
					      screen_saver();
					      }

		else if((x>540&&x<630)&&(y>25&&y<40))
						     {
						      setdisk(2);
						      rmdir("ROZ.EXE");
						      rmdir("ROZ.OBJ");
						      exit(1);
						      }

		else if((x>540&&x<585)&&(y>43&&y<58))
						     { s=2;
						       p=540;
						       setplace_file(p,s);
						       content();
						       }


		else if( c==1&&(x>102)       || c==1&&(x>10&&x<102)&&(y<40||y>105)||
			 c==2&&(x<105||x>198)|| c==2&&(x>120&&x<198)&&(y<40||y>105)||
			 c==3&&(x<200||x>305)|| c==3&&(x>222&&x<300)&&(y<40||y>75)||
			 c==4&&(x<310||x>420)|| c==4&&(x>330&&x<410)&&(y<40||y>75) )

			pre_menu();

		}//end of if(b==1)
	 }//end of while(1)
}
//**************
void initmouse()
{
 in.x.ax=0;
 int86 ( 0x33,&in,&out);
}

void showmouse()
{
 in.x.ax=1;
 int86 ( 0x33,&in,&out);
}

void hidemouse()
{
 in.x.ax=2;
 int86 ( 0x33,&in,&out );
}

void getmouse(int &button,int &x,int &y)
{
 in.x.ax=3;
 int86 ( 0x33,&in,&out );
 button=out.x.bx;
 x=out.x.cx;
 y=out.x.dx;
}
//****************
void win ( int a , int b   , int c  , int d  )
{
 union REGS regs;
 regs.x.ax = 07 ;
 regs.x.cx = a ;
 regs.x.dx = c ;
 int86 (0x33 , &regs, &regs);

 regs.x.ax = 8 ;
 regs.x.cx = d ;
 regs.x.dx = b ;
 int86 (0x33 , &regs, &regs);
}
//*******************************
void setplace_file(int p,int s)
{
 union REGS regs;
 regs.x.ax = 04;
 regs.x.cx =p;
 if(s==1)
 regs.x.dx =40;
 else
 regs.x.dx =47;
 int86(0x33, &regs, &regs );
}
//*************************************
void pre_menu()
{
 setfillstyle(1,LIGHTGRAY);
 bar(9,41,91,105);
 bar(120,41,190,105);
 bar(220,41,305,75);
 bar(330,41,420,75);
 line(9,40,91,40);
 line(120,40,190,40);
 line(220,40,310,40);
 line(330,40,420,40);
}
//**************
void file_n();
void file_o();
//***************
void file_menu(int &c)
{
 int b,x,y,row,culmn;
 setfillstyle(1,BLUE);
 bar(10,40,90,105);
 rectangle(10,40,90,105);
 settextstyle(2, HORIZ_DIR,5);
	moveto(25,50);
	outtext("NEW");
 line(10,60,90,60);
	moveto(25,65);
	outtext("OPEN");
 line(10,75,90,75);
	moveto(25,80);
	outtext("PRINT");
 line(10,90,90,90);
	moveto(25,95);
	outtext("EXIT");
 c=1;
 row=getmaxx()/2;
 culmn=getmaxy()/2;
 char *str;
 while(1){
	  getmouse(b,x,y);
	  if(b==1){

		   if(x>10&&x<90&&y>40&&y<60){
			   bar(row-200,culmn-67,row+200,culmn-47);
			   rectangle(row-200,culmn-67,row+200,culmn-47);
			   outtextxy(row-190,culmn-59,"Enter File Adress :");
			   hidemouse();
			   graphdefaults();
			   file_n();
			   break;
			   }

		  if(x>10&&x<90&&y>60&&y<75){
			   bar(row-200,culmn-67,row+200,culmn-47);
			   rectangle(row-200,culmn-67,row+200,culmn-47);
			   outtextxy(row-190,culmn-59,"Enter File Adress :");
			   hidemouse();
			   graphdefaults();
			   file_o();
			   break;
			   }

	   if(x>10&&x<90&&y>90&&y<105){
			   setcolor(LIGHTMAGENTA);
			   setfillstyle(1,YELLOW);
			   bar(row-200,culmn-77,row+200,culmn-37);
			   rectangle(row-198,culmn-75,row+198,culmn-39);
			   outtextxy(row-75,culmn-65,"We hope you enjoy it");
			   outtextxy(row-30,culmn-50,"Good Bye");
			   sleep(2);
			   hidemouse();
			   exit(1);
			   }


	   else if(x>10&&x<90&&!(y>40&&y<105)||x<10||x>100)
			  break;

		    }//end of if(b==1)
	  }//end of while(1)
 showmouse();
 hidemouse();
 menu();
}
//**********************
void edit_cpy(int);
void edit_del();
void edit_ren();
//*************************
void edit_menu (int &c)
{
 int b,x,y,q;
 setfillstyle(1,BLUE);
 bar(120,40,188,105);
 rectangle(120,40,188,105);
 settextstyle(2, HORIZ_DIR,5);
	moveto(125,50);
	outtext("Cut");
 line(120,60,188,60);
	moveto(125,65);
	outtext("Copy");
 line(120,75,188,75);
	moveto(125,80);
	outtext("Delete");
 line(120,90,188,90);
	moveto(125,95);
	outtext("Rename");
 c=2;
 while(1){
	  getmouse(b,x,y);
	  if(b==1){

		     if(x>120&&x<188&&y>40&&y<60){
						   q=1;
						   edit_cpy(q);
						   break;
						  }

		     if(x>120&&x<188&&y>60&&y<75){
						   q=2;
						   edit_cpy(q);
						   break;
						  }

		     if(x>120&&x<188&&y>75&&y<90){
						   edit_del();
						   break;
						  }

		     if(x>120&&x<188&&y>90&&y<105){
						    edit_ren();
						    break;
						   }

		    else if(x>120&&x<188&&!(y>40&&y<105)||x<120||x>200)
						    break;

		  }//end of if(b==1)
	  }//end of while(1)
 showmouse();
 hidemouse();
 menu();
}
//*********************
void folder_n(int);
//*************************
void folder_menu(int &c)
{
 int b,x,y,q;
 setfillstyle(1,BLUE);
 bar(222,40,300,75);
 rectangle(222,40,300,75);
 settextstyle(2, HORIZ_DIR,5);
	moveto(230,50);
	outtext("New");
 line(222,60,300,60);
	moveto(230,65);
 outtext("Delete");
 c=3;
 while(1){
	  getmouse(b,x,y);
	  if(b==1){

		   if(x>222&&x<300&&y>40&&y<60){
						 q=1;
						 folder_n(q);
						 break;
						}

		   if(x>222&&x<300&&y>60&&y<75){
						 q=2;
						 folder_n(q);
						 break;
						}

		   if(x>222&&x<300&&!(y>40&&y<60)||x<222||x>305)
						 break;
		  }//end of if(b==1)
	  }//end of while(1)
 showmouse();
 hidemouse();
 menu();
}
//***************************
void proper_time();
void proper_drive();
//****************************
void property_menu(int &c)
{
 int b,x,y;
 setfillstyle(1,BLUE);
 bar(330,40,410,75);
 rectangle(330,40,410,75);
 settextstyle(2, HORIZ_DIR,5);
	moveto(335,50);
	outtext("Time");
 line(330,60,410,60) ;
	moveto(335,65);
	outtext("Directory");
 c=4;
 while(1){
	   getmouse(b,x,y);
	   if(b==1){

		    if(x>330&&x<410&&y>40&&y<60){
						  proper_time();
						  break;
						  }

		    if(x>330&&x<410&&y>60&&y<75){
						  proper_drive();
						  break;
						  }

	      if(x>330&&x<410&&!(y>40&&y<75)||x<330||x>420)
							   break;
	      }//end of if(b==1)
	   }//end of while(1)
 showmouse();
 hidemouse();
 menu();
}
//*********************************
void help_menu()
{
 setfillstyle(1,DARKGRAY);
 bar(1,160,550,375);

 setcolor(WHITE);
 rectangle(150,260,400,280);
 outtextxy(160,270,"Press any key to countinue...");

 setcolor(LIGHTRED);
 outtextxy(1,200,"File");
 outtextxy(1,350,"Folder");
 outtextxy(300,200,"Edit");
 outtextxy(300,350,"Property");

 setcolor(LIGHTGREEN);
 line(30,205,150,170);
 line(30,205,150,190);
 line(30,205,150,210);
 line(30,205,150,230);

 line(45,355,155,340);
 line(45,355,155,370);

 line(330,205,450,170);
 line(330,205,450,190);
 line(330,205,450,210);
 line(330,205,450,230);

 line(365,355,455,340);
 line(365,355,455,370);

 setcolor(LIGHTMAGENTA);
 outtextxy(150,165,"New");
 outtextxy(150,185,"Open");
 outtextxy(150,205,"Print");
 outtextxy(150,225,"Exit");

 outtextxy(155,335,"New");
 outtextxy(155,365,"Delete");

 outtextxy(450,165,"Cut");
 outtextxy(450,185,"Copy");
 outtextxy(450,205,"Delete");
 outtextxy(450,225,"Rename");

 outtextxy(455,335,"Time");
 outtextxy(455,365,"Directory");

 setfillstyle(1,YELLOW);
 bar(100,375,450,445);
 setcolor(LIGHTBLUE);
 outtextxy(120,390,"For more information contact us at:");
 outtextxy(170,420,"IT.Zarza @ gmail.com");
 outtextxy(170,435,"Hergholi @ yahoo.com");

 getch();
 hidemouse();
 menu();
}
//***********************
void screen_saver()
{
 clrscr();
 float k,x,y,i,j;
 float pi = 3.14159;
 int d,s;
 int m=1;
 while(!kbhit()){
		  setcolor(m++);
		  s=0;
		  d=rand()%101;
		  do {
		      i = 38+2*d*cos(pi*s/190);
		      j = 175+2*d*sin(pi*s/190);
		      x = (int)i;
		      y = (int)j;
		      circle(x+s,y,(int)y/6);
		      s=s+3;
		      delay(100);
		      } while (!kbhit()&&s<550);   //end of do while()

		  outtextxy(260,10,"Himan Zarza");
		  outtextxy(260,20,"Fadel Hergholi");
		  sleep(3);
		  clearviewport();
		  if(m>15)
		  m=1;

		}// end of while()

 getch();
 hidemouse();
 showmouse();
 menu();
}
//***********************************************
void content_display(char *ptr[135],int &conut);
void content_ch(char *ptr[135],char dir[MAXDIR]);
//************************************************
void content()
{
 char *ptr[135];
 int count=0;
 char dir[MAXDIR];
 bar(0,65,600,420);
 setfillstyle(1,DARKGRAY);
 setcolor(YELLOW);

 bar(0,45,50,60);
 outtextxy(7,51,"<----");

 bar(150,45,165,60);
 outtextxy(154,51,"A");

 bar(185,45,200,60);
 outtextxy(189,51,"C");

 bar(220,45,235,60);
 outtextxy(224,51,"D");

 bar(255,45,270,60);
 outtextxy(259,51,"E");

 bar(290,45,305,60);
 outtextxy(294,51,"F");

 bar(325,45,340,60);
 outtextxy(329,51,"G");

 bar(360,45,375,60);
 outtextxy(364,51,"H");

 setfillstyle(1,BLUE);
 bar(0,64,600,430);
 rectangle(0,80,600,430);
 rectangle(98,80,100,430);
 rectangle(198,80,200,430);
 rectangle(298,80,300,430);
 rectangle(398,80,400,430);
 rectangle(498,80,600,430);
 outtextxy(30,68,"Curent Directory is :");

 graphdefaults();
 getcurdir(0,dir);
 gotoxy(27,5);
 printf("%c:\\%s",getdisk()+'A',dir) ;

 setcolor(YELLOW);
 rectangle(0,63,600,79);
 flushall();
 content_display(ptr,count);
 content_ch(ptr,dir);
 hidemouse();
 showmouse();
 menu();
}
//***************
void file_n()
{
 FILE *fp;
 long char ch;
 char fn[50],mode;
 gotoxy(38,12);
 gets(fn);
 fp=fopen(fn,"w+t");
 if(!fp){
	 printf("\n");
	 printf("cannot open file.");
	 getch();
	 menu();
	}
 normvideo();
 setcolor(BLUE);
 outtextxy(0,120,"Enter string (press  <Shift+\\>  to end)");

 setviewport(0,130,639,479,1);
 clearviewport();
 graphdefaults();

 gotoxy(1,10);
 while(1){
	  scanf("%c",&ch);
	  if(ch=='\r'){
		       printf("\n");
		       ch='`';
		       }
	  if(ch=='|')
		     break;
	  fputc(ch,fp);
	  }
 fflush(fp);
 fclose(fp) ;
}
//***************
void file_o()
{
 FILE *fp;
 long char ch;
 char fn[50],mode;
 gotoxy(38,12);
 gets(fn);
 fp=fopen(fn,"r+t");
 if(!fp){
	 printf("\n");
	 printf("cannot open file.");
	 getch();
	 menu();
	 }
 normvideo();
 setcolor(BLUE);
 outtextxy(0,120,"the content of file is:");

 setviewport(0,130,639,479,1);
 clearviewport();
 graphdefaults();

 gotoxy(1,10);
 ch=fgetc(fp);
 while(ch!=EOF){
		if(ch=='`')
			    printf("\n");
		else
		     printf("%c",ch);
	       ch=fgetc(fp);
	       }//end of while
 fclose(fp) ;
 getch();
}
//**************************************
int file_copy(char *oldn,char *newn);
//***************************************
void edit_cpy(int q)
{
 FILE *fp;
 long char ch;
 int row,culmn;
 row=getmaxx()/2;
 culmn=getmaxy()/2;
 char fn[50],mode;
 char source[80],dist[80],*tok,*tbt,*tst;

	      bar(row-210,culmn-100,row+200,culmn-75);
	      rectangle(row-210,culmn-100,row+200,culmn-75);
	      outtextxy(row-205,culmn-92,"Enter File Adress :");
	      gotoxy(38,10);
	      graphdefaults();
	      gets(fn);

	      setcolor(LIGHTBLUE);
	      setfillstyle(1,LIGHTGREEN);
	      bar(row-210,culmn-55,row+200,culmn-30);
	      rectangle(row-210,culmn-55,row+200,culmn-30);
	      outtextxy(row-205,culmn-43,"Enter distnation file:");
	      gotoxy(38,13);
	      graphdefaults();
	      gets(dist);

 strcpy(tbt,fn);
 tok=strtok(tbt,"\\");
 while(tok!=NULL){
		  strcpy(tst,tok);
		  tok=strtok(NULL,"\\");
		  }
 strcat(dist,tst);

		setcolor(LIGHTGREEN);
 if(file_copy(fn,dist)==0){
		      setfillstyle(1,YELLOW);
		      bar(row-140,culmn-20,row+100,culmn);
		      rectangle(row-140,culmn-20,row+100,culmn);
		      outtextxy(row-130,culmn-10,"copy operation successful");

		     if(q==1)
			      remove(fn);
		      }//end of if(file_copy(fn,dist)==0)
 else{
       setfillstyle(1,RED);
       bar(row-150,culmn-20,row+130,culmn);
       rectangle(row-150,culmn-20,row+130,culmn);
       outtextxy(row-120,culmn-10,"error during copy operation");
      }// end of else
 sleep(2);
}
//*****************************************
int file_copy(char *oldn,char *newn)
{
 FILE *fold,*fnew;
 char c;
 if((fold= fopen(oldn,"r(r+t)"))==NULL)
				       return -1;
 if((fnew=fopen(newn,"w+(w+t)"))==NULL)
				       return -1;

 while(1)
	 {
	   c=fgetc(fold);
	   if(!feof(fold))
			  fputc(c,fnew);
	   else
		break;
	  }//end of while(1)
 fclose (fnew);
 fclose(fold);
 return(0);
}
//****************
void edit_del()
{
 FILE *fp;
 char fn[50],mode;
 char ans='y';
 int row,culmn;
 row=getmaxx()/2;
 culmn=getmaxy()/2;
 hidemouse();
	   bar(row-200,culmn-67,row+200,culmn-47);
	   rectangle(row-200,culmn-67,row+200,culmn-47);
	   outtextxy(row-190,culmn-59,"Enter File Adress :");
	   graphdefaults();
	   gotoxy(38,12);
	   gets(fn);

	   setfillstyle(1,LIGHTRED);
	   bar(row-140,culmn-35,row+100,culmn-15);
	   rectangle(row-140,culmn-35,row+100,culmn-15);
	   outtextxy(row-130,culmn-25,"Are you sure ?(Y,N)");
	   graphdefaults();
	   gotoxy(45,14);
	   if(ans=='y'){
			ans=getchar();
			remove(fn);
			}
}
//************************
void edit_ren()
{
 FILE *fp;
 char fn[50],mode;
 char *newe,*tok,*tbt,*tst;
 int row,culmn;
 row=getmaxx()/2;
 culmn=getmaxy()/2;
 hidemouse();
	   bar(row-200,culmn-67,row+200,culmn-47);
	   rectangle(row-200,culmn-67,row+200,culmn-47);
	   outtextxy(row-190,culmn-59,"Enter File Adress :");
	   graphdefaults();
	   gotoxy(38,12);
	   gets(fn);

	   setcolor(LIGHTBLUE);
	   setfillstyle(1,LIGHTGREEN);
	   bar(row-200,culmn-38,row+200,culmn-15);
	   rectangle(row-200,culmn-38,row+200,culmn-15);
	   outtextxy(row-190,culmn-28,"Enter New name :");
	   graphdefaults();
	   gotoxy(38,14);
	   gets(newe);

 strcpy(tbt,fn);
 strtok(tbt,"\\");
 strcat(tbt,"\\");
 strcat(tbt,newe);

	    setcolor(BLUE);
	    setfillstyle(1,LIGHTRED);
	    bar(row-130,culmn-10,row+90,culmn+5);
	    rectangle(row-130,culmn-10,row+90,culmn+5);
	    if(rename(fn,tbt)==0)
				outtextxy(row-80,culmn-7,"Rename complited");
	    else{
		  bar(row-130,culmn-10,row+90,culmn+5);
		  rectangle(row-130,culmn-10,row+90,culmn+5);
		  outtextxy(row-80,culmn-7,"Erorr in renaming");
		  }
 sleep(1);
}
//*********************
void folder_n(int q)
{
 FILE *fp;
 char fn[50],mode;
 int b,x,y,row ,culmn;
 row=getmaxx()/2;
 culmn=getmaxy()/2;
 hidemouse();

	   setfillstyle(1,BLUE);
	   bar(row-200,culmn-67,row+200,culmn-47);
	   rectangle(row-200,culmn-67,row+200,culmn-47);
	   outtextxy(row-190,culmn-59,"Enter Adress : ");
	   graphdefaults();
	   gotoxy(38,12);
	   gets(fn);

	   setcolor(BLACK);
	   setfillstyle(1,LIGHTRED);
	   bar(row-70,culmn-37,row+70,culmn-17);
	   rectangle(row-70,culmn-37,row+70,culmn-17);
	   if(q==1){
		    if(!mkdir(fn))
				  outtextxy(row-60,culmn-27,"Folder created");
		     else
		     outtextxy(row-20,culmn-27,"Error");
		    }//end of if(q==1)

	    else if(q==2){
			  if(!rmdir(fn))
				  outtextxy(row-60,culmn-27,"folder removed");
			  else
				   outtextxy(row-20,culmn-27,"Error");
			  }//end of else if(q==2)

 sleep(1);
}
//***********************
void proper_time()
{
 int b,x,y,row,culmn;
 int h,m,s;
 row=getmaxx()/2;
 time_t curtime;
 culmn=getmaxy()/2;
		 setcolor(LIGHTGREEN);
		 setfillstyle(1,BROWN) ;
		 bar3d(row-250,culmn-70,row-50,culmn-40,4,6);
		 outtextxy(row-190,culmn-55,"Show Time");

		 bar3d(row+50,culmn-70,row+250,culmn-40,4,6);
		 outtextxy(row+110,culmn-55,"Set Time");
		 graphdefaults();
 while(1){
       getmouse(b,x,y) ;
       if(b==1){
	     if(x>69&&x<269&&y>169&&y<199){
				 while (!kbhit()){
					       gotoxy(52,10);
					       printf("  ");
					       time(&curtime);
					       gotoxy(26,10);
					       printf("  %s",ctime(&curtime));
					       sleep(1);
						  }// end of while (!kbhit())
				 break;
				 }//end of if

	       if(x>369&&x<569&&y>169&&y<199){
				   setfillstyle(1,GREEN);
				   setcolor(MAGENTA);
				   bar(row-50,culmn-38,row+50,culmn+20);
				   rectangle(row-50,culmn-38,row+50,culmn+20);
				   outtextxy(row-40,culmn-25,"Hour ");
				   outtextxy(row-40,culmn-10,"Minute ");
				   outtextxy(row-40,culmn+5,"Second ");
				   gotoxy(45,14);
				   scanf("%d",&h);
				   gotoxy(45,15);
				   scanf("%d",&m);
				   gotoxy(45,16);
				   scanf("%d",&s);
				   struct time t;
						 t.ti_hour=h;
						 t.ti_min=m;
						 t.ti_sec=s;
						 t.ti_hund=0;
				   settime(&t);
				   break;
				   }// end of if


	       if(x>69&&x<169&&!(y>169&&y<199)||
	       x>369&&x<569&&!(y>40&&y<60||y>169&&y<199)
	       ||x<69||x>169&&x<369||x>569)
				    break;
	     }//end of if(b==1)
       }// end of while(1)
 showmouse();
 hidemouse();
 menu();
}
//*************************
void proper_drive()
{
 int b,x,y;
 char ds[]={'f','\0'};
 ds[0]=getdisk()+'A';

 setfillstyle(1,BLUE);
 outtextxy(210,250,"Current Drive :");
 setcolor(LIGHTBLUE);
 outtextxy(330,250,ds);
 setcolor(LIGHTRED);
 ellipse(275,250,0,360,80,30);

  bar3d(100,100,150,140,3,4);
  outtextxy(120,120,"A");

  bar3d(100,190,150,230,3,4);
  outtextxy(120,210,"C");

 bar3d(100,290,150,330,3,4);
 outtextxy(120,310,"D");

 bar3d(260,390,310,430,3,4);
 outtextxy(280,410,"E");

 bar3d(400,100,450,140,3,4);
 outtextxy(420,120,"F");

 bar3d(400,190,450,230,3,4);
 outtextxy(420,210,"G");

 bar3d(400,290,450,330,3,4);
 outtextxy(420,310,"H");

 while(1){
	  getmouse(b,x,y);
	  if(b==1){

		   if(x>100&&x<150&&y>100&&y<140){
						   setdisk(0);
						   break;
						   }

		    else if(x>100&&x<150&&y>190&&y<230){
							 setdisk(2);
							 break;
							 }

		    else if(x>100&&x<150&&y>290&&y<330){
							 setdisk(3);
							 break;
							 }

		    else if(x>260&&x<310&&y>390&&y<430){
							 setdisk(4);
							 break;
							 }

		    else if(x>400&&x<450&&y>100&&y<140){
							 setdisk(5);
							 break;
							 }

		    else if(x>400&&x<450&&y>190&&y<230){
							 setdisk(6);
							 break;
							 }

		    else if(x>400&&x<450&&y>290&&y<330){
							 setdisk(7);
							 break;
							 }

		 }//end of if(b==1)
	}//end of while(1)

}
//**********************************************
void content_display(char *ptr[135],int &count)
{
 int b,x,y;
 char str[135][80];
 char c1;
 char *temp;
 int in,out,i=2,j=90;
 struct ffblk f;
 register int done;
	   done=findfirst("*.*",&f,16);
	   while(!done&&count<135){
			   strcpy(str[count],f.ff_name);
			   done=findnext(&f);
			   if(!str[count][0])
					      break;
			   *(ptr+count++)=str[count];
			   }//end of while

for(out=count-1;out>0;out--)
	 for(in=0;in<out;in++)
		   if(strcmp(*(ptr+in),*(ptr+in+1))>0){
						 temp=*(ptr+in);
						 *(ptr+in)=*(ptr+in+1);
						 *(ptr+in+1)=temp;
						 }//end of if
 moveto(i,j);
 for(out=0;out<count;out++){
			     outtext(*(ptr+out));
			     j+=15;
			     if(j>420){
				       i+=100;
				       j=90;}
			     moveto(i,j);
			     }//end of for
}
//****************************************************
void content_ch_choose(char *ptr[135],int x,int y);
//*****************************************************
void content_ch(char *ptr[135],char dir[MAXDIR])
{
 int b,x,y,p,s;
 int i=3;
 char *str,*tbt,c='\\';
 tbt=(char*)malloc(sizeof(char));
 str=(char*)malloc(sizeof(char));
 str=strrchr(dir,c);
 gotoxy(10,10);
while(1){
	getmouse(b,x,y);
	if(b==1){

		 if(x<50&&y>45&&y<60){
				       p=51;
				       s=2;
				       setplace_file(p,s);
				       delay(250);
				       printf("%d",str-dir+3);
				      while(i<(str-dir+3)){
							  *(tbt+i)=*(dir+i-3);
							  i++;}//end of while

				      *(tbt+i)='\0';
				      *(tbt+0)=getdisk()+'A';
				      *(tbt+1)=':';
				      *(tbt+2)='\\';
				      puts(tbt);
				      chdir(tbt);
				      free(tbt);
				      free(str);
				      flushall();
				      content();

				      }//end of if


		 else if(x>150&&x<165&&y>45&y<60){
						   p=166 ;
						   s=2;
						   setdisk(0);
						   setplace_file(p,s);
						   delay(250);
						   content();
						   }//end of if

		 else if(x>180&&x<200&&y>45&&y<60){
						    p=201;
						    s=2;
						    setdisk(2);
						    setplace_file(p,s);
						    delay(250);
						    content();
						    }//end of if

		 else if(x>220&&x<235&&y>45&&y<60){
						    p=236;
						    s=2;
						    setdisk(3);
						    setplace_file(p,s);
						    delay(250);
						    content();
						    }//end of if

		  else if(x>255&&x<270&&y>45&&y<60){
						     p=271;
						     s=2;
						     setdisk(4);
						     setplace_file(p,s);
						     delay(250);
						     content();
						     }//end of if

		  else if(x>290&&x<305&&y>45&&y<60){
						     p=306;
						     s=2;
						     setdisk(5);
						     setplace_file(p,s);
						     delay(250);
						     content();
						     }//end of if

		 else if(x>325&&x<340&&y>45&&y<60){
						     p=341;
						     s=2;
						     setdisk(6);
						     setplace_file(p,s);
						     delay(250);
						     content();
						     }//end of if

		 else if(x>360&&x<375&&y>45&&y<60){
						     p=376;
						     s=2;
						     setdisk(7);
						     setplace_file(p,s);
						     delay(250);
						     content();
						     }//end of if

		 else if(x>585&&y>43&&y<58){
					     p=540;
					     s=2;
					     setplace_file(p,s);
					     break;
					    }//end of if

		 else if(x>0&&x<600){
				      content_ch_choose(ptr,x,y);
				      break;
				      }//end of if
		}//end of if(b==1)
	}//end of while
}
//***************************************************
void content_ch_choose(char *ptr[135],int x,int y)
{
 FILE *stream;
 FILE *fp;
 long char ch;
 struct ftime ft;
 int p,m,n,z,b,u,v;
 char *tok,*tst,*tbt;
 tok=new char;
 tst=new char;
 tbt=new char;
 z=y-85;
 z=z/15;
 if(z>=0&&z<=22){
	 if(x>100&&x<200) z+=23;
	 if(x>200&&x<300) z+=47;
	 if(x>300&&x<400) z+=71;
	 if(x>400&&x<500) z+=95;
	 if(x>500&&x<600) z+=119;
	 graphdefaults();
	 gotoxy(25,28);

	 if ((stream = fopen(*(ptr+z),"r+t")) == NULL)
		       {
			 printf("--------------------DIR-------------------");
			 delay(250);
			 while(1){
				  getmouse(p,m,n);
				  if(p==1)
				       if(m>x-20&&m<x+20&&n>y-4&&n<y+4&&m==x){
						       chdir(*(ptr+z));
						       fflush(stream);
						       fclose(stream);
						       setplace_file(100,100);
						       content();
						       }//end of if
				       else
					    break;
				  }//end of while
			 }//end of if
	  else{
		getftime(fileno(stream), &ft);
		printf("Last modified: %u:%u:%u     ",
		       ft.ft_hour, ft.ft_min,ft.ft_tsec * 2);
		printf("     %u/%u/%u",
		       ft.ft_month, ft.ft_day,ft.ft_year+1980);

		fclose(stream);
		fflush(stream);
		flushall();
		delay(250);
		while(1){
			 getmouse(b,u,v);
			 if(b==1)
				 if(u==x){
				       setplace_file(10,1);
				       strcpy(tbt,*(ptr+z));
				       tok=strtok(tbt,".");
				       while(tok!=NULL){
							 strcpy(tst,tok);
							 tok=strtok(NULL,".");
							}//end of while
				       strupr(tst);
			 if((strcmp("TXT",tst)==0)||(strcmp("CPP",tst)==0)) {
					 (fp = fopen(*(ptr+z),"r+t"));
					 setviewport(0,63,639,479,1);
					 clearviewport();
					 graphdefaults();
					 gotoxy(1,5) ;
					 printf("File name: %s\t\t\t\t\tpress any key to exit\n",*(ptr+z)) ;
					 for(int t=0;t<80;t++)
					 printf("%c",205);
					 gotoxy(1,7);
					 ch=fgetc(fp);
					 while(ch!=EOF){
							if(ch=='`')
								 printf("\n");
							else
							     printf("%c",ch);
							ch=fgetc(fp);
							}//end of while
							getch();
					 fclose(fp) ;
					 flushall();

					 }//end of if
					 break;
					 }//end of if(u==x)
			  else
			       break;
			  }//end of if(b==1)
		  }//end of while(1)
	   }//end of else
}
//*********************************************
void main(){
 int driver = VGA, mode=2;
 initgraph(&driver,&mode, "");
 menu();
 getch();
}