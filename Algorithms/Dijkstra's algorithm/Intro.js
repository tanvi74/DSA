/**
 * 
 * -- Implement a Weighted Graph.
 * -- Implement Dijkstra's uaing a naive Priority Queue.
 * -- Implement Dijkstra's uaing a binary Heap Priority Queue.
 * -- Find the shortest Path in Graph.
 * 
 * 
 * USEFUL CASES
 * -- GPS -> Finding Fastest Route.
 * -- Network Routing -> Find open shortest path for data.
 * -- Biology -> Used to model the spread of viruses among Humans.
 * -- Airline Tickets -> Finding Cheapest Route to your Destination
 * -- Biology -> Used to model the spread of viruses among humans.
 * 
 * 
 * STEPS
 * -- Everytime we look to visit a new node, we pick the node with the smallest known distance to visit first.
 * -- Once we moved to the node we are going to visit, we look at each of its neighbours.
 * -- For each neighbouring node, we calculate the distance by summing the total edges that lead to the node we are checking from the starting node.
 * -- If the new total Distance to a node is less than the previous total, we store the new shortest distance for that node.
 * 
 * 
 */