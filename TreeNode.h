#include <iostream>
#include <list>

using namespace std;

struct TreeNode
{
    string medicareId;
    int directContacts = 0;
    int totalCases = 1;
    TreeNode *parent;
    list<TreeNode*> children;

    TreeNode(const string &medId) { medicareId = medId; parent = nullptr; }
    TreeNode(TreeNode *parentPtr, const string &medId) { medicareId = medId; parent = parentPtr; };
};