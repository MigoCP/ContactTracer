#include <iostream>
#include <list>

using namespace std;

struct TreeNode
{
private:
    string medicareId;
    int directContacts = 0;
    int totalCases = 1;
    TreeNode *parent;
    list<TreeNode *> children;

public:
    TreeNode(const string &medId)
    {
        medicareId = medId;
        parent = nullptr;
    }
    TreeNode(TreeNode *parentPtr, const string &medId)
    {
        medicareId = medId;
        parent = parentPtr;
    };
};

class ContactTrace
{
private:
public:
    ContactTrace()
    {
    }

    ~ContactTrace()
    {
    }

    bool IsEmpty()
    {
    }

    int GetSize()
    {
    }

    void AddPatient0(const string &)
    {
    }

    void AddContact(const string &, const string &)
    {
    }

    TreeNode *LookUpContact(const string &)
    {
    }

    void DeleteContact(const string &)
    {
    }

    void DisplayContact(TreeNode *)
    {
    }

    void DisplayContact(const string &)
    {
    }

    void TraceSource(const string &)
    {
    }

    void PrintContactCases(const string &)
    {
    }

    void PrintContactTree()
    {
    }

    void PrintHierarchicalTree()
    {
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
