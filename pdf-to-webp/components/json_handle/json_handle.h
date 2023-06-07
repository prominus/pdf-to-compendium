#ifndef JSON_HANDLE
#define JSON_HANDLE

#include "jsoncpp/json/json.h"

namespace libpdftowebp
{
    std::shared_ptr<Json::Value> GetJsonHandle(const char *file);
};

#endif // JSON_HANDLE