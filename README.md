# Arduino L298N Servo Interface

```c++

#include <L298N_Servo.h>

L298N_Servo servo;

int pos;
int steps;

void setup() {
  servo.attach(3, 4, 1);
  pos = 0;
  steps = 5;
}

void loop() {
  if (pos > 255)
    steps = -5;
  if (pos < 0)
    steps = 5;
    
  pos += steps;
  
  servo.write(pos);
  servo.refresh();
  delay(100);
}
```
