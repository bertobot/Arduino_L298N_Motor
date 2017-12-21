#ifndef __L298N_Motor_h_
#define __L298N_Motor_h_

#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

class L298N_Motor {
public:
    L298N_Motor(uint8_t in1, uint8_t in2, uint8_t en1);
    L298N_Motor(uint8_t in1, uint8_t in2, uint8_t en1, uint8_t in3, uint8_t in4, uint8_t en2);
    virtual ~L298N_Motor(){}

    void move(int power1=0, int power2=0);

    void flipA();
    void flipB();

private:
    uint8_t mPins[4], mEnable[2], mStates[4];
    bool mSingle, mReverse[2];
};

#endif
