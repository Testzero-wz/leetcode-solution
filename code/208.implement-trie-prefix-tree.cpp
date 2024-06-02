/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */
#include <string>
using namespace std;
// @lc code=start
class Trie
{
public:
    typedef struct Node
    {
        Node(bool is_end)
        {
            is_word_end = is_end;
            for (int i = 0; i < 26; i++)
            {
                children[i] = nullptr;
            }
        }
        Node *children[26];
        bool is_word_end;
    } Node;

    int c2i(char c)
    {
        return c - 'a';
    }

    Node *root;
    Trie()
    {
        root = new Node(false);
    }

    void insert(string word)
    {
        Node *cur_node = root;
        bool last_char = false;
        char c;
        int idx;
        Node *tmp;
        for (int i = 0; i < word.length(); i++)
        {
            c = word[i];
            last_char = i == word.length() - 1;
            idx = c2i(c);
            tmp = cur_node->children[idx];
            if (tmp == nullptr)
            {
                // nullptr
                cur_node->children[idx] = new Node(last_char);
                tmp = cur_node->children[idx];
            }
            else
            {
                if(last_char)
                    tmp->is_word_end = true;
            }
            cur_node = tmp;
        }
        return;
    }

    bool search(string word)
    {
        Node *cur_node = root;
        Node *tmp;
        bool last_char = false;
        char c;
        for (int i = 0; i < word.length(); i++)
        {
            c = word[i];
            tmp = cur_node->children[c2i(c)];
            last_char = i == word.length() - 1;
            if (tmp == nullptr)
            {
                return false;
            }
            cur_node = tmp;
            if (last_char)
            {
                return cur_node->is_word_end;
            }
        }
        return true;
    }

    bool startsWith(string prefix)
    {
        Node *cur_node = root;
        bool found = true;
        Node *tmp;
        for (auto c : prefix)
        {
            tmp = cur_node->children[c2i(c)];
            if (tmp == nullptr)
            {
                found = false;
                break;
            }
            cur_node = tmp;
        }
        return found;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
