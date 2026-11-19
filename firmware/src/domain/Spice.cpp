#include "domain/Spice.hpp"

Spice::Spice(int slotNumber, const String& spiceName)
    : slot(slotNumber), name(spiceName) {
}

int Spice::getSlot() const {
    return slot;
}

const String& Spice::getName() const {
    return name;
}