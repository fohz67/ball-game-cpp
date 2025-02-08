#include "components/Leaderboard.hpp"

Leaderboard& Leaderboard::get()
{
    static Leaderboard instance;
    return instance;
}

const void Leaderboard::setLeaderboard(const std::vector<std::string>& leaderboard)
{
    this->leaderboard = leaderboard;
}

std::vector<std::string> Leaderboard::getLeaderboard()
{
    return leaderboard;
}
