const int ldr=39;
const int led=33;

void setup() {
  pinMode(ldr,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);// put your setup code here, to run once:

}

void loop() {
  float time=analogRead(ldr);
  Serial.println(time);
  digitalWrite(led,HIGH);
  delay(time);
  digitalWrite(led,LOW);
  delay(time);// put your main code here, to run repeatedly:
  

}
