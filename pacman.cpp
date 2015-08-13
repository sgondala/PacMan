#include <simplecpp>


void blue(float x,float y){
Rectangle r(x,y,20,20);
r.setFill(true);
r.setColor(COLOR("blue"));
r.imprint();}//to be used in fill


void fill(int p,int q,int r,int c,bool a[][27]){
for(int i=0;i<r;i++){
for(int j=0;j<c;j++){
blue(54+20*p+20*j,60+20*q+20*i);
a[q+i][p+j]=false;
}}}
//This is used to make blue boxes and create path 
//every box is made by union of a finite no. of small squares. 
//p,q gives the initial coordinates from which the required rectangle is to be drawn
//r,c are no. of rows and columns


void gameover(int x,int y,int xg1,int yg1,int xg2,int yg2,int xg3,int yg3,int xg4,int yg4,int s0){
if(((x==xg1)&&(y==yg1))||((x==xg2)&&(y==yg2))||((x==xg3)&&(y==yg3))||((x==xg4)&&(y==yg4)))
	{Text t11(700,350,"game over");
	wait(6);
		closeCanvas();};}//game over
		
		
void black(int i,int j,int &s){
//i,j is used in coordinates of center of dots and s stands for score 
Circle c(20*j+44,20*i+50,5);
c.setFill(true);
c.setColor(COLOR("black"));
c.imprint();s=s+10;
if(s==2940){closeCanvas();cout<<" u won " <<endl;}}
// to blacken the red dots


int ab(int x){
	if(x>=0)return x;
	else return (-x);}
	//absolute value of x
	

void check(int &xg,int &yg){//checking if ghost is at a transporting point
if((xg==564)&&(yg==330)){
xg=69;return;
};		
if((xg==64)&&(yg==330)){
xg=559;return;
}}




bool possible(int x,int y,char c,char current,int blackSquare[][28]){
	int p=x-44,q=y-50;//this is done because the origin is not at the top of gamemap
if(current=='l'){return false;}
//this solely serves the purpose of executing the command at proper time
	//that is taking a turn at possible positions only ,even when it is asked to do it before
	//and at the same time doing what is asked(excluding time)//finds if there is a chance for //pacman to take a turn 
	//and in case of ghosts it even helps for moving straight 

if(c==current){
	if(c=='d'){
	if((p%20!=0)){return true;}
	if((p%20==0)&&(q%20!=0)){return false;}
	if((p%20==0)&&(q%20==0)&&(blackSquare[(q/20)][(p/20)+1]==1)){return true;}
	else return false;
	//the order in which logic is applied plays an important role
	};
	
	if(c=='s'){
	if((q%20!=0)){return true;}
	if((q%20==0)&&(p%20!=0)){return false;}
	if((p%20==0)&&(q%20==0)&&(blackSquare[(q/20)+1][(p/20)]==1)){return true;}
	else return false;
	};
	
	if(c=='a'){
	if((p%20!=0)){return true;}
	if((p%20==0)&&(q%20!=0)){return false;}
	if((p%20==0)&&(q%20==0)&&(blackSquare[(q/20)][(p/20)-1]==1)){return true;}
	else return false;
	};
	
	if(c=='w'){
	if((q%20!=0)){return true;}
	if((q%20==0)&&(p%20!=0)){return false;}
	if((p%20==0)&&(q%20==0)&&(blackSquare[(q/20)-1][(p/20)]==1)){return true;}
	else return false;
	}}
	
	//We used current=c only in case of ghosts motion(in function motion)
	//so that ghost would not take a turn at unecessary points
	
	
	else{
	if(c=='a'){if(current=='w'){
	if((p%20==0)&&(q%20==0)&&(blackSquare[(q/20)-1][(p/20)]==1)){return true;}
	else return false;};
	if(current=='s'){
	if((p%20==0)&&(q%20==0)&&(blackSquare[(q/20)+1][(p/20)]==1)){return true;}
	else return false;};
	if(current=='d'){
	return true;}}
	
	
    if(c=='s'){if(current=='a'){
	if((p%20==0)&&(q%20==0)&&(blackSquare[(q/20)][(p/20)-1]==1)){return true;}
	else return false;};
	if(current=='d'){
	if((p%20==0)&&(q%20==0)&&(blackSquare[(q/20)][(p/20)+1]==1)){return true;}
	else return false;}
	if(current=='w'){
	return true;}}
	
	
	if(c=='d'){if(current=='w'){
	if((p%20==0)&&(q%20==0)&&(blackSquare[(q/20)-1][(p/20)]==1)){return true;}
	else return false;};
	if(current=='s'){
	if((p%20==0)&&(q%20==0)&&(blackSquare[(q/20)+1][(p/20)]==1)){return true;}
	else return false;};
	if(current=='a'){
	return true;}}
	
		
	if(c=='w'){if(current=='a'){
	if((p%20==0)&&(q%20==0)&&(blackSquare[(q/20)][(p/20)-1]==1)){return true;}
	else return false;};
	if(current=='d'){
	if((p%20==0)&&(q%20==0)&&(blackSquare[(q/20)][(p/20)+1]==1)){return true;}
	else return false;};
	if(current=='s'){
	return true;}}}
	
	}
	
	


