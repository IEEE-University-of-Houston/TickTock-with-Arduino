void setup()
{
  pinMode(8,OUTPUT);
}

void loop()
{
  digitalWrite(0,HIGH);
  delay(1000); //wait for 1 second
  digitalWrite(0,LOW);
  delay(1000); //wait for 1 second
}
