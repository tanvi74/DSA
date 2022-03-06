/**
 * 
 * PSEUDOCODE
 * -- DFS (vertex):
 *      if vertex is empty:
 *          return (this is base case)
 *      add vertex to results list
 *      mark vertex as visited
 *      for each neighbour in vertex's neighbours:
 *          if neighbour is not visited:
 *              recursively calls DFS on neighbour
 * 
 * 
 * --> The function that accepts a starting node.
 * --> Create a list to store the end result, to be returned at the very end.
 * --> Create a object to store visited vertices.
 * --> Create a helper function which accepts a vertex.
 *          --> The helper function should return early of the vertex is empty.
 *          --> The helper function should place the vertex it accepts into the visited object & push that vertex intot he result array.
 *          --> Loop over the values in the adjacency list for that vertex.
 *          --> If any of those values have not been visited, recursively invoke the helper function with that vertex.
 * --> Invoke the helper function with starting Vertex 
 * --> Return result array.
 * 
 * 
 */


 class Graph
 {
     constructor()
     {
         this.adjacencyList = {};
     }

     DFS(startNode)
     {
        let result = [];
        let visited = [];
        let adjacencyList = this.adjacencyList;
        
        (
            function(vertex)
            {
                if(!vertex)
                {
                    return null;
                }

                visited[vertex] = true;
                result.push(vertex);
                adjacencyList[vertex].forEach(neighbour => 
                    {
                        if(!visited[neighbour])
                        {
                            return dfs(neighbour);
                        }
                    });
            }
        )(startNode);

        return result;

     }
}
