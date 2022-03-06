/**
 * 
 * -- A Node can have atmost 2 children.
 * 
 *                                                  N1
 *                                                /    \
 *                                              N2       N3
 *                                             /  \     /  \
 *                                            N4   N5  N6   N7
 * 
 * 
 * 
 * BINARY SEARCH TREES
 * -- Every Node to the left of a parent node is always less than parent.
 * -- Every Node to the right of a parent node is always greater than the parent.
 * 
 * 
 * COMPLEXITIES
 * -- Insertion -> O(log N) for Best/Avg Case
 * -- Searching -> O(log N) for Best/Avg Case
 * -- For Worst Case -> O(N)
 * 
 * Worst Case Example -> As number of nodes grow, number of comparisons will also grow 
 * N1
 *  \
 *   N2
 *    \
 *     N3
 *      \
 *      N4
 *       \
 *        N5
 * 
 * 
 *                                       
 */