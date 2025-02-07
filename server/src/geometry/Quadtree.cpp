#include "geometry/Quadtree.hpp"

#include "config/Config.hpp"

Quadtree::Quadtree(int level, const FloatRect2& bounds) : level(level), bounds(bounds)
{
}

void Quadtree::clear()
{
    cells.clear();
    for (auto& node : nodes)
    {
        node.clear();
    }
    nodes.clear();
}

void Quadtree::split()
{
    float subWidth = bounds.width / 2.0f;
    float subHeight = bounds.height / 2.0f;

    float x = bounds.left;
    float y = bounds.top;

    nodes.emplace_back(level + 1, FloatRect2(x + subWidth, y, subWidth, subHeight));
    nodes.emplace_back(level + 1, FloatRect2(x, y, subWidth, subHeight));
    nodes.emplace_back(level + 1, FloatRect2(x, y + subHeight, subWidth, subHeight));
    nodes.emplace_back(level + 1, FloatRect2(x + subWidth, y + subHeight, subWidth, subHeight));
}

int Quadtree::getIndex(const FloatRect2& area)
{
    int index = -1;

    float verticalMidpoint = bounds.left + (bounds.width / 2);
    float horizontalMidpoint = bounds.top + (bounds.height / 2);

    bool topQuadrant =
        (area.top < horizontalMidpoint && area.top + area.height < horizontalMidpoint);
    bool bottomQuadrant = (area.top > horizontalMidpoint);

    if (area.left < verticalMidpoint && area.left + area.width < verticalMidpoint)
    {
        if (topQuadrant)
        {
            index = 1;
        }
        else if (bottomQuadrant)
        {
            index = 2;
        }
    }
    else if (area.left > verticalMidpoint)
    {
        if (topQuadrant)
        {
            index = 0;
        }
        else if (bottomQuadrant)
        {
            index = 3;
        }
    }

    return index;
}

void Quadtree::insert(Cell* cell)
{
    if (!nodes.empty())
    {
        int index = getIndex(cell->getBounds());

        if (index != -1)
        {
            nodes[index].insert(cell);
            return;
        }
    }

    cells.push_back(cell);

    if (cells.size() > Config::Quadtree::MAX_OBJECTS && level < Config::Quadtree::MAX_LEVELS)
    {
        if (nodes.empty())
        {
            split();
        }

        auto it = cells.begin();
        while (it != cells.end())
        {
            int index = getIndex((*it)->getBounds());
            if (index != -1)
            {
                nodes[index].insert(*it);
                it = cells.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }
}

std::vector<Cell*> Quadtree::retrieve(const FloatRect2& area)
{
    std::vector<Cell*> result;
    int index = getIndex(area);

    if (index != -1 && !nodes.empty())
    {
        result = nodes[index].retrieve(area);
    }

    result.insert(result.end(), cells.begin(), cells.end());

    return result;
}
