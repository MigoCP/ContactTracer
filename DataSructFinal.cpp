#include <iostream>
#include <list>
#include <queue>

using namespace std;

struct TreeNode
{
//private: 
    string medicareId;
    int directContacts = 0;
    int totalCases = 1;
    TreeNode *parent;
    list<TreeNode*> children;

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
    TreeNode* root;
public:
    ContactTrace()
    {
        this->root = nullptr;
    }

    ~ContactTrace()
    {
    }

    bool IsEmpty()
    {
        return true; //this->size == 0; //this->roo == nullptr;
    }

    int GetSize()
    {
        return this->size;
    }

    void AddPatient0(const string &id)
    {
        root = new TreeNode(id); 
        //parameterized constructor that accepts a contact Id 
        //and creates the tree as well as its first node.
    }

    void AddContact(const string &id1, const string &id2)
    {
        TreeNode *node1 = LookUpContact(id1);
        if(node1 != nullptr)
        {
            TreeNode *node2 = new TreeNode(node1, id2);
            node2->children.push_back(node1);
            node1->directContacts++;
            //node1->totalCases++;
            TreeNode *newParent = node1;
            
        }
    }

    TreeNode *LookUpContact(const string &searchId)
    {
        //queue helps us focus on specific operations needed
        //for BFS
        //queue allows nodes to be enqueued at the back and
        //dequeued from the front in constant time
        //queue has a simple interface compared to  deque
        // 
        queue<TreeNode*> p; //p storing the pointers to the TreeNode objects
        if(this->root != nullptr)
        {
            p.push(root);  
        }
        while(!p.empty())
        {
            TreeNode *currentElem = p.front(); 
            //currentElem = currentChild
        
            if(currentElem->medicareId == searchId)
            {
                return currentElem; 
            }
            else
            {
                 p.pop(); 
            //front elem is dequeue/removed showing 
            //that currentElem is != searchId
            } 

            for(TreeNode *child : currentElem->children)
                p.push(child);
        }
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
        //choose the order to use preorder,...?
        //found in stack file - fibonacci
    }
};

int main()
{
    std::cout << "This is our contact tracer!\n";
    std::cout << "This is our contact tracer!\n";
}
