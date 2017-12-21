# Arduino L298N Motor Interface

Controls 1 or 2 motors:

## Single motor control:
```c++

#include <L298N_Motor.h>

// (D7, D8) for (IN1, IN2); D9 (pwm) for EN1
L298N_Motor motor(7, 8, 9);

int value;
int direction;

void setup() {
    value = 0;
    direction = 1;
}

void loop() {
    value += direction;
    if (value > 254) direction = -1;
    if (value < -254) direction = 1;

    motor.move(value);

    delay(100);
}
```

## Double motor control:
```c++

#include <L298N_Motor.h>

// (D7, D8) for (IN1, IN2); D9 (pwm) for EN1
// (D12, D11) for (IN3, IN4); D10 (pwm) for EN2
L298N_Motor motor(7, 8, 9, 12, 11, 10);

int value;
int direction;

void setup() {
    value = 0;
    direction = 1;
}

void loop() {
    value += direction;
    if (value > 254) direction = -1;
    if (value < -254) direction = 1;

    motor.move(value, value);
    delay(100);
}
```
