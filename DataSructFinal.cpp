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
    int size = 0;
    TreeNode* head;
public:
    ContactTrace()
    {
    }

    ~ContactTrace()
    {
    }

    bool IsEmpty()
    {
        return true;
    }

    int GetSize()
    {
        return 0;
    }

    void AddPatient0(const string &)
    {
    }

    void AddContact(const string &, const string &)
    {
    }

    TreeNode *LookUpContact(const string &)
    {
        return nullptr;
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
    std::cout << "This is our contact tracer!\n";
}
