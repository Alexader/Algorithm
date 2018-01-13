#include<iostream>
#include<algorithm>
#include <queue>
#include<vector>
using namespace std;
using std::vector;
const int EMPTY = -1;
const int UNVISITED = 0;
const int VISITED = 1;
const int INFINT = 65535;
class Graph
{
protected:
	int** adjacencyList;// represent edge value
	int * vertex;// represent vertex value
	int* mark;
	int n;// node number
public:
	// return the first vertex node is connected.
	virtual int first(const int node) = 0;
	// return the first vertex after w
	virtual int next(const int node, const int w) = 0;
	virtual int size() = 0;
	virtual void setMark(int node, int mark) = 0;
	virtual int getMark(int node) = 0;
};
class ArrayGraph : public Graph
{
public:
	ArrayGraph(vector<vector<int>> matrix, int* value, const int number) {
		n = number;
		mark = new int[n];
		vertex = new int[n];
		for (int i = 0; i < n; i++) {
			mark[i] = UNVISITED;
			vertex[i] = value[i];
		}
		// number in the matrix is the weight of each edge
		adjacencyList = new int*[n];
		for (int i = 0; i<n; i++) {
			adjacencyList[i] = new int[n];
			for (int j = 0; j<n; j++)
				// copy two dimensional array into graph
				adjacencyList[i][j] = matrix[i][j];
		}
	}
	~ArrayGraph();

	int first(const int node) {
		int i;
		for (i = 0; i<n; i++)
			if (adjacencyList[node][i] != 0) return i;
		return EMPTY;
	}

	int next(const int node, const int after_node) {
		int i;
		//the next vertex of `after_node` in the vertex `node` exclude `after_node`
		for (i = after_node+1; i<n; i++)
			if (adjacencyList[node][i] != 0) return i;
		return EMPTY;
	}

	int distance(int ndStart, int ndEnd) {
		// get the distance between two nodes
		return adjacencyList[ndStart][ndEnd]==-1?INFINT:adjacencyList[ndStart][ndEnd];
	}
	void setClear() {
		for(int i=0;i<n;i++)
			mark[i] = UNVISITED;
	}
	void setMark(int node, int mk) {
		mark[node] = mk;
	}

	int getMark(int node) {
		return mark[node];
	}

	int operator[](int nodeNum) {
		return adjacencyList[nodeNum][0];
	}

	int size() { return n; }
	int getValue(int node) { return vertex[node]; }
};

void visit(ArrayGraph* graph, int node) {
	cout << "this is node " << node << " value:" << graph->getValue(node) << endl;
}

/* build a matrix for representing a graph. element K_ij in matrix is the 
* weight between vertex i and j. If they are not directly connected, its value
* is INFINIT.
*/
vector<vector<int>> buildMatrix(int* array, int iRow, int iCol) {
	auto retVec = vector<vector<int>>(iRow, vector<int>(iCol));
	for (int i = 0; i < iRow; i++) {
		for (int j = 0; j < iCol; j++)
			retVec[i][j] = array[i*iCol + j];
	}
	return retVec;
}

// /* help function for dijkstra which will find the minist value in a vector */
// int findMinVert(vector<int> distance) {
	
// }
/* find the shortest path for startNode*/
vector<int> dijkstra(ArrayGraph* g, int startNode) {
	g->setClear();// in case some vertex are visted
	vector<int> distance;
	for(int i=0;i<g->size();i++)
		// init distance vector with graph
		distance.push_back(g->distance(startNode, i));
	for(int i=0;i<g->size();i++) {
		int v;
		vector<int>::iterator min;
		min = min_element(distance.begin(), distance.end());
		if(*min==INFINT) return distance; // vertex unreachable
		g->setMark(min-distance.begin(), VISITED);
		for(v=g->first(min-distance.begin());v!=EMPTY;v=g->next(min-distance.begin(), v)) {
			if(g->getMark(v)==UNVISITED && distance.at(v)>(*min + g->distance(min-distance.begin(), v)))
				distance.at(v) = *min + g->distance(min-distance.begin(), v);// update distance vector
		}
	}
	return distance;
}
int main()
{
	int array[] = { 0, 3, 6, -1,
									3, 0, 4, -1,
									6, 4, 0, 7,
									-1, -1, 7, 0 };
	auto matrix = buildMatrix(array, 4, 4);
	int value[4] = { 3, 5, 9, 8 };
	ArrayGraph* graph = new ArrayGraph(matrix, value, 4);
	vector<int> dis = dijkstra(graph, 0);
	cout<<dis.size()<<endl;
	for(int i=0;i<graph->size();i++)
		cout<<"shortest path from vertex 0 to "<<i<<" is "<<dis[i]<<endl;
	cout<<"it is over now"<<endl;
	return 0;
}
