//1.학번 201524582
//2.이름 정희석(Jeong Hee Seok)
//3.다음 코드를 사용하여 Sollin’s minimal spanning tree 구현
//	A.Minheap를 사용해야 함
//	B.Class set를 사용해야 함//union, find를 사용한다
//	C.아래 주어진 코드를 사용해야 함 - 가져온 코드는 0점 처리함

// min heap, set 사용하여 MST 구현
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
const int HeapSize = 100;

enum Boolean { FALSE, TRUE };

template <class Type>
class Element {
public:
	Type key;
};
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//
//Minimum Heap// Priority Queue//
template <class Type>
class MinPQ {
public:
	virtual void Insert(const Element<Type>&) = 0;
	virtual Element<Type>* DeleteMax(Element<Type>&) = 0;
};

template <class Type>
class MinHeap : public MinPQ<Type> {
public:
	MinHeap(int sz = HeapSize) {
		if (sz < 1) throw "Capacity must be over 1";
		MaxSize = sz; n = 0;
		heap = new Element<Type>[MaxSize + 1]; // Don't want to use heap[0]
	}
	void display();
	void Insert(const Element<Type>& x);
	Element<Type> *DeleteMin(Element<Type>&);
private:
	Element<Type> *heap;
	int n; // current size of MaxHeap
	int MaxSize; // Maximum allowable size of MinHeap

	void HeapEmpty() { cout << "Heap Empty" << "\n"; };
	void HeapFull() { cout << "Heap Full"; };
};

template <class Type>
void MinHeap<Type>::display()
{
	int i;
	cout << "MinHeap:: (i, heap[i].key): ";
	for (i = 1; i <= n; i++) cout << "(" << i << ", " << heap[i].key << ") ";
	cout << "\n";
}

template <class Type>
void MinHeap<Type>::Insert(const Element<Type>& x)
{
	int count = 0;
	if (n == MaxSize) { HeapFull(); return; }
	heap[n] = x;
	n++;
	for (Element<Type> *temp : heap) {

	}
}
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//
template <class Type>
Element<Type>* MinHeap<Type>::DeleteMin(Element<Type>& x)
{
	int i, j;
	if (!n) { HeapEmpty(); return 0; }
	x = heap[1]; Element<Type> k = heap[n]; n--;

	for (i = 1, j = 2; j <= n; )
	{
		if (j < n) if (heap[j].key < heap[j + 1].key) j++;
		// j points to the larger child
		if (k.key >= heap[j].key) break;
		heap[i] = heap[j];
		i = j; j *= 2;
	}
	heap[i] = k;
	return &x;
}

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//
/*
//Need To change to MinPQ//
template <class Type>
class MaxPQ {
public:
	virtual void Insert(const Element<Type>&) = 0;
	virtual Element<Type>* DeleteMax(Element<Type>&) = 0;

};

template <class Type>
class MaxHeap : public MaxPQ<Type> {
public:
	MaxHeap(int sz = HeapSize)
	{
		MaxSize = sz; n = 0;
		heap = new Element<Type>[MaxSize + 1]; // Don't want to use heap[0]
	};
	void display();
	void Insert(const Element<Type>& x);
	Element<Type> *DeleteMax(Element<Type>&);
private:
	Element<Type> *heap;
	int n; // current size of MaxHeap
	int MaxSize; // Maximum allowable size of MaxHeap

	void HeapEmpty() { cout << "Heap Empty" << "\n"; };
	void HeapFull() { cout << "Heap Full"; };
};

template <class Type>
void MaxHeap<Type>::display()
{
	int i;
	cout << "MaxHeap:: (i, heap[i].key): ";
	for (i = 1; i <= n; i++) cout << "(" << i << ", " << heap[i].key << ") ";
	cout << "\n";
}

template <class Type>
void MaxHeap<Type>::Insert(const Element<Type>& x)
{
	int i;
	if (n == MaxSize) { HeapFull(); return; }
	n++;
	for (i = n; 1; ) {
		if (i == 1) break; // at root
		if (x.key <= heap[i / 2].key) break;
		// move from parent to i
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = x;
}

template <class Type>
Element<Type>* MaxHeap<Type>::DeleteMax(Element<Type>& x)
{
	int i, j;
	if (!n) { HeapEmpty(); return 0; }
	x = heap[1]; Element<Type> k = heap[n]; n--;

	for (i = 1, j = 2; j <= n; )
	{
		if (j < n) if (heap[j].key < heap[j + 1].key) j++;
		// j points to the larger child
		if (k.key >= heap[j].key) break;
		heap[i] = heap[j];
		i = j; j *= 2;
	}
	heap[i] = k;
	return &x;
}

*/
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//
class Sets {
public:
	Sets(int);
	void display();
	void SimpleUnion(int, int);
	int SimpleFind(int);
	void WeightedUnion(int, int);
	int CollapsingFind(int);
private:
	int *parent;
	int n;
};

Sets::Sets(int sz = HeapSize)
{
	n = sz;
	parent = new int[sz + 1]; // Don't want to use parent[0]
	for (int i = 1; i <= n; i++) parent[i] = -1;  // 0 for Simple versions
}

void Sets::SimpleUnion(int i, int j)
// Replace the disjoint sets with roots i and j, i != j with their union
{
	parent[j] = i;
}

int Sets::SimpleFind(int i)
// Find the root of the tree containing element i
{
	while (parent[i] > 0) i = parent[i];
	return i;
}

