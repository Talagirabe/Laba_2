#ifndef LABA2_IENUMERATE_H
#define LABA2_IENUMERATE_H

//шбак обходить элементы последовательности
template<class T>
class IEnumerator {

public:
    virtual ~IEnumerator() = default;

    // проверяет
    virtual bool has_more_elements() = 0;

    // возращает текущий элемент иделает шаг
    virtual const T& next() = 0;

};

#endif //LABA2_IENUMERATE_H