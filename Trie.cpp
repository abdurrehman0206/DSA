#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct Node
{
    char ch;
    map<char, Node *> children;
};

class Trie
{
public:
    Trie() { head.ch = -1; };
    ~Trie();

    void build_trie(string words[], int length);
    void insert(string word);
    void search(string word, bool &result);

    void print_tree(map<char, Node *> tree);
    void print();

protected:
    Node head;

    vector<Node *> children;
};

Trie::~Trie()
{
    for (int i = 0; i < children.size(); ++i)
    {
        delete children[i];
    }
}

void Trie::build_trie(string words[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        insert(words[i]);
    }
}

void Trie::insert(string word)
{
    map<char, Node *> *current_tree = &head.children;
    map<char, Node *>::iterator it;

    for (int i = 0; i < word.length(); ++i)
    {
        char ch = word[i];

        if ((it = current_tree->find(ch)) != current_tree->end())
        {
            current_tree = &it->second->children;
            continue;
        }

        if (it == current_tree->end())
        {
            Node *new_node = new Node();
            new_node->ch = ch;
            (*current_tree)[ch] = new_node;

            current_tree = &new_node->children;

            children.push_back(new_node);
        }
    }
}

void Trie::search(string word, bool &result)
{
    map<char, Node *> current_tree = head.children;
    map<char, Node *>::iterator it;

    for (int i = 0; i < word.length(); ++i)
    {
        if ((it = current_tree.find(word[i])) == current_tree.end())
        {
            result = false;
            return;
        }
        current_tree = it->second->children;
    }

    result = true;
    return;
}

void Trie::print_tree(map<char, Node *> tree)
{
    if (tree.empty())
    {
        return;
    }

    for (map<char, Node *>::iterator it = tree.begin(); it != tree.end(); ++it)
    {
        cout << it->first << endl;
        print_tree(it->second->children);
    }
}

void Trie::print()
{
    map<char, Node *> current_tree = head.children;
    print_tree(current_tree);
}

int main(int argc, char **argv)
{
    string words[] = {"foo", "bar", "baz", "barz"};
    Trie trie;
    trie.build_trie(words, 4);
    cout << "All nodes..." << endl;
    trie.print();

    cout << "Searching..." << endl;
    bool in_trie = false;
    trie.search("foo", in_trie);
    cout << "foo " << in_trie << endl;

    trie.search("fooz", in_trie);
    cout << "fooz " << in_trie << endl;

    trie.search("bar", in_trie);
    cout << "bar " << in_trie << endl;

    trie.search("baz", in_trie);
    cout << "baz " << in_trie << endl;

    trie.search("barz", in_trie);
    cout << "barz " << in_trie << endl;
    ;

    trie.search("bbb", in_trie);
    cout << "bbb " << in_trie << endl;
    ;
    system("pause");
    return 0;
}