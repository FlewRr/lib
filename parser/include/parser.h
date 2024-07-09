#ifndef PARSER_INCLUDE_PARSER_H_20240907
#define PARSER_INCLUDE_PARSER_H_20240907

#include "pugixml.hpp"
#include <fstream>

class AbstractParser {
public:
    AbstractParser() = default;
    virtual ~AbstractParser() = default;

    virtual const char* load(const char* filename);
};


class XMLParser {
public:
    XMLParser() = default;
    ~XMLParser() = default;

    const char* load(const char* filename);
};


class JSONParser {
public:
    JSONParser() = default;
    ~JSONParser() = default;

    // const char* load(const char* filename){
    //     std::ifstream f(filename);

    //     json data = json::parse(f);
        
    //     return data[0];
    // }
};
#endif