/*A streetlight should save energy by adapting to conditions. You are asked to simulate an Energy-Saving Streetlight with Manual Override, using ESP32. 
Let an LED represent the streetlight. Push button acts as a maintenance override: pressing it forces the LED OFF regardless of conditions.
When released, the street light takes the energy-saving mode. LDR senses ambient light: LED ON at night, OFF during the day.
A night is detected if the LDR value is less than 2048.0 represents the darkest night time and 4095 represents noon.
During night, the streetlight is ON with full brightness (255), and during day time it should be off (0).
A potentiometer can be used to adjust the LED brightness between 0 and 255.*/

const int button=32;
const int led=33;
const int ldr=39;
const int pot=36;

void setup() {
  pinMode(led,OUTPUT);
  pinMode(button,INPUT_PULLUP);
  pinMode(ldr,INPUT);
  pinMode(pot,INPUT);
  Serial.begin(9600);

}

void loop() {
  bool button_state=digitalRead(button);
  if (button_state==LOW) {
    analogWrite(led,0);
  }
  else {
    float ldr_value=analogRead(ldr);
    Serial.println(ldr_value);
    if (ldr_value<2048.0) {
      analogWrite(led,255);
      float pot_value=analogRead(pot)/16.1;
      analogWrite(led,pot_value);
    }
    else {
      analogWrite(led,0);
    }
  }
}