/**
 * 
 * PSEUDOCODE for UNDIRECTED UNWEIGHTED GRAPH.
 * -- This function should accept a vertex to remove.
 * -- Function should loop as long as there are any other vertices in the adjacency list for that vertex.
 * -- Inside of the loop, call our removeEdge function with the vertex we are removing & any values in the adjacency list for that vertex.
 * -- Delete the key in the adjacency list for that vertex.
 * 
 */


 class Graph
 {
     constructor()
     {
         this.adjacencyList = {};
     }
 
     removeVertex(vertex)
     {
         while(this.adjacencyList[vertex].length)
         {
             const adjV = this.adjacencyList[vertex].pop();
             this.removeEdge(vertex, adjV);
         }

         delete this.adjacencyList[vertex];
     }
 }
 
 