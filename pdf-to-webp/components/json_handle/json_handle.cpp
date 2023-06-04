#include <iostream>
#include <jsoncpp/json/json.h>
#include <fstream>
#include <string>
#include "json_handle.h"

/// @brief Generate an object from the JSON file to use 
/// @param file absolute file path to the JSON file
/// @details 
/// Based off of the provide [read from stream example](https://github.com/open-source-parsers/jsoncpp/blob/master/example/readFromStream/readFromStream.cpp).
/// There is no check that the file is valid. That should be done already.
/// @return The JSON object reference
Json::Value* libpdftowebp::GetJsonHandle(const char* file)
{
    // The JSON handle workers will reference
    Json::Value* json_handle = new Json::Value();
    Json::Reader reader;

    // Stream in the JSON file
    std::ifstream ifs;
    ifs.open(file);
    reader.parse(ifs, *json_handle);
    
    return json_handle;
}