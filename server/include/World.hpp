#pragma once

class World {
  public:
    World(int width, int height);
    int get_width() const;
    int get_height() const;

  private:
    int width;
    int height;
};
