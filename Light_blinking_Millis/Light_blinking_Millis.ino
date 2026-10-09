/*A marine research team is assembling a floating sensor buoy powered by an ESP32. The buoy communicates its status to surface research vessels at night using two navigation markers: 
  LED connected to Pin 4 is used as a Water-level beacon (Yellow marker) 
  LED connected to Pin 33 is used as a Satellite link indicator (Green marker)

These two systems run on separate hardware clocks inside the buoy, and hence their visual indicators must operate entirely on their own cadences: 
  The Water-level beacon must turn ON and OFF at a brisk, steady rhythm—flipping its state every 300 ms to warn incoming marine vessels. 
   The Satellite link indicator operates on an entirely different schedule—it must flip its state every 750 ms to confirm continuous telemetry uplink. 
 */

const int pin1=33;
const int pin2=4;
long start_time1=0;
long start_time2=0;
bool led1_state=HIGH;
bool led2_state=HIGH;

void setup() {
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);// put your setup code here, to run once:

}

void loop() {
  long current_time=millis();
  if (current_time-start_time1>=300) {
    digitalWrite(pin1,led1_state);
    led1_state=!led1_state;
    start_time1=current_time;
  }
  if (current_time-start_time2>=750) {
    digitalWrite(pin2,led2_state);
    led2_state=!led2_state;
    start_time2=current_time;
  }


}

