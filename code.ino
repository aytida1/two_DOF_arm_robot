#include<Servo.h>
Servo servo1, servo2;    //servo1 is attached to base frame which give angel theta1

int x, y;
float k1, k2;
float theta1, theta2; 

void setup() {
  
  servo1.attach(3);
  servo1.attach(4);

  while(!digitalRead(2)){
    delay(10);
  }

  servo1.write(90);
  servo2.write(90);

  
}

void loop() {
  
  x = analogRead(A2);
  y = analogRead(A3);

  k1 = (map(x, 0, 1023, 1, 24))/12.5;
  k2 = (map(y, 0, 1023, 1, 24))/12.5;

  //calculation from inverse kinematics
  theta2 = acos((pow(k1, 2) + pow(k1, 2) -2)/2);
  theta2 = theta2*180/PI;
  theta1 = acos(k2/(2*cos(theta2/2))) - theta2/2;
  theta1 = theta1*180/PI;

  servo1.write(theta1);
  servo2.write(theta2);
}
