#include <iostream>
#include <jsoncpp/json/json.h>
#include <fstream>
#include <string>
#include "json_handle.h"

/// @brief Generate an object from the JSON file to use 
/// @param file absolute file path to the JSON file
/// @details Based off of the provide [read from stream example](https://github.com/open-source-parsers/jsoncpp/blob/master/example/readFromStream/readFromStream.cpp)
/// @return The JSON object reference
Json::Value* libpdftowebp::GetJsonHandle(const char* file)
{
    Json::Value* root = new Json::Value();
    Json::Reader reader;
    std::ifstream ifs;

    ifs.open(file);

    reader.parse(ifs, *root);
    
    return root;
}