void setup() {
  Serial.begin(9600);
  //right motor
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  //left motor
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  //enpins
  pinMode(3,OUTPUT);
  pinMode(9,OUTPUT);
}

void loop() {
  if(Serial.available()>0)
  { 
    char data = Serial.read();
    
    if (data == 'L')
    {
    Serial.println("Left");
    //Turn on right motor
    //Turn off left motor
    digitalWrite(11,HIGH)
    digitalWrite(10,LOW);
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);  }
    
    
    else if(data == 'R')
    {
      Serial.println("Right");
    //Turn on left motor
    //Turn off right motor
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
    }
    
    
    else if(data == 'F')
    {
     Serial.println("Forward");
    //Turn on both the motors   
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
    }
    
    else{
    Serial.println("Stop"); 
    //Turn off both the motors
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);    
     }
  }
}
