#ifndef POSITION_H
#define POSITION_H

#include <cstddef>
class get_next_decor;

class position {
    public:
        size_t x, y;
        
        position();

        position(size_t x1, size_t x2);

        bool equals(const position & other) const;

        void accept(get_next_decor & next_decor) const;

        void print() const;
};

#endif
