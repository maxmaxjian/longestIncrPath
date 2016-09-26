#ifndef FLYWEIGHT_FACTORY_H
#define FLYWEIGHT_FACOTYR_H

#include <unordered_map>
#include "position.h"
#include <functional>


class PairHasher {
    public:
        size_t operator()(const std::pair<size_t,size_t> & pr) const {
            return std::hash<size_t>()(pr.first) & std::hash<size_t>()(pr.second);
        }
};

bool operator==(const std::pair<size_t,size_t> & p1, const std::pair<size_t,size_t> & p2);

class flyweight_factory {
    private:
        static flyweight_factory * instance;
        std::unordered_map<std::pair<size_t,size_t>, position, PairHasher> map;

    private:
        flyweight_factory() {}
        flyweight_factory(const flyweight_factory & other) = delete;
        flyweight_factory & operator=(const flyweight_factory & other)  = delete;

    public:
        static flyweight_factory * get_instance() {
            if (instance == nullptr) {
                instance = new flyweight_factory();
            }
            return instance;
        }

        const position & get_pos(size_t nrow, size_t ncol) {
            if (map.find(std::make_pair(nrow, ncol)) == map.end()) {
                map[std::make_pair(nrow, ncol)] = position(nrow, ncol);
            }
            return map[std::make_pair(nrow, ncol)];
        }
};

#endif
