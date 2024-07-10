#include "include/jsonparser.h"
#include "include/xmlparser.h"
#include "pugixml.hpp"
#include <iostream>

std::string XMLParser::load(const char* filename){
    std::string str = filename;

    if (str.substr(str.find_last_of(".") + 1) != "xml")
        throw std::invalid_argument("Invalid file extension. Expected .xml");

    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(filename);
    xml_string_writer writer;

    doc.first_child().print(writer, "");

    if (writer.result == "")
        throw std::invalid_argument("Internal error has occured");
    
    return writer.result;
}


std::string JSONParser::load(const char* filename){
    std::string str = filename;

    if (str.substr(str.find_last_of(".") + 1) != "json")
        throw std::invalid_argument("Invalid file extension. Expected .json");

    std::ifstream f(filename);
    try{
    nlohmann::json data = nlohmann::json::parse(f);
    std::string result = data.dump(2);
    return result;
    }
    catch(const nlohmann::json_abi_v3_11_3::detail::parse_error& e){
        throw std::invalid_argument("Corrupted data");
    }

    throw std::invalid_argument("Internal error has occured");
}