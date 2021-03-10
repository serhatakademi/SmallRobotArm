int motorPin1 = 8, motorPin2 = 11, motorPin3 = 12, motorPin4 = 13;
int potx1=A0;
int poty1=A1;
int potx2=A2;
int poty2=A3;
#include <Stepper.h>
#define STEPS 200
Stepper stepper1(STEPS, 2, 5);
Stepper stepper2(STEPS, 3, 6);
Stepper stepper3(STEPS, 4, 7);
#define motorInterfaceType 1
void setup() {
  pinMode(motorPin1, OUTPUT);                                  
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT); 
  pinMode(potx1,INPUT);
  pinMode(poty1,INPUT);
  pinMode(potx2,INPUT);
  pinMode(poty2,INPUT);
}

void loop() {

  if (analogRead(potx1) >= 700) {
      stepper1.setSpeed(500);
      stepper1.step(200);
    }
    else if (analogRead(potx1) <= 400) {
      stepper1.setSpeed(500);
      stepper1.step(-200);
    }

    else if (analogRead(poty1) <= 400) {
      stepper2.setSpeed(500);
      stepper2.step(200);
    }
    else if (analogRead(poty1) >= 700) {
      stepper2.setSpeed(500);
      stepper2.step(-200);
    }

    else if (analogRead(potx2) <= 400) {
      stepper3.setSpeed(500);
      stepper3.step(200);
    }
    else if (analogRead(potx2) >= 700) {
      stepper3.setSpeed(500);
      stepper3.step(-200);
    }
    else if(analogRead(poty2)>=700){
      for(int adim = 0; adim < 5; adim++){                    
          stepIleri(10); 
      }
  }
   
    else if(analogRead(poty2)<=400){
      for(int adim = 0; adim < 5; adim++){                    
          stepGeri(10); 
        }
    }

}

void stepIleri(int beklemeSuresi){                               //5v Step motora ileri hareketi yaptırır.
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(beklemeSuresi);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(beklemeSuresi);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(beklemeSuresi);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(beklemeSuresi);
}

void stepGeri(int beklemeSuresi){                                //5v Step motora geri hareketi yaptırır.
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(beklemeSuresi);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(beklemeSuresi);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(beklemeSuresi);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(beklemeSuresi);
}
