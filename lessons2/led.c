int i=0;
void setup()
{
  for(i=0;i<10;i=i+2)
 {
  pinMode(10, OUTPUT);
 }
  
}

void loop()
{
  for(i=0;i<10;i=i+2)
 {
  digitalWrite(i, HIGH);
  delay(300);
  digitalWrite(i, LOW);
  delay(300);
 }
}