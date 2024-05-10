#include <iostream>
#include <fstream>
#include <vector>

#include "Layer.hpp"
#include "functions.hpp"

#ifndef MLPERCEPTRON_HPP
#define MLPERCEPTRON_HPP

template <typename T>
class MLPerceptron
{
    std::vector<Layer<T, activation_func>> layers;
    

public:
    MLPerceptron()
    {
        layers.emplace_back(784, 200);
        layers.emplace_back(200, 10);
        //layers.emplace_back(new Layer<T, tansig>(784, 200));
        //layers.emplace_back(new Layer<T, purelin>(200, 10));

    }

    void addLayer(size_t prevNeurons, size_t numNeurons){}

    void process(std::vector<T> &values)
    {
        for (size_t layer_num=0; layer_num<layers.size(); layer_num++)
        {
            std::cout << "\033[31m Layer " << layer_num+1 << "\033[0m\n";
            values = layers[layer_num].process(values);
            for (size_t i = 0; i < values.size(); i++)
            {
                std::cout << "\033[31m" << values[i] << "\033[0m\n";
            }
        }
        
        

    }
    ~MLPerceptron(){}
};

#endif //MLPERCEPTRON_HPP
