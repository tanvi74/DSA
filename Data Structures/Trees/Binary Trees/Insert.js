/**
 * 
 * PSEUDOCODE
 * -- Steps -> Iteratively or Recursively
 * -- Create a new node.
 * -- Starting at the root.
 *      -- Check if there is a root, if not the root becomes that new model.
 *      -- If there is a root, check if the value of the new Node is greater than or less than the value of the root.
 *      -- If it is greater
 *          -- Check to see if there is a node to the right 
 *              -- If there is , move to that node & repeat these steps
 *              -- If there is not, add that node as the right property.
 *      -- If it is lower
 *          -- Check to see if there is node to the left
 *              -- If there is, move to that node & repeat these steps.
 *              -- If there is not, add that node ad the left property. 
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
    
    insert(value)
    {
        var newNode = new Node(value);
        if(this.root === null)
        {
            this.root = newNode;
            return this;
        }

        var current = this.root;
        while(true)
        {
            if(current.value === value)
                return undefined;
            
            if(current.value < value)
            {
                if(current.right === null)
                {
                    current.right = newNode;
                    return this;
                }
                current = current.right;
            }
            else
            {
                if(current.left === null)
                {
                    current.left = newNode;
                    return this;
                }
                current = current.left;
            }
        }
    }
}

/**
 * COMPLEXITY
 * O(log N)
 * 
 */