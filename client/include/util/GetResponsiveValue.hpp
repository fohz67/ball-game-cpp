#pragma once

class GetResponsiveValue {
  public:
    float getResponsivePosX(int baseWidth, int currentWidth, int originalPosX);
    float getResponsivePosY(int baseHeight, int currentHeight,
                            int originalPosY);
    float getResponsiveSizeX(int baseWidth, int currentWidth,
                             int originalWidth);
    float getResponsiveSizeY(int baseHeight, int currentHeight,
                             int originalHeight);
};
