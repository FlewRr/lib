#include "parser.h"
#include "pugixml.hpp"

const char* AbstractParser::load(const char* filename){
    return "";
}


const char* XMLParser::load(const char* filename){
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(filename);

    if (result){
        pugi::xml_node root = doc.child("root");
        if (root) {
            return root.name();
        }
    }

    return "";
}
