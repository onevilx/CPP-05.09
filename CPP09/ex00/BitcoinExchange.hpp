#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _rates;
        bool isValidDate(const std::string& date) const;
        bool isValidValue(double value) const;

    public:
        BitcoinExchange();
        ~BitcoinExchange();

        void loadDatabase(const std::string& filename);
        void processInput(const std::string& filename);
};

#endif