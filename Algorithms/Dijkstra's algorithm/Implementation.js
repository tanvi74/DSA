/**
 * 
 * PSEUDOCODE
 * -- This function should accept a starting and ending vertex.
 * -- Create an object (we will call it distances) & set each key to be every vertex in the adjacency list with a value of infinity, except for the starting vertex which should have a value of zero.
 * -- After setting a value in the distances object, add each vertex with a priority of infinity to the priority queue, except the starting vertex, which should have a priority of zero because that's where we begin.
 * -- Create another object called previous and set each key to be every vertex in the adjacency list with a value of null.
 * -- Start looking as long as there is anything in the priority queue.
 *      -- Dequeue a vertex from the priority queue.
 *      -- If that vertex is the same as the ending vertex -> we are done.
 *      -- Otherwise loop through each value in the adjacency list at that vertex.
 *              -- Calculate the distance to that vertex from the starting vertex.
 *              -- If the distance is less than what is currently stored in our distances object.
 *                      -- Update the distances object with new lower distance.
 *                      -- Update the previous object to contain that vertex.
 *                      -- Enqueue the vertex with the total distance from the starting node.
 *   
 * 
 */


class WeightedGraph
{
    constructor()
    {
        this.adjacencyList = {};
    }

    addVertex(vertex)
    {
        if(!this.adjacencyList[vertex])
        {
            this.adjacencyList[vertex] = {};
        }
    }

    addEdge(vertex1, vertex2, weight)
    {
        this.adjacencyList[vertex1].push({node: vertex2, weight});
        this.adjacencyList[vertex2].push({node: vertex1, weight});
    }

    Dijkstra(start, finish)
    {
        const nodes = new PriorityQueue();
        const distances = {};
        const previous = {};
        let smallest;
        let path = [];

        //build up initial state
        for(let vertex in this.adjacencyList)
        {
            if(vertex == start)
            {
                distances[vertex] = 0;
                nodes.enqueue(vertex,0);
            }
            else
            {
                distances[vertex] = Infinity;
                nodes.enqueue(vertex, Infinity);
            }

            previous[vertex] = null;
        }

        while(nodes.values.length)
        {
            smallest = nodes.dequeue().val;
            if(smallest === finish)
            {
                // We are done
                // Build up path to return at end.
                while(previous[smallest])
                {
                    path.push(smallest);
                    smallest = previous[smallest];
                }

                break;
            }
            
            if(smallest || distances[smallest] !== Infinity)
            {
                for(let neighbour in this.adjacencyList[smallest])
                {
                    // Find Neighbouring node
                    let nextNode = this.adjacencyList[smallest][neighbour];

                    // Calculate new distance to neighbouring node
                    let candidate = distances[smallest] + nextNode.weight;
                    
                    let nextNeighbour = nextNode.node;
                    if(candidate < distances[nextNeighbour])
                    {
                        // Updating new smallest distance to neighbour
                        distances[nextNeighbour] = candidate;
                        
                        // Updating previous -> How we got to neighbour
                        previous[nextNeighbour] = smallest;

                        // Enqueue in Priority Queue with new Priority
                        nodes.enqueue(nextNeighbour,  candidate); 
                    }
                }
            }
        }

        return path.concat(smallest).reverse();
    }
}
