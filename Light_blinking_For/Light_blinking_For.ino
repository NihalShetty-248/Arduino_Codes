/*A model car company is prototyping an autonomous pursuit vehicle based on the ESP32. The hardware engineer installed two ultra-bright blue strobe lights on the roof rack—using the LEDs connected to Pin 4 (left strobe) and Pin 33 (right strobe). To simulate the vehicle's high-visibility pursuit mode, the lighting system must produce a distinct double-pulse warning pattern rather than a simple continuous blink. 
a. When the cruiser enters pursuit mode, both roof strobes must flash together in rapid bursts to mimic real emergency lights: they illuminate simultaneously for 100 milliseconds, shut off for 100 milliseconds. This warning sequence occurs exactly twice. 
b. Once that warning is delivered, Left Strobe illuminates for 100ms and shuts off. When Left strobe becomes off, Right Strobe illuminates for 100ms and shuts off.
c. Then the system needs a deliberate quiet interval: both lights must stay completely dark for 1.5 seconds, so the human eye can distinguish between separate pursuit alerts. 
Then the above cycle repeats. */

const int pin1=33;
const int pin2=4;
int i=0;
void setup() {
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);// put your setup code here, to run once:

}

void loop() {
  while (i<2) {
    digitalWrite(pin1,HIGH);
    digitalWrite(pin2,HIGH);
    delay(100);
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,LOW);
    delay(100);
    i=i+1;
  } 
  i=0;
  digitalWrite(pin2,HIGH);
  delay(100);
  digitalWrite(pin2,LOW);
  delay(100);
  digitalWrite(pin1,HIGH);
  delay(100);
  digitalWrite(pin1,LOW);
  delay(1500);// put your main code here, to run repeatedly:

}
