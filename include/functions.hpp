#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

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


#endif //FUNCTIONS_HPP