void shortestPath(int &xg,int &yg,int x,int y,char &cg,int blackSquare[][28]){
//ghosts finds the shortest path to pac man and follows it

       if(((x-xg)>0)&&((y-yg)>0)){
	   if(cg!='a'){if(possible(xg,yg,cg,'d',blackSquare)){xg=xg+5;cg='d';return;}};
       if(cg!='w'){ if(possible(xg,yg,cg,'s',blackSquare)){yg=yg+5;cg='s';return;}};
       if(cg!='d') {if(possible(xg,yg,cg,'a',blackSquare)){xg=xg-5;cg='a';return;}};
       if(cg!='s'){if(possible(xg,yg,cg,'w',blackSquare)){yg=yg-5;cg='w';return;}};
       };
        
   if(((x-xg)<0)&&((y-yg)>0)){
	   if(cg!='d'){if(possible(xg,yg,cg,'a',blackSquare)){xg=xg-5;cg='a';return;}};
       if(cg!='w') {if(possible(xg,yg,cg,'s',blackSquare)){yg=yg+5;cg='s';return;}};
       if(cg!='s'){ if(possible(xg,yg,cg,'w',blackSquare)){yg=yg-5;cg='w';return;}};
       if(cg!='a'){if(possible(xg,yg,cg,'d',blackSquare)){xg=xg+5;cg='d';return;}};
       };
        
   if(((x-xg)<0)&&((y-yg)<0)){
	   if(cg!='d'){if(possible(xg,yg,cg,'a',blackSquare)){xg=xg-5;cg='a';return;}};
       if(cg!='s'){if(possible(xg,yg,cg,'w',blackSquare)){yg=yg-5;cg='w';return;}};
       if(cg!='a') { if(possible(xg,yg,cg,'d',blackSquare)){xg=xg+5;cg='d';return;}};
       if(cg!='w'){if(possible(xg,yg,cg,'s',blackSquare)){yg=yg+5;cg='s';return;}};
      };
 
   if(((x-xg)>0)&&((y-yg)<0)){
	   if(cg!='s'){if(possible(xg,yg,cg,'w',blackSquare)){yg=yg-5;cg='w';return;}};
       if(cg!='a'){if(possible(xg,yg,cg,'d',blackSquare)){xg=xg+5;cg='d';return;}};
       if(cg!='w'){if(possible(xg,yg,cg,'s',blackSquare)){yg=yg-5;cg='s';return;}};
	   if(cg!='d'){if(possible(xg,yg,cg,'a',blackSquare)){xg=xg-5;cg='a';return;}};
        };
        
     if(((x-xg)==0)&&((y-yg)>0)){ 
	  if(cg!='w'){if(possible(xg,yg,cg,'s',blackSquare)){yg=yg+5;cg='s';return;}};
      if(cg!='a')  {if(possible(xg,yg,cg,'d',blackSquare)){xg=xg+5;cg='d';return;}};
	  if(cg!='d') { if(possible(xg,yg,cg,'a',blackSquare)){xg=xg-5;cg='a';return;}};
	  if(cg!='s'){if(possible(xg,yg,cg,'w',blackSquare)){yg=yg-5;cg='w';return;}};
	  }
	
	  if(((x-xg)==0)&&((y-yg)<0)){ 
		   if(cg!='s'){if(possible(xg,yg,cg,'w',blackSquare)){yg=yg-5;cg='w';return;}};
	  if(cg!='d') { if(possible(xg,yg,cg,'a',blackSquare)){xg=xg-5;cg='a';return;}};
	   if(cg!='a') {if(possible(xg,yg,cg,'d',blackSquare)){xg=xg+5;cg='d';return;}};
	    if(cg!='w'){if(possible(xg,yg,cg,'s',blackSquare)){yg=yg+5;cg='s';return;}};
	   }
	
	
     if(((y-yg)==0)&&((x-xg)<0)){  
	  if(cg!='d') { if(possible(xg,yg,cg,'a',blackSquare)){xg=xg-5;cg='a';return;}};
	  if(cg!='s')  {if(possible(xg,yg,cg,'w',blackSquare)){yg=yg-5;cg='w';return;}};
     if(cg!='w') {  if(possible(xg,yg,cg,'s',blackSquare)){yg=yg+5;cg='s';return;}};
      if(cg!='a'){if(possible(xg,yg,cg,'d',blackSquare)){xg=xg+5;cg='d';return;}};
     };
                                                                       
       if(((y-yg)==0)&&((x-xg)>0)){  
	  if(cg!='a') { if(possible(xg,yg,cg,'d',blackSquare)){xg=xg+5;cg='d';return;}};
      if(cg!='w') { if(possible(xg,yg,cg,'s',blackSquare)){yg=yg+5;cg='s';return;}};
      if(cg!='s') { if(possible(xg,yg,cg,'w',blackSquare)){yg=yg-5;cg='w';return;};}
       if(cg!='d'){if(possible(xg,yg,cg,'a',blackSquare)){xg=xg-5;cg='a';return;}};
      };}
       

