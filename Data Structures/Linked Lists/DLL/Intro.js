/**
 * -- DS that contains a head, tail and length property.
 * -- DLL are almost identical to SLL except there is an extra pointer to previous node.
 * -- e.g. Next & Previous options on the browser.
 * -- Better than SLL for finding nodes & can be done in half time.
 * -- However, they do take up more memory considering extra pointer.
 * -- LL contains nodes & each node has a value& a pointer to another node or null.
 *                         List        |           v/s             |       Array
 *                 --------------------|---------------------------|---------------------
 *                 No indexes          |                           |  Indexed in order
 *          Connected via nodes with a |                           |  Insertion & Deletion  can be expensive
 *                  next pointer
 *        Random access is not allowed |                           |  Can quickly be accessed at specific index
 * 
 * 
 *  * MERITS 
 * -- SLL are excellent alternative to arrays when insertion & deletion at the beginning are frequently required.
 * -- Arrays contain a built in index wheras LL do not.
 * -- The indea of a list DS that consists of nodes is the foundation for other DS like Stacks and Queues.
 * 
 * 
 * DEMERIT 
 * -- More Memory required in DLL, therefore trade-off.
 * 
 *  
 * 
 * COMPLEXITIES
 * -- Insertion - O(1)
 * -- Removal - O(1)
 * -- Searching - O(N)  Technically O(N/2)
 * -- Accessing - O(N)  Technically O(N/2)
 * 
 */

