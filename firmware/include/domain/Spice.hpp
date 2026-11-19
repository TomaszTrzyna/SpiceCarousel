#pragma once
#include <Arduino.h>

class Spice
{
private:
    int slot;
    String name;
public:
    Spice(int slotNumber, const String& spiceName);

    int getSlot() const;
    const String& getName() const;
};