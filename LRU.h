#pragma once

using namespace std;

#include <unordered_map>
#include <list>

class LRUCache
{
public:

    struct LRUNode
    {
        int timestamp;
        int key;

        LRUNode(int t_, int k_) :timestamp(t_), key(k_) {}
    };

    using LRUList = list<LRUNode>;

    struct CacheNode
    {
        int value;
        LRUList::iterator lruIterator;
    };

    using Cache = unordered_map<int, CacheNode>;

    LRUCache(int capacity):m_cache(capacity+1)
    {
        N = capacity;        
    }

    int get(int key)
    {
        auto it = m_cache.find(key);
        if (it == m_cache.end())
            return -1;

        auto& item = it->second;
        m_lru.erase(item.lruIterator);
        m_lru.emplace_back(++timestamp, key);
        item.lruIterator = --m_lru.end();

        return item.value;
    }

    void put(int key, int value)
    {
        auto it = m_cache.find(key);
        if (it != m_cache.end()) //replace
        {
            auto& item = it->second;

            m_lru.erase(item.lruIterator);
            m_lru.emplace_back(++timestamp, key);

            item.lruIterator = --m_lru.end();
            item.value = value;
            
            return;
        }

        if (m_cache.size() < N)
        {
            m_lru.emplace_back(++timestamp, key);
            m_cache.emplace(key, CacheNode{ value, --m_lru.end() });
        }
        else
        {
            LRUNode& node = m_lru.front();
            m_cache.erase(node.key);
            m_lru.pop_front();            

            m_lru.emplace_back(++timestamp, key);
            m_cache.emplace(key, CacheNode{ value, --m_lru.end() });
        }
    }

    int N;
    int timestamp = 0;
    LRUList m_lru;
    Cache m_cache;

    static void test()
    {
        LRUCache cache(2 /* capacity */);

        int ret = 0;
        cache.put(1, 1);
        cache.put(2, 2);
        ret = cache.get(1);       // returns 1
        cache.put(3, 3);    // evicts key 2
        ret = cache.get(2);       // returns -1 (not found)
        cache.put(4, 4);    // evicts key 1
        ret = cache.get(1);       // returns -1 (not found)
        ret = cache.get(3);       // returns 3
        ret = cache.get(4);       // returns 4
        cache.put(4, 1);    // evicts key 1
        ret = cache.get(4);       // returns 1
    }
};
