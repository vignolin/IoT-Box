#include <virtuabotixRTC.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define clk   6
#define dat   7
#define rst   8

#define   segL       30
#define   minL       45
#define   horL       18
#define   d_semL      2
#define   d_mesL     2
#define   mesL        7
#define   anoL      2024

virtuabotixRTC   myRTC(clk, dat, rst);    
LiquidCrystal_I2C lcd(0x27,20,4);



void setup() {
  // put your setup code here, to run once:
  lcd.init();            

  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Seja bem-vind@!");
  delay(500);
  lcd.clear();

  //myRTC.setDS1302Time(segL, minL, horL, d_semL, d_mesL, mesL, anoL);
}

void loop() {
  
  myRTC.updateTime();         //faz leitura do DS1302

  // Imprime informações
  lcd.setCursor(4, 0);
  lcd.print(myRTC.dayofmonth);
  lcd.print("/");
  lcd.print(myRTC.month);
  lcd.print("/");
  lcd.print(myRTC.year);
  lcd.setCursor(6, 1);
  if(myRTC.hours < 10) lcd.print("0");
  lcd.print(myRTC.hours);
  lcd.print(":");
  if(myRTC.minutes < 10) lcd.print("0");
  lcd.print(myRTC.minutes);
  delay(59500);
  lcd.clear();
  delay(500);

}
