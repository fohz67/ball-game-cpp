#pragma once

class World {
  public:
    World(const World&) = delete;
    World& operator=(const World&) = delete;
    static World& get();
    int get_width() const;
    int get_height() const;

  private:
    World();
    ~World() = default;
    int width;
    int height;
};
