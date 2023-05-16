/*
Project Code: Solar Tracking System
*/

#include <Servo.h>
// Defining Servos
Servo servohori;  // Horizontal Servo
int servoh = 0;
int servohLimitHigh = 160;
int servohLimitLow = 20;

Servo servoverti;  // Vertical Servo
int servov = 0;
int servovLimitHigh = 160;
int servovLimitLow = 20;

int ldrtopl = 2;  // top left LDR green
int ldrtopr = 0;  // top right LDR yellow
int ldrbotl = 1;  // bottom left LDR blue
int ldrbotr = 3;  // bottom right LDR orange


void setup() {
  pinMode(A0, INPUT);  // Light sensor up - left
  pinMode(A1, INPUT);  // Light sensor up - right
  pinMode(A2, INPUT);  // Light sensor bottom - left
  pinMode(A3, INPUT);  // Light sensor bottom - right
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  servohori.attach(10);
  servohori.write(90);
  servoverti.attach(9);
  servoverti.write(90);
  delay(500);
}

void loop() {
  servoh = servohori.read();
  servov = servoverti.read();

  //capturing analog values of each LDR
  int topl = analogRead(ldrtopl);
  int topr = analogRead(ldrtopr);
  int botl = analogRead(ldrbotl);
  int botr = analogRead(ldrbotr);

  // calculating average
  int avgtop = (topl + topr) / 2;    // average of top LDRs
  int avgbot = (botl + botr) / 2;    // average of bottom LDRs
  int avgleft = (topl + botl) / 2;   // average of left LDRs
  int avgright = (topr + botr) / 2;  // average of right LDRs

  if (avgtop < avgbot) {
    servoverti.write(servov + 1);
    if (avgtop == avgbot)
      servoverti.write(servov);
    if (servov > servovLimitHigh) {
      servov = servovLimitHigh;
    }
    delay(20);
  } else if (avgbot < avgtop) {
    servoverti.write(servov - 1);
    if (avgbot == avgtop)
      servoverti.write(servov);
    if (servov < servovLimitLow) {
      servov = servovLimitLow;
    }
    delay(20);
  }

  if (avgleft > avgright) {
    servohori.write(servoh + 1);
    if (avgleft == avgright)
      servohori.write(servoh);
    if (servoh > servohLimitHigh) {
      servoh = servohLimitHigh;
    }
    delay(20);
  } else if (avgright > avgleft) {
    servohori.write(servoh - 1);
    if (avgleft == avgright)
      servohori.write(servoh);
    if (servoh < servohLimitLow) {
      servoh = servohLimitLow;
    }
    delay(20);
  }

  digitalWrite(11, LOW);
  if (botr < 800) {
    if (botl < 800) {
      if (topr < 800) {
        if (topl < 800)
          digitalWrite(12, HIGH);
        else digitalWrite(12, LOW);
      } else digitalWrite(12, LOW);
    } else digitalWrite(12, LOW);
  } else digitalWrite(12, LOW);
}