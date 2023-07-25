#define USE_ARDUINO_INTERRUPTS true   
#include <PulseSensorPlayground.h>        
// Variable declearing
const int PulseWire = 0;       // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
const int LED = LED_BUILTIN;   // The on-board Arduino LED
int Threshold = 680;           // Determine which Signal to "count as a beat" and which to ignore.

                               
PulseSensorPlayground pulseSensor;  // Creates an instance of the PulseSensorPlayground object called "pulseSensor"


void setup()
{   

  Serial.begin(9600);          // For Serial Monitor baudrate

  // Configure the PulseSensor object, by assigning our variables to it. 
  pulseSensor.analogInput(PulseWire);   //analog input form port A0 analog port
  pulseSensor.blinkOnPulse(LED);       //blink Arduino's LED with heartbeat.
  pulseSensor.setThreshold(Threshold); //threshold is set 680  

  // Double-check the "pulseSensor" object was created and "began" seeing a signal. 
   if (pulseSensor.begin()) {
    Serial.println("We created a pulseSensor Object !");  //This prints one time at Arduino power-up,  or on Arduino reset.  
  }
}



void loop() {

 

if (pulseSensor.sawStartOfBeat()) {            // Constantly test to see if "a beat happened".
int myBPM = pulseSensor.getBeatsPerMinute();  // Calls function on our pulseSensor object that returns BPM as an "int".

int myBPM1 = myBPM-153; // Print phrase "BPM:" 
 if(myBPM1>0)   //to eliminate negative values
 {
    Serial.print("BPM: "); 
    Serial.println(myBPM1);}                        // Print the value inside of myBPM. 
}

  delay(20);                    // to sync the code with python.

}

  
