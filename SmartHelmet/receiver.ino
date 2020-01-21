#include<VirtualWire.h>
#include <LiquidCrystal.h>
const int transmit_pin =12;
const int receive_pin =11;
 const int transmit_en_pin =3;
//initialize the library by associating any needed LCD interface pin with the arduino pin no it is connected to
const int rs=12,en=10,d4=5,d5=4,d=6,d7=2; 
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("setup");
  vw_set_tx_pin(transmit_pin);
  vw_set_rx_pin(receive_pin);
  vw_set_ptt_pin(transmit_en_pin);
  vw_set_ptt_inverted(true);
  vw_setup(2000);
  vw_rx_start();
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT); 
lcd.begin(16,2);
//initialize the serial communications
Lcd.write(“Smart Helmet”);
Lcd.setCursor(0,1);
}

void loop() {
  // put your main code here, to run repeatedly:
uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen= VW_MAX_MESSAGE_LEN;

if (vw_get_message(buf, &buflen))
{
 if (buf[0]=='X')
{
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
Serial.println(“Ignition on”);
lcd.clear();
lcd.write(“IGNITION ON”);
}
else if(buf[0]=='Y'){
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
Serial.println(“Ignition off-helmet not worn”);
lcd.clear();
lcd.write(“IGNITION OFF”);
lcd.setCursor(0,1);
lcd.write(“HELMET NOT WORN”);
  }
else if (buf[0]==’Z’){
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
Serial.println(“Ignition off-alcohol detected”);
lcd.clear();
lcd.write(“IGNITION OFF”);
lcd.setCursor(0,1);
lcd.write(“ALCOHOL  SENSED”);

}
}}
