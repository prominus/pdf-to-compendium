#ifndef JSON_REF
#define JSON_REF

// #include <jsoncpp/json/json.h>
#include <jsoncpp/json/json.h>

std::shared_ptr<Json::Value> GetJsonHandle(const char *file);

#endif // JSON_REF