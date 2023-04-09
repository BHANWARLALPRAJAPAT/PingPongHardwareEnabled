void setup()
{
  fullScreen();
  
  //size(800,800);
  reset();

  textSize(100);
  textAlign(CENTER,CENTER);
}
int backX,backY,backZ;
int ballcX,ballcY,ballcZ;
int bar1cX,bar1cY,bar1cZ;
int bar2cX,bar2cY,bar2cZ;
color back = color(backX,backY,backZ);
color bar1c = color(bar1cX,bar1cY,bar1cZ);
color bar2c = color(bar2cX,bar2cY,bar2cZ);
color ballc = color(ballcX,ballcY,ballcZ);
int ballX,ballY,ballR=20;
int bar1X,bar1Y,bar2X,bar2Y;
int barW=20,barH=100,barS=5;
int speedX=5,speedY=5;
boolean leftup;
boolean leftdown,rightup,rightdown;
int score1,score2,winpoint=2;
String in_str;
int inp1,inp2,bt1,bt2;

void reset()
{
  ballX=width/2;
  ballY=height/2;
  bar1Y=bar2Y=height/2-barH/2;
  bar1X=0;;
  bar2X=width-barW;
  if(score1!=winpoint && score2!=winpoint)
  {
    
  draw();
  }
}
void drawbackground()
{
  background(100,100,100);
  //background(back);
}
void drawball()
{
  fill(ballc);
  circle(ballX,ballY,2*ballR);
}
void moveball()
{
  ballX+=speedX;
  ballY+=speedY;
}
void deflect()
{
  if(ballY<=ballR || ballY>=height-ballR)
  {
    speedY*=-1;
    
  }
  
}
//void keyReleased()
//{
  
//  if(key=='W' || key=='w')
//  {
//    leftup=false;
//  }
//  else if(key=='S' || key=='s')
//  {
//    leftdown=false;
//  }
//  if(keyCode ==UP)
//  {
//    rightup=false;
//  }
//  else if(keyCode ==DOWN)
//  {
//    rightdown = false;
//  }
//}
void checkforgameend()
{
  if(score1==winpoint)
  {
    fill(30,60,90);
    text("Player 1 Wins ",width/2,50);
    speedX=0;
    speedY=0;
    
    
    
  }
  else if(score2==winpoint)
  {
     fill(30,60,90);
    text("Player 2 Wins ",width/2,50);
    speedX=0;
    speedY=0;
    
  }
}
void gameover()
{
  if(ballX<=ballR )
  {
    score1++;
    reset();   
  }
  else if(ballX>width-ballR)
  {
    score2++;
    reset();
  }
  checkforgameend();
}
void drawpaddle()
{
  fill(bar1c);
  rect(bar1X,bar1Y,barW,barH);

  rect(bar2X,bar2Y,barW,barH);
  
}
void stringinput()
{
  
  //print(inp1,inp2,bt1,bt2);
}
void stringoutput()
{
  
}
//void keyPressed()
//{
//  if(key=='W' || key=='w')
//  {
//    leftup=true;
//  }
//  else if(key=='S' || key=='s')
//  {
//    leftdown=true;
//  }
//  if(keyCode ==UP)
//  {
//    rightup=true;
//  }
//  else if(keyCode ==DOWN)
//  {
//    rightdown = true;
//  }
//}

void movepaddle()
{
 if(leftup)
 {
   bar1Y-=barS;
 }
 else if(leftdown)
 {
   bar1Y +=barS;
 }
 if(rightup)
 {
   bar2Y -=barS;
 }
 else if(rightdown)
 {
    bar2Y +=barS;
  
}
}
void restrictpaddle()
{
  
  if(bar1Y<0)
  {
    bar1Y = 0;
  }
  else if(bar1Y>height-barH)
  {
    bar1Y = height-barH;
    
  }
  if(bar2Y<0)
  {
    bar2Y=0;
  }
  else if(bar2Y>height-barH)
  {
     bar2Y = height-barH;
  }
}
void contactpaddle()
{
  if(ballX - bar1X-barW<=ballR)
  {
    if(ballY>=bar1Y-ballR && ballY<=bar1Y+barH+ballR)
    {
      speedX*=-1;
    }
    
  }
  else if(bar2X-ballX<=ballR)
  {
     if(ballY>=bar2Y-ballR && ballY<=bar2Y+barH+ballR)
     {
    speedX*=-1;
     }
    
  }
 
}
void showscore()
{
  fill(255);
  text(score1,100,50);
  text(score2,width-100,50);
  //line(0,0,200,300);
}
void draw()
{
  stringinput();
  in_str = "1023,0,0,1";
  //print(in_str.length());
  in_str.trim();
  //print(in_str.length());
  String[] st_str = splitTokens(in_str,",");
  inp1 = int(st_str[0]);
  inp2 = int(st_str[1]);
  bt1 = int(st_str[2]);
  bt2 = int(st_str[3]);
  bar1Y = inp1;
  bar2Y = inp2;
  drawbackground();
  drawball();
  moveball();
  deflect();
  drawpaddle();
  movepaddle();
  restrictpaddle();
  contactpaddle();
  showscore();
  gameover();
  stringoutput();
}
