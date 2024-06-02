/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */
#include <vector>
#include <map>
using namespace std;
// @lc code=start
class LRUCache
{
public:
    typedef struct node
    {
        int key;
        int value;
        node *prev;
        node *next;
    } node;
    int cap;
    map<int, node *> nodes;
    node *head;
    node *tail;
    bool full;
    LRUCache(int capacity)
    {
        nodes = map<int, node *>();
        cap = capacity;
        head = new node{-1, -1, nullptr, nullptr};
        tail = new node{-1, -1, nullptr, nullptr};
        tail->prev = head;
        head->next = tail;
        full = false;
    }

    int get(int key)
    {
        if (nodes.find(key) == nodes.end())
        {
            return -1;
        }
        node *n = unlink(key);
        append(n);
        int value = n->value;
        return value;
    }

    void put(int key, int value)
    {
        node *n = nullptr;
        // key in map

        if (nodes.find(key) != nodes.end())
        {
            // unlink
            n = unlink(key);
            n->value = value;
        }
        else
        {
            if (full)
            {
                // full
                // ecivt node first
                int del_key = head->next->key;
                unlink(del_key);
                nodes.erase(del_key);
            }
            n = new node{
                key,
                value,
                nullptr,
                nullptr,
            };
        }

        append(n);
        
        if (!full && nodes.size() == cap)
        {
            full = true;
        }
    }
    void append(node *n)
    {
        n->prev = tail->prev;
        n->next = tail;
        tail->prev->next = n;
        tail->prev = n;
        nodes[n->key] = n;
    }
    node *unlink(int key)
    {
        node *n = nodes[key];
        n->prev->next = n->next;
        n->next->prev = n->prev;
        n->prev = nullptr;
        n->next = nullptr;
        return n;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
