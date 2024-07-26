#define trigPin 13
#define echoPin 12
#define buzzer 6
#define sensorPower 7
#define sensorPin A0

// Ultrasonic sensor and water sensor -> Using Arduino Nano

// to store water level
int val = 0;

void setup()
{
  // WATER SENSOR
  // Set D7 as an OUTPUT
  pinMode(sensorPower, OUTPUT);
  
  // Set to LOW so no power flows through the sensor
  digitalWrite(sensorPower, LOW);

  // ULTRANSONIC SENSOR
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer,OUTPUT);
}

void loop()
{ 
  // WATER SENSOR
  //get the reading from the function below and print it
  int level = readSensor();
 
  Serial.print("Water level: ");
  Serial.println(level);

  if(val > 300)
  {
    // when water level is 380 and above
    digitalWrite(buzzer,HIGH); 
  }
  else
  {
    digitalWrite(buzzer,LOW);
  }
  delay(250);
  
  // ULTRASONIC SENSOR
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1; 
  
  if (distance < 70) // Checking the distance, you can change the value
  { 
  // When the the distance below 100cm
  digitalWrite(buzzer,HIGH);
  } else
  {
  // when greater than 100cm
  digitalWrite(buzzer,LOW); 
  } delay(50);
}

// WATER SENSOR
//This is a function used to get the reading
int readSensor() {
  digitalWrite(sensorPower, HIGH);  // Turn the sensor ON
  delay(10);              // wait 10 milliseconds
  val = analogRead(sensorPin);    // Read the analog value form sensor
  digitalWrite(sensorPower, LOW);   // Turn the sensor OFF
  return val;             // send current reading
}
