/**
 * 
 * PSEUDOCODE
 * -- Create a variable to store the values of nodes visited.
 * -- Store the root of the BST in a variable called current.
 * -- Write a helper function which accepts a node.
 *      -- If the node has a left property, call the helper function with the left property on the node.
 *      -- Push the value of the node to the variable that stores the values.
 *      -- If the node has a right property, call the helper function with the right property on the node.
 * -- Invoke the helper function with the current variable
 * -- Return the Array of values.
 * 
 * e.g.                                         10
 *                                             /  \
 *                                            6    15
 *                                           / \     \
 *                                          3   8     20
 * 
 *          Left,Node,Right                [3,6,8,10,15,20]
 * 
 * 
 * -- It will come up in aescending order
 * -- It will take more space.
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

class DFS
{
    constructor()
    {
        this.root = null;
    }
    
    DFS_Inorder()
    {
        var data = [];
        var current = this.root;

        function traverse(node)
        {
            if(node.left)
            {
                traverse(node.left);
            }
            data.push(node.value);
            if(node.right)
            {
                traverse(node.right)
            }
        }

        traverse(current);
        return data;
    }
}


/**
 *
 * COMPLEXITY
 * O(V) : No. of nodes
 * 
 */