// the overall motion of ghost
     void motion(int &xg,int &yg,int x,int y,char &cg,int blackSquare[][28],int &ig,int &v){
		int p=xg-44;int q=yg-50;
//v is used to make ghost follow pac only for particular time interval

	if(((ab((x-xg))+ab((y-yg)))<200)&&(v<=3)){v++;

	if(cg=='w'){if((p%20==0)&&(q%20==0)&&((blackSquare[(q/20)][(p/20)-1]==1)||(blackSquare[(q/20)][(p/20)+1]==1)))
	{shortestPath(xg,yg,x,y,cg,blackSquare);return;}
	            else{yg=yg-5;return;}};
	if(cg=='a'){if((p%20==0)&&(q%20==0)&&((blackSquare[(q/20)-1][(p/20)]==1)||(blackSquare[(q/20)+1][(p/20)]==1)))
	{shortestPath(xg,yg,x,y,cg,blackSquare);return;}
	            else{{xg=xg-5;return;}};}
	if(cg=='s'){if((p%20==0)&&(q%20==0)&&((blackSquare[(q/20)][(p/20)-1]==1)||(blackSquare[(q/20)][(p/20)+1]==1)))
	{shortestPath(xg,yg,x,y,cg,blackSquare);return;}
	            else{yg=yg+5;return;}};
	if(cg=='d'){if((p%20==0)&&(q%20==0)&&((blackSquare[(q/20)-1][(p/20)]==1)||(blackSquare[(q/20)+1][(p/20)]==1)))
	{shortestPath(xg,yg,x,y,cg,blackSquare);return;}
	            else{xg=xg+5;return;}}};
    v=0;
	if(ig%5==1){
	if(cg!='s'){if(possible(xg,yg,cg,'w',blackSquare)){cg='w';yg=yg-5;ig++;return;}};
	if(cg!='a'){if(possible(xg,yg,cg,'d',blackSquare)){cg='d',xg=xg+5;ig++;return;}};
	if(cg!='w'){if(possible(xg,yg,cg,'s',blackSquare)){cg='s';yg=yg+5;ig++;return;}};
	if(cg!='d'){if(possible(xg,yg,cg,'a',blackSquare)){cg='a';xg=xg-5;ig++;return;}};
	};

	if(ig%5==2){
	if(cg!='a'){if(possible(xg,yg,cg,'d',blackSquare)){cg='d',xg=xg+5;ig++;return;}};
	if(cg!='s'){if(possible(xg,yg,cg,'w',blackSquare)){cg='w';yg=yg-5;ig++;return;}};
	if(cg!='d'){if(possible(xg,yg,cg,'a',blackSquare)){cg='a';xg=xg-5;ig++;return;}};
	if(cg!='w'){if(possible(xg,yg,cg,'s',blackSquare)){cg='s';yg=yg+5;ig++;return;}};
	};
	
	if(ig%5==3){
	if(cg!='d'){if(possible(xg,yg,cg,'a',blackSquare)){cg='a';xg=xg-5;ig++;return;}};
	if(cg!='w'){if(possible(xg,yg,cg,'s',blackSquare)){cg='s';yg=yg+5;ig++;return;}};
	if(cg!='s'){if(possible(xg,yg,cg,'w',blackSquare)){cg='w';yg=yg-5;ig++;return;}};
	if(cg!='a'){if(possible(xg,yg,cg,'d',blackSquare)){cg='d',xg=xg+5;ig++;return;}};};
	
	if(ig%5==4){
	if(cg!='w'){if(possible(xg,yg,cg,'s',blackSquare)){cg='s';yg=yg+5;ig++;return;}};
	if(cg!='s'){if(possible(xg,yg,cg,'w',blackSquare)){cg='w';yg=yg-5;ig++;return;}};
	if(cg!='d'){if(possible(xg,yg,cg,'a',blackSquare)){cg='a';xg=xg-5;ig++;return;}};
	if(cg!='a'){if(possible(xg,yg,cg,'d',blackSquare)){cg='d',xg=xg+5;ig++;return;}};};
	
	if(ig%5==0){
	if(cg!='s'){if(possible(xg,yg,cg,'w',blackSquare)){cg='w';yg=yg-5;ig++;return;}};
	if(cg!='w'){if(possible(xg,yg,cg,'s',blackSquare)){cg='s';yg=yg+5;ig++;return;}};
	if(cg!='d'){if(possible(xg,yg,cg,'a',blackSquare)){cg='a';xg=xg-5;ig++;return;}};
	if(cg!='a'){if(possible(xg,yg,cg,'d',blackSquare)){cg='d',xg=xg+5;ig++;return;}};};
	
	}
	


