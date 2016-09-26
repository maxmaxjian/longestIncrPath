#include "get_next_decor.h"
#include "position.h"
#include "flyweight_factory.h"

get_next_decor::get_next_decor(size_t mx, size_t my) : xmax(mx), ymax(my) {}

void get_next_decor::visit(const position &pos)
{
    if (!next.empty())
        next.clear();
    if (pos.x > 0)
        next.push_back(flyweight_factory::get_instance()->get_pos(pos.x - 1, pos.y));
    if (pos.x < xmax - 1)
        next.push_back(flyweight_factory::get_instance()->get_pos(pos.x + 1, pos.y));
    if (pos.y > 0)
        next.push_back(flyweight_factory::get_instance()->get_pos(pos.x, pos.y - 1));
    if (pos.y < ymax - 1)
        next.push_back(flyweight_factory::get_instance()->get_pos(pos.x, pos.y + 1));
}

std::vector<position> get_next_decor::get_next(const std::vector<std::vector<int>> & visited)
{
	std::vector<size_t> idx;
	for (size_t i = 0; i < next.size(); i++) {
		if (visited[next[i].x][next[i].y])
			idx.push_back(i);
	}
	
	if (!idx.empty()) {
		for (size_t i = idx.size()-1; i < idx.size(); i--)
			next.erase(next.begin()+idx[i]);
	}
	
    return next;
}
