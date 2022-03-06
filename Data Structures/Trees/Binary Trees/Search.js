/**
 * 
 * PSEUDOCODE
 * -- Starting at the root.
 *      -- Check if there is a root, if not we are done with searching.
 *      -- If there is a root, check if the value of the new Node is the value we are looking for. If we found it, we're done.
 *  	-- If not, check to see if the value is greater than or less than the value of the root.
 *      -- If it is greater
 *          -- Check to see if there is a node to the right 
 *              -- If there is , move to that node & repeat these steps
 *              -- If there is not, we are done with searching.
 *      -- If it is lower
 *          -- Check to see if there is node to the left
 *              -- If there is, move to that node & repeat these steps.
 *              -- If there is not, we are done with searching.
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
    
    contains(value)
    {
        if(this.root === null)
        {
            return false;
        }

        var current = this.root;
        var found = false;

        while(current && !found)
        {
            if(value < current.value)
            {
                current = current.left;
            }
            else if(value > current.right)
            {
                current = current.right;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
}

/**
 * COMPLEXITY
 * O(log N)
 * 
 */