main_program{

initCanvas("pac man",1000,700);
	

double draw[42][2]={{15,0},{14,-5.48},{13,-7.48},{12,-9},{11,-10.19},{10,-11.18},{9,-12},{8,-12.68},{7,-13.26},
{6,-13.74},{5,-14.14},{4,-14.45},{3,-14.69},{2,-14.86},{1,-14.96},{0,-15},{-1,-14.96},{-2,-14.86},{-3,-14.69},{-4,-14.45},
{-5,-14.14},{-6,-13.74},{-7,-13.26},{-8,-12.68},{-9,-12},{-10,-11.18},{-11,-10.19},{-12,-9},{-13,-7.48},{-14,-5.48},{-15,0},
{-15,12},{-12,15},{-9,12},{-6,15},{-3,12},{0,15},{3,12},{6,15},{9,12},{12,15},{15,12}};
                            //coordinates of the ghost.
                            


Text t0(500,350,"play game");
Polygon g0(30,50,draw,42);   g0.setScale(1.75);       
g0.setFill(true);
g0.setColor(COLOR("red"));
Circle c0(110,50,15*1.75);
c0.setFill(true);
c0.setColor(COLOR("gold"));
int x0 = 0;
Polygon g8(500,350,draw,42); 
g8.setScale(5);
while(true){
g0.moveTo(30+x0,50);
c0.moveTo(110+x0,50);
x0 = x0+5;
if ( x0== 1000){ x0 = 0;};
XEvent e;
if(checkEvent(&e)){
if(mouseButtonPressEvent(&e)){                               
if ((e.xbutton.x>350)&&(e.xbutton.x<650)&&(e.xbutton.y>250)&&(e.xbutton.y<550)){
t0.hide();
c0.hide();
g0.hide();
g8.hide();
break;
}};

}};

	
	//start up of the game
	
	                                  
Rectangle r1(54+20*(13),60+(20*29.0/2),540,600);
Rectangle r2(54+20*(13),60+(20*29.0/2),550,610);//borders

bool a[30][27];
//a is used to make ghost and pac move in the path 

beginFrame();
for(int i=0;i<30;i++){
for(int j=0;j<27;j++){
a[i][j]=true;}};
fill(10,12,4,7,a);
fill(2,2,2,3,a);
fill(7,2,2,4,a);
fill(13,0,4,1,a);
fill(16,2,2,4,a);
fill(22,2,2,3,a);
fill(2,6,1,3,a);
fill(7,6,7,1,a);
fill(7,9,1,4,a);
fill(10,6,1,7,a);
fill(19,6,7,1,a);
fill(13,6,4,1,a);
fill(16,9,1,4,a);
fill(7,15,4,1,a);
fill(19,15,4,1,a);
fill(10,18,1,7,a);
fill(13,18,4,1,a);
fill(2,21,1,3,a);
fill(4,21,4,1,a);
fill(7,21,1,4,a);
fill(16,21,1,4,a);
fill(22,21,1,3,a);
fill(22,21,4,1,a);
fill(0,24,1,2,a);
fill(7,24,4,1,a);
fill(10,24,1,7,a);
fill(19,24,4,1,a);
fill(2,27,1,9,a);
fill(16,27,1,9,a);
fill(25,24,1,2,a);
fill(13,24,4,1,a);
fill(0,9,4,5,a);
fill(0,15,4,5,a);
fill(22,9,4,5,a);
fill(22,15,4,5,a);
fill(22,6,1,3,a);
	Text score(800,100,"score:");
endFrame();

int blackSquare[31][28],dots[31][28];
int s0=0;//score initially is zero
Text t10(900,100,s0);
for(int i=0;i<31;i++){blackSquare[i][0]=0;blackSquare[i][27]=0;dots[i][0]=0;dots[i][27]=0;};
for(int i=0;i<28;i++){blackSquare[0][i]=0;blackSquare[30][i]=0;dots[0][i]=0;dots[30][i]=0;};
	
blackSquare[15][0]=1;blackSquare[15][27]=1;

beginFrame();
for(int i=0;i<29;i++){
for(int j=0;j<26;j++){
	
blackSquare[i+1][j+1]=(((a[i][j]==true)&&(a[i+1][j]==true)&&
(a[i][j+1]==true)&&(a[i+1][j+1]==true)));

dots[i+1][j+1]=false;

if(blackSquare[i+1][j+1]){
Rectangle r(20*j+64,20*i+70,30,30);
r.setFill(true);
r.setColor(COLOR("black"));
r.imprint();
Circle c(20*j+64,20*i+70,5);
c.setFill(true);
c.setColor(COLOR("red"));
c.imprint();}}};
endFrame();

black(17,14,s0);
black(17,13,s0);

int x=74+20*12,y=70+20*16
,p=(x-44)/20,q=(y-50)/20;

Circle pac(64+20*12+10,70+20*16,15);
pac.setFill(true);
pac.setColor(COLOR("gold"));

char cg1='d',cg2='s',cg3='d',cg4='a';
//cg is to give the ghost an initial direction

int ig1=1,ig2=2,ig3=3,ig4=0;
//ig denotes a number corresponding to a ghost and it helps to randomize the motion of ghost 
int ig11=1,ig12=1,ig13=1,ig14=1;
//these are variables used to make ghost follow only for a particular time interval


Polygon ghost1(74,70,draw,42);
ghost1.setFill(true);
ghost1.setColor(COLOR("pink"));
Polygon ghost2(64+20*25,70,draw,42);
ghost2.setFill(true);
ghost2.setColor(COLOR("green"));
Polygon ghost3(64,70+20*28,draw,42);
ghost3.setFill(true);
ghost3.setColor(COLOR("orange"));
Polygon ghost4(64+20*25,70+20*28,draw,42);
ghost4.setFill(true);
ghost4.setColor(COLOR("sky blue"));

int xg1=64,yg1=70;
int xg2=64+20*25,yg2=70;
int xg3=64,yg3=70+20*28;
int xg4=64+20*25,yg4=70+20*28;

char current='l';//initialization of current 
//current is used to give motion to pac
char c;//c is the direction in which the ghost is presently moving




while(true){	

XEvent event;

if(checkEvent(&event)){
c =charFromEvent(&event);
current=c;
};
beginFrame();// ghosts movement
motion(xg1,yg1,x,y,cg1,blackSquare,ig1,ig11);
ghost1.moveTo(xg1,yg1);
ghost1.setFill(true);
motion(xg2,yg2,x,y,cg2,blackSquare,ig2,ig12);
ghost2.moveTo(xg2,yg2);
ghost2.setFill(true);
motion(xg3,yg3,x,y,cg3,blackSquare,ig3,ig13);
ghost3.moveTo(xg3,yg3);
ghost3.setFill(true);
motion(xg4,yg4,x,y,cg4,blackSquare,ig4,ig14);
ghost4.moveTo(xg4,yg4);
ghost4.setFill(true);
wait(0.04);
endFrame();

//as the ghosts move even when the pac  is not moving

gameover(x,y,xg1,yg1,xg2,yg2,xg3,yg3,xg4,yg4,s0);

if (c=='d'){
	
while(true){
	
if(blackSquare[q][p+1]==0){c='l';break;};
x=x+5;
pac.reset(x,y,15);
pac.setFill(true);

gameover(x,y,xg1,yg1,xg2,yg2,xg3,yg3,xg4,yg4,s0);

beginFrame();
motion(xg1,yg1,x,y,cg1,blackSquare,ig1,ig11);
check(xg1,yg1);
ghost1.moveTo(xg1,yg1);
ghost1.setFill(true);
motion(xg2,yg2,x,y,cg2,blackSquare,ig2,ig12);
check(xg2,yg2);
ghost2.moveTo(xg2,yg2);
ghost2.setFill(true);
motion(xg3,yg3,x,y,cg3,blackSquare,ig3,ig13);
check(xg3,yg3);
ghost3.moveTo(xg3,yg3);
ghost3.setFill(true);
motion(xg4,yg4,x,y,cg4,blackSquare,ig4,ig14);
check(xg4,yg4);
ghost4.moveTo(xg4,yg4);
ghost4.setFill(true);
t10.reset(900,100,s0);
wait(0.03);
endFrame();

p=(x-44)/20;
q=(y-50)/20;

gameover(x,y,xg1,yg1,xg2,yg2,xg3,yg3,xg4,yg4,s0);
		
if((blackSquare[q][p+1]!=0)&&
(dots[q][p+1]==0)){
black(q,p+1,s0);
dots[q][p+1]=1;
};

XEvent event;
	if(checkEvent(&event)){
		char u =charFromEvent(&event);
		current = u;};
		
if(current!='d'){
		if (possible(x,y,'d',current, blackSquare)){c=current;break;}};
	               if(blackSquare[q][p+1]==0){c='l';break;}}}
			
			
			
if (c=='a'){
		
while(true){
if(blackSquare[q][p]==0){x=x+5;
p=(x-44)/20;
q=(y-50)/20;
c='l';
break;}

pac.reset(x,y,15);
pac.setFill(true);
gameover(x,y,xg1,yg1,xg2,yg2,xg3,yg3,xg4,yg4,s0);

beginFrame();
motion(xg1,yg1,x,y,cg1,blackSquare,ig1,ig11);
check(xg1,yg1);
ghost1.moveTo(xg1,yg1);
ghost1.setFill(true);
motion(xg2,yg2,x,y,cg2,blackSquare,ig2,ig12);
check(xg2,yg2);
ghost2.moveTo(xg2,yg2);
ghost2.setFill(true);
motion(xg3,yg3,x,y,cg3,blackSquare,ig3,ig13);
check(xg3,yg3);
ghost3.moveTo(xg3,yg3);
ghost3.setFill(true);
motion(xg4,yg4,x,y,cg4,blackSquare,ig4,ig14);
check(xg4,yg4);
ghost4.moveTo(xg4,yg4);
ghost4.setFill(true);
t10.reset(900,100,s0);
wait(0.03);
endFrame();

gameover(x,y,xg1,yg1,xg2,yg2,xg3,yg3,xg4,yg4,s0);

x=x-5;
p=(x-44)/20;
q=(y-50)/20;
if((blackSquare[q][p]!=0)&&(dots[q][p]==0)){
black(q,p,s0);

dots[q][p]=1;};

XEvent event;
  if(checkEvent(&event)){
	  char u =charFromEvent(&event);
		 current = u;};
	
       if(current!='a'){
			if (possible(x,y,'a',current, blackSquare)){c=current;break;}}}}



if (c=='s'){
		
while(true){
if(blackSquare[q+1][p]==0){c='l';break;};
y=y+5;
pac.reset(x,y,15);
pac.setFill(true);
gameover(x,y,xg1,yg1,xg2,yg2,xg3,yg3,xg4,yg4,s0);

beginFrame();
motion(xg1,yg1,x,y,cg1,blackSquare,ig1,ig11);
check(xg1,yg1);
ghost1.moveTo(xg1,yg1);
ghost1.setFill(true);
motion(xg2,yg2,x,y,cg2,blackSquare,ig2,ig12);
check(xg2,yg2);
ghost2.moveTo(xg2,yg2);
ghost2.setFill(true);
motion(xg3,yg3,x,y,cg3,blackSquare,ig3,ig13);
check(xg3,yg3);
ghost3.moveTo(xg3,yg3);
ghost3.setFill(true);
motion(xg4,yg4,x,y,cg4,blackSquare,ig4,ig14);
check(xg4,yg4);
ghost4.moveTo(xg4,yg4);
ghost4.setFill(true);
t10.reset(900,100,s0);
wait(0.03);
endFrame();

gameover(x,y,xg1,yg1,xg2,yg2,xg3,yg3,xg4,yg4,s0);


;
p=(x-44)/20;
q=(y-50)/20;
if((blackSquare[q+1][p]!=0)&&(dots[q+1][p]==0)){
black(q+1,p,s0);

dots[q+1][p]=1;};

XEvent event;
	if(checkEvent(&event)){
		char u =charFromEvent(&event);
		current = u;};
	
		if(current!='s'){
			if (possible(x,y,'s',current, blackSquare)){c=current;break;}};
			if(blackSquare[q+1][p]==0){c='l';break;}}}


if (c=='w'){
		
	while(true){
		
		if(blackSquare[q][p]==0){y=y+5;
		p=(x-44)/20;
q=(y-50)/20;
c='l';break;}
pac.reset(x,y,15);
pac.setFill(true);
gameover(x,y,xg1,yg1,xg2,yg2,xg3,yg3,xg4,yg4,s0);

beginFrame();
motion(xg1,yg1,x,y,cg1,blackSquare,ig1,ig11);
check(xg1,yg1);
ghost1.moveTo(xg1,yg1);
ghost1.setFill(true);
motion(xg2,yg2,x,y,cg2,blackSquare,ig2,ig12);
check(xg2,yg2);
ghost2.moveTo(xg2,yg2);
ghost2.setFill(true);
motion(xg3,yg3,x,y,cg3,blackSquare,ig3,ig13);
check(xg3,yg3);
ghost3.moveTo(xg3,yg3);
ghost3.setFill(true);
motion(xg4,yg4,x,y,cg4,blackSquare,ig4,ig14);
check(xg4,yg4);
ghost4.moveTo(xg4,yg4);
ghost4.setFill(true);
t10.reset(900,100,s0);
wait(0.03);
endFrame();

gameover(x,y,xg1,yg1,xg2,yg2,xg3,yg3,xg4,yg4,s0);


;
y=y-5;
p=(x-44)/20;
q=(y-50)/20;
if((blackSquare[q][p]!=0)&&(dots[q][p]==0)){
black(q,p,s0);

dots[q][p]=1;};

XEvent event;
	if(checkEvent(&event)){
		char u =charFromEvent(&event);
		current = u;};
	
		if(current!='w'){
			if (possible(x,y,'w',current, blackSquare)){c=current;break;}};
			;}}	
		
		
//if pac is at a transporting point		
if((x==64)&&(y==330)){
      if(dots[q][26]==0){black(q,26,s0);
      
      dots[q][26]=1;};
x=569;
p=(x-44)/20;
pac.reset(x,y,15);
pac.setFill(true);
c='a';};

if((x==564)&&(y==330)){
 if(dots[q][1]==0){
black(q,1,s0);

 dots[q][1]=1;};
x=64;
p=(x-44)/20;
pac.reset(x,y,15);
pac.setFill(true);
c='d';};
		
		


}
}








