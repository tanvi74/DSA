/**
 * 
 * PSEUDOCODE for UNDIRECTED UNWEIGHTED GRAPH.
 * -- This function should accepts 2 vertices, we can call them vertex1, vertex2.
 * -- The function should find in the adjacency list the key of vertex1 and push vertex2 to the array.
 * -- The function should find in the adjacency list the key of vertex2 & push vertex1 to the array.
 * -- Don't worry about handling errors/invalid vertices.
 * 
 */


 class Graph
 {
     constructor()
     {
         this.adjacencyList = {};
     }
 
     addEdge(vertex1, vertex2)
     {
         this.adjacencyList[v1].push(v2);
         this.adjacencyList[v2].push(v1);
     }
 }
 
 