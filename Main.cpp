#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Node.h"
#include "Tree.h"

using namespace std;

Node* createNode() {
    string data;
    cout << "Create node: ";
    cin >> data;
    
    return new Node(data);
}

int main(int argc, char* argv[])
{
    string choice;
    Tree tree = Tree();
    
    for (int i = 0; i < argc; i++)
    {
        if (string(argv[i]) == "-i") {
            cout << "Inserting " << argv[i + 1] << endl;
            tree.insert(argv[i + 1]);
        }
        else if (string(argv[i]) == "-d") {
            tree.deleteNode(argv[i + 1]);
        }
        else if (string(argv[i]) == "-iv") {
            cout << "Inserting " << argv[i + 1] << endl;
            tree.insert(argv[i + 1]);
            tree.print();
            cout << "Press enter to continue...";
            cin;
        }
        else if (string(argv[i]) == "-dv") {
            cout << "Deleting " << argv[i + 1] << endl;
            tree.deleteNode(argv[i + 1]);
            tree.print();
            cout << "Press enter to continue...";
            cin;
        }
        else if (string(argv[i]) == "-if") {
            cout << "Creating nodes from " << argv[i + 1] << endl;
            ifstream infile{ argv[i + 1] };

            while (infile) {
                string fileInput;
                infile >> fileInput;
                
                if (fileInput.size() > 0)
                    tree.insert(fileInput);
            }
        }
        else if (string(argv[i]) == "-df") {
            cout << "Deleting nodes from " << argv[i + 1] << endl;
            ifstream infile{ argv[i + 1] };

            while (infile) {
                string fileInput;
                infile >> fileInput;
                tree.deleteNode(fileInput);
            }
        }
        else if (string(argv[i]) == "-ifv") {
            cout << "Creating nodes from " << argv[i + 1] << endl;
            ifstream infile{ argv[i + 1] };

            while (infile) {
                string fileInput;
                infile >> fileInput;
                if (fileInput.size() > 0) {
                    tree.insert(fileInput);
                    cout << "Inserting " << fileInput << endl;
                    tree.print();
                    system("pause");
                }
            }
        }
        else if (string(argv[i]) == "-df") {
            cout << "Deleting nodes from " << argv[i + 1] << endl;
            ifstream infile{ argv[i + 1] };

            while (infile) {
                string fileInput;
                infile >> fileInput;
                if (fileInput.size() > 0) {
                    tree.deleteNode(fileInput);
                    cout << "Deleting " << fileInput << endl;
                    tree.print();
                    system("pause");
                }
            }
        }
    }
    

    while (true)
    {
        cout << "\n--Main Menu--\n";
        cout << "1) display tree\n";
        cout << "2) insert node\n";
        cout << "3) search for node\n";
        cout << "4) delete node\n";
        cout << "5) rebalance tree\n";
        cout << "6) exit\n";
        cout << "-> ";
        cin >> choice;

        if (choice == "1" || choice == "display tree") {
            cout << "----- Key -----\n";
            cout << "\033[0;91m Unbalanced\n";
            cout << "\033[0;32m Balanced\n";
            cout << "\033[0;37m---------------\n\n";
            tree.print();
        }
        else if (choice == "2" || choice == "insert node") {
            cout << "New node: ";
            cin >> choice;
            tree.insert(new Node(choice));
        }
        else if (choice == "3" || choice == "search for node") {
            cout << "Search for: ";
            cin >> choice;
            Node* foundNode = tree.search(choice);

            if (foundNode)
                tree.printNodeInTree(foundNode);
            else
                cout << "Node not found.\n";
        }
        else if (choice == "4" || choice == "delete node") {
            cout << "Delete node: ";
            cin >> choice;
            tree.search(choice) ? cout << "Node deleted.\n" : cout << "Node not found.\n";
            tree.deleteNode(choice);
        }
        else if (choice == "5" || choice == "rebalance tree") {
            tree.rebalance();
            cout << "Rebalancing tree...\n";
            tree.print();
        }
        else if (choice == "6" || choice == "exit") { 
            break; 
        }
    }
}
