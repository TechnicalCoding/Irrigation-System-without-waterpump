#include <LiquidCrystal_I2C.h> //LCD I2C liberary 
#include <Wire.h> //wire library 
LiquidCrystal_I2C lcd(0x3F, 16, 2); 
void setup() 
{
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
}
void loop() 
{
 int S1 = analogRead(A0);
 if(S1 >= 680)
 {
  lcd.setCursor(0,0);
  lcd.print("   Soil Status");
  lcd.setCursor(0,1);
  lcd.print("Not in Soil    ");
  Serial.print("Not in Soil");
 }
 if(S1 < 680 && S1 >= 435)
 {
  lcd.setCursor(0,0);
  lcd.print("   Soil Status");
  lcd.setCursor(0,1);
  lcd.print("Dry           ");
 }
 if(S1 < 435 && S1 >=420)
 {
  lcd.setCursor(0,0);
  lcd.print("   Soil Status");
  lcd.setCursor(0,1);
  lcd.print("      Humid   ");
 }
 if(S1 < 420)
 {
  lcd.setCursor(0,0);
  lcd.print("   Soil Status");
  lcd.setCursor(0,1);
  lcd.print("Water logging     ");
 }
}
