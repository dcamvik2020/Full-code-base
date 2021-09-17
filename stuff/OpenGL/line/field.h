
/// Size of the field:
/// weidth = height = 50 pixels (without borders)

/// Width of border = 5 pixels

class Field {
private:
    bool sides[4]; /// 0 - left, 1 - up, ...
public:
    Field();
    void left();
    void up();
    void right();
    void down();
};
