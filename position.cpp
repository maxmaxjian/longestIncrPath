#include "position.h"
#include "get_next_decor.h"
#include <iostream>

position::position() {}

position::position(size_t x1, size_t x2) : x(x1), y(x2) {}

bool position::equals(const position &other) const
{
    return x == other.x && y == other.y;
}

void position::accept(get_next_decor &next_decor) const
{
    next_decor.visit(*this);
}

void position::print() const
{
    std::cout << "(" << x << ", " << y << ") ";
}
