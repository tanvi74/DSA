/**
 * 
 * PSEUDOCODE
 * -- If there is nothing in stack, return null.
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
         this.value = val;
         this.next = null;
     }
 }
 
 class Stack
 {
     constructor()
     {
         this.first = null;
         this.last = null;
         this.size = null;
     }
 
     pop()
     {
        if(!this.first)
        {
            return null;
        }

        var temp = this.first;

        if(this.first === this.last)
        {
            this.last = null;
        }

        this.first = this.first.next;
        this.size--;

        return temp.value;
     }
 }
 
 /**
  * COMPLEXITY 
  * O(1)
  */