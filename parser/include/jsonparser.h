#ifndef SRC__INCLUDE_JSONPARSER_H_20241007
#define SRC_INCLUDE_JSONPARSER_H_20241007

#include "abstract_parser.h"

class JSONParser : AbstractParser{
public:
    JSONParser() = default;
    ~JSONParser() = default;

    std::string load(const char* filename);
};

#endif