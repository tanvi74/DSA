/**
 * 
 * PSEUDOCODE
 * -- Create a variable to store the values of nodes visited.
 * -- Store the root of the BST in a variable called current.
 * -- Write a helper function which accepts a node.
 *      -- Push the value of the node to the variable that stores the values.
 *      -- If the node has a left property, call the helper function with the left property on the node.
 *      -- If the node has a right property, call the helper function with the right property on the node.
 * -- Invoke the helper function with the current variable
 * -- Return the Array of values.
 * 
 * 
 * 
 * e.g.                                         10
 *                                             /  \
 *                                            6    15
 *                                           / \     \
 *                                          3   8     20
 * 
 *          Node,Left,Right                [10,6,3,8,15,20]
 * 
 * -- It will take more space.
 * -- Preorder will be used to "export" a tree as it is easy to reconstruct or copied. 
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
    
    DFS_Preorder()
    {
        var data = [];
        var current = this.root;

        function traverse(node)
        {
            data.push(node.value);
            if(node.left)
            {
                traverse(node.left);
            }
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