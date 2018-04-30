// Jarod Gates
// Purpose: This program takes a user inputted Array-Pointer and decieds which nodes are adjacent and which nodes are isolated...
// and returns an adjacency matrix.
#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_LENGTH=30; //Used to initialize Array-Pointer
const int MAX_WIDTH=2; //Used to initialize Array-Pointer
void CheckIsolated(int Array[MAX_LENGTH][MAX_WIDTH], int r, int c, int nodes);
void AssignArray(int Array[MAX_LENGTH][MAX_WIDTH], int rows);
void PrintArray(int Array[5][5], int nodes);

int main()
{
    int Array_Pointer[MAX_LENGTH][MAX_WIDTH]={0}; //Stores the Array-Pointer
    int nodes; //Takes user input for the # of nodes
    int rows; //Takes user input for the # of rows
    int NodeNext=0; //Used to keep track of which node to travel to next in adjacency assignment
    int AdjNode=0; //Used to store the location of a node adjacent to another
    
    //Ask for the number of nodes and initialize adjacency matrix
    cout << "Please enter the amount of nodes: " << endl;
    cin >> nodes;
    int Adjacency[5][5]={0};
    
    //Ask for the amount of rows in the array-pointer representation of the graph
    cout << "How many rows are in the array-pointer representation of the graph?: " << endl;
    cin >> rows;
    
    
    AssignArray(Array_Pointer, rows);
    
    CheckIsolated(Array_Pointer, rows, MAX_WIDTH,  nodes);
    
    
    //Assigns the Adjacency Matrix
    for(int i=0; i<nodes; i++) {
        NodeNext=Array_Pointer[i][1];
        
        while(NodeNext!=-1) {
            AdjNode=Array_Pointer[NodeNext-1][0];
            Adjacency[i][AdjNode-1]=1;
            NodeNext=Array_Pointer[NodeNext-1][1];
        }
    }
    
    PrintArray(Adjacency, nodes);
    
    
    return 0;
}

//Assigns the Array
void AssignArray(int Array[MAX_LENGTH][MAX_WIDTH], int rows) {
    cout << "Please enter the array-pointer representation of the graph: " << endl;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<MAX_WIDTH; j++) {
            cin >> Array[i][j];
        }
        
    }
}

//Checks for isolated nodes
void CheckIsolated(int Array[MAX_LENGTH][MAX_WIDTH], int r, int c, int nodes) {
    int Isolated[30]={0}; //Stores the location of the isolated arrays
    int cnt=0;
    for(int i=0; i<nodes; i++) {
        for(int j=0; j<c; j++) {
            if(Array[i][j]==-1) {
                cnt++;
                Isolated[i]=Array[i][j-1];
            }
            else {
                Isolated[i]=0;
            }
        }
    }
    if(cnt==0) {
        cout << endl;
        cout << "There are no Isolated Nodes." << endl;
    }
    else {
        cout << endl;
        cout << "Isolated Nodes: ";
        for(int x=0; x<nodes; x++) {
            if(Isolated[x]!=0) {
                cout << Isolated[x] << endl;
            }
        }
    }
    
}

// Prints the Adjacency Array
void PrintArray(int Array[5][5], int nodes) {
    cout << endl;
    cout << endl;
    cout << "This is the Adjacency Matrix: " << endl;
    for(int i=0; i<nodes; i++) {
        for(int j=0; j<nodes; j++) {
            cout << left << setw(4) << Array[i][j];
        }
        cout << endl;
    }
}

