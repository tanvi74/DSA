/**
 * 
 * -- Hash Tables are used to store key-value pairs
 * -- They are like arrays, but the keys are not ordered.
 * -- Unlike arrays, hash tables are fast for all of the following operations
 *      -- Finding Values
 *      -- Adding new Values
 *      -- Removing Values
 * -- Nearly every programmable language has some sort of hash table Data Structure, because of their speed, hash tables are used.
 * -- In order to look up values by key, we need a way to convert keys into valid array indicies. A function that performs this task is called as Hash Tables
 * 
 * -- e.g. -> Python has Dictionaries
 *         -> JS has objects & maps
 *         -> Java, Go, Scale has maps
 *         -> Ruby has Hashes
 * 
 * -- WHAT MAKES A GOOD HASH
 *      -- Fast (i.e. Constant time)
 *      -- Doesn't cluster outputs at specific indicies, but distributes uniformly.
 *      -- Deterministic (same I/P yields same O/P).
 * 
 * -- Prime No. in the hash function is helpful in spreading out the keys more uniformly.
 * -- It is helpful if the array that you are putting values into has a prime length.
 * 
 * -- DEALING WITH COLLISIONS
 *      -- Seperate Chaining
 *              --> This allows us to store a single key-value at each index.
 *              --> We can store more data than our hash table.
 *              --> e.g.
 *                                    _ _ _ _ _ _ 
 *                                   | | | | | | |            obj1 -> 3, obj2 -> 3 (Collision happenend, but it will store at 3rd index only) 
 *                                    1 2 3 4 5 6
 *      -- Linear Probing
 *              --> When we find a collision, we search through the array to find the next emplty slot.
 *              --> Once the table is filled, we can't store more data
 *              --> e.g.
 *                                    _ _ _ _ _ _ 
 *                                   | | | | | | |            obj1 -> 3, obj2 -> 4 (Collision happenend, so we will find empty slot, and will place it over there) 
 *                                    1 2 3 4 5 6
 * 
 * 
 * KEYS
 * -- Loops through the hash table array & return an array of keys in the table.
 * 
 * VALUES
 * -- Loops through the hash table array & returns an array of values in the table.
 * 
 * 
 * COMPLEXITIES
 * -- Insertion -> O(1)
 * -- Deletion -> O(1)
 * -- Access -> O(1)
 * --> For worst case -> Delete/Access -> O(N)
 * 
 */

// EXAMPLE OF HASHING FUNCTION

function hash(key, arrayLen)
{
    let total = 0;
    for(let char of key)
    {
        let value = char.charCodeAt(0)-96;
        total = (total + value) % arrayLen;
    }
    return total;
}

function hashRevisited(key, arrayLen)
{
    let total = 0;
    let WIERD_PRIME = 31;
    for(let i=0; i< Math.min(key.length, 100); i++)
    {
        let char = key[i];
        let value = char.charCodeAt(0)-96;
        total = (total * WIERD_PRIME + value)%arrayLen;
    }
    return total;
}