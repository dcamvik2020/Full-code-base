#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <stdio.h>
#include <vector>
#include <limits>

using namespace std;
using City = struct City;

class TSP {
private:
    struct City{
        double x;
        double y;
    };
    string iFile;
    string oFile;
    vector<int> odds;     /// odd nodes
    int **cost;           /// Smaller cost matrix to find minimum matching on odd nodes
    vector<int> *adjList; /// Adjacency list

    /// Find all vertices of odd degree in the MST. Store them in an subgraph O
    void findOdds() {
        for (int i = 0; i < n; i++) {
            /// if degree of vertex i is odd
            if ((adjlist[i].size() % 2) != 0) {
                /// push vertex to odds, which is a representation of subgraph O
                odds.push_back(i);
            }
        }
    }

public:
    int n;                /// Number of cities
    int **path_vals;      /// The path
    int pathLength;       /// Shortest path length
    vector<int> circuit;  /// Euler circuit
    vector<City> cities;
    double **graph;       /// size = n*n, pairwise distances between cities
    vector<int> *adjlist;

    /// Constructor
    TSP(string in, string out) {
        /// CHECK INPUT
        iFile = in;
        oFile = out;
        ifstream inStream;
        inStream.open(iFile.c_str(), ios::in);
        if(!inStream){
            cerr << "Can't open input file " << iFile << endl;
            exit(1);
        }

        ///READ DATA
        int c;
        double x, y;
        int count = 0;
        while(!inStream.eof()){
            inStream >> c >> x >> y;
            count++;
            struct City newCity = {x, y};
            cities.push_back(newCity);
        }
        count--;
        cout << "cities created" << endl;
        inStream.close();

        ///Initialize member variables
        n = count;
        graph = new double*[n];
        for(int i = 0; i < n; i++){
            graph[i] = new double[n];
            for(int j = 0; j < n; j++){
                graph[i][j] = 0;
            }
        }

        cost = new int*[n];
        for(int i = 0; i < n; i++){
            cost[i] = new int[n];
        }

        path_vals = new int*[n];
        for(int i = 0; i < n; i++){
            path_vals[i] = new int[n];
        }

        adjlist = new vector<int>[n];
        for(unsigned i = 0; i < cities.size(); i++){
            struct City cur = cities[i];
        }
    }

    /// Destructor
    ~TSP() {
        for(int i = 0; i < n; i++){
            delete [] graph[i];
            delete [] cost[i];
            delete [] path_vals[i];
        }
        delete [] path_vals;
        delete [] graph;
        delete [] cost;
        delete [] adjlist;
    }

    double get_distance(City c1, City c2){
        int dx = pow(c1.x - c2.x, 2);
        int dy = pow(c1.y - c2.y, 2);
        return sqrt(dx + dy);
    }

    ///Find perfect matching M in the subgraph O using greedy algorithm
    void perfectMatching() {
        int closest, length;
        std::vector<int>::iterator tmp, first;

        /// Find nodes with odd degrees in T to get subgraph O
        findOdds();

        /// for each odd node
        while (!odds.empty()) {
            first = odds.begin();
            vector<int>::iterator it = odds.begin() + 1;
            vector<int>::iterator end = odds.end();
            length = std::numeric_limits<int>::max();
            for (; it != end; ++it) {
                /// if this node is closer than the current closest, update closest and length
                if (graph[*first][*it] < length) {
                    length = graph[*first][*it];
                    closest = *it;
                    tmp = it;
                }
            }
            /// two nodes are matched, end of list reached
            adjlist[*first].push_back(closest);
            adjlist[closest].push_back(*first);
            odds.erase(tmp);
            odds.erase(first);
        }
    }

    /// Find Euler tour
    void euler_tour(int start, vector<int> &path){
        ///Create copy of adj. list
        vector<int> *tempList = new vector<int>[n];
        for(int i = 0; i < n; i++){
            tempList[i].resize(adjlist[i].size());
            tempList[i] = adjlist[i];
        }

        stack<int> stack;
        int pos = start;
        path.push_back(start);
        while(!stack.empty() || tempList[pos].size() > 0){
            /// Current node has no neighbors
            if(tempList[pos].empty()){
                /// add to circuit
                path.push_back(pos);
                /// remove last vertex from stack and set it to current
                pos = stack.top();
                stack.pop();
            }
            /// If current node has neighbors
            else{
                /// Add vertex to stack
                stack.push(pos);
                /// Take a neighbor
                int neighbor = tempList[pos].back();
                /// Remove edge between neighbor and current vertex
                tempList[pos].pop_back();
                for(int i = 0; i < tempList[neighbor].size(); i++){
                    if(tempList[neighbor][i] == pos){
                        tempList[neighbor].erase(tempList[neighbor].begin()+i);
                    }
                }
                /// Set neighbor as current vertex
                pos = neighbor;
            }
        }
        path.push_back(pos);
    }

    /// Make euler tour Hamiltonian
    void make_hamiltonian(vector<int> &path, int &pathCost){

        /// remove visited nodes from Euler tour
        bool *visited = new bool[n];
        for(int i = 0; i < n; i++){
            visited[i] = 0;
        }

        pathCost = 0;

        int root = path.front();
        vector<int>::iterator cur = path.begin();
        vector<int>::iterator iter = path.begin()+1;
        visited[root] = 1;

        /// iterate through circuit
        bool addMore = true;
        while(iter != path.end()){
            if(!visited[*iter]){
                pathCost += graph[*cur][*iter];
                cur = iter;
                visited[*cur] = 1;
                iter = cur + 1;
            }
            else{
                iter = path.erase(iter);
            }
        }

        ///Add distance to root
        if ( iter != path.end() ){
            pathCost += graph[*cur][*iter];
        }
    }

