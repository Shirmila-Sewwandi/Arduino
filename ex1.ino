int trig_Pin = 11;
int echo_Pin = 8;
int buz=5;

void setup() {
  Serial.begin(9600);
  pinMode(trig_Pin,OUTPUT);
  pinMode(echo_Pin,INPUT);
  pinMode(buz,OUTPUT);
}

void loop() {
  long duration, cm;
  digitalWrite(trig_Pin,LOW);
  delayMicroseconds(2);
  
  digitalWrite(trig_Pin,HIGH);
  delayMicroseconds(5);
  digitalWrite(trig_Pin,LOW);
  
  duration = pulseIn(echo_Pin, HIGH);
  cm = microsecondsToCentimeters(duration);
  
  if (cm<=70 && cm>0)
  {
    digitalWrite(buz,HIGH);
    delay(100);
    digitalWrite(buz,LOW);
    delay(100);
  }
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);
  }
  long microsecondsToCentimeters(long microseconds)
  {
    return microseconds/29/2;
  }
 