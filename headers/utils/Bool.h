//
// Created by Dklishch on 5/8/2023.
//

#ifndef LAB_BOOL_H
#define LAB_BOOL_H

#include "Object.h"

class Bool: public Object {
public:
    Bool(bool value = false);

    std::string toString() override;

    bool get() const;

    bool* getPointer();
private:
    bool value;
};

#endif //LAB_BOOL_H
