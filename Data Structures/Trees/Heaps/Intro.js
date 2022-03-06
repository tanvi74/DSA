/**
 * 
 * BINARY HEAPS
 * -- Very much similar to BST, with some different rules
 * 
 *      TYPES OF BINARY HEAPS
 *          -- Max Binary Heaps {Parent is always greater than its children}
 *          -- Min Binary Heaps {Parent is always smaller than its children}
 * 
 *      IMPLEMENTATION
 *          -- Will be using List/Array
 * 
 * e.g.                         100
 *                              /  \
 *                             19    36
 *                            /  \   / \
 *                          17   12 25  5 
 * 
 *                      [100,19,36,17,12,25,5]
 * 
 * STAR POINTS
 * -- Children for any index "N" 
 *      -- 2*N + 1 -> Left Child
 *      -- 2*N + 2 -> Right Child
 * 
 * -- Parents for any index "N"
 *      -- Math.floor((N-1)/2)
 * 
 * -- Binary heaps are very useful DS for sorting & implementing DS for Priority Queue.\
 * -- Mainly used because of Insertion and Deletion technique.
 * 
 * COMPLEXITY
 * -- Insertion -> O(log N)
 * -- Deletion -> O(log N)
 * -- Search -> O(N)
 * 
 */