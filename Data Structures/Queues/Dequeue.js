/**
 * 
 * PSEUDOCODE
 * -- If there is no first property, return null.
 * -- Store the first property in a variable.
 * -- See if the first is the same as the last(check if there is only one node). If so, set the first & last to be null.
 * -- If there is more than 1 node, set the first property to be the next property of first.
 * -- Decrement the size by 1.
 * -- Return the value of the node dequeued.
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
 
     dequeue()
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