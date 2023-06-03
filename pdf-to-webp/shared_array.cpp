#include <array>
#include <memory>
#include "shared_array.h"

/// @brief Verify if the index is within range
/// @tparam N The max size for this Map
/// @param index 
/// @return 
template<std::size_t N>
std::size_t pdftowebp::StaticMap<N>::isValidIndex(std::size_t index) const
{
    return capacity;
}

/// @brief 
/// @tparam N 
template<std::size_t N>
pdftowebp::StaticMap<N>::StaticMap() : capacity(N) {
}

/// @brief 
/// @tparam N 
template<std::size_t N>
pdftowebp::StaticMap<N>::~StaticMap()
{
    // for (auto &&image : images)
    // {

    // }
}

/// @brief 
/// @tparam N 
/// @param key 
/// @return 
template<std::size_t N>
std::shared_ptr<pdftowebp::Image> pdftowebp::StaticMap<N>::findImage(std::string key) const
{
    for (auto &&image : images)
    {
        
    }
    
    return std::shared_ptr<pdftowebp::Image>();
}

/// @brief 
/// @tparam N 
/// @param key 
/// @param value 
template<std::size_t N>
void pdftowebp::StaticMap<N>::insert(const std::string key, const std::shared_ptr<Image> value) const
{
}

template <std::size_t N>
int pdftowebp::StaticMap<N>::getCapacity() const
{
    return 0;
}

template <std::size_t N>
std::shared_ptr<pdftowebp::Image> pdftowebp::StaticMap<N>::indexImage(int index) const
{
    return std::shared_ptr<Image>();
}

// pdftowebp::StaticMap map = pdftowebp::StaticMap<100>();

