#ifndef LABA2_ENUMERATOR_WRAPPER_H
#define LABA2_ENUMERATOR_WRAPPER_H

#include "i_enumerator.h"
/* FIXED: Вместо ручного delete для IEnumerator используется обёртка EnumeratorWrapper.
 * FIXED: Она хранит внутри указатель на энумератор и удаляет его в своём деструкторе.*/


template<class T>
class EnumeratorWrapper {
private:
    IEnumerator<T>* enumerator;

public:
    EnumeratorWrapper(IEnumerator<T>* enumerator) {
        this->enumerator = enumerator;
    }

    ~EnumeratorWrapper() {
        delete enumerator;
    }

    EnumeratorWrapper(const EnumeratorWrapper<T>& other) = delete; //запрещает копирующий конструктор иначе двойное удаление
    EnumeratorWrapper<T>& operator=(const EnumeratorWrapper<T>& other) = delete;

    bool has_more_elements() {
        return enumerator->has_more_elements();
    }

    const T& next() {
        return enumerator->next();
    }
};

#endif //LABA2_ENUMERATOR_WRAPPER_H