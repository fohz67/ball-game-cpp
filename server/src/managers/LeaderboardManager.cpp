#include "managers/LeaderboardManager.hpp"

#include <algorithm>

#include "config/Config.hpp"
#include "managers/CellManager.hpp"
#include "managers/PlayerManager.hpp"
#include "protocol/Send.hpp"

LeaderboardManager& LeaderboardManager::get()
{
    static LeaderboardManager instance;
    return instance;
}

const void LeaderboardManager::updateLeaderboard()
{
    std::vector<Player*> players = PlayerManager::get().getPlayers();
    std::vector<LeaderboardEntry> leaderboard;

    leaderboard.reserve(players.size());

    for (Player* player : players)
    {
        uint32_t id = player->getId();
        double score = player->getScore();
        double totalMass = 0.0;

        std::vector<Cell*> cells = CellManager::get().getCellsByPlayerId(id);
        size_t cellCount = cells.size();

        for (Cell* cell : cells)
        {
            totalMass += cell->getMass();
        }

        if (totalMass > score)
        {
            score = totalMass;
            player->setScore(score);
        }

        player->setTotalMass(totalMass);
        player->setCellCount(cellCount);

        LeaderboardEntry entry{id, player->getNickname(), totalMass, cellCount, score};
        leaderboard.push_back(entry);
    }

    std::sort(leaderboard.begin(),
              leaderboard.end(),
              [](const LeaderboardEntry& a, const LeaderboardEntry& b)
              { return a.totalMass > b.totalMass; });

    this->leaderboard = leaderboard;
}

std::vector<LeaderboardEntry> LeaderboardManager::getLeaderboard() const
{
    return leaderboard;
}

std::vector<LeaderboardEntry> LeaderboardManager::getClientLeaderboard() const
{
    return leaderboard.size() > Config::Gameplay::Leaderboard::MAX_ENTRIES
               ? std::vector<LeaderboardEntry>(
                     leaderboard.begin(),
                     leaderboard.begin() + Config::Gameplay::Leaderboard::MAX_ENTRIES)
               : leaderboard;
}
