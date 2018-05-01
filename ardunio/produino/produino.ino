#include "SPI.h"
#include "Phpoc.h"

PhpocEmail email;
PhpocDateTime datetime;

const int THRESHOLD = 50;
boolean objPresent = false;
long adcValue = 0;

boolean sendGmail();

///---------////////////////////////////////////////////

char val; // Data received from the serial port
int redPin = 11; // Set the pin to digital I/O 13
int greenPin = 9;
int bluePin = 10;
int buzzer = 12;

///////////////////////////////////////////////////
 void setup() {
   pinMode(redPin, OUTPUT); // Set pin as OUTPUT
   pinMode(greenPin, OUTPUT); // Set pin as OUTPUT
   pinMode(bluePin, OUTPUT); // Set pin as OUTPUT
   pinMode(buzzer, OUTPUT); // Set pin for activating buzzer
   Serial.begin(9600); // Start serial communication at 9600 bps
 

//FOR THE EMAIL SENDING //////////////////////////////////

//    Serial.begin(9600);
//    while(!Serial)
//    ;
//    pinMode(A0, INPUT); // to read value from sensor
//    pinMode(5, OUTPUT); // to control relay
//    
//    Phpoc.begin(PF_LOG_SPI | PF_LOG_NET | PF_LOG_APP);
//    datetime.date("Y-M-d H:i:s");
    
}

  void loop() {
   if (Serial.available()) 
   { // If data is available to read,
     val = Serial.read(); // read it and store it in val
   }

   
 //// LED trigger code//////////////////////////////////////

    if (val == '0') 
   { // If 1 was received
     digitalWrite(redPin, 102); // turn the LED on
     digitalWrite(greenPin, 51); // turn the LED on
     digitalWrite(bluePin, 0); // turn the LED on
     tone(buzzer,150,400);//
     delay(1500);
     tone(buzzer,350,400 );//
     delay(1500);


   } else {
     digitalWrite(redPin, LOW); // otherwise turn it off
     digitalWrite(greenPin, LOW); // otherwise turn it off
     digitalWrite(bluePin, LOW); // otherwise turn it off
     tone(buzzer,LOW);//
     //delay(1000);
   }
   delay(10); // Wait 10 milliseconds for next reading
   
/*
//---------------------------------------//////////////
//code for email in void loop
// read 30 time and get average value to eliminate noises

    adcValue = 0;
    
    for(int i = 0; i < 30; i++)
    {
        adcValue += analogRead(A0);
        delay(10);
    }
    
    adcValue /= 30;
    
    if(adcValue < THRESHOLD)
    {
        
        if(objPresent)
        {
            //Alert
             digitalWrite(5, HIGH);
            // send notification
            while(!sendGmail())
               ;
            
            objPresent = false;
        }
    }
    else
    {
        objPresent = true;
        digitalWrite(5, LOW);
    } */
}
/*
boolean sendGmail(){
    // setup outgoing relay server - gmail.com
    email.setOutgoingServer("smtp.gmail.com", 587);
    email.setOutgoingLogin("your_account", "your_password");
    
    // setup From/To/Subject
    email.setFrom("ayanosmanphotog@gmail.com", "Arduino");
    email.setTo("ayanosmanphotog@gmail.com", "Boss");
    
    email.setSubject("Alert: Your treasure is being taken away");
    
    // write email message
    email.beginMessage();
    email.println("Location: Planet Earth.");
    email.println("");
    email.print("Time: ");
    email.println(datetime.date());
    email.println("");
    email.println("Your treasure is being taken away.");
    email.endMessage();
    
    // send email
    if(email.send() > 0)
    {
        Serial.println("Email send ok");
        return true;
    }
    else
    {
        Serial.println("Email send failed");
        return false;
    }
} */
