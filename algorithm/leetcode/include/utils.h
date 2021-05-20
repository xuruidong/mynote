#ifndef UTILS_H
#define UTILS_H

#include <vector>

class utils
{
    public:
        utils();
        virtual ~utils();
        static int vector_print(std::vector<int> &nums);
        //template<typename T> static int vector_print(T &nums);
        static std::vector<int> generateRandomArray(int maxSize, int maxValue);

    protected:

    private:
};

#endif // UTILS_H
