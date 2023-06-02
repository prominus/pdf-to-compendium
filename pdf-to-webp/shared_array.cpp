#include <array>
#include <memory>
#include "shared_array.h"

template <typename K, typename V>
Node<K, V>::Node(K key, V value) : _key(key), _value(value)
{

}

std::size_t StaticMap::isValidIndex(std::size_t index) const
{
    return capacity;
}

StaticMap::StaticMap() {}

StaticMap::StaticMap(std::size_t capacity) //: capacity(capacity)
{
    // std::array<Node<std::string, std::shared_ptr<Image>>, x> images{};
}

StaticMap::~StaticMap()
{
    // for (auto &&image : images)
    // {
        
    // }   
}

Image StaticMap::find(std::string image) const
{
    return Image();
}