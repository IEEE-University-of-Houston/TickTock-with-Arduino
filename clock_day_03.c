#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);

//intialize time
int h = 18, m = 21, s = 0;
int month = 10, day = 27, year = 22;

void setup()
{
  lcd.begin(16,2);
  lcd.clear();
  Serial.begin(9600);
}

void loop()
{
  //increment seconds
  s=s+1;
  if(s==60)
  {
    //increment minutes
    m=m+1;
    s=0;
  }
  
  if(m==60)
  {
    m=0;
    //increment hours
    h=h+1;
  }
  
  //output data to clock
  lcd.setCursor(4,0);
  if(h < 10)
  {
    lcd.print("0");
    lcd.print(h);
  }
  else
  {
    lcd.print(h);
  }
  lcd.print(":");
    
  if (m < 10)
  {
    lcd.print("0");
    lcd.print(m);
  }
  else
  {
     lcd.print(m);
  }
  lcd.print(":");
  
   if (s < 10)
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
 
  
  //run every second
  delay(1000);
  lcd.clear();
}
