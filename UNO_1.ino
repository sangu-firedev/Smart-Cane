#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <Arduino.h>
#include <stdio.h>


// Choose two Arduino pins to use for software serial (gps)
// gps
int RXPin = 2;
int TXPin = 3;

int GPSBaud = 9600;
String datareal; 
String dataimaginary;
String combined;
int raw = 1000000;
 
String datareal2;
String dataimaginary2;
String combined2;
 
 
 double longitude; 
 double latitude;
// Create a Tinygps++ object
TinyGPSPlus gps;

// Create a software serial port called "gpsSerial"
SoftwareSerial gpsSerial(RXPin, TXPin);

/*
The circuit:
* RX is digital pin 10 (connect to TX of GSM Modem)
* TX is digital pin 11 (connect to RX of GSM Modem)
*/

// Vibration Sensor
int vibr_Pin =4;

// GSM
SoftwareSerial gsmSerial(10, 11); // RX, TX

void setup(){
  Serial.begin(9600); 
  // Start the software serial port at the GPS's default baud
  gpsSerial.begin(GPSBaud);

  pinMode(7, OUTPUT);
  
  pinMode(vibr_Pin, INPUT); //set vibr_Pin input for measurment
  Serial.begin(9600); //init serial 9600
}


void loop(){
  digitalWrite(7, HIGH);

  latitude = gps.location.lat(), 6 ;
  longitude = gps.location.lng(), 6 ;
  // for latitude
  long datareal = int(latitude);
  int fahad = ( latitude - datareal) * 100000;
  
  // for longitude
  long datareal2 = int(longitude);
  int fahad2 = (longitude - datareal2 ) * 100000;


  // If 5000 milliseconds pass and there are no characters coming in
  // over the software serial port, show a "No GPS detected" error
  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println("No GPS detected");
    while(true);
  }

  long measurement =TP_init();
  delay(50);
 // Serial.print("measurment = ");
  Serial.println(measurement);
  if (measurement > 50000){
    Accident();
  }
  
  // print response over serial port
  if (gsmSerial.available())
  Serial.write(gsmSerial.read());
}
void Accident()
{
  Serial.println("Calling through GSM Modem");

  // set the data rate for the SoftwareSerial port
  gsmSerial.begin(9600);
  delay(2000);
  gsmSerial.println("ATD6364220275;"); // ATD81290255XX;
  delay(1000);
  Serial.println("Called ATD6364220275");
  delay(2000);
  
  gsmSerial.println("AT+CMGF=1"); // Configuring TEXT mode
  delay(1000);
  gsmSerial.println("AT+CMGS=\"Your Phone number\"\r");
  delay(1000);
  gsmSerial.println("Accident Alert......!");                 // The SMS text you want to send
  gsmSerial.print("https://www.google.com/maps/search/");
  gsmSerial.print(lati);
  gsmSerial.print("%2C");
  gsmSerial.print(longi);
  delay(100);
  gsmSerial.println((char)26);
  delay(1000);
}

void displayInfo()
{
  if (gps.location.isValid())
  {
    Serial.print("Latitude: ");
    Serial.println(gps.location.lat(), 6);
    Serial.print("Longitude: ");
    Serial.println(gps.location.lng(), 6);
    Serial.print("Altitude: ");
    Serial.println(gps.altitude.meters());
  }
  else
  {
    Serial.println("Location: Not Available");
  }
  
  Serial.print("Date: ");
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print("/");
    Serial.print(gps.date.day());
    Serial.print("/");
    Serial.println(gps.date.year());
  }
  else
  {
    Serial.println("Not Available");
  }

  Serial.print("Time: ");
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10) Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(":");
    if (gps.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(":");
    if (gps.time.second() < 10) Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(".");
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    Serial.println(gps.time.centisecond());
  }
  else
  {
    Serial.println("Not Available");
  }

  Serial.println();
  Serial.println();
  delay(1000);
}

long TP_init(){
  delay(10);
  long measurement=pulseIn (vibr_Pin, HIGH);  //wait for the pin to get HIGH and returns measurement
  return measurement;
}
