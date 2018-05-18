#include<Servo.h>
Servo s;
int Btn[] = {2,3,4,5,6};
int Ans[] = {2,3,4,5,6};
int P1[] = {0,0,0,0,0};
int Led[] = {A0,A1,A2,A3,A4};
bool button[] = {0,0,0,0,0};////宣告各個按鈕的狀態
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i = 0 ; i < 5 ; i++ )////按鈕設定INPUT，LED設定OUTPUT
  {
    pinMode(8,OUTPUT);
    pinMode(Btn[i],INPUT_PULLUP);
    pinMode(Led[i],OUTPUT);
    digitalWrite(Led[i],LOW);
  }
  delay(1000);
  s.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0 ; i < 5 ; i++ )////讀取各個按鈕是否被按下
  {
    button[i]=digitalRead(Btn[i]);
  }
  for(int i = 0 ; i < 5 ; i++ )////印出各個按鈕的狀態
  {
    Serial.print(button[i]);
  }
  Serial.println();
  for(int i = 0 ; i < 5 ; i++)
  {
    if(button[i]==0)
    {
      P1[i]=Ans[i];
    }
  }
  for(int i = 0 ; i < 5 ; i++)
  {
    if(P1[i]!=0)
    {
      digitalWrite(Led[i],HIGH);  
    }
    else
    {
      digitalWrite(Led[i],LOW);
      P1[0]=0;
      P1[1]=0;
      P1[2]=0;
      P1[3]=0;
      P1[4]=0;
    }
  }
  if(P1[0]==Ans[0]&&P1[1]==Ans[1]&&P1[2]==Ans[2]
     &&P1[3]==Ans[3]&&P1[4]==Ans[4])
     {
      digitalWrite(8,HIGH);
      s.attach(9);
      Serial.println("Done!!!");
      s.write(100);
      delay(10000);
      digitalWrite(8,LOW);
      s.detach();
      P1[0]=0;
      P1[1]=0;
      P1[2]=0;
      P1[3]=0;
      P1[4]=0;
     }
}

