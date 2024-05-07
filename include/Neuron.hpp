#include <iostream>
#include <vector>

#ifndef NEURON_HPP
#define NEURON_HPP


template <typename T>
class Neuron
{
    T bias;
    std::vector<T> weights;
    


public:
    Neuron(T input_bias, std::vector<T> input_weights)
        : bias(input_bias), weights(std::move(input_weights)) {}

    T giveWeight(size_t pos)
    {
        return weights[pos];
    }

    std::vector<T>& giveWeights()
    {
        return weights;
    }

    T giveBias()
    {
        return bias;
    }




    ~Neuron(){};

};


#endif //NEURON_HPP