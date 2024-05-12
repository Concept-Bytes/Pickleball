
#include "thingProperties.h"
#include <Arduino_LSM6DSOX.h>

float Ax, Ay, Az;
float velocity = 0;
bool toggle = true;
unsigned long previousMillis = 0;
unsigned long currentMillis = millis();
float deltaTime = (currentMillis - previousMillis) /1000.0;
const float conversionFactor = 2.237;



void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  if (!IMU.begin()){
    Serial.println("Failed to initialize the IMU!");
      while (1);
  }

  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println("Hz");

  

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 


  //Read in accelerometer data
  if (IMU.accelerationAvailable()){
    IMU.readAcceleration(Ax, Ay, Az);
  }

  //Calculate acceleration magnitude
  accel_magnitude = sqrt(Ax * Ax + Ay * Ay + Az * Az) - 1; //Subtract one for gravity

  currentMillis = millis();
  deltaTime = (currentMillis - previousMillis) /1000.0;

  if (abs(accel_magnitude) > 0.5) {
    velocity += accel_magnitude * deltaTime;
  } else{
    velocity = 0;
  }

  //Convert to MPH
  mph = velocity * conversionFactor;

  //hit counter
  if (accel_magnitude > 4.0 && toggle == true) {
    hit_counter +=1; 
    toggle = false;
  }
  else if (accel_magnitude <= 4.0 && toggle == false) {
    toggle = true; //reset toggle when swing stops
  }

  previousMillis = currentMillis;
  
  if (mph > max_mph){
    max_mph = mph;
  }

  delay(100); 
  
}



/*
  Since HitCoutner is READ_WRITE variable, onHitCoutnerChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onHitCoutnerChange()  {
  // Add your code here to act upon HitCoutner change
}

/*
  Since Mph is READ_WRITE variable, onMphChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMphChange()  {
  // Add your code here to act upon Mph change
}



/*
  Since HitCounter is READ_WRITE variable, onHitCounterChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onHitCounterChange()  {
  // Add your code here to act upon HitCounter change
}


/*
  Since MaxMph is READ_WRITE variable, onMaxMphChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMaxMphChange()  {
  // Add your code here to act upon MaxMph change
}

/*
  Since AccelMagnitude is READ_WRITE variable, onAccelMagnitudeChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onAccelMagnitudeChange()  {
  // Add your code here to act upon AccelMagnitude change
}

/*
  Since Reset is READ_WRITE variable, onResetChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onResetChange()  {
  // Add your code here to act upon Reset change
  max_mph = 0;
  hit_counter = 0;
  
}