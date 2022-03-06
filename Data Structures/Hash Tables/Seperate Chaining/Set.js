/**
 * 
 * PSEUDOCODE
 * -- Accepts a key & value.
 * -- Hashes the key.
 * -- Stores the key value pair in the hash table array via seperate chaining
 * 
 */


class HashTable
{
    constructor()
    {
        this.keyMap = new Array(size);
    }

    _hash(key, arrayLen)
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

    set(key, value)
    {
        let index = this._hash(key);
        if(!this.keyMap[index])
        {
            this.keyMap[index] = [];
        }
        this.keyMap[index].push([key,value]);
    }
}