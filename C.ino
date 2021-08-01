#include <Servo.h>
#include <Wire.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

const byte ROWS = 4; //rows
const byte COLS = 3; //columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {12,11,10,9 }; //Row
byte colPins[COLS] = {8,7,6}; //Column

Servo ServoMotor; 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 
String pass = "1234";
String mypass;
int posi=0;
int buzzerPin=4;
int c=-1;
 
void setup(){
  Serial.begin(9600);  
  lcd.init();
  lcd.backlight();
  ServoMotor.attach(3); //Servomotor
  pinMode(buzzerPin, OUTPUT);
  lcd.print("Enter Password:");
}
  
void loop()
{
 char key = keypad.getKey();
  if (key){
    Serial.println(key);
    c = c + 1; 
    lcd.setCursor(c, 1);
    lcd.print("*");
  }
  if (key == '1'){
    mypass = mypass + 1;   
    digitalWrite(buzzerPin, HIGH);
    delay(50);
    digitalWrite(buzzerPin, LOW);;
  }
    if (key == '2'){
    mypass = mypass + 2;  
    digitalWrite(buzzerPin, HIGH);
    delay(50);
    digitalWrite(buzzerPin, LOW);;
  }
  if (key == '3'){
    mypass = mypass + 3; 
    digitalWrite(buzzerPin, HIGH);
    delay(50);
    digitalWrite(buzzerPin, LOW);;
  }
   if (key == '4'){
    mypass = mypass + 4;  
    digitalWrite(buzzerPin, HIGH);
    delay(50);
    digitalWrite(buzzerPin, LOW);;
  }
  if (key == '5'){
    mypass = mypass + 5;
    digitalWrite(buzzerPin, HIGH);
    delay(50);
    digitalWrite(buzzerPin, LOW);;
  }
   if (key == '6'){ 
    mypass = mypass + 6; 
    digitalWrite(buzzerPin, HIGH);
    delay(50);
    digitalWrite(buzzerPin, LOW);;
  }
   if (key == '7'){
    mypass = mypass + 7; 
    digitalWrite(buzzerPin, HIGH);
    delay(50);
    digitalWrite(buzzerPin, LOW);;
  }
   if (key == '8'){
    mypass = mypass + 8; 
    digitalWrite(buzzerPin, HIGH);
    delay(50);
    digitalWrite(buzzerPin, LOW);;
  }
  if (key == '9'){
    mypass = mypass + 9;
    digitalWrite(buzzerPin, HIGH);
    delay(50);
    digitalWrite(buzzerPin, LOW);;
  }
  if (key == '0'){
    mypass = mypass + 0; 
    digitalWrite(buzzerPin, HIGH);
    delay(50);
    digitalWrite(buzzerPin, LOW);;
  }
  if (key == '*')
  {
    Serial.println(mypass); 
    if ( pass == mypass )
    {
      int a=1;
      lcd.setCursor(0,0);
      for(posi = 180; posi>=0; posi-=5) 
      {
        ServoMotor.write(posi);
        delay(15); //15ms
      }
      digitalWrite(buzzerPin, HIGH);
      delay(50);
      digitalWrite(buzzerPin,LOW);
      delay(50);
      digitalWrite(buzzerPin, HIGH);
      delay(50);
      digitalWrite(buzzerPin,LOW);
      delay(50);
      lcd.print("The Door Is Opening");
      lcd.setCursor(0,1);
      lcd.print("*******************");
      delay(2000);
      digitalWrite(buzzerPin, HIGH);
      delay(50);
      digitalWrite(buzzerPin,LOW);
      delay(50);
      digitalWrite(buzzerPin, HIGH);
      delay(50);
      digitalWrite(buzzerPin,LOW);
      delay(50);
      for(posi = 0; posi <= 90; posi +=5) 
      { 
        ServoMotor.write(posi); 
        delay(15); //15ms
        mypass = "";
        c=-1;
       }
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("!Door is closing!");
      delay(2000);
      lcd.clear();
      lcd.setCursor(0,0); 
      lcd.print("Enter Password");
    }
    else
    {
      c=-1;
      lcd.clear(); 
      lcd.setCursor(0,0); 
      lcd.print("Wrong Password");
      delay(1000);
      lcd.clear(); 
      lcd.println("Enter password: ");
      lcd.setCursor(0,1); 
      mypass = ""; 
    }
  } 
}
