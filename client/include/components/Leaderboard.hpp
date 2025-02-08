#pragma once

#include <string>
#include <vector>

class Leaderboard
{
   public:
    Leaderboard(const Leaderboard&) = delete;
    Leaderboard& operator=(const Leaderboard&) = delete;

    static Leaderboard& get();

    const void setLeaderboard(const std::vector<std::string>& leaderboard);
    std::vector<std::string> getLeaderboard();

   private:
    Leaderboard() = default;
    ~Leaderboard() = default;

    std::vector<std::string> leaderboard;
};
