/**
 * 
 * -- A graph DS consists of a finite (and possibly mutabl{changable}) set of vertices or nodes or points, together with a set of unordered pairs of these vertices for an undefined graph or a set of ordered pairs for a directed graph.
 * 
 * USES OF GRAPHS
 * -- Social Networks
 * -- Location / Mapping
 * -- Routing Algorithms
 * -- Visual Hierarchy
 * -- File System Organizations
 * -- Almost Everywhere
 * 
 * 
 * TERMINOLOGY
 * -- Vertex -> Node
 * -- Edge -> Connection Between Nodes
 * -- Weighted / Unweighted -> Values assigned to distances
 * -- Directed / Undirected -> Direction Assigned to distance between vertices
 * 
 * 
 * TYPES OF GRAPHS
 *      -- Undirected Graph
 *      -- Directed Graph
 *      -- Weighted Graph
 *      -- Unweighted Graph
 * 
 * WAYS OF REPRESENTING GRAPH
 *      -- Adjacency Matrix
 *              --> Takes up more space(in sparse graphs).
 *              --> Slower to iterate over all edges.
 *              --> Faster to lookup specific edge.
 *      -- Adjacency List
 *              --> Takes up less space (in sparse graphs).
 *              --> Faster to iterate over all edges.
 *              --> Can be slower to lookup specific edge.
 *              --> Are used mostly in daily practices. 
 *   
 * 
 * e.g. 
 *                              A
 *                             / \
 *                            F   B
 *                            |   |
 *                            E   C
 *                             \ /
 *                              D
 * 
 * 
 * -- > Adjacency Matrix Representation
 *  
 *      | A | B | C | D | E | F
 *    A | 0 | 1 | 0 | 0 | 0 | 1
 *    B | 1 | 0 | 1 | 0 | 0 | 0
 *    C | 0 | 1 | 0 | 1 | 0 | 0 
 *    D | 0 | 0 | 1 | 0 | 1 | 0 
 *    E | 0 | 0 | 0 | 1 | 0 | 1 
 *    F | 1 | 0 | 0 | 0 | 1 | 0
 * 
 * -- > Adjacency List Representation
 * 
 *      [ [1,5], [0,2], [1,3], [2,4], [3,5], [4,0] ]
 *          A      B      C      D      E      F
 * 
 * --> Hash Tables Representation
 * 
 *  { 
 *      A: ["B", "F"],
 *      B: ["A", "C"],
 *      C: ["B", "D"],
 *      D: ["C", "E"],
 *      E: ["D", "F"],
 *      F: ["A", "E"]
 *  }
 * 
 * 
 * COMPLEXITY
 * 
 *      OPERATION     |        ADJACENCY LIST       |      ADJACENCY MATRIX
 *                    |                             |
 *      Add Vertex    |        O(1)                 |           O(V^2)
 *      Add Edge      |        O(1)                 |   	    O(1)
 *      Remove Vertex |      O(|V| + |E|)           |           O(V^2)
 *      Remove Edge   |        O(|E|)               |           O(1)
 *      Query         |      O(|V| + |E|)           |           O(1)
 *      Storage       |      O(|V| + |E|)   	    |           O(V^2)
 * 
 * 
 */
