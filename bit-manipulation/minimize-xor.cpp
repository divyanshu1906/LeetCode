class Solution {
public: 
    bool isSet(int &x, int bit){
        return x &(1<<bit);
    }
    bool setBit(int &x, int bit){
        return x |= (1<<bit);
    }
    bool unsetBit(int &x, int bit){
        return x &= ~(1<<bit);
    }
    int minimizeXor(int num1, int num2) {
        int x = num1;
        int requried = __builtin_popcount(num2);
        int current = __builtin_popcount(x);
        int bit = 0;
        if(current < requried){
            while(current < requried){
                if(!isSet(x,bit)){
                    setBit(x,bit);
                    current++;
                }
                bit++;
            }
        }
        else if(current > requried){
            while(current > requried){
                if(isSet(x,bit)){
                    unsetBit(x,bit);
                    current--;
                }
                bit++;
            }
        }
        return x;
    }
};