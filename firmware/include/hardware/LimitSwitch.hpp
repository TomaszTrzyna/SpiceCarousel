#pragma once
#include <Arduino.h>

class LimitSwitch {
    private:
    uint8_t pin;

public:
    LimitSwitch(uint8_t pinNumber);

    void begin();

    bool isPressed() const;

    bool isReleased() const;
};
