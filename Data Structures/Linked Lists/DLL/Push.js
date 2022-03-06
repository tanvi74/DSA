/**
 * PSEUDOCODE
 * 
 * -- This function is used for adding a node at the end of the linked list.
 * -- This function should accept a value.
 * -- Create a new Node using the value passed to the function.
 * -- If the head property is null set the head & tail to be the newly created node.
 * -- If not, set the next property on the tail to be that node.
 * -- Set the previous property ont he newly created node to be the tail.
 * -- Set the tail to be the newly created node.
 * -- Increment the length.
 * -- Return doubly LL.   
 * 
 */

class Node
{
    constructor(val)
    {
        this.val = val;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLinkedList
{ 
    constructor()
    {
        this.head = null;
        this.tail = null;
        this.length = 0;
    }

    push(val)
    {
        var newNode = new Node(val);
        if(!this.head)
        {
            this.head = newNode;
            this.tail = newNode;
        }
        else
        {
            this.tail.next = newNode;
            newNode.prev = this.tail;
            this.tail = newNode;
        }

        this.length++;
        return this;
    }
}


/**
 * COMPLEXITY
 * O(1)
 */
