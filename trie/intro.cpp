#include <bits/stdc++.h>
using namespace std;
class trieNode
{
public:
    char data;
    trieNode *children[26];

    bool isTerminal;
    trieNode(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class trie
{

public:
    trieNode *root;
    trie()
    {
        root = new trieNode('\0'); // initialised the root node with null character
    }
    void insertUtil(trieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        cout << "code is running smoothly" << endl;
        // word is in capital letters
        int index = word[0] - 'A';
        trieNode *child;
        if (root->children[index] != NULL)
        { // means the word is already present
            child = root->children[index];
        }
        else
        {
            child = new trieNode(word[0]);
            root->children[index] = child;
        }
        // recursive call
        insertUtil(child, word.substr(1));
    }
    void insert(string word)
    {
        insertUtil(root, word);
    }
    bool searchUtil(trieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0] - 'A';
        trieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return searchUtil(child, word.substr(1));
    }
    bool search(string word)
    {
        return searchUtil(root, word);
    }
    bool startUtil(trieNode *root, string pre)
    {
        if (pre.length() == 0)
        {
            return true;
        }
        trieNode *child;
        int index = pre[0] - 'A';
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return startUtil(child, pre.substr(1));
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        return startUtil(root, prefix);
    }

    // startwith wale se ham pta krenge ki given string prefix wai se start koi string trie me exist krti h ya nhi
    //  saurabh is inserted if i check for sau then it will return true and for saurabha then false;
    // now deletion is starting
    void removeUtil(trieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'A';
        trieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return;
        }
        removeUtil(child, word.substr(1));
    }
    void removeword(string word)
    {
        removeUtil(root, word);
    }
};
int main()
{
    trie *t = new trie();
    string a, b, c;
    cin >> a >> b >> c;
    t->insert(a);
    t->insert(b);
    t->insert(c);
    cout << "enter the word to be searched\n";
    string sea;
    cin >> sea;
    cout << "is " << sea << " present  " << t->search(sea) << endl;
    cout << "enter the prefix to be searched\n";
    string pre;
    cin >> pre;
    cout << "is word start with " << pre << " present  " << t->startsWith(pre) << endl;
    cout << "enter the word to be deleted\n";
    string del;
    cin >> del;
    t->removeword(del);
    cout << "enter the word to be searched\n";
    cin >> sea;
    t->search(sea);
    cout << "is " << sea << " present  " << t->search(sea) << endl;
    return 0;
}