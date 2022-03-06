/**
 * PSEUDOCODE
 * 
 * -- This function is used for getting the node by it's position in the LL.
 * -- Funtion should accept an index.
 * -- If the index is less than zero or greater than or equal to the length of the list, return UNDEFINED.
 * -- If the index is less than or equal to half the length of the list.
 *      -- Loop through the list starting from the head & loop towards the middle.
 *      -- Return the node once it is found.
 * -- If the index is greater than half of the length of the list. 
 *      -- Loop through the list starting from the tail & loop towards the middle.
 *      -- Return tthe node once it is found.
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
 
     get(index)
     {
        if(index < 0 || index >= this.length)
        {
            return undefined;
        }

        var count, current;
        if(index <= this.length/2)
        {
            count = 0;
            current = this.head;
            while(count != index)
            {
                current = current.next;
                count++;
            }
        }
        else
        {
            count = this.length - 1;
            current = this.tail;
            while(count != index)
            {
                current = current.prev;
                count--;
            }
        }
        
        return current;

     }
 }
 
 
 /**
  * COMPLEXITY
  * O(N)
  */
 