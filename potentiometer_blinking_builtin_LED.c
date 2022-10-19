int sensorValue = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  //read value from analog pin
  sensorValue = analogRead(A0);
  //turn LED ON
  digitalWrite(LED_BUILTIN, HIGH);
  //blink
  delay(sensorValue);
  //turn LED OFF
  digitalWrite(LED_BUILTIN, LOW);
  //blink
  delay(sensorValue);
}
