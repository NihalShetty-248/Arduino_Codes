/*A marine research team is assembling a floating sensor buoy powered by an ESP32. The buoy communicates its status to surface research vessels at night using two navigation markers: 
  LED connected to Pin 4 is used as a Water-level beacon (Yellow marker) 
  LED connected to Pin 33 is used as a Satellite link indicator (Green marker)

These two systems run on separate hardware clocks inside the buoy, and hence their visual indicators must operate entirely on their own cadences: 
  The Water-level beacon must turn ON and OFF at a brisk, steady rhythm—flipping its state every 300 ms to warn incoming marine vessels. 
   The Satellite link indicator operates on an entirely different schedule—it must flip its state every 750 ms to confirm continuous telemetry uplink. 
 */

const int pin=33;
const int pot=36;
const int ldr=39;
const int but=0;

void setup() {
  pinMode(pin,OUTPUT);
  pinMode(pot,INPUT);
  pinMode(ldr,INPUT);
  pinMode(but,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int button_state=digitalRead(but);
  if (button_state==LOW) {
    analogWrite(pin,255);
  
  }
  else {
    float ldr_value=analogRead(ldr);
    Serial.println(ldr_value);
    if (ldr_value < 1024) {
      analogWrite(pin,255);
      float pot_value=analogRead(pot)/16;
      analogWrite(pin,pot_value);
    }
    else {
      analogWrite(pin,0);
    }
    

  }
}
