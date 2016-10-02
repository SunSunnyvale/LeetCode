/*
Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
Example:

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 1 is the only number in the set, getRandom always return 1.
randomSet.getRandom();
*/
class RandomizedSet {
    unordered_map<int,int> mapOfElements_;
    vector<int> listOfElements_;
public:
    /** Initialize your data structure here. */
    RandomizedSet(){
        listOfElements_.reserve(5000);
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        // cout<<"\nval::"<<val <<" Insert..";
        // for(int ele:listOfElements_){
        //     cout<<" "<<ele;
        // }
        if(mapOfElements_.find(val) != mapOfElements_.end()){
            return false;
        }
        listOfElements_.push_back(val);
        mapOfElements_.insert(make_pair(val,listOfElements_.size()-1));
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        // cout<<"\nval::"<<val <<" Remove..";
        // for(int ele:listOfElements_){
        //     cout<<" "<<ele;
        // }
        
        if(mapOfElements_.find(val) == mapOfElements_.end() || listOfElements_.empty()){
            //cout<<"\n Cannot find val or list is empty";
            return false;
        }
        int size=listOfElements_.size();
        if(size==1){
            listOfElements_.erase(listOfElements_.begin(),listOfElements_.end());
            mapOfElements_.clear();
            return true;
        }
       
        int indexOfEleToRemove=mapOfElements_[val];
        //cout<<"\n indexOfEleToRemove::"<<indexOfEleToRemove;
        mapOfElements_.erase(val);
        listOfElements_[indexOfEleToRemove]=  listOfElements_[size-1];
        mapOfElements_[listOfElements_[size-1]]=indexOfEleToRemove;
        listOfElements_.resize(size-1);
        return true;
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        // cout<<"\n getRandom..";
        // for(int ele:listOfElements_){
        //     cout<<" "<<ele;
        // }
        return listOfElements_[rand() % (listOfElements_.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */