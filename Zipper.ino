#include <Servo.h>
int GSM1 = 3;
int GSM2 = 11;

// ******Parameter******
int maxspeed = 50;
int spinning_time = 1000;
int pause_time = 5000;
// ******Parameter******

#define In1 5
#define In2 6

#define In3 10
#define In4 9

void setup() {
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(GSM1, OUTPUT);

  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(GSM2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  startSpin();
  delay(spinning_time);
  rotate();
  delay(spinning_time);
  stopRotate();
  stopSpin();
  delay(spinning_time);
  reverseRotate();
  reverseSpin();
  delay(spinning_time);
  stopRotate();
  delay(spinning_time);
  stopSpin();
  delay(pause_time);
}

void startSpin() {
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  for (int i = 0; i <= maxspeed; i += 1) {
    analogWrite(GSM1, i * 3);
    delay(50);
  }
}
void reverseSpin() {
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  for (int i = 0; i <= maxspeed; i += 1) {
    analogWrite(GSM1, i * 3);
    delay(50);
  }
}

void rotate() {
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  for (int i = 0; i <= maxspeed; i += 1) {
    analogWrite(GSM2, i);
    delay(50);
  }
}

void reverseRotate() {
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  for (int i = 0; i <= maxspeed; i += 1) {
    analogWrite(GSM2, i);
    delay(50);
  }
}


void stopRotate() {
  for (int i = maxspeed; i >= 0; i -= 1) {
    analogWrite(GSM2, i);
    delay(50);
  }
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
}

void stopSpin() {
  for (int i = maxspeed; i >= 0; i -= 1) {
    analogWrite(GSM1, i / 3);
    delay(50);
  }
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
}