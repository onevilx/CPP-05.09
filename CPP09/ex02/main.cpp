#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try
    {
        PmergeMe pm;
        pm.parseInput(argc, argv);
        pm.process();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
