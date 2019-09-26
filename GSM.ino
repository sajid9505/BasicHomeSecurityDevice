/*********
  Complete project details at https://randomnerdtutorials.com
*********/

#include <SoftwareSerial.h>

// Configure software serial port
//SoftwareSerial SIM900(7, 8);
SoftwareSerial SIM900(8, 7);


void setup() {
  // Arduino communicates with SIM900 GSM shield at a baud rate of 19200
  // Make sure that corresponds to the baud rate of your module
  SIM900.begin(19200);
  Serial.begin(19200);

//////////////////// Uncomment this once everytime you change the operator, then comment it back again.
//    delay(1000);
//  SIM900.print("AT+CSCA=\"+8801600006001\""); // For AIRTEL
//  delay(1000);
//  SIM900.print("AT+CSCA=\"+8801700000600\""); // For GRAMEEN
//  SIM900.print("AT+CSCA=\"+8801801000004\""); // For ROBI
//  SIM900.print("AT+CSCA=\"+88019900557\""); // For BANGLALINK
//
//  // Give time to your GSM shield log on to network
  Serial.println("Initialzing");
  delay(20000);
  Serial.println("Done Initialzing");
//
//  // Send the SMS
  Serial.println("Sending SMS");
  sendSMS();
//
  Serial.println("Done Sending SMS");
}

void loop() {
//  if (SIM900.available()){
//    Serial.write(SIM900.read());
//  }
//  if (Serial.available()){
//    SIM900.write(Serial.read());
//  }
}

//void sendSMS() {
//
//
//  // REPLACE THE X's WITH THE RECIPIENT'S MOBILE NUMBER
//  // USE INTERNATIONAL FORMAT CODE FOR MOBILE NUMBERS
//  SIM900.println("AT+CMGS=\"+8801794342790\"");
//  delay(100);
//
//  // REPLACE WITH YOUR OWN SMS MESSAGE CONTENT
//  SIM900.print("Message example from Arduino Uno.");
//  delay(100);
//
//  // End AT command with a ^Z, ASCII code 26
//  SIM900.print((char)26);
//  delay(100);
//  SIM900.println();
//  // Give module time to send SMS
//  delay(100);
//
//
//}

void sendSMS() {

  // AT command to set SIM900 to SMS mode
  SIM900.print("AT+CMGF=1\r"); 
  delay(100);

  // REPLACE THE X's WITH THE RECIPIENT'S MOBILE NUMBER
  // USE INTERNATIONAL FORMAT CODE FOR MOBILE NUMBERS
  SIM900.println("AT + CMGS = \"+8801552344582\""); 
  delay(100);
  
  // REPLACE WITH YOUR OWN SMS MESSAGE CONTENT
  SIM900.println("test"); 
  delay(100);

  // End AT command with a ^Z, ASCII code 26
  SIM900.println((char)26); 
  delay(100);
  SIM900.println();
  // Give module time to send SMS
  delay(5000); 
}
