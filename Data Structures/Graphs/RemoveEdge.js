/**
 * 
 * PSEUDOCODE for UNDIRECTED UNWEIGHTED GRAPH.
 * -- This function should accepts 2 vertices, we can call them vertex1, vertex2.
 * -- The function should reassign the key of vertex1 to be an array that does not contain vertex2.
 * -- The function should reassign the key of vertex2 to be an array that does not contain vertex1.
 * -- Don't worry about handling errors/invalid vertices.
 * 
 */


 class Graph
 {
     constructor()
     {
         this.adjacencyList = {};
     }
 
     removeEdge(vertex1, vertex2)
     {
         this.adjacencyList[vertex1] = this.adjacencyList[vertex1].filter(v => v !== vertex2);
         this.adjacencyList[vertex2] = this.adjacencyList[vertex2].filter(v => v !== vertex1);
     }
 }
 
 