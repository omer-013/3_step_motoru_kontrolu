#ifndef Step_Motor_h
#define Step_Motor_h

#include "Arduino.h"

class Step_Motor {
private:
    int pin1;
    int pin2;
    int pin3;
    int pin4;
    int hiz = 500;
    int yon = 1;
    int step;
public:
    Step_Motor(int pin_1, int pin_2, int pin_3, int pin_4) {
        pin1 = pin_1;
        pin2 = pin_2;
        pin3 = pin_3;
        pin4 = pin_4;
        
        pinMode(pin1, OUTPUT);
        pinMode(pin2, OUTPUT);
        pinMode(pin3, OUTPUT);
        pinMode(pin4, OUTPUT);
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, LOW);
        
    }

    void step_yon(int yon_1) {
        yon = yon_1;
    }

    void step_hiz(int hiz_1) {
        hiz = hiz_1;
    }

    void calistir(int step)
    {
      if(yon == 1)
        hareket(step);
        else if(yon == -1)
          ters_hareket(step);
    }
//pin1 = -1, pin2 = 1, pin3 = 0, pin4 = 2
    void hareket(int step)
    {
        switch(step){
          case 0: //45
            digitalWrite(pin2, HIGH);
            digitalWrite(pin1, LOW);
            digitalWrite(pin3, HIGH);
            digitalWrite(pin4, LOW);
            delay(hiz);
            break;
          case 1: //90
            digitalWrite(pin2, HIGH);
            digitalWrite(pin3, LOW);
            delay(hiz);
            break;
           case 2: //135
            digitalWrite(pin2, HIGH);
            digitalWrite(pin3, LOW);
            digitalWrite(pin4, HIGH);
            digitalWrite(pin1, LOW);
            delay(hiz);
            break; 
           case 3: //180
            digitalWrite(pin2, LOW);
            digitalWrite(pin4, HIGH);
            delay(hiz);
            break;
           case 4: //225
            digitalWrite(pin1, HIGH);
            digitalWrite(pin2, LOW);
            digitalWrite(pin4, HIGH);
            digitalWrite(pin3, LOW);
            delay(hiz);
            break;
          case 5: //270
            digitalWrite(pin1, HIGH);
            digitalWrite(pin4, LOW);
            delay(hiz);
            break;
           case 6: //315
            digitalWrite(pin1, HIGH);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, HIGH);
            digitalWrite(pin2, LOW);
            delay(hiz);
            break;
          case 7: //360
            digitalWrite(pin1, LOW);
            digitalWrite(pin3, HIGH);
            delay(hiz);
            break; 
            

      }
    }
    //pin1 = -1, pin2 = 1, pin3 = 0, pin4 = 2
    void ters_hareket(int step)
    {
      switch(step){
          case 0: //-45
            digitalWrite(pin1, HIGH);
            digitalWrite(pin2, LOW);
            digitalWrite(pin3, HIGH);
            digitalWrite(pin4, LOW);
            delay(hiz);
            break;
          case 1: //-90
            digitalWrite(pin1, HIGH);
            digitalWrite(pin3, LOW);
            delay(hiz);
            break;
          case 2: //-135
            digitalWrite(pin1, HIGH);
            digitalWrite(pin3, LOW);
            digitalWrite(pin4, HIGH);
            digitalWrite(pin2, LOW);
            delay(hiz);
            break;
          case 3: //-180
            digitalWrite(pin1, LOW);
            digitalWrite(pin4, HIGH);
            
            delay(hiz);
            break;
           case 4: //-225
            digitalWrite(pin4, HIGH);
            digitalWrite(pin1, LOW);
            digitalWrite(pin2, HIGH);
            digitalWrite(pin3, LOW);
            delay(hiz);
            break; 
          case 5: //-270
            digitalWrite(pin4, LOW);
            digitalWrite(pin2, HIGH);
            delay(hiz);
            break;
          case 6: //-315
            digitalWrite(pin2, HIGH);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, HIGH);
            digitalWrite(pin1, LOW);
            delay(hiz);
            break;  
          case 7: //-360
            digitalWrite(pin2, LOW);
            digitalWrite(pin3, HIGH);
            delay(hiz);
            break; 
          
           }
    }
};

#endif