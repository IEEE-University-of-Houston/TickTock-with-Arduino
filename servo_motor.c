//#include <Servo.h>
int Input = 0;
int Output = 0;
Servo servo_3;

void setup()
{
  pinMode(A0, INPUT);
  servo_3.attach(3,500,2500);
}

void loop()
{
  Input = analogRead(A0);
  Output = map(Output, 0, 1023, 0, 100);
  servo_3.write(Input);
  delay(10);
}
