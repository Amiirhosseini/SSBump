#include <AccelStepper.h>
#define dirPin 6
#define stepPin 7
#define motorInterfaceType 1

// Create a new instance of the AccelStepper class:
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);

void setup() {
stepper.setMaxSpeed(3000);
stepper.setAcceleration(2500);
stepper.moveTo(6000);
stepper.runToPosition();
delay(1000);

stepper.moveTo(3000);
stepper.runToPosition();
delay(1000);

// Move back to zero:
stepper.moveTo(0);
stepper.runToPosition();
stepper.moveTo(300);
stepper.runToPosition();
delay(1000);
}

void loop() {

}
