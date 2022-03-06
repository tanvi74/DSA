/**
 * PSEUDOCODE
 * 
 * -- This function is used for reversing a LL without making its copy.
 * -- Swap the head & tail.
 * -- Create a variable called NEXT.
 * -- Create a variable called PREV.
 * -- Create a variable node & initialize it to the head property.
 * -- Loop through the list.
 * -- Set NEXT to be the next property of whatever the node is.
 * -- Set next property on the node to be whatever PREV is.
 * -- Set PREV to be the value of the node variable.
 * -- Set the node variable to be the value of the next variable.
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

    reverse()
    {
        if(!this.length)
        {
            return undefined;
        }
        
        var currentNode = this.head;
        this.head = this.tail;
        this.tail = currentNode;
        var prevNode = null;
        var nextNode;

        for(let i=0; i<this.length; i++)
        {
            nextNode = currentNode.next;
            currentNode.prev = nextNode;
            currentNode.next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }

        return this;
    };
 }
 
 
/**
  * COMPLEXITY
  * O(N)
*/
 