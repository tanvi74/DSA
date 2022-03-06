/**
 * PSEUDOCODE
 * 
 * -- This function is used for adding a node to the LL at a specific position.
 * -- If the index is less than 0 or greater than the length, return false.
 * -- If the index is 0, unshift.
 * -- If the index is same as the length, push.
 * -- Use the get method to access the index -1.
 * -- Set the next & prev properties on the correct nodes to link everything together.
 * -- Increment the length.
 * -- Return true. 
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

    push(val)
    {
        var newNode = new Node(val);
        if(!this.head)
        {
            this.head = newNode;
            this.tail = newNode;
        }
        else
        {
            this.tail.next = newNode;
            newNode.prev = this.tail;
            this.tail = newNode;
        }

        this.length++;
        return this;
    }

    unshift(val)
    {
       var newNode = new Node(val);
       if(!this.head)
       {
           this.head = newNode;
           this.tail = newNode;
       }
       else
       {
           this.head.prev = newNode;
           newNode.next = this.head;
           this.head = newNode;
       }

       this.length++;
       return this;
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
 
    insert(index, val)
    {
        if(index < 0 || index > this.length)
        {
            return false;
        }
        if(index === this.length)
        {
            return !!this.push(val);
        }
        if(index === 0)
        {
            return !!this.unshift(val);
        }
        
        var newNode = new Node(val);
        var beforeNode = this.get(index-1);
        var afterNode = beforeNode.next;

        beforeNode.next = newNode;
        newNode.prev = beforeNode;
        newNode.next = afterNode;
        afterNode.prev = newNode;
      
        this.length++;
        return true;
    };
 }
 
 
/**
  * COMPLEXITY
  * O(N)
*/
 