//
// Created by Dklishch on 6/1/2023.
//

#ifndef LAB_LONG_H
#define LAB_LONG_H


#include "Object.h"

class Long : public Object {
public:
    Long(long long value = 0);

    std::string toString() override;

    long long get() const;

    long long* getPointer();
private:
    long long value;
};

#endif //LAB_LONG_H
