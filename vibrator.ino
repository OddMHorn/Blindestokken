/*
    Vibration Motor with Arduino
    For more details, visit: https://techzeero.com/arduino-tutorials/vibration-motor-with-arduino/
*/
long duration, distance;
#define TRIG 5 //Module pins
#define ECHO 16
int motorPin = 0; //motor transistor is connected to pin 0                         
#define powervib  12 //motor power connected to pin 12
#define PWM1_Ch    0
#define PWM1_Res   8
#define PWM1_Freq  1000

int PWM1_DutyCycle = 0;

void setup()
{
  pinMode(motorPin, OUTPUT);
  pinMode(powervib, OUTPUT);
  ledcAttachPin(powervib, PWM1_Ch);
  ledcSetup(PWM1_Ch, PWM1_Freq, PWM1_Res);
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(TRIG, OUTPUT);
  //pinMode(ECHO, INPUT_PULLUP);
  pinMode(ECHO, INPUT);
}

void loop()
{
  ledcWrite(PWM1_Ch, PWM1_DutyCycle); //pwm halv styrke
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
  digitalWrite(motorPin, HIGH); //vibrate
  if(distance<10){
    PWM1_DutyCycle = 0;
  }
  if(distance<15 && distance>10){
    PWM1_DutyCycle = 190;
  }
  if(distance<20 && distance>15){
    PWM1_DutyCycle = 225;
  }
  if(distance<30 && distance>20){
    PWM1_DutyCycle = 400;
  }
  if(30<distance){
    PWM1_DutyCycle = 555;
  }
  Serial.print(PWM1_DutyCycle);
  //digitalWrite(motorPin, HIGH); //vibrate
  
  //digitalWrite(motorPin, LOW);  //stop vibrating
  delay(10);
  
}