    /// Prim's algorithm for determine a minimum spanning tree on the graph
    void findMST() {
        int *key = new int[n];
        bool *included = new bool[n];
        int *parent = new int[n];

        for (int i = 0; i < n; i++) {
            /// set each key to infinity
            key[i] = std::numeric_limits<int>::max();

            /// node node yet included in MST
            included[i] = false;
        }

        /// root of MST has distance of 0 and no parent
        key[0] = 0;
        parent[0] = -1;

        for (int i = 0; i < n - 1; i++) {
            /// find closes vertex not already in tree
            int k = getMinIndex(key, included);

            /// set included to true for this vertex
            included[k] = true;

            /// examine each unexamined vertex adjacent to most recently added
            for (int j = 0; j < n; j++) {
                /// node exists, is unexamined, and graph[k][j] less than previous key for u
                if (graph[k][j] && included[j] == false && graph[k][j] < key[j]) {
                    parent[j] = k; /// update parent
                    key[j] = graph[k][j]; /// update key

                }
            }
        }

        /// construct a tree by forming adjacency matrices
        for (int i = 0; i < n; i++) {
            int j = parent[i];
            if (j != -1) {
                adjlist[i].push_back(j);
                adjlist[j].push_back(i);
            }
        }
    }

    /// Find the index of the closest unexamined node
    int getMinIndex(int key[], bool mst[]) {
        /// initialize min and min_index
        int min = std::numeric_limits<int>::max();
        int min_index;

        /// iterate through each vertex
        for (int i = 0; i < n; i++) {

            /// if vertex hasn't been visited and has a smaller key than min
            if (mst[i] == false && key[i] < min) {

            /// reassign min and min_index to the values from this node
            min = key[i];
            min_index = i;
            }
        }
        return min_index;
    }

    void printResult(){
        ofstream outputStream;
        outputStream.open(oFile.c_str(), ios::out);
        outputStream << pathLength << endl;
        for (vector<int>::iterator it = circuit.begin(); it != circuit.end(); ++it) {
            outputStream << *it << endl;
        }
        outputStream.close();
    }

    void printPath(){
        cout << endl;
        for (vector<int>::iterator it = circuit.begin(); it != circuit.end()-1; ++it) {
            cout << *it << " to " << *(it+1) << " ";
            cout << graph[*it][*(it+1)] << endl;
        }
        cout << *(circuit.end()-1) << " to " << circuit.front();
        cout << "\nLength: " << pathLength << endl << endl;
    }

    void printEuler() {
        for (vector<int>::iterator it = circuit.begin(); it != circuit.end(); ++it) {
            cout << *it << endl;
        }
    }

    void printAdjList() {
        for (int i = 0; i < n; i++) {
            cout << i << ": "; /// print which vertex's edge list follows
            for (int j = 0; j < (int)adjlist[i].size(); j++) {
                cout << adjlist[i][j] << " "; /// print each item in edge list
            }
            cout << endl;
        }
    }

    void printCities() {
        cout << endl;
        int i = 0;
        for (vector<City>::iterator it = cities.begin(); it != cities.end(); ++it)
            cout << i++ << ":  " << it->x << " " << it->y << endl;
    }

    int get_size() {
        return n;
    }

    void fillMatrix() {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                graph[i][j] = graph[j][i] = get_distance(cities[i],cities[j]);
            }
        }
    }

    int findBestPath(int start){
        vector<int> path;
        euler_tour(start, path);
        int length;

        make_hamiltonian(path, length);
        return length;
    }

};


int main(int argc, char** argv) {
    if(argc < 2){
        exit(-1);
    }

    /// Read file names from input
    string input, output;
    input = output = argv[1];
    output.append(".tour");

    /// Create new tsp object
    TSP tsp(input, output);
    cout << "tsp created" << endl;
    int tsp_size = tsp.get_size();

    /// Fill N x N matrix with distances between nodes
    cout << "Fillmatrix started" << endl;
    tsp.fillMatrix();
    cout << "Filled Matrix" << endl;

    /// Find a MST T in graph G
    tsp.findMST();
    cout << "MST created" << endl;

    /// Find a minimum weighted matching M for odd vertices in T
    tsp.perfectMatching();
    cout << "Matching completed" << endl;

    /// Loop through each index and find shortest path
    int best = INT_MAX;
    int bestIndex;
    for (long t = 0; t < tsp_size; t++) {
        int result = tsp.findBestPath(t);

        tsp.path_vals[t][0] = t; /// set start
        tsp.path_vals[t][1] = result; /// set end

        if (tsp.path_vals[t][1] < best) {
            bestIndex = tsp.path_vals[t][0];
            best = tsp.path_vals[t][1];
        }
    }

    ///Create path for best tour
    tsp.euler_tour(bestIndex,tsp.circuit);
    tsp.make_hamiltonian(tsp.circuit,tsp.pathLength);

    /*
    tsp.euler_tour(0, tsp.circuit);
    cout << "euler completed" << endl;
    tsp.make_hamiltonian(tsp.circuit, tsp.pathLength);
    cout << "ham completed" << endl;
    */

    // Store best path
    //tsp.create_tour(bestIndex);

    cout << "Final length: " << tsp.pathLength << endl;

    tsp.printPath();
    tsp.printResult();
    return 0;
}
