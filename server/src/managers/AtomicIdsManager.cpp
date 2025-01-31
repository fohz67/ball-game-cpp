#include "managers/AtomicIdsManager.hpp"

AtomicIdsManager& AtomicIdsManager::get() {
    static AtomicIdsManager instance;
    return instance;
}

uint32_t AtomicIdsManager::getNextId() {
    if (!recycledIds.empty()) {
        uint32_t id = recycledIds.top();

        recycledIds.pop();
        usedIds.insert(id);

        return id;
    }

    usedIds.insert(nextId);

    return nextId++;
}

void AtomicIdsManager::removeId(uint32_t id) {
    if (usedIds.erase(id)) {
        recycledIds.push(id);
    }
}
