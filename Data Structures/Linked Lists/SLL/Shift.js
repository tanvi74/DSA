/**
 * PSEUDOCODE
 * 
 * -- This function is used for removing element from the beginning.
 * -- If there are no nodes, return UNDEFINED.
 * -- Store the current head property in a variable.
 * -- Set the head property to be the current head's next property.
 * -- Decrement the length by one.
 * -- Return the value of the node removed.
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
 
     shift()
     {
        if(!this.head)
        {
            return undefined;
        }
            
        var currentHead = this.head;
        this.head = currentHead.next;
        this.length--;

        if(this.length == 0)
        {
            this.tail = 0;
        }

        currentHead.next = null;
        return currentHead;
     }
 }
 
 
 /**
  * COMPLEXITY
  * O(1)
  */
 