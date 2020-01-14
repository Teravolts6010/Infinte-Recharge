#define Trig 2
#define Echo 3
#define UltrasonicTR 11

 long distance;

void setup() {
  
  Serial.begin(9600);
  pinMode (Trig, OUTPUT);
  pinMode (Echo, INPUT);
  pinMode (UltrasonicTR, OUTPUT);

}

void loop() {

  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);

  distance = pulseIn(Echo, HIGH) / 58;

  if(distance >= 500 || distance <= 0)
     distance = 0;

  Serial.print(distance);
  Serial.println(" cm");

  analogWrite(11, distance * 0.51);

  
}
