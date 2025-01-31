#pragma once

#include <cstdint>
#include <queue>
#include <set>

class AtomicIdsManager {
  public:
    AtomicIdsManager(const AtomicIdsManager&) = delete;
    AtomicIdsManager& operator=(const AtomicIdsManager&) = delete;

    static AtomicIdsManager& get();

    uint32_t getNextId();
    void removeId(uint32_t id);

  private:
    AtomicIdsManager() = default;
    ~AtomicIdsManager() = default;

    uint32_t nextId = 0;
    std::set<uint32_t> usedIds;
    std::priority_queue<uint32_t, std::vector<uint32_t>, std::greater<uint32_t>>
        recycledIds;
};
