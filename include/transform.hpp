/*
Contains various functions for transforming pieces of compressed image data between different forms,
and their helper functions
*/

#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <string>
#include <utility>

#include "types.hpp"

namespace jpeg_compression {


    const std::pair<const int, const int> zzOrderToMatIndices(const int zzindex);

    const int matIndicesToZZOrder(const int row, const int column);

    const int16 bitStringtoValue(const std::string& bitStr);

    const int16 getValueCategory(const int16 value);

}


#endif //TRANSFORM_HPP
