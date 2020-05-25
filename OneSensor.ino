#include <phyphoxBle.h>


BleServer server("Arduino"); //Server anlegen

#define XSHUT_pin1 19
#define XSHUT_pin2 18
#define ButtonPin  2


#define Sensor1_newAddress 42
#define Sensor2_newAddress 43

#include <Wire.h>
#include <VL53L0X.h>

VL53L0X Sensor1;
VL53L0X Sensor2;

float distance1,distance2, t, b;

void setup()
{
  server.start();
  //disable tof sensors using shutdown pins 
  pinMode(XSHUT_pin1, OUTPUT);   
  pinMode(XSHUT_pin2, OUTPUT);
  pinMode(ButtonPin, INPUT_PULLUP);
  digitalWrite(XSHUT_pin1, LOW);
  digitalWrite(XSHUT_pin2, LOW);
 
  Serial.begin(115200);
  delay(2500)  ; //wait for serial
  Wire.begin();

  changeAddress();
  Serial.println(" init done ");
  digitalWrite(XSHUT_pin2, LOW);  //disable sensor 2

  // Start continuous back-to-back mode (take readings as
  // fast as possible).  To use continuous timed mode
  // instead, provide a desired inter-measurement period in
  // ms (e.g. sensor.startContinuous(100)).
  Sensor1.startContinuous();
  //Sensor2.startContinuous();
  
}

void loop()
{

  t = 0.001*(float)millis();
  distance1 = Sensor1.readRangeContinuousMillimeters();
  distance2 = 1.0 //Sensor2.readRangeContinuousMillimeters();
  if (distance1 == 8190)
    distance1 = 0;
  if (distance2 == 8190)
    distance2 = 0;

  b = (float)digitalRead(ButtonPin);
  
  //sendData
  server.write(distance1,distance2, t, b);

  Serial.print(distance1);
  Serial.print("   -    "); 
  Serial.println(distance2);
  Serial.print("   -    "); 
  Serial.println(b);
}

void changeAddress(){
  digitalWrite(XSHUT_pin1, HIGH);
  delay(100);
  Sensor1.setAddress(Sensor1_newAddress);
  Sensor1.setTimeout(500);
  if (!Sensor1.init())
  {
    Serial.println("Failed to detect and initialize sensor 1!");
    while (1) {}
  }

  digitalWrite(XSHUT_pin2, HIGH);
  delay(100);
  Sensor2.setAddress(Sensor2_newAddress);
  Sensor2.setTimeout(500);
  if (!Sensor2.init())
  {
    Serial.println("Failed to detect and initialize sensor 2!");
    while (1) {}
  }  
  
}
