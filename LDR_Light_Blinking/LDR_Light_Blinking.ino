const int ldr=39;
const int led=33;

void setup() {
  pinMode(ldr,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);// put your setup code here, to run once:

}

void loop() {
  float intensity=analogRead(ldr);
  Serial.println(intensity);
  analogWrite(led,intensity);// put your main code here, to run repeatedly:
  

}
