/**
 * PSEUDOCODE
 * 
 * -- This function is used for getting the node by it's position in the LL.
 * -- Funtion should accept an index.
 * -- If the index is less than zero or greater than or equal to the length of the list, return null.
 * -- Loop through the list until you reach the index & return the node at that specific index 
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
 
     get(index)
     {
        if(index < 0 || index >= this.length)
        {
            return undefined;
        }

        var counter = 0;
        var current = this.head;
        while(counter !== index)
        {
            current = current.next;
            counter++;
        }
        return current;
     }
 }
 
 
 /**
  * COMPLEXITY
  * O(N)
  */
 