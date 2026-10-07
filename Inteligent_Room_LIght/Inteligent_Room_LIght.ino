/*The LED acts as the room light. The push button toggles the system ON/OFF (manual override). When the button is pressed,
manual mode is activated, and the LED needs to glow with maximum brightness. If the button is released/not pressed, the system works in automatic mode.
In automatic mode, the LDR detects ambient brightness: if the room is dark, the LED should turn ON. Darkness is defined as any LDR value less than 1024.
The potentiometer adjusts the LED brightness – When there is more darkness, the brightness should be high (255); if there is no darkness, the brightness is set to a standard value of 100.  
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
      analogWrite(pin,100);
    }
    

  }
}
