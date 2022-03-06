/**
 * 
 * DS where each element has a priority. Elements with higher priorities are served before elements with lower priorities.
 * 
 * -- Lower Priority Number -> Higher Priority
 * 
 * -- Each node has a value and a priority. Use the priority to build the heap.
 * -- Enqueue methoeue method removes root element, d accepts a value & priority, makes a new node & puts it in the right spot based off of its priority.
 * -- Dequreturn it, & rearrange heap using priority. 
 * 
 */

class Node 
{
    constructor(value, priority)
    {
        this.val = value;
        this.priority = priority;
    }
}

class PriorityQueue
{
    constructor()
    {
        this.values = [];
    }

    insert(val, priority)
    {
        let newNode = new Node(val, priority);
        this.values.push(newNode);
        this.bubbles_up();
    }

    bubbles_up()
    {
        let idx = this.values.length - 1;
        let element = this.values[idx];
        while(idx > 0)
        {
            let pIdx = Math.floor((idx-1)/2);
            let parent = this.values[pIdx];
            
            if(element.priority <= parent.priority)
            {
                break;
            }

            this.values[pIdx] = element;
            this.values[idx] = parent;
            idx = pIdx;
        }
    }

    dequeue()
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
        const length = this.values.length;
        const element = this.values[0];
        
        while(true)
        {
            let Lidx = (2*idx) + 1;
            let Ridx = (2*idx) + 2;
            let Lchild, Rchild, swap = null;

            if(Lidx < length)
            {
                Lchild = this.values[Lidx];
                if(Lchild.priority > element.priority)
                {
                    swap = Lidx;
                }
            }
            if(Ridx < length)
            {
                Rchild = this.values[Ridx];
                if( (Rchild.priority > element.priority && swap == null) || (swap != null && Rchild.priority > Lchild.priority) )
                {
                    swap = Ridx;
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




/**
 * 
 * COMPLEXITY
 * -- Insertion -> O(log N)
 * -- Deletion -> O(log N)
 * -- Search -> O(N)
 * 
 */
