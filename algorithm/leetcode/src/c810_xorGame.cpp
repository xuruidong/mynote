#include "c810_xorGame.h"

c810_xorGame::c810_xorGame()
{
    //ctor
}

c810_xorGame::~c810_xorGame()
{
    //dtor
}

bool xorGame(vector<int>& nums)
{
    if((nums.size() & 0x01) == 0) {
        return true;
    }

    int sum = 0;
    for(int i=0; i<nums.size(); ++i) {
        sum ^= nums[i];
    }
    return sum == 0;
}
