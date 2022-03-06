/**
 * PSEUDOCODE
 * 
 * -- This function is used for removing element from the beginning.
 * -- If there are no nodes, return UNDEFINED.
 * -- Store the current head property in a variable. (Let's call it old Head)
 * -- If the length is one ->
 *    -- set the head = null
 *    -- set the tail = null
 * -- Update the head to be the next of the old Head.
 * -- Set the head's prev property to null.
 * -- Set the old head's next to null.
 * -- Decrement the length
 * -- Return the old head.      
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
 
     shift()
     {
        if(!this.head)
        {
            return undefined;
        }
            
        var oldHead = this.head;
        if(this.length === 1)
        {
            this.head = null;
            this.tail = null;
        }
        else
        {
            this.head = oldHead.next;
            this.head.prev = null;
            oldHead.next = null;
        }

        this.length--;
        return oldHead;
     }
 }
 
 
 /**
  * COMPLEXITY
  * O(1)
  */
 