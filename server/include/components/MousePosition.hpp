struct MousePosition {
    double x{0};
    double y{0};

    MousePosition() = default;
    MousePosition(double x, double y) : x(x), y(y) {}

    void updatePosition(double x, double y) {
        this->x = x;
        this->y = y;
    }
};
