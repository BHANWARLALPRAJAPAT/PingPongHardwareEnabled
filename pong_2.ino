bool a,b;
unsigned short int score1,score2;
int BallOrient;
int lastOut;
int commaIndex[3];
String valueSTR[4];

#define Buzzer_pin 7
#define left_button 5
#define right_button 6
#define left_pot A1
#define right_pot A2
#define LED1_DP 19
#define LED2_DP 8
int leftoutput=0;
int rightoutput=0;
const int leds_pins[2][7] = {
  //A B  C  D  E  F  G 
  {13,12,18,17,16,14,15},
  {4,26, 9,10,11,21,20}      
};

int displayArray[10][7]{
  {0,0,0,0,0,0,1},//0
  {1,0,0,1,1,1,1},//1
  {0,0,1,0,0,1,0},//2
  {0,0,0,0,1,1,0},//3
  {1,0,0,1,1,0,0},//4
  {0,1,0,0,1,0,0},//5
  {0,1,0,0,0,0,0},//6
  {0,0,0,1,1,1,1},//7
  {0,0,0,0,0,0,0},//8
  {0,0,0,0,1,0,0} //9
  
};
void showLED(int a, int b)
{
  a = a%10;
  b= b%10;
  
    for(int j = 0;j<7;j++)
    {
      digitalWrite(leds_pins[0][j],displayArray[a][j]);
    }
    for(int j = 0;j<7;j++)
    {
      digitalWrite(leds_pins[1][j],displayArray[b][j]);
    }
  
  
  
}
// pos1 ,pos2, btn1,btn2
//1012,43,
void init_leds()
{
  for(int i = 0;i<2;i++)
  {
    for(int j = 0;j<7;j++)
    {
      pinMode(leds_pins[i][j],OUTPUT);
    }
  }
  pinMode(LED1_DP,OUTPUT);
  pinMode(LED2_DP,OUTPUT);
}
void on_everypin()
{
  for(int i = 0;i<2;i++)
  {
    for(int j = 0;j<7;j++)
    {
      digitalWrite(leds_pins[i][j],LOW);
    }
  }
  digitalWrite(LED1_DP,LOW);
  digitalWrite(LED2_DP,LOW);
}
void off_everypin()
{
  for(int i = 0;i<2;i++)
  {
    for(int j = 0;j<7;j++)
    {
      digitalWrite(leds_pins[i][j],HIGH);
    }
  }
  digitalWrite(LED1_DP,HIGH);
  digitalWrite(LED2_DP,HIGH);
}
void setup() {
  Serial1.begin(115200);
  Serial.begin(115200);
  
  pinMode(left_button,INPUT_PULLUP);
  pinMode(right_button,INPUT_PULLUP);
  init_leds();

}
void StringCommaFounder(String STR,int *commaIndex)
{
  int j= 0;
  for(int i = 0;i<STR.length();i++)
  {
    if(STR[i] == ',')
    {
      commaIndex[j] = i;
      j++;
    }
  }
}
 void buzzerfunc(){
  switch(BallOrient)
  {
    
    case 1: //ON THE BAT
      digitalWrite(Buzzer_pin,HIGH);
      delay(10);
      digitalWrite(Buzzer_pin,LOW);
      break;
    case 2: //screen unvisible
        for(int ab=0;ab<2;ab++)
        {
      digitalWrite(Buzzer_pin,HIGH);
      delay(10);
      digitalWrite(Buzzer_pin,LOW);
      delay(10);
     
        }
         break;
      case 0:
      digitalWrite(Buzzer_pin,LOW);
      break;
    
  }
}
  void   Dpcontrol(){
    switch(lastOut)
    {
    case 0:
      digitalWrite(LED1_DP,HIGH);
      digitalWrite(LED2_DP,HIGH);
      break;
    case 1:
     digitalWrite(LED1_DP,LOW);
      digitalWrite(LED2_DP,HIGH);
      break;
    case 2:
     digitalWrite(LED1_DP,HIGH);
      digitalWrite(LED2_DP,LOW);
      break;
  }
  }

//     int value[4];
void loop() {
 
  leftoutput = analogRead(left_pot);
  rightoutput = analogRead(right_pot);
  Serial1.print("left =  "); 
  Serial1.print(leftoutput);
  Serial. print(leftoutput);
  Serial1.print(" Right=  ");
  Serial. print (",");
  Serial1.print(rightoutput);
  Serial. print(rightoutput);
  a = digitalRead(left_button);
  b = digitalRead(right_button);
  Serial1.print(" lb =  ");
  Serial. print (",");
  Serial1.print(a);
  Serial. print(a);
  Serial. print (",");
  Serial1.print(" rb =  ");
  Serial. println (b);
  Serial1.println(b);
  //delay()
  //output
  
  
//  delay(20);
 
  // Serial1.println("");
  // delay(200);
  // put your main code here, to run repeatedly:
  //  
  
//    String STR = Serial.readStringUntil('\n');
    String STR = "3,5,0,0";
    STR.trim();
   
    StringCommaFounder(STR,commaIndex);
   
    valueSTR[0] = STR.substring(0,commaIndex[0]);
    valueSTR[1] = STR.substring(commaIndex[0]+1,commaIndex[1]);
    valueSTR[2] = STR.substring(commaIndex[1]+1,commaIndex[2]);
    valueSTR[3] = STR.substring(commaIndex[2]+1);
    
    score1 = valueSTR[0].toInt();
    score2 = valueSTR[1].toInt();
    BallOrient = valueSTR[2].toInt();
    lastOut= valueSTR[3].toInt();
    showLED(score1,score2);
    buzzerfunc();
    Dpcontrol();
}
