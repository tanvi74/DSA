/**
 * PSEUDOCODE
 * 
 * -- This function is used for changing the value of the node based on its position in th LL.
 * -- Function should accepts a value & an index.
 * -- Use your get function to find the specific node.
 * -- If node is not found, return false.
 * -- If node is found, set the value of that node to be the value passed tot he function and return true.
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
 