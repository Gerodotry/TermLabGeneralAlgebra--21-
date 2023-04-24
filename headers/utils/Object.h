//
// Created by Dklishch on 3/26/2023.
//

#ifndef MAIN_CPP_OBJECT_H
#define MAIN_CPP_OBJECT_H

#include <string>

class Object {
public:
    virtual std::string toString() const {
        return "Object";
    }
};

#endif //MAIN_CPP_OBJECT_H
