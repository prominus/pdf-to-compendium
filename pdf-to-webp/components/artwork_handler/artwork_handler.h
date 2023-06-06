#ifndef ARTWORK_HANDLER
#define ARTWORK_HANDLER

#include "../tsqueue/tsqueue.h"

namespace libpdftowebp
{

    class ArtworkHandler: public Handler
    {
    public:
        ArtworkHandler(const std::string output_folder, std::shared_ptr<TSQueue<ImgNode>> queue, std::shared_ptr<Json::Value> schema);
        ~ArtworkHandler();
        void HandleTask();
    };

}
#endif