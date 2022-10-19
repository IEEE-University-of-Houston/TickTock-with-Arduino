#include <time.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//variable setup
int starttime;
int activetime;
int prevoustime = 0;

//buzzer 
const int buzzer = 7;
const int button = 1;

//clock start times
int hours = 0;
int mins = 0;
int secs = 0;

//alarm start time
int ahours = 0;
int amins = 0;

//date setup
int startdate;
int activedate;
int previousdate = 0;

//date start time
int day = 1;
int month = 1;
int year = 2020;
 
void setup()
{
   lcd.begin(16, 2);
   lcd.clear();
   Serial.begin(9600);

   pinMode(6, INPUT);
   digitalWrite(6, HIGH);
   pinMode(8, INPUT);
   digitalWrite(8, HIGH);
   pinMode(9, INPUT);
   digitalWrite(9, HIGH);
   pinMode(10, INPUT);
   digitalWrite(10, HIGH);
   pinMode(A4, INPUT);
   digitalWrite(A4, HIGH);
  
   pinMode(buzzer, OUTPUT);
   pinMode(button, INPUT_PULLUP);
   
   starttime = millis()/1000,DEC;
}
 
void loop()
{
  //when alarm button is on set the cursor to the middle of line 1
  //when button 1 is pressed increase the minutes
  while(digitalRead(A4) == LOW)
  {
    lcd.setCursor(0,0);
    lcd.print("Alarm");
    
    if(digitalRead(8) == LOW)
    {
      amins++;
    } 
    //if button 2 is pressed increase the hours
    else if (digitalRead(6) == LOW)
    {
      ahours++;
    }
    lcd.setCursor(6,0);

    //alarm setup
    if(ahours < 10)
    {
      lcd.print("0");
      lcd.print(ahours);
    }
    else
    {
      lcd.print(ahours);
    }
    
    lcd.print(":");
    
    if (amins < 10)
    {
      lcd.print("0");
      lcd.print(amins);
    }
    else
    {
      lcd.print(amins);
    }
    
    if(amins > 59)
    {
       ahours++;
       amins = 0;
    } 
    if(ahours > 23)
    {
       ahours = 0; 
    }
    delay(500);
    lcd.clear();
  }
  
  //if set time button is on set the writing to line 1
  //same thing as above for minutes and hours
  if(digitalRead(10) == LOW)
  {
    lcd.setCursor(0,0);
    lcd.print("Time");
    lcd.setCursor(6,0);
    
    if(digitalRead(8) == LOW)
    {
      mins++;
    } 
    else if (digitalRead(6) == LOW)
    {
      hours++;
    }
  }

  //clock time setup
  activetime = (millis() / 1000) - starttime;
  
  if(prevoustime < (activetime - 59))
  { 
    mins++;
    prevoustime = activetime;
  } 

  if(secs > 59)
  {
    mins++;
    secs = 0;
  }
  
  if(mins > 59)
  {
    hours++;
    mins = 0;
  } 
     
  if(hours > 23)
  {
     hours = 0; 
  }
  lcd.setCursor(6,0);
  
  if(hours < 10)
  {
    lcd.print("0");
    lcd.print(hours);
  }
  else
  {
    lcd.print(hours);
  }
  lcd.print(":");
    
  if (mins < 10)
  {
    lcd.print("0");
    lcd.print(mins);
  }
  else
  {
     lcd.print(mins);
  }
  
  //buzzer set up for the ringing
  if(ahours == hours && amins == mins)
  {
    tone(buzzer, 1000); // Send 1KHz sound signal...
    delay(1000);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...
    delay(1000);        // ...for 1sec
  }
  
  else
  {
    delay(300);
  }
  lcd.clear();

  //button to switch it off
  int buttonState = digitalRead(button); //state of button
  if (buttonState == HIGH)
  {
    Serial.println("The button is unpressed");
    digitalWrite(button, LOW);  // turn off
  }
 
  Serial.println(mins);
  Serial.println(hours);
  Serial.println("");
  Serial.println(amins);
  Serial.println(ahours);
  Serial.println("");
  Serial.println(activetime);
  Serial.println(prevoustime);
  Serial.println(starttime);
  Serial.println("");

  //date setup
  //
  //
  //
  {
    if(digitalRead(9) == LOW)
    {
      lcd.setCursor(0,1);
      lcd.print("Date");
      lcd.setCursor(5,1);
    
      if(digitalRead(8) == LOW)
      {
        month++;
      } 

      else if(digitalRead(6) == LOW)
      {
        day++;
      }
    }
    lcd.setCursor(4,1); 
    
      //format
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
    }
    
    Serial.println(day);
    Serial.println(month);
    Serial.println(year);
    Serial.println("");
    
    //coding for new days
    if(hours == 0 && mins == 0 && secs == 0)
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
    if(month > 12)
    {
      year++;
      month = 1;
    }
    lcd.setCursor(6,0);
}

