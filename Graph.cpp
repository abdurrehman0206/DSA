#include <iostream>
#include <cfloat>
#include <fstream>
#include <iomanip>

using namespace std;

class wtdGraphAdjMat
{
public:
    void createWtdGraph();
    void shortestPath(int vertex);

    void printShortestDistance(int vertex);
    // wtdGraphAdjMat(int size = 0);
    // Constructor
    // Postcondition: gSize = 0; maxSize = size;
    //     graph is an array of pointers to linked lists.
    //     weights is a two-dimensional array to store the weights
    //        of the edges.
    //     smallestWeight is an array to store the smallest weight
    //        from source to vertices.

    // ~wtdGraphAdjMat();
    // Destructor
    // The storage occupied by the vertices and the arrays
    // weights and smallestWeight is deallocated.

protected:
    double **wtdMat;        // pointer to create weight matrix
    double *smallestWeight; // pointer to create the array to store
                            // the smallest weight from source to vertices
    int *pred;
    int gSize;
};

int main()
{
    wtdGraphAdjMat G;
    G.createWtdGraph();
    G.shortestPath(0);
    G.printShortestDistance(0);
    system("pause");
    return 0;
}

void wtdGraphAdjMat::createWtdGraph()
{
    ifstream infile;

    int vertex;
    int adjacentVertex;
    double adjVertWt;
    infile.open("graph.txt");

    infile >> gSize; // get the number of vertices

    wtdMat = new double *[gSize];
    for (int i = 0; i < gSize; i++)
        wtdMat[i] = new double[gSize];

    for (int i = 0; i < gSize; i++)
        for (int j = 0; j < gSize; j++)
        {
            wtdMat[i][j] = DBL_MAX;
            if (i == j)
                wtdMat[i][j] = 0;
        }

    smallestWeight = new double[gSize];

    for (int index = 0; index < gSize; index++)
    {
        infile >> vertex;
        infile >> adjacentVertex;

        while (adjacentVertex != -999)
        {
            infile >> adjVertWt;
            wtdMat[vertex][adjacentVertex] = adjVertWt;
            infile >> adjacentVertex;
        } // end while
    }     // end for

    infile.close();
}

void wtdGraphAdjMat::shortestPath(int vertex)
{
    for (int j = 0; j < gSize; j++)
        smallestWeight[j] = wtdMat[vertex][j];

    bool *weightFound;
    weightFound = new bool[gSize];
    pred = new int[gSize];

    for (int j = 0; j < gSize; j++)
    {
        weightFound[j] = false;
        pred[j] = -1;
    }
    weightFound[vertex] = true;
    smallestWeight[vertex] = 0;

    for (int i = 0; i < gSize - 1; i++)
    {
        double minWeight = DBL_MAX;
        int v;

        for (int j = 0; j < gSize; j++)
            if (!weightFound[j])
                if (smallestWeight[j] < minWeight)
                {
                    v = j;
                    minWeight = smallestWeight[v];
                }

        weightFound[v] = true;

        for (int j = 0; j < gSize; j++)
            if (!weightFound[j])
                if (minWeight + wtdMat[v][j] < smallestWeight[j])
                {
                    smallestWeight[j] = minWeight + wtdMat[v][j];
                    pred[j] = v;
                }
    } // end for
}

void wtdGraphAdjMat::printShortestDistance(int vertex)
{
    cout << "Source Vertex: " << vertex << endl;
    cout << "Shortest distance from source to each vertex."
         << endl;
    cout << "Vertex  Shortest_Distance" << endl;

    for (int j = 0; j < gSize; j++)
        cout << setw(4) << j << setw(12) << smallestWeight[j] << setw(12) << pred[j]
             << endl;
    cout << endl;
} // end printShortestDistance
