#include "parser.h"
#include "pugixml.hpp"
#include <iostream>

const char* AbstractParser::load(const char* filename){
    return "";
}


std::string XMLParser::load(const char* filename){
    std::string str = filename;

    if (str.substr(str.find_last_of(".") + 1) != "xml")
        throw std::invalid_argument("Invalid file extension. Expected .xml");

    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(filename);
    xml_string_writer writer;

    doc.first_child().print(writer, "");

    return writer.result;
}


std::string JSONParser::load(const char* filename){
    std::string str = filename;

    if (str.substr(str.find_last_of(".") + 1) != "json")
        throw std::invalid_argument("Invalid file extension. Expected .json");

    std::ifstream f(filename);
    nlohmann::json data = nlohmann::json::parse(f);

    std::string result = data.dump(2);

    return result;
}