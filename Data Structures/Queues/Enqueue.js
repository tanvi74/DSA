/**
 * 
 * PSEUDOCODE
 * -- Function should accept a value.
 * -- Create a new Node with that value.
 * -- If there are no nodes in the queue, set the first & last property to be the created node.
 * -- Otherwise, set the next property on the current last to be that node & set the last property of the queue to be that node.
 * -- Increment the size of the queue by 1. 
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
 
 class Queue
 {
     constructor()
     {
         this.first = null;
         this.last = null;
         this.size = null;
     }
 
     enqueue(val)
     {
         var newNode = new Node(val);
         if(!this.first)
         {
             this.first = newNode;
             this.last = newNode;
         }
         else
         {
             this.first.next = newNode;
             this.last = newNode;
         }
 
         return ++this.size;
     }
 }
 
 /**
  * COMPLEXITY 
  * O(1)
  */