void Sets::WeightedUnion(int i, int j)
// Union sets with roots i and j, i != j, using the weighting rule.
// parent[i]~=~-count[i] and parent[i]~=~-count[i].
{
	int temp = parent[i] + parent[j];
	if (parent[i] > parent[j]) { // i has fewer nodes
		parent[i] = j;
		parent[j] = temp;
	}
	else { // j has fewer nodes
		parent[j] = i;
		parent[i] = temp;
	}
}

int Sets::CollapsingFind(int i)
// Find the root of the tree containing element i.
// Use the collapsing rule to collapse all nodes from @i@ to the root
{
	int r;
	for (r = i; parent[r] > 0; r = parent[r]); // find root
	while (i != r) {
		int s = parent[i];
		parent[i] = r;
		i = s;
	}
	return r;
}



void Sets::display()
{
	cout << "display:index= ";
	for (int i = 1; i <= n; i++) cout << " " << i;
	cout << "\n";
	cout << "display: value= ";
	for (int i = 1; i <= n; i++) cout << " " << parent[i];
	cout << "\n";
}

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//

// a structure to represent a weighted edge in graph
struct Edge
{
	int src, dest, weight;
};

// a structure to represent a connected, undirected and weighted graph
struct Graph
{
	// V-> Number of vertices, E-> Number of edges
	int V, E;

	// graph is represented as an array of edges. Since the graph is
	// undirected, the edge from src to dest is also edge from dest
	// to src. Both are counted as 1 edge here.
	struct Edge* edge;
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) 
{
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph)); 
	graph->V = V;
	graph->E = E;

	graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));

	return graph;
}
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//

// A structure to represent a subset for union-find
struct subset
{
int parent;
int rank;
};

// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i) //작성해야함//
{
	return 0;
}

// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], int x, int y)//작성해야함
{

}

// Compare two edges according to their weights.
// Used in qsort() for sorting an array of edges
int myComp(const void* a, const void* b)
{
struct Edge* a1 = (struct Edge*)a;
struct Edge* b1 = (struct Edge*)b;
return a1->weight > b1->weight;
}

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//
// The main function to construct MST using Sollin's algorithm
void SollinMST(struct Graph* graph) {

}


//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//
//Not Touch//
// The main function to construct MST using Kruskal's algorithm
void KruskalMST(struct Graph* graph)
{
	int V = graph->V;
	struct Edge result[20];  // Tnis will store the resultant MST
	int e = 0;  // An index variable, used for result[]
	int i = 0;  // An index variable, used for sorted edges

				// Step 1:  Sort all the edges in non-decreasing order of their weight
				// If we are not allowed to change the given graph, we can create a copy of
				// array of edges
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

	// Allocate memory for creating V subsets
	struct subset *subsets =
		(struct subset*) malloc(V * sizeof(struct subset));

	// Create V subsets with single elements
	for (int v = 0; v < V; ++v)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	// Number of edges to be taken is equal to V-1
	while (e < V - 1)
	{
		// Step 2: Pick the smallest edge. And increment the index
		// for next iteration
		struct Edge next_edge = graph->edge[i++];

		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);

		// If including this edge does't cause cycle, include it
		// in result and increment the index of result for next edge
		if (x != y)
		{
			result[e++] = next_edge;
			Union(subsets, x, y);
		}
		// Else discard the next_edge
	}

	// print the contents of result[] to display the built MST
	printf("Following are the edges in the constructed MST\n");
	for (i = 0; i < e; ++i)
		printf("%d -- %d == %d\n", result[i].src, result[i].dest,
			result[i].weight);
	return;
}

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//
// Driver program to test above functions
//Modified//
int main(void)
{
	/* Let us create following weighted graph
	int V = 4;  // Number of vertices in graph
	int E = 5;  // Number of edges in graph
	struct Graph* graph = createGraph(V, E);
	*/// 아래 코드로 교체

	//Graph 생성, spanningTree생성//
	
	int V;
	//int E = 0;  // Number of edges in graph
	//struct Graph* g = createGraph(V, E);
	int select ;
	int start, end, weight;
	cout << "Input Number of Vertex : ";
	cin >> V;
	do
	{
		cout << "\nSelect command 1: Add edges and Weight, 2: Display Adjacency Lists, 3: spanningTree, 4: Quit => ";
		cin >> select;
		switch (select) {
			case 1:
				cout << "Add an edge: " << endl;
				cout << "--------Input start node: ";
				cin >> start;
				cout << "--------Input  destination  node: ";
				cin >> end;
				if (start < 0 || start >= V || end < 0 || end >= V) {
					cout << "the input node is out of bound." << endl;
				break;
				}
				cout << "--------Input  weight: ";
				cin >> weight;
				//g->E = E++;
				//g.InsertVertex(start, end, weight); //need to make
				break;
			case 2:
			//display
				//g.displayAdjacencyLists(); //need to modify
				break;
			case 3:
				cout << "\nSpanningTree - Sollin's algorithm: " << endl;
				//SollinMST(g); //need to make
				/*
				cout << "\nSpanningTree - Prim's algorithm: " << endl;
				spanningTree = g.spanningTree_PrimAlgorithm();
				if (spanningTree) {
					spanningTree->displayAdjacencyLists();
				}
				*/
				/*
				cout << "\nSpanningTree - Kruskal's algorithm: " << endl;
				spanningTree = g.spanningTree_KruskalAlgorithm();
				if (spanningTree) {
				spanningTree->displayAdjacencyLists();
				}
				*/
				
			break;
			case 4:
				exit(0);
				break;
			default:
				cout << "WRONG INPUT  " << endl;
				cout << "Re-Enter" << endl;
				break;
			}	
		} while (select != '0');
	system("pause");
	return 0;
}

