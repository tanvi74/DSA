/**
 * PSEUDOCODE
 * 
 * -- This function is used for removing a node from the LL at a specific position.
 * -- If the index is less than 0 or greater than the length, return UNDEFINED.
 * -- If the index is same as the length-1, pop.
 * -- If the index is 0, shift.
 * -- Otherwise, using the get method, access the node at index -1.
 * -- Set the next property on that node to be the next of the new node.
 * -- Set the next property on the new node to be the previous next.
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
        
        var previousNode = this.get(index-1);
        var removed = previousNode.next;
        previousNode.next = removed.next;
        this.length--;
        return removed;
    };
 }
 
 
/**
  * COMPLEXITY
  * O(N)
*/
 