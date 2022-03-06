/**
 * 
 * PSEUDOCODE
 * -- Function should accept a value.
 * -- Create a new Node with that value.
 * -- If there are no nodes in the stack, set the first & last property to be the created node.
 * -- If there is at least one node, create a variable that stores the current first property on that stack.
 * -- Reset the first property to be the newly created node.
 * -- Set the next property on the node to be the previously created variable.
 * -- Increment the size of the stack by 1. 
 * 
 */

class Node
{
    constructor(val)
    {
        this.value = val;
        this.next = null;
    }
}

class Stack
{
    constructor()
    {
        this.first = null;
        this.last = null;
        this.size = null;
    }

    push(val)
    {
        var newNode = new Node(val);
        if(!this.first)
        {
            this.first = newNode;
            this.last = newNode;
        }
        else
        {
            var temp = this.first;
            this.first = newNode;
            this.first.next = temp;
        }

        return ++this.size;
    }
}

/**
 * COMPLEXITY 
 * O(1)
 */