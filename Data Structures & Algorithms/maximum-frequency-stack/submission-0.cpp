class FreqStack {
public:
     unordered_map<int,int>freq;
    unordered_map<int,vector<int>>group;
    int maxFreq;

    FreqStack() {
         maxFreq = 0;
    }
    
    void push(int x) {
        freq[x]++;
        maxFreq = max(maxFreq,freq[x]);
        group[freq[x]].push_back(x);
    }
    
    int pop() {
        int x = group[maxFreq].back();
        group[maxFreq].pop_back();
        freq[x]--;
        if(group[maxFreq].empty()) maxFreq--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */