/**
 * 
 * DEFINITON
 * -- The procedure for deleting the root from the heap (effectively extracting the maximum element) & restoring the properties is called 
 *      -- AKA
 *          -- Down-heap
 *          -- Bubble Down
 *          -- Percolate Down
 *          -- Shift Down
 *          -- Trickle Down
 *          -- Heapify Down
 *          -- Cascade Down
 *          -- Extract Max
 * 
 * 
 * PSEUDOCODE
 * -- Swap the forst value in the values property with the last one
 * -- Pop from the values property, so you can return the value at the end.
 * -- Have the new root "Sink Down" to the correct spot.
 *      -- Your parent index starts at 0 (root).
 *      -- Find the index of the left child: (2*index)+1 (make sure it is not out of bounds)
 *      -- Find the right child index (2*index + 2) (make sure it is not out of bounds)
 *      -- If the left or right child is greater than the element swap. If both left & right children are larger, swap with the largest child.
 *      -- The child index you swapped to now become the new parent index.
 *      -- Keep looping & swapping to new becomes the new parent index.
 *  	-- Return the old root. 
 * 
 */

class MaxBinaryHeap
{
    constructor()
    {
        this.values = [];
    }

    extractMax()
    {
        const max = this.values[0];
        const end = this.values.pop();

        if(this.values.length > 0)
        {
            this.values[0] = end;
            this.sinkDown();
        }
        return max;
    }

    sinkDown()
    {
        let idx = 0;
        const element = this.values[0];
        while(true)
        {
            let left_idx = (2*idx) + 1;
            let right_idx = (2*idx) + 2;
            let left_child, right_child, swap = null;

            if(left_idx < this.values.length)
            {
                left_child = this.values[left_idx];
                if(element < left_child)
                {
                    swap = left_idx;
                }
            }

            if(right_idx < this.values.length)
            {
                right_child = this.values[right_idx];
                if((swap === null && right_child > element) || (swap !== null && right_child > left_child))
                {
                    swap = right_idx;
                }
            }

            if(swap === null)
            {
                break;
            }         
            
            this.values[idx] = this.values[swap];
            this.values[swap] = element;
            idx = swap;
        }
    }
}