#include "hardware/LimitSwitch.hpp"

LimitSwitch::LimitSwitch(uint8_t pinNumber)
    : pin(pinNumber) {
}

void LimitSwitch::begin() {
    pinMode(pin, INPUT_PULLUP);
}

bool LimitSwitch::isPressed() const {
    return digitalRead(pin) == LOW;
}

bool LimitSwitch::isReleased() const {
    return !isPressed();
}