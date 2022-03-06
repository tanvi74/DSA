/**
 * 
 * PSEUDOCODE
 * -- Accepts a key
 * -- Hashes the key
 * -- Retrieves the key-value pair in the hash table.
 * -- If key not found, return UNDEFINED
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

    get(key)
    {
        let index = this._hash(key);
        if(!this.keyMap[index])
        {
            return undefined;
        }
        for(let i=0; i<this.keyMap[index].length; i++)
        {
            if(this.keyMap[index][i][0] === key)
            {
                return this.keyMap[index][i][1];
            }
        }

        return undefined
    }
}