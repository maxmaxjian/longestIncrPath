/*
 * flyweight_factory.cpp
 *
 *  Created on: Sep 26, 2016
 *      Author: jianwei
 */

#include "flyweight_factory.h"

flyweight_factory * flyweight_factory::instance = nullptr;


bool operator==(const std::pair<size_t,size_t> & p1, const std::pair<size_t,size_t> & p2) {
    return p1.first == p2.first && p1.second == p2.second;
}
