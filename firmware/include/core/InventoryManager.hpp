#pragma once
#include <Arduino.h>
#include <vector>
#include "domain/Spice.hpp"

class InventoryManager {
private:
    static constexpr int MAX_SLOTS = 16;

    std::vector<Spice> spices;

public:
    bool addSpice(int slot, const String& name);
    int findSlotByName(const String& name) const;
    int getCount() const;
    bool isSlotOccupied(int slot) const;
};