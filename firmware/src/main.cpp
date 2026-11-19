#include <Arduino.h>
#include "hardware/LimitSwitch.hpp"

LimitSwitch switchA(4);
LimitSwitch switchB(5);

void setup() {
    Serial.begin(115200);
    delay(1500);

    switchA.begin();
    switchB.begin();

    Serial.println("==Test krancowek==");

}

void loop() {
    bool stateA = switchA.isPressed();
    bool stateB = switchB.isPressed();

    Serial.print("Krancowka A: ");
    Serial.println(stateA ? "WCISNIETA" : "ZWOLNIONA");

    Serial.print("Krancowa B: ");
    Serial.println(stateB ? "WCISNIETA" : "ZWOLNIONA");

    Serial.println("-----------");

    delay(500);
}