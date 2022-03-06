/**
 * 
 * PSEUDOCODE
 * -- Push the value intot he values property on the heap.
 * -- Bubble the value up to its correct spot.
 * -- Bubble up
 *      -- Create a variable called index which is the length of the values property - 1.
 *      -- Create a variable called parentIndex which is the floor of (index-1)/2
 *      -- Keep looping as long as the values element at the parent index is greater than the values element at the child index.
 *          -- Swap the value of the values element at the parent index with the value of the element property at the child index.
 *          -- Set the index to the parent index and start over.
 * 
 */


class MinBinaryHeap
{
    constructor()
    {
        this.values = [];
    }

    insert(value)
    {
        this.values.push(value);
        this.bubbleUp();
    }

    bubbleUp()
    {
        let idx = this.values.length - 1;
        const element = this.values[idx];
        while(idx > 0)
        {
            let pIdx = Math.floor((idx-1)/2);
            let parent = this.values[pIdx];
            
            if(element >= parent)
            {
                break;
            }

            this.values[pIdx] = element;
            this.values[idx] = parent;
            idx = pIdx;
        }
    }
}