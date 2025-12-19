#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(int argc, char **argv)
{
    if (argc < 2)
        throw std::runtime_error("Error");

    for (int i = 1; i < argc; i++)
    {
        std::string s(argv[i]);

        if (s.empty())
            throw std::runtime_error("Error");

        for (size_t j = 0; j < s.size(); j++)
        {
            if (!isdigit(s[j]))
                throw std::runtime_error("Error");
        }

        long value = std::atol(s.c_str());
        if (value <= 0 || value > INT_MAX)
            throw std::runtime_error("Error");

        _vec.push_back(static_cast<int>(value));
        _deq.push_back(static_cast<int>(value));
    }
}

void PmergeMe::binaryInsertVector(std::vector<int>& chain, int value)
{
    size_t left = 0;
    size_t right = chain.size();

    while (left < right)
    {
        size_t mid = (left + right) / 2;
        if (chain[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    chain.insert(chain.begin() + left, value);
}

void PmergeMe::binaryInsertDeque(std::deque<int>& chain, int value)
{
    size_t left = 0;
    size_t right = chain.size();

    while (left < right)
    {
        size_t mid = (left + right) / 2;
        if (chain[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    chain.insert(chain.begin() + left, value);
}

void PmergeMe::fordJohnsonVector(std::vector<int>& v)
{
    if (v.size() <= 1)
        return;

    std::vector<int> mainChain;
    std::vector<int> pending;

    for (size_t i = 0; i + 1 < v.size(); i += 2)
    {
        int a = v[i];
        int b = v[i + 1];
        if (a > b)
            std::swap(a, b);

        mainChain.push_back(b);
        pending.push_back(a);
    }

    if (v.size() % 2 != 0)
        pending.push_back(v.back());

    fordJohnsonVector(mainChain);

    for (size_t i = 0; i < pending.size(); i++)
        binaryInsertVector(mainChain, pending[i]);

    v = mainChain;
}

void PmergeMe::fordJohnsonDeque(std::deque<int>& d)
{
    if (d.size() <= 1)
        return;

    std::deque<int> mainChain;
    std::deque<int> pending;

    for (size_t i = 0; i + 1 < d.size(); i += 2)
    {
        int a = d[i];
        int b = d[i + 1];
        if (a > b)
            std::swap(a, b);

        mainChain.push_back(b);
        pending.push_back(a);
    }

    if (d.size() % 2 != 0)
        pending.push_back(d.back());

    fordJohnsonDeque(mainChain);

    for (size_t i = 0; i < pending.size(); i++)
        binaryInsertDeque(mainChain, pending[i]);

    d = mainChain;
}

void PmergeMe::sortVector()
{
    fordJohnsonVector(_vec);
}

void PmergeMe::sortDeque()
{
    fordJohnsonDeque(_deq);
}

void PmergeMe::process()
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    clock_t startVec = clock();
    sortVector();
    clock_t endVec = clock();

    clock_t startDeq = clock();
    sortDeque();
    clock_t endDeq = clock();

    std::cout << "After:  ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    double vecTime = (double)(endVec - startVec) / CLOCKS_PER_SEC * 1e6;
    double deqTime = (double)(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;

    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : "
              << vecTime << " us" << std::endl;

    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque  : "
              << deqTime << " us" << std::endl;
}
