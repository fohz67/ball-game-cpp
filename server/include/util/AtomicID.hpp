#pragma once

#include <cstdint>
#include <queue>
#include <set>

class AtomicID {
  public:
    AtomicID(const AtomicID&)            = delete;
    AtomicID& operator=(const AtomicID&) = delete;

    static AtomicID& get();

    uint32_t getNextId();
    void     removeId(uint32_t id);

  private:
    AtomicID()  = default;
    ~AtomicID() = default;

    uint32_t                                                                     nextId = 2;
    std::set<uint32_t>                                                           usedIds;
    std::priority_queue<uint32_t, std::vector<uint32_t>, std::greater<uint32_t>> recycledIds;
};
