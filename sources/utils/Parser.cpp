//
// Created by Dklishch on 5/8/2023.
//

#include "utils/Parser.h"

std::vector<std::string> Parser::parseNumbers(const std::string &string) {
    std::vector<std::string> results;
    std::string tmp;
    for (const char& c: string) {
        if (c == ' ') continue;
        if (c >= '0' && c <= '9' || c == '-') {
            tmp += c;
        } else {
            results.push_back(tmp);
            tmp.clear();
        }
        if (c == '\00') break;
    }
    return results;
}
