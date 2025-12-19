#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error, Try ./RPN \"...\" " << std::endl;
        return 1;
    }
    try
    {
        RPN rpn;
        rpn.calcul(argv[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
