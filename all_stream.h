#ifndef LABA2_ALL_STREAM_H
#define LABA2_ALL_STREAM_H

#include <ostream>
#include "sequence.h"
//FIXED: вынес в отдельный файл
template<class T>
std::ostream& operator<<(std::ostream &os, const Sequence<T> &seq) {
    auto it = seq.get_enumerator();

    os << "[";

    while (it->has_more_elements()) {
        os << it->next();

        if (it->has_more_elements())
            os << ", ";
    }

    os << "]";

    delete it;
    return os;
}

#endif //LABA2_ALL_STREAM_H

