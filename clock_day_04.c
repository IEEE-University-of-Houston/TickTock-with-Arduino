//full clock code
// C++ code
#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);
//initialize variables
int h = 6, m = 59, s = 58;
int month = 10, day = 27, year = 22;
//create and set alarm variables
int ah = 7, am = 0, as = 0;
//set buzzer
const int buzzer = 8;
//set button
const int button = 9;
const int button2 = 10;


void setup()
{
  lcd.begin(16,2);
  lcd.clear();
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
  pinMode(button, INPUT_PULLUP);
}

void loop()
{
  s=s+1;
  if(s == 60)
  {
    m = m+1;
    s = 0;
  }
  if (m==60)
  {
    h = h+1;
    m = 0;
  }
  delay(1000);
  lcd.clear();
  
  //output data to clock
  lcd.setCursor(4,0);
  //hours
  if (h <10)
  {
    lcd.print("0");
    lcd.print(h);
  }
  else
  {
    lcd.print(h);
  }
  lcd.print(":");
  
  //minutes
  if (m <10)
  {
    lcd.print("0");
    lcd.print(m);
  }
  else
  {
    lcd.print(m);
  }
  lcd.print(":");
  
  //seconds
  if (s <10)
  {
    lcd.print("0");
    lcd.print(s);
  }
  else
  {
    lcd.print(s);
  }
  //coding for new days
    if(h == 0 && m == 0 && s == 0)
    {
      day + 1;
    }
    //months with 31 days
    if((day > 30) && (month == 1 || 3 || 5 || 7 || 8 || 10 || 12))
    {
      month++;
      day = 1;
    }
    //months with 30 days
    if((day > 29) && (month == 4 || 6 || 9 || 11))
    {
      month++;
      day = 1;
    }
    //february
    if((day > 27) && (month == 2))
    {
      month++;
      day = 1;
    }
  	//years
    if(month > 12)
    {
      year++;
      month = 1;
    }
  
    lcd.setCursor(4,1);
  	if(month < 10)
  {
    lcd.print("0");
    lcd.print(month);
  }
  else
  {
    lcd.print(month);
  }
  lcd.print("/");
    
  if (day < 10)
  {
    lcd.print("0");
    lcd.print(day);
  }
  else
  {
     lcd.print(day);
  }
  lcd.print("/");
  
 
   lcd.print(year);
  
  if(ah == h && am == m && as == s)
  {
    Buzz();
  }
  
  //change minutes
  if(digitalRead(9) == LOW)
  {
  	m++;
  }
  //change hours
  if(digitalRead(9) == LOW)
  {
  	h++;
  }
}

void Buzz()
{
  int i = 0;
  for(i = 0; i < 10; i++)
  {
  tone(buzzer, 1000); //sound buzzer
  delay(500); // delay half a second
  noTone(buzzer); //turn off buzzer
  delay(500); //delay half a second
  s++;
  }
}

