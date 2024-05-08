#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2); 
Servo tap_servo;

int sensor_pin = 7;
int tap_servo_pin =9;
int val;

void setup(){

  lcd.init();
  lcd.clear();         
  lcd.backlight(); 


  Serial.begin(9600);
  pinMode(sensor_pin,INPUT);
  tap_servo.attach(tap_servo_pin);
  
}
int state;
void loop(){
  val = digitalRead(sensor_pin);

  if (val==0)
  {tap_servo.write(0);
  state = "walang laman";
  lcd.setCursor(0,1);   //Set cursor to character 2 on line 0
  lcd.print("Walang Laman");
  }
  if (val==1)
  {tap_servo.write(180);
  lcd.setCursor(0,1);   //Set cursor to character 2 on line 0
  lcd.print("May Laman");
  state = "may laman";
    }
  Serial.println(val, state);
  delay(500);
}
