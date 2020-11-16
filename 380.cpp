class RandomizedSet {
    public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val)!=mp.end()) return false;

        mp[val]=vect.size();
        vect.push_back(val);

        return true;

    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.find(val)==mp.end()) return false;

        int loc = mp[val];
        int last = vect[vect.size()-1];

        swap(vect[loc],last);

        vect.pop_back();
        mp[vect[loc]]= loc;
        
        mp.erase(val);

        return true;

    }

    /** Get a random element from the set. */
    int getRandom() {

        return vect[rand()%vect.size()];
    }

    private:

    vector<int> vect;
    unordered_map<int,int> mp;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
