int a=7;
int b=6;
int c=5;
int d=11;
int e=10;
int f=8;
int g=9;
int dp=4;
int pinInterrupt = 2; //接中断信号的脚
void onChange()
{
   if ( digitalRead(pinInterrupt) == LOW )
   {
       return Serial.begin(9600);
   }
}
void digital_0(void)
{
unsigned char j;
for(j=5;j<=11;j++)
digitalWrite(j,HIGH);
digitalWrite(g,LOW);
digitalWrite(dp,LOW);
}
void digital_1(void)
{
unsigned char j;
digitalWrite(c,HIGH);
digitalWrite(b,HIGH);
for(j=7;j<=11;j++)
digitalWrite(j,LOW);
digitalWrite(dp,LOW);
}
void digital_2(void)
{
unsigned char j;
digitalWrite(b,HIGH);
digitalWrite(a,HIGH);
for(j=9;j<=11;j++)
digitalWrite(j,HIGH);
digitalWrite(dp,LOW);
digitalWrite(c,LOW);
digitalWrite(f,LOW);
}
void digital_3(void)
{
unsigned char j;
digitalWrite(g,HIGH);
digitalWrite(d,HIGH);
for(j=5;j<=7;j++)
digitalWrite(j,HIGH);
digitalWrite(dp,LOW);
digitalWrite(f,LOW);
digitalWrite(e,LOW);
}
void digital_4(void)
{
digitalWrite(c,HIGH);
digitalWrite(b,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
digitalWrite(dp,LOW);
digitalWrite(a,LOW);
digitalWrite(e,LOW);
digitalWrite(d,LOW);
}
void digital_5(void)
{
unsigned char j;
for(j=7;j<=9;j++)
digitalWrite(j,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(dp,LOW);
digitalWrite(b,LOW);
digitalWrite(e,LOW);
}
void digital_6(void)
{
unsigned char j;
for(j=7;j<=11;j++)
digitalWrite(j,HIGH);
digitalWrite(c,HIGH);
digitalWrite(dp,LOW);
digitalWrite(b,LOW);
}
void digital_7(void)
{
unsigned char j;
for(j=5;j<=7;j++)
digitalWrite(j,HIGH);
digitalWrite(dp,LOW);
for(j=8;j<=11;j++)
digitalWrite(j,LOW);
}
void digital_8(void)
{
unsigned char j;
for(j=5;j<=11;j++)
digitalWrite(j,HIGH);
digitalWrite(dp,LOW);
}
void digital_9(void)
{
unsigned char j;
for(j=5;j<=11;j++)
digitalWrite(j,HIGH);
digitalWrite(e,LOW);
digitalWrite(dp,LOW);
}

void setup()
{
  Serial.begin(9600);
  pinMode( pinInterrupt, INPUT);
  attachInterrupt( digitalPinToInterrupt(pinInterrupt), onChange, CHANGE);
  int i;
  for(i=4;i<=11;i++)
  pinMode(i,OUTPUT);
}
void loop()
{
digital_0();
delay(1000); 
digital_1();
delay(1000);
digital_2();
delay(1000); 
digital_3();
delay(1000); 
digital_4();
delay(1000); 
digital_5();
delay(1000); 
digital_6();
delay(1000); 
digital_7();
delay(1000); 
digital_8();
delay(1000); 
digital_9();
delay(1000); 
}