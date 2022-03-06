/**
 * PSEUDOCODE
 * 
 * -- This function is used for removing a node from the LL at a specific position.
 * -- If the index is less than 0 or greater than the length, return UNDEFINED.
 * -- If the index is same as the length-1, pop.
 * -- If the index is 0, shift.
 * -- Use the get method to return the item to be removed.
 * -- Update the next & prev properties to remove the found node from the list.
 * -- Set next & prev to null on the found node.
 * -- Decrement the length.
 * -- Return the value of node removed. 
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
 
    remove(index)
    {
        if(index < 0 || index > this.length)
        {
            return undefined;
        }
        if(index === 0)
        {
            return this.shift();
        }
        if(index === this.length-1)
        {
            return this.pop();
        }
        
        var removedNode = this.get(index-1);
        
        removedNode.prev.next = removedNode.next;
        removedNode.next.next = removedNode.prev;
        removedNode.next = null;
        removedNode.prev = null;

        this.length--;
        return removedNode;
    };
 }
 
 
/**
  * COMPLEXITY
  * O(N)
*/
 