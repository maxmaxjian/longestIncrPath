#ifndef GET_NEXT_DECOR_H
#define GET_NEXT_DECOR_H

#include <cstddef>
#include <vector>

class position;

class get_next_decor {
    private:
        size_t xmax, ymax;
        std::vector<position> next;

    public:
        get_next_decor(size_t mx, size_t my) ;

        void visit(const position & pos);

        std::vector<position> get_next(const std::vector<std::vector<int>> & visited);
};

#endif
