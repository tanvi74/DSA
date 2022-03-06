/**
 * -- DS that contains a head, tail and length property.
 * -- LL contains nodes & each node has a value& a pointer to another node or null.
 *                         List        |           v/s             |       Array
 *                 --------------------|---------------------------|---------------------
 *                 No indexes          |                           |  Indexed in order
 *          Connected via nodes with a |                           |  Insertion & Deletion  can be expensive
 *                  next pointer
 *        Random access is not allowed |                           |  Can quickly be accessed at specific index
 * 
 * 
 * MERITS 
 * -- SLL are excellent alternative to arrays when insertion & deletion at the beginning are frequently required.
 * -- Arrays contain a built in index wheras LL do not.
 * -- The indea of a list DS that consists of nodes is the foundation for other DS like Stacks and Queues.
 * 
 * 
 * COMPLEXITIES
 * -- Insertion - O(1)
 * -- Removal - O(1) to O(N)
 * -- Searching - O(N)
 * -- Accessing - O(N)
 * 
 * 
 */

