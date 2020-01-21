#include<VirtualWire.h>

const char*message="MERRY";
const int transmit_pin = 7;
const int receive_pin = 2;
const int transmit_en_pin = 3;
int a=0;
int b=0;

void setup(){
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(8,INPUT);
    vw_set_tx_pin(transmit_pin);
    vw_set_rx_pin(receive_pin);
    vw_set_ptt_pin(transmit_en_pin);
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);       // Bits per sec
}

void loop() {
  // put your main code here, to run repeatedl
int alc=analogRead(A0);
int touch=digitalRead(8);
    if(touch==1){
	a++;
	delay(100);
	if(a>15){
	  Serial.println(a);
	  Serial.println(“Turn on”);
	  b=0;
 	  message="X";
  	  vw_send((uint8_t*)message,strlen(message));
  	  vw_wait_tx();
 	  Serial.println("X");
	  delay(100);
     }}
     else if(touch==0){
  	b++;
   	delay(100);
   	if(b>15){
   	  Serial.println(b);
   	  Serial.println(“Turn off”);
   	  a=0;
   	  message="Y";
       	  vw_send((uint8_t*)message,strlen(message));
  	  vw_wait_tx();
 	  Serial.println("Y");
 	  delay(100);  
     }}
     if(alc>300){
 	Serial.println(alc);
 	Serial.println(“Turn off”);
	message=”Z”;
   	vw_send((uint8_t*)message,strlen(message));
        vw_wait_tx();
 	Serial.println(“Z”);
 	delay(100);
	}

}

