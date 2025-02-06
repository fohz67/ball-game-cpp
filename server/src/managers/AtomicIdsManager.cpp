#include "util/AtomicID.hpp"

AtomicID& AtomicID::get() {
    static AtomicID instance;
    return instance;
}

uint32_t AtomicID::getNextId() {
    if (!recycledIds.empty()) {
        uint32_t id = recycledIds.top();

        recycledIds.pop();
        usedIds.insert(id);

        return id;
    }

    usedIds.insert(nextId);

    return nextId++;
}

void AtomicID::removeId(uint32_t id) {
    if (usedIds.erase(id)) {
        recycledIds.push(id);
    }
}
