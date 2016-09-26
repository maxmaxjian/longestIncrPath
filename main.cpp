#include <iostream>
#include <unordered_map>
#include <vector>
#include "get_next_decor.h"
#include "flyweight_factory.h"

using std::vector;

class solution {	
    public:
        /*vector<vector<position>>*/ vector<position> longestIncreasingPath(const vector<vector<int>> & matrix) {
//        	vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), 0));
//            auto curr = flyweight_factory::get_instance()->get_pos(1,0);
//            get_next_decor next_decor(matrix.size(), matrix[0].size());
//            curr.accept(next_decor);
//            return next_decor.get_next(visited);
        	
        	vector<vector<position>> cands;
        	for (size_t i = 0; i < matrix.size(); i++) {
        		for (size_t j = 0; j < matrix[i].size(); j++) {
        			auto start = flyweight_factory::get_instance()->get_pos(i, j);
        			vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), 0));
        			auto temp = longestPathFrom(matrix, start, visited);
        			for (auto tmp : temp)
        				cands.push_back(tmp);
        		}
        	}
        	
        	size_t idx = 0;
        	for (size_t i = idx+1; i < cands.size(); i++) {
        		if (cands[i].size() > cands[idx].size())
        			idx = i;
        	}        	
        	return cands[idx];
        	
//        	return cands;
        }
        
        vector<vector<position>> longestPathFrom(const vector<vector<int>> & matrix, const position & start, vector<vector<int>> & visited) {
        	visited[start.x][start.y] = 1;
        	vector<vector<position>> paths;
        	get_next_decor next_decor(matrix.size(), matrix[0].size());
        	start.accept(next_decor);
        	auto next = next_decor.get_next(visited);
        	if (next.empty()) {
        		vector<position> path;
        		paths.push_back(path);
        	}
        	else {
        		vector<vector<position>> cands;
        		for (auto n : next) {
        			if (matrix[start.x][start.y] < matrix[n.x][n.y]) {
        				auto cpy = visited;
        				auto temp = longestPathFrom(matrix, n, cpy);
        				for (auto path : temp) {
        					path.insert(path.begin(), start);
        					cands.push_back(path);
        				}
        			}
        		}
        		
//        		if (!cands.empty()) {
//        			size_t idx = 0;
//        			for (size_t i = idx+1; i < cands.size(); i++)
//        				if (cands[i].size() > cands[idx].size())
//        					idx = i;
//        			
//        			for (size_t i = 0; i < cands.size(); i++) {
//        				if (cands[i].size() == cands[idx].size())
//        					paths.push_back(cands[i]);
//        			}
//        		}
        		
        		paths = cands;
        		if (paths.empty()) {
        			vector<position> path{start};
        			paths.push_back(path);
        		}
        	}
        	return paths;
        }
};

int main() {
    vector<vector<int>> matrix {
        {9,9,4},
        {6,6,8},
        {2,1,1} 
    };
    
//	vector<vector<int>> matrix{
//		{3,4,5},
//		{3,2,6},
//		{2,2,1}
//	};

    solution soln;
    vector<position> next = soln.longestIncreasingPath(matrix);
    for (auto p : next) {
        p.print();
    }
    std::cout << std::endl;//    
    for (auto p : next) {
    	std::cout << matrix[p.x][p.y] << " ";
    }
    std::cout << std::endl;
    
//    auto paths = soln.longestIncreasingPath(matrix);
//    for (auto path : paths) {
//    	for (auto p : path)
//    		p.print();
//    	std::cout << std::endl;
//    }

    return 0;
}
