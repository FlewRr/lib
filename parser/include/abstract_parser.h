#ifndef PARSER_INCLUDE_PARSER_H_20240907
#define PARSER_INCLUDE_PARSER_H_20240907

#include "pugixml.hpp"
#include "json.hpp"
#include <string>
#include <fstream>

class AbstractParser {
public:
    AbstractParser() = default;
    virtual ~AbstractParser() = default;

    virtual std::string load(const char* filename){
        return "";
    }
};

#endif