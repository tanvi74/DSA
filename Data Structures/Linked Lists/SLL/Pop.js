/**
 * PSEUDOCODE
 * 
 * -- If there are no nodes in the list, return UNDEFINED.
 * -- Loop through the entire list until you reach the tail.
 * -- Set the next property of the second to last Node to be null.
 * -- Set the tail to be the second to the last node.
 * -- Decrement the length of the list by 1.
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
 
     pop()
     {
        if(!this.head)
        {
            return undefined;
        }
        
        var current = this.head;
        var newTail = current;

        while(current.next != null)
        {
            newTail = current;
            current = current.next;
        }

        this.tail = newTail;
        this.tail.next = null;
        this.length--;

        if(this.length == 0)
        {
            this.head = null;
            this.tail = null;
        }

        return current;
     }
 }
 
 
 /**
  * COMPLEXITY
  * O(N)
  */ 