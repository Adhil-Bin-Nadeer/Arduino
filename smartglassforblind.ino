#define pingPin 2        //trig pin of sr04
#define echoPin 3

void setup() {
   Serial.begin(38400); // Starting Serial Terminal
   pinMode(pingPin,OUTPUT); 
   pinMode(echoPin,INPUT);
   pinMode(12,OUTPUT);   //pin12 is used as GND pin  for buzzer since arduino nano has only two GND pins
   pinMode(A3,OUTPUT);   //pin A3 provides the output on buzzer
}

void loop() {
   long duration, cm;
  digitalWrite(5, LOW);   //Buzzer GND is always low


   //send a signal at ping pin at an interval of 0.002 seconds to check for an object
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);    
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(2);
   digitalWrite(pingPin, LOW);

  
   duration = pulseIn(echoPin, HIGH);  //check time using pulseIn function
   
   cm = microsecondsToCentimeters(duration);   //functin call to find distance


   
    if (cm<70&&cm>50) {analogWrite(A3,20000); 
                           delay(250); 
                           analogWrite(A3,0); 
                           delay(500); }   //sound buzzer every 0.5 seconds if obstacle distance is between 10-20cm. 
  
   
   else if (cm<50&&cm>30)  {analogWrite(A3,20000); 
                           delay(100); 
                           analogWrite(A3,0);
                           delay(250); }    //sound buzzer every 0.1 seconds if obstacle distance is between 0-10cm. 

   else if (cm<30&&cm>0)  {analogWrite(A3,20000); 
                           delay(50); 
                           analogWrite(A3,0);
                           delay(0); }    //sound buzzer every 0.1 seconds if obstacle distance is between 0-10cm. 
                          
  
   
   else                     analogWrite(A3,0); //do not sound the buzzer
}



//function to return distance in cm from microseconds
long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
