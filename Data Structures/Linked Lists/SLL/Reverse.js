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
     }
 }
 
 class SinglyLinkedList
 { 
    constructor()
    {
        this.head = null;
        this.tail = null;
        this.length = 0;
    }

    reverse()
    {
        var node = this.head;
        this.head = this.tail;
        this.tail = node;

        var next;
        var prev = null;
        
        for(var i=0;i<this.length;i++)
        {
            next = node.next;
            node.next = prev;
            prev = node;
            node = next;
        }
        return this;
    };
 }
 
 
/**
  * COMPLEXITY
  * O(N)
*/
 