/**
 * 
 * PSEUDOCODE
 * -- Create a queue ( this can be array ) & a variable to store the values of nodes visited.
 * -- Place the root node in the queue.
 * -- Loop as long as there is anything in the queue.
 *      -- Dequeue a node from the queue & push the value of the node into the variable that stores the node.
 *      -- If there is a left property on the node dequeued -> add it to the queue.
 *      -- If there is a right property on the node queueud -> add it to the queue.
 * -- Return the variable that stores the value.
 * 
 */


class Node
{
    constructor(value)
    {
        this.left = null;
        this.right = null;
        this.value = value;
    }
}

class BST
{
    constructor()
    {
        this.root = null;
    }
    
    BFS()
    {
        var node = this.root;
        var data = [];
        var queue = [];

        queue.push(this.root);

        while(queue.length)
        {
            node = queue.shift();
            data.push(node.value);
            
            if(node.left)
            {
                queue.push(node.left);
            }

            if(node.right)
            {
                queue.push(node.right);
            }
        }

        return data;
    }
}

/**
 *
 * COMPLEXITY
 * O(V) : No. of nodes
 * 
 */
