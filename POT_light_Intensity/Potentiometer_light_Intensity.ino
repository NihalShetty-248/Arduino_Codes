const int pot=36;
const int led=33;

void setup() {
  pinMode(pot,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);// put your setup code here, to run once:

}

void loop() {
  float intensity=analogRead(pot);
  Serial.println(intensity);
  analogWrite(led,intensity);// put your main code here, to run repeatedly:
  

}
