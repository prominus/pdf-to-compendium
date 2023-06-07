#ifndef ARTWORK_HANDLER
#define ARTWORK_HANDLER

#include "../handler/handler.h"
#include "../tsqueue/tsqueue.h"

namespace libpdftowebp
{

    class ArtworkHandler: public Handler
    {
    public:
        ArtworkHandler(const std::string output_folder, std::shared_ptr<TSQueue<ImageNode>> queue, std::shared_ptr<Json::Value> schema);
        ~ArtworkHandler();
        void HandleTask();
    };

}
#endif