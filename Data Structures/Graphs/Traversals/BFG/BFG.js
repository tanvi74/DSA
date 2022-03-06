/**
 * 
 * PSEUDOCODE
 * -- This function should accept a starting vertex.
 * -- Create a queue (you can use an array) & place the start vertex in it.
 * -- Create an array to store the nodes visited.
 * -- Create an abject to store nodes visited.
 * -- Mark the starting vertex as visited.
 * -- Loop as long as there is anything in the queue.
 * -- Remove the first vertex from the queue & push it into the array that stores nodes visited.
 * -- Loop over each vertex in the adjacency list for the vertex you are visiting.
 * -- If it is not inside the object that stores nodes visited, mark it as visited & enqueue that vertex.
 * -- Once you have finished looping, return the array of visited nodes.
 * 
 */

 class Graph
 {
     constructor()
     {
         this.adjacencyList = {};
     }

     BFS(start)
     {
         const queue = [start];
         const result = [];
         const visited = {};

         let currentVertex;
         visited[start] = true;

         while(queue.length)
         {
             currentVertex = queue.shift();
             result.push(currentVertex);
             this.adjacencyList[currentVertex].forEach(neighbour => 
                {
                    if(!visited[neighbour])
                    {
                        visited[neighbour] = true;
                        queue.push(neighbour);
                    }
                });
         }

         return result;
     }

}