#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <cmath>
#include <iomanip>
#include <vector>
#include <iostream>

double purelin(const std::vector<double> &xs, const std::vector<double> &ws, double b) 
{
    double result = 0;
    for (size_t i = 0; i< xs.size(); i++)
    {
        for (size_t j = 0; j < ws.size(); j++)
        {
            result += xs[j]*ws[j];
            //std::cout << "+ " << xs[j] << " * " << ws[j] <<" :\033[32m"  << result <<  "\033[0m\n";
            
        }
    }
    result+=b;
    return result;
}

double tansig(const std::vector<double> &xs, const std::vector<double> &ws, double b) 
{
    double result = 0;
    std::cout << "\033[33m tansig \033[0m\n";
    for (size_t i = 0; i< xs.size(); i++)
    {
        for (size_t j = 0; j < ws.size(); j++)
        {
            result += xs[j]*ws[j];
            //std::cout << "+ " << xs[j] << " * " << ws[j] <<" :\033[32m"  << result <<  "\033[0m\n";
            
        }
    }
    result+=b;
    std::cout << "\033[33m" << std::fixed << result << "\033[0m\n";
    return 2.0/(1.0+exp(-2.0*result)) -1.0;
}



double activation_func(const std::vector<double> &xs, const std::vector<double> &ws, double b, int type)
{
    if (type == 1)
        return purelin(xs, ws, b);
    else if (type == 2)
        return tansig(xs, ws, b);
    else
        return 0;
    
}



#endif //FUNCTIONS_HPP