#include<LiquidCrystal.h>
#include <IRremote.h>
 
int RECV_PIN = 6;
IRrecv irrecv(RECV_PIN);
decode_results results;
LiquidCrystal lcd(11, 10, 5, 4, 3, 2);
int i=0;

byte Heart[] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000};

byte Z1[] = {
  B01111,
  B00001,
  B00010,
  B00100,
  B01000,
  B01111,
  B00000,
  B00000};

byte Z2[] = {
  B00000,
  B00000,
  B00000,
  B00111,
  B00001,
  B00010,
  B00100,
  B00111};
void setup() {
 lcd.createChar(1, Heart);
  lcd.createChar(2, Z1);
  lcd.createChar(3, Z2);
Serial.begin (9600);
irrecv.enableIRIn();
lcd.begin(16, 2);
lcd.print("Starting System");
delay(2000);
lcd.clear();
lcd.print("System on");
delay(1000);
lcd.clear();
lcd.setCursor(0, 0);
    lcd.print("Press Button");
lcd.setCursor(0, 1);
    lcd.print("To Get Value");

    
}
void loop(){
  if (irrecv.decode(&results)){
switch(results.value)
     {        
  case 0xF720DF://1 Button
    Serial.print("Button Pressed 1 Passing Text to LCD");
    lcd.begin(16, 2);
    lcd.print("Button Press 1"); // Button 2  
    lcd.setCursor(0, 1);
    lcd.print("How Are You");
break;          
  
        
  case 0xF7A05F://2 Button
    Serial.print("Button Pressed 2 Passing Text to LCD");
    lcd.begin(16, 2);
    lcd.print("Button Press 2"); // Button 2  
    lcd.setCursor(0, 1);
    lcd.print("What to Do?");
break;              

  case 0xF7609F://3 Button
    Serial.print("Button Pressed 3 Passing Text to LCD");
    lcd.begin(16, 2);
    lcd.print("Button Press 3"); // Button 2  
    lcd.setCursor(0, 1);
    lcd.print("Good Morning");
break;

case 0xF7E01F://4 Button
    Serial.print("Button Pressed 4 Passing Text to LCD");
    lcd.begin(16, 2);
    lcd.print("Button Press 4"); // Button 2  
    lcd.setCursor(0, 1);
    lcd.print("Good Afternon");
break;

case 0xF710EF://5 Button
    Serial.print("Button Pressed 5 Passing Text to LCD");
    lcd.begin(16, 2);
    lcd.print("Button Press 5"); // Button 2  
    lcd.setCursor(0, 1);
    lcd.print("Custom Icon");
break;


case 0xF7906f://6 Button
 Serial.print("Button Pressed 6 Passing Text to LCD");
    lcd.begin(16, 2);
  lcd.print("  I ");
  lcd.write(1);
  lcd.print(" ARDUINO");
  lcd.setCursor(0,1);
  lcd.print("  I sleep ");
  lcd.write(2);
  lcd.write(3);
  break;


     case 0xF7D028://5 Button
    Serial.print("Button Pressed 6 Passing Text to LCD");
    lcd.begin(16, 2);
    lcd.print("Button Press 6"); // Button 2  
    lcd.setCursor(0, 1);
    lcd.print("Good Night");
break;


case 0xF750AF://7 Button
    Serial.print("Button Pressed 7 Passing Text to LCD");
    lcd.begin(16, 2);
    lcd.print("Button Press 7"); // Button 2  
    lcd.setCursor(0, 1);
    lcd.print("Animate Text");
break;

case 0xF7D02F://8 Button
    Serial.print("BLinking");
    
    lcd.begin(16, 2);
    
    lcd.print("BLinking"); // Button 2  
    lcd.setCursor(0, 1);
    lcd.print("    Text    ");
    lcd.noBlink();
    delay(2000);
    lcd.blink();
  delay(2000);

case 0xF730CF://9 Button
    Serial.print("Scroll");
    
    lcd.setCursor(15,0);
  lcd.print("I LOVE");
  delay(500);
  for(i=0;i<20;i++)
  {
    lcd.scrollDisplayLeft();
    delay(150);
  }
  lcd.clear();
  lcd.setCursor(15,0);
  lcd.print("ARDUINO");
  delay(500);
  for(i=0;i<22;i++)
  {
    lcd.scrollDisplayLeft();
    delay(150);
  }
  lcd.clear();


break;
     default:
Serial.print("Undefined code received: 0x");
Serial.println(results.value, HEX);
lcd.begin(16, 2);
    lcd.print("Undefined Button");
  lcd.setCursor(0, 1);
    lcd.print(results.value, HEX);
  break;
}
irrecv.resume();
}
