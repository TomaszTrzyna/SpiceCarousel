#include "core/InventoryManager.hpp"

bool InventoryManager::addSpice(int slot, const String& name) {
    // Sprawdzenie poprawności danych
    if (slot < 1 || slot > MAX_SLOTS || name.length() == 0) {
        return false;
    }

    // Sprawdzenie zajętości miejsca
    if (isSlotOccupied(slot)) {
        return false;
    }

    // Sprawdzenie czy przyprawa już istnieje
    for (const Spice& spice : spices) {
        if (spice.getName().equalsIgnoreCase(name)) {
            return false;
        }
    }
    // Dodanie nowej przyprawy
    spices.emplace_back(slot, name);
    return true;
}

int InventoryManager::findSlotByName(const String& name) const {
    for (const Spice& spice : spices) {
        if (spice.getName().equalsIgnoreCase(name)) {
            return spice.getSlot();
        }
    }
    return -1;
}

int InventoryManager::getCount() const {
    return static_cast<int>(spices.size());
}

bool InventoryManager::isSlotOccupied(int slot) const {
    for (const Spice& spice : spices) {
        if (spice.getSlot == slot) {
            return true;
        }
    }
    return false;
}