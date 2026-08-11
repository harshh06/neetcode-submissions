class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int m=0;
        for(int i=0;i<32;i++){
            m<<=1;
            int lastBit=n&1;
            m|=lastBit;
            n>>=1;
        }
        return m;
    }
};
