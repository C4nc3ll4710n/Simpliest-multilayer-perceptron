#include "./include/MLPerceptron.hpp"
#include "./include/functions.hpp"
#include <iostream>
#include <iomanip>



int main(){
    MLPerceptron<double> mlperc;
    std::string filename = "t10kimage.pgm";
    std::vector<double> values(784, 0);
    std::ifstream f(filename, std::ios::binary);



    if (!f.is_open()) { std::cerr << "Failed to open files" << std::endl; }
    char buffer;
    for (size_t v = 0; v<values.size(); v++) 
    {
        f.read(&buffer, 1);
        //std::cout << "\033[33m buffer: " << v << "\033[0m" << buffer << "\n";
        values[v] = static_cast<double>(static_cast<unsigned char>(buffer));
    }
    f.close();


    int num = 1;
    for (double val : values)
    {
        std::cout << std::fixed << val << " \n";
        num++;
    }
    std::cout << std::endl;

    mlperc.process(values);
    num = 1;
    for (double val : values)
    {
        std::cout << num << ": " << std::fixed << val << " \n";
        num++;
    }
    std::cout << std::endl;





    return 0;
}