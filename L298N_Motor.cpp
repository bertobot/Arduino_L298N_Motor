#include "L298N_Motor.h"

L298N_Motor::L298N_Motor(uint8_t in1, uint8_t in2, uint8_t en1) {
    mSingle = true;

    mPins[0] = in1;
    mPins[1] = in2;
    mEnable[0] = en1;
    mReverse[0] = false;

    for (int i = 0; i < 2; i++) {
        pinMode(mPins[i], OUTPUT);
        mStates[i] = (i % 2 == 0) ? LOW : HIGH;
        digitalWrite(mPins[i], mStates[i]);
    }

    pinMode(mEnable[0], OUTPUT);
}

L298N_Motor::L298N_Motor(uint8_t in1, uint8_t in2, uint8_t en1, uint8_t in3, uint8_t in4, uint8_t en2) {
    mSingle = false;

    mPins[0] = in1;
    mPins[1] = in2;
    mPins[2] = in3;
    mPins[3] = in4;

    mEnable[0] = en1;
    mEnable[1] = en2;

    mReverse[0] = false;
    mReverse[1] = false;

    for (int i = 0; i < 4; i++) {
        pinMode(mPins[i], OUTPUT);
        mStates[i] = (i % 2 == 0) ? LOW : HIGH;
        digitalWrite(mPins[i], mStates[i]);
    }

    pinMode(mEnable[0], OUTPUT);
    pinMode(mEnable[1], OUTPUT);
}

void L298N_Motor::move(int power1, int power2) {
    if (mReverse[0] && power1 > 0) {
        flipA();
        mReverse[0] = false;
    }
        
    if (power1 < 0) {
        power1 *= -1;
        if (!mReverse[0]) {
            flipA();
            mReverse[0] = true;
        }
    }

    if (!mSingle) {
        if (mReverse[1] && power2 > 0) {
            flipB();
            mReverse[1] = false;
        }

        if (power2 < 0) {
            power2 *= -1;
            if (!mReverse[1]) {
                flipB();
                mReverse[1] = true;
            }
        }

        analogWrite(mEnable[1], power2);
    }

    analogWrite(mEnable[0], power1);
}

void L298N_Motor::flipA() {
    for (int i = 0; i < 2; i++) {
        mStates[i] = (mStates[i] == LOW) ? HIGH : LOW;
        digitalWrite(mPins[i], mStates[i]);
    }
}

void L298N_Motor::flipB() {
    for (int i = 2; i < 4; i++) {
        mStates[i] = (mStates[i] == LOW) ? HIGH : LOW;
        digitalWrite(mPins[i], mStates[i]);
    }
}

