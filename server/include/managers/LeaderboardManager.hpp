#pragma once
#include <cstdint>
#include <string>
#include <vector>

struct LeaderboardEntry {
    uint32_t    playerId;
    std::string nickname;
    double      totalMass;
    size_t      cellCount;
    double      score;
};

class LeaderboardManager {
  public:
    LeaderboardManager(const LeaderboardManager&)            = delete;
    LeaderboardManager& operator=(const LeaderboardManager&) = delete;

    static LeaderboardManager& get();

    const void updateLeaderboard();

    std::vector<LeaderboardEntry> getLeaderboard();

  private:
    LeaderboardManager()  = default;
    ~LeaderboardManager() = default;

    std::vector<LeaderboardEntry> leaderboard;
};
