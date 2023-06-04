#ifndef JSON_HANDLE
#define JSON_HANDLE

#include <jsoncpp/json/json.h>

namespace libpdftowebp
{
    Json::Value *GetJsonHandle(const char *file);
};

#endif // JSON_HANDLE