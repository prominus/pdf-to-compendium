#ifndef FS_MAP
#define FS_MAP

#include <iostream>
#include <map>

template <typename Key, typename Value, std::size_t Size>
class FixedSizeOrderedMap {
public:
    FixedSizeOrderedMap() : map() {}

    void insert(const Key& key, const Value& value) {
        if (map.size() >= Size) {
            std::cerr << "Cannot insert more elements. The map is full." << std::endl;
            return;
        }

        map[key] = value;
    }

    Value& operator[](const Key& key) {
        return map[key];
    }

    std::size_t size() const {
        return map.size();
    }

private:
    std::map<Key, Value> map;
};

#endif // FS_MAP