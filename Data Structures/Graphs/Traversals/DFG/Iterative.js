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
        const result = [];
        let stack = [startNode];
        let visited = {};

        visited[startNode] = true;

        while(stack.length)
        {
            let currentVertex = stack.pop();
            result.push(currentVertex);
            this.adjacencyList[currentVertex].forEach(neighbour => 
                {
                    if(!visited[neighbour])
                    {
                        visited[neighbour] = true;
                        stack.push(neighbour);
                    }
                });
        }

        return result;
     }
}
