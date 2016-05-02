# Dijikstra's Algorithm

This is my implementation of Dijkstra's algorithm, using an undirected, weighted graph.
In this implementation, Dijkstra's algorithm is implemented as a function member of the graph class.

The following assumptions are made:
 
	1) All vertices are unique (i.e. no duplicates).
	2) Weights are non-negative double values. The algorithm will fail if given negative weight values.
 
Once Dijkstra is executed on a given vertex (origin), all other vertices are updated to hold their
current 'travel' cost with respect to the origin vertex. The cost any node node `p` is then easily retrivable via a simple
function call. It is also possible to print the path from the origin to any node `p`.

Input Files:
============
An input file should represent a graph in the following manner:

	5
	1 2 0.2 4 10.1 5 0.5
	2 1 1.5
	3 2 100.0 4 50.2
	4 
	5 2 10.5 3 13.9

The first line states the number of nodes `n` (`n` = 5 nodes in this example; `Graph1.txt`)
Note: In my current implementation, this number is not used and I plan on fixing
my parser not requier n to be stated in the input file.

The next `n` lines represent a node in the following manner:

	<Node1> <Neighbor1> <Weight(Node1, Neighbor1)> ... <Neighbor-k> <Weight(Node1, Neighbor-k)>
	.
	.
	.
	<Node-n> <Neighbor1> <Weight(Node-n, Neighbor1)> ... <Neighbor-k> <Weight(Node-n, Neighbor-k)>

So, in the given example:
node 1 is connected to node 2 with a cost of 0.2
node 1 is connected to node 4 with a cost of 10.1
node 1 is connected to node 5 with a cost of 0.5
node 2 is connected to node 1 with a cost of 1.5
etc.

Query Files:
============
A query file check to see if an edge exists between node i and j.
The format of a query file is simply pair of integers representing the nodes.
For example, query file `AdjacencyQueries1.txt`

	4 1
	3 4
	1 5
	5 1
	1 3

contains five queries and check to see if an edge exists between node 4 and node 1, 3 and 4, 1 and 5, etc.
Remember, this is an undirected graph. Then it doesn't necessarily mean that if an edge exists between node 4 and node 1,
one will exist between node 1 and node 4.


Compilation:
============

`make all` - To compile all sections.

Run:
====
1) `make testGraph ARGS="<GRAPH_INPUT> <GRAPH_QUERY>"` - To test the graph with an input file and a query file.

	e.g. `make testGraph ARGS="Graph1.txt AdjacencyQueries1.txt"`
	to build a graph with Graph1.txt as an input, and query it using AdjacencyQueries1.txt.

2) `make findPath ARGS="<GRAPH_INPUT> <ORIGIN_VERTEX>"` - To run Dijkstra's algorithm over a graph from an input file, using
	ORIGIN_VERTEX as the starting vertex.

	e.g. `make findPath ARGS="Graph2.txt 1"`
	to build a graph with Graph2.txt as an input, and find all the shortest paths from 1
	to the other vertices.

NOTE: ARGS' default value is: "Graph1.txt AdjacencyQueries1.txt"

Clean Up:
=========
`make clean` - To remove all `*.o` and executable files.
