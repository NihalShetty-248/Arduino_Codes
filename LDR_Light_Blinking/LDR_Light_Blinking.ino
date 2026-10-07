void setup() {
  pinMode(39,INPUT);
  pinMode(33,OUTPUT);
  Serial.begin(9600);// put your setup code here, to run once:

}

void loop() {
  float intensity=analogRead(39);
  Serial.println(intensity);
  analogWrite(33,intensity);// put your main code here, to run repeatedly:
  

}
