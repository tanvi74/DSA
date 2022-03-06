/**
 * PSEUDOCODE
 * 
 * -- This function is used for changing the value of the node based on its position in th LL.
 * -- Create a variable which is the result of the get method at the index passed to the function
 * -- Return true
 * -- Otherwise return false.
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
 
     set(index, value)
     {
        var foundNode = this.get(index);
        if(foundNode)
        {
            foundNode.val = value;
            return true;
        }
        return false;
     }
 }
 
 
 /**
  * COMPLEXITY
  * O(N)
  */
 