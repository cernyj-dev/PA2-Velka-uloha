#ifndef PAIR_UTIL_HPP
#define PAIR_UTIL_HPP

#include <utility>    // for std::pair
#include <functional> // for std::hash

// used for the circular cell reference detector in CSpreadsheet
struct pairHasher
{
    long long operator()(const std::pair<long long, long long> pair) const
    {
        return (std::hash<long long>()(pair.first)) ^ (std::hash<long long>()(pair.second) << 1);
    }
};

// used for the circular cell reference detector in CSpreadsheet
struct pairEqual
{
    bool operator()(const std::pair<long long, long long> &lhs, const std::pair<long long, long long> &rhs) const
    {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }
};

#endif
