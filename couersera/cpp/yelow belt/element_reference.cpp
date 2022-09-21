#include <map>
#include <stdexcept>

template <typename Key, typename Value>
Value &GetRefStrict(map<Key, Value> &M, const Key &k)
{
    if (M.count(k) == 0)
    {
        throw runtime_error("no suchkey in dictionary");
    }
    return M[k];
}