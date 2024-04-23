#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

class ContactTree
{
private:
    TreeNode* root;
    int size;

    // Delete node and all its children (entire tree)
    void DeleteContact(TreeNode* node)
    {
        if (node) // If node is not nullptr
        {   
            for (TreeNode* child : node->children) { DeleteContact(child); } // Delete all children with recursion
            delete node;  // Delete the currentElem node after deleting children
        }
    }

public:
    // Default constructor
    ContactTree() { this->root = nullptr; this->size = 0; }
    // Parameterized constructor
    ContactTree(const string &id) { this->root = new TreeNode(id); this->size++; }
    // Destructor
    ~ContactTree() { DeleteContact(root); }

    bool IsEmpty() { return this->size == 0; }
    int GetSize() { return this->size; }

    // No need for AddPatient0() func because  
    // parameterized constructor takes care of first patient

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

    // Get contact with ID by traversing the tree with a Queue data structure
    TreeNode* LookUpContact(const string &searchId)
    {
        // If tree is empty or Id is null, return immediately
        if (root == nullptr || &searchId == nullptr) return nullptr;  

        /* The Queue facilitates level order traversal
        by ensuring that nodes are checked in the 
        order they are discovered (FIFO). This means
        all nodes at one level are checked completely
        before moving on to the next one */ 

        queue<TreeNode*> p;  // Local queue of node pointers
        p.push(root);  // Start with root

        while (!p.empty()) 
        {
            TreeNode* currentElem = p.front();  // Get the front (first-in) node 
            p.pop();  // Remove the front node from the queue

            if (currentElem->medicareId == searchId) { return currentElem; } // Return node if match
            
            // Enqueue all children of the currentElem node (process entire level)
            for (TreeNode* child : currentElem->children) { p.push(child); }
        }

        return nullptr;  // Return nullptr if no match found
    }

    // Display using pointer
    void DisplayContact(TreeNode * displayer)
    {
        string parent;
        if (!displayer->parent) parent = "Unknown (Potentially patient 0)";
        else parent = displayer->parent->medicareId;
        
        cout << "\nPatient ID " << displayer->medicareId << endl;
        cout << "\tInfected by: " << parent << endl;
        cout << "\tDirect contacts: " << displayer->directContacts << endl;
        cout << "\tTotal cases originated in this patient: " << displayer->totalCases << endl;
        cout << "\tPatients infected: " << endl;
        for (TreeNode* child : displayer->children) { cout << "\t\t- " << child->medicareId << endl; }
        cout << endl;
    }

    // Display using ID
    void DisplayContact(const string &searchId)
    {
        TreeNode* p = LookUpContact(searchId);
        if (!p) DisplayContact(p);
        else cout << "No contact found" << endl;
    }

    void TraceSource(const string& searchId)
    {
        TreeNode* currentElem = LookUpContact(searchId);

        // If current element's parent is not nullptr
        if (currentElem->parent) 
        { 
            DisplayContact(currentElem->parent); 
            TraceSource(currentElem->parent->medicareId); // Use recursion to reach root
        }
        else // If not, there's no parent and hence root has been reached
        {
            cout << "Contact Root: " << endl;
            DisplayContact(currentElem);
        }
                    return; // end recursion loop 
    }

    void PrintContactCases(const string &searchId)
    {
        // If id is not null and contact is found
        if(&searchId && LookUpContact(searchId))
        {
            TreeNode* p = LookUpContact(searchId);
            for (TreeNode* directContact : p->children) { DisplayContact(p); } // Display each child
            return; // End function
        }
        // Else, let user know no contact was found
        cout << "No contact found with such Id" << endl;
    }

    void PrintContactTree()
    {
        // If tree is empty, return immediately
        if (IsEmpty) { cout << "Tree is empty" << endl; return;}

        /* The Queue facilitates level order traversal
        by ensuring that nodes are checked in the 
        order they are discovered (FIFO). This means
        all nodes at one level are checked completely
        before moving on to the next one */ 

        queue<TreeNode*> p;  // Local queue of node pointers
        p.push(root);  // Start with root

        while (!p.empty()) 
        {
            TreeNode* currentElem = p.front();  // Get the front (first-in) node 
            p.pop();  // Remove the front node from the queue

            DisplayContact(currentElem); // Display current node
            
            // Enqueue all children of the currentElem node (process entire level)
            for (TreeNode* child : currentElem->children) { p.push(child); }
        }
    }

    void PrintHierarchicalTree()
    {
        //choose the order to use preorder,...?
        //found in stack file - fibonacci
    }
};