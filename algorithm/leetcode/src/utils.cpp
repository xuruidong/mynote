#include "utils.h"
#include <random>
#include <iostream>


utils::utils()
{
    //ctor
    srand(time(NULL));
}

utils::~utils()
{
    //dtor
}

int utils::vector_print(std::vector<int> &nums)
{
    for(auto it = nums.begin(); it != nums.end(); ++it){
        std::cout<<*it<<",";
    }
    std::cout<<std::endl;
    return 0;
}

std::vector<int> utils::generateRandomArray(int maxSize, int maxValue)
{
    /*
    std::default_random_engine e;
    std::uniform_int_distribution<int> u(1, maxSize);
    e.seed(time(NULL));
    */
    int size = rand()%maxSize;
    //std::vector<int> *ret = new std::vector<int>;
    std::vector<int> ret;
    //std::uniform_int_distribution<int> v(0, maxValue);
    for (int i = 0; i < size; ++i) {
        //ret->push_back(v(e));
        ret.push_back(rand()%maxValue);
    }

    return ret;
}
