#ifndef SRC_INCLUDE_XMLPARSER_H_20241007
#define SRC_INCLUDE_XMLPARSER_H_20241007

#include "abstract_parser.h"

class XMLParser : AbstractParser{  
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


#endif