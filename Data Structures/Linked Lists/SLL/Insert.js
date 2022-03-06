/**
 * PSEUDOCODE
 * 
 * -- This function is used for adding a node to the LL at a specific position.
 * -- If the index is less than 0 or greater than the length, return false.
 * -- If the index is same as the length, push a new node to the end of the list.
 * -- If the index is 0, unshift a new node to the start of the list.
 * -- Otherwise, using the get method, access the node at index -1.
 * -- Set the next property on that node to the new node.
 * -- Set the next property on the new node to be the previous next.
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

    push(val)
    {
        var newNode = new Node(val);
        if(!this.head)
        {
            this.head = newNode;
            this.tail = this.head;
        }
        else
        {
            this.tail.next = newNode;
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

       var counter = 0;
       var current = this.head;
       while(counter !== index)
       {
           current = current.next;
           counter++;
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
        var prev = this.get(index-1);
        var temp = prev.next;
        prev.next = newNode;
        newNode.next = temp;
        this.length++;
        return true;
    };
 }
 
 
/**
  * COMPLEXITY
  * O(N)
*/
 