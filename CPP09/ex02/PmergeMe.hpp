#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <climits>
#include <algorithm>
#include <iomanip>

class PmergeMe
{
    private:
        std::vector<int> _vec;
        std::deque<int>  _deq;

        void sortVector();
        void sortDeque();
        void fordJohnsonVector(std::vector<int>& v);
        void binaryInsertVector(std::vector<int>& mainChain, int value);
        void fordJohnsonDeque(std::deque<int>& d);
        void binaryInsertDeque(std::deque<int>& mainChain, int value);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void parseInput(int argc, char **argv);
        void process();
};

#endif
