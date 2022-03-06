/**
 * PSEUDOCODE
 * 
 * -- This function is used for adding element from the beginning.
 * -- Create a new node with the value passed to the function.
 * -- If the length is 0
 *      -- Set the head to be the new Node.
 *      -- Set the tail to be the new Node.
 * -- Otherwise
 *      -- Set the prev property on the head of the list to be the new Node.
 *      -- Set the next property on the new Node to be the head property.
 *      -- Update the head to be the new Node.
 * -- Increment the length
 * -- Return the list
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
 }
 
 
 /**
  * COMPLEXITY
  * O(1)
  */
 