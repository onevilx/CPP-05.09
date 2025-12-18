#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidValue(double value) const
{
    return value <= 1000;
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int y = std::atoi(date.substr(0, 4).c_str());
    int m = std::atoi(date.substr(5, 2).c_str());
    int d = std::atoi(date.substr(8, 2).c_str());

    if (m < 1 || m > 12 || d < 1 || d > 31)
        return false;

    if (date < "2009-01-02")
        return false;

    (void)y;
    return true;
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    std::string line;

    if (!file)
        throw std::runtime_error("Error: could not open database.");
    std::getline(file, line);

    while (std::getline(file, line))
    {
        size_t pos = line.find(',');
        if (pos == std::string::npos)
            continue;

        std::string date = line.substr(0, pos);
        double rate = std::atof(line.substr(pos + 1).c_str());

        _rates[date] = rate;
    }
}

void BitcoinExchange::processInput(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    std::string line;

    if (!file)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::getline(file, line);

    while (std::getline(file, line))
    {
        size_t sep = line.find(" | ");
        if (sep == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, sep);
        double value = std::atof(line.substr(sep + 3).c_str());
        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (value < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (!isValidValue(value))
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        std::map<std::string, double>::iterator it = _rates.lower_bound(date);

        if (it == _rates.begin() && it->first != date)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (it == _rates.end() || it->first != date)
            --it;

        std::cout << date << " => " << value << " = " << value * it->second << std::endl;
    }
}