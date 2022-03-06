/**
 * PSEUDOCODE
 * 
 * -- This function is used for removing a node at the end of the linked list.
 * -- If there are no head, return UNDEFINED.
 * -- Store the current tail in a variable to return later.
 * -- If the length is 1, set the head & tail to be null.
 * -- Update the tail to be the previous node.
 * -- Set the new Tail's next to be null.
 * -- Decrement the length.
 * -- Return the value removed.
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
 
     pop()
     {
        if(!this.head)
        {
            return undefined;
        }
        
        var poppedNode = this.tail;
        if(this.length == 1)
        {
            this.head = null;
            this.tail = null;
        }
        else
        {
            this.tail = poppedNode.prev;
            this.tail.next = null;
            poppedNode.prev = null;
        }
        this.length--;
        return poppedNode;
     }
 }
 
 
 /**
  * COMPLEXITY
  * O(1)
  */ 