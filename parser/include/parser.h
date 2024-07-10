#ifndef PARSER_INCLUDE_PARSER_H_20240907
#define PARSER_INCLUDE_PARSER_H_20240907

#include "pugixml.hpp"
#include "json.hpp"
#include <fstream>

class AbstractParser {
public:
    AbstractParser() = default;
    virtual ~AbstractParser() = default;

    virtual const char* load(const char* filename);
};


class XMLParser {  
    struct xml_string_writer: pugi::xml_writer
    {
        std::string result;

        virtual void write(const void* data, size_t size)
        {
            result.append(static_cast<const char*>(data), size);
        }
    };
public:
    XMLParser() = default;
    ~XMLParser() = default;

    std::string load(const char* filename);
};


class JSONParser {
public:
    JSONParser() = default;
    ~JSONParser() = default;

    std::string load(const char* filename);
};
#endif