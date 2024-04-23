#include <iostream>
#include <list>
#include <queue>
#include "ContactTree.h"

using namespace std;

int main() {
    // Create a new ContactTree with a root node
    ContactTree tree("Patient0");

    // Add some contacts; assume "Patient0" has directly infected "Patient1" and "Patient2"
    tree.AddContact("Patient0", "Patient1");
    tree.AddContact("Patient0", "Patient2");

    // Add more contacts, "Patient1" infects "Patient3" and "Patient4"
    tree.AddContact("Patient1", "Patient3");
    tree.AddContact("Patient1", "Patient4");

    // Display specific contact details
    cout << "Details for Patient1:" << endl;
    tree.DisplayContact("Patient1");

    // Trace the source of infection for "Patient3"
    cout << "Tracing source for Patient3:" << endl;
    tree.TraceSource("Patient3");

    // Print all contact cases from "Patient1"
    cout << "Direct contact cases from Patient1:" << endl;
    tree.PrintContactCases("Patient1");

    // Print the entire contact tree
    cout << "Printing the entire Contact Tree:" << endl;
    tree.PrintContactTree();

    return 0;
}
