/**
 * 
 * PSEUDOCODE
 * -- Write a method called addVertex, which accepts a name of a vertex.
 * -- It should add a key to the adjacency list with the name of the vertex & sets its value to be an empty array.
 * 
 */


class Graph
{
    constructor()
    {
        this.adjacencyList = {};
    }

    addVertex(vertex)
    {
        if(!this.adjacencyList[vertex])
        {
            this.adjacencyList[vertex] = [];
        }
    }
}

