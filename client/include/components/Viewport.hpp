struct Viewport {
    double width{0};
    double height{0};
    double x{0};
    double y{0};

    Viewport() = default;
    Viewport(double w, double h, double x, double y)
        : width(w), height(h), x(x), y(y) {}

    void updatePosition(double x, double y) {
        this->x = x;
        this->y = y;
    }

    void updateSize(double w, double h) {
        this->width = w;
        this->height = h;
    }
};
