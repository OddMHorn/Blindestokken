#define TRIG 2 //Module pins
#define ECHO 3

long duration, distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(TRIG, OUTPUT);
  //pinMode(ECHO, INPUT_PULLUP);
  pinMode(ECHO, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = (duration/2) / 29.1;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm");
  Serial.println();
  delay(10);

/*
digitalWrite(TRIG, LOW);
delayMicroseconds(20);

digitalWrite(TRIG, HIGH);
int distance = pulseIn(ECHO, HIGH, 26000);

distance = distance/58;


Serial.print("Distance ");
Serial.print(distance);
Serial.print("cm");
Serial.println();

delay(50);

digitalWrite(TRIG, LOW);
delayMicroseconds(20);
*/
}
