#include <iostream>
#include <fstream>
#include <vector>

#include "Layer.hpp"

#ifndef MLPERCEPTRON_HPP
#define MLPERCEPTRON_HPP

template <typename T, T (*func)(const std::vector<T>&, const std::vector<T>&, T)>
class MLPerceptron
{
    std::vector<Layer<T, func>> layers;
    

public:
    MLPerceptron()
    {
        layers.emplace_back(784, 200);
        layers.emplace_back(200, 10);
    }

    void LoadFunc(){}

    void addLayer(size_t prevNeurons, size_t numNeurons){}

    void process(std::vector<T> &values)
    {
        size_t layer_num = 1; 
        for (Layer<T, func> layer : layers)
        {
            //std::cout << "\033[31m Layer " << layer_num << "\033[0m\n";
            values = layer.process(values);
        }

    }
    ~MLPerceptron(){}
};

#endif //MLPERCEPTRON_HPP
