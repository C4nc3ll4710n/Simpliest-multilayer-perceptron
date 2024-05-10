#include <iostream>
#include <vector>
#include "Neuron.hpp"
#include <cstring> 
#include <future>

#ifndef LAYER_HPP
#define LAYER_HPP


template <typename T,  T (*func)(const std::vector<T>&, const std::vector<T>&, T, int)>
class Layer
{
    std::vector<Neuron<T>> neurons;
    int type;

public:

    Layer(size_t prevNeurons, size_t numNeurons)
    {
        
        std::string fbias, fweight;
        type = 0;

        if (numNeurons == 200)
        {
            fbias   = "net_train_bias1.bin";
            fweight = "net_train_weight1.bin";
            type = 1;
        }
        else if (numNeurons == 10) 
        {
            fbias   = "net_train_bias2.bin";
            fweight = "net_train_weight2.bin";
            type = 2;
        }
        else
            std::cerr << "didn't expect this kind of number... I have no such file..." << std::endl;

        
        std::ifstream fbs(fbias, std::ios::binary), fwght(fweight, std::ios::binary);

        if (!fbs.is_open() || !fwght.is_open()) { std::cerr << "Failed to open files" << std::endl; }
        std::vector<T> bias(numNeurons);
        char buffer[sizeof(T)];
        for (size_t b = 0; b<numNeurons; b++) 
        {
            fbs.read(buffer, sizeof(T));
            std::memcpy(&bias[b], buffer, sizeof(T));
            
        }
        fbs.close();

        std::vector<std::vector<T>> weights(prevNeurons, std::vector<T>(numNeurons));
        //std::cout << "\033[31m" << "ALERT" << "\033[0m \n";
        for (size_t i = 0; i<prevNeurons; i++)
        {
            for (size_t k = 0; k<numNeurons; k++)
            {
                fwght.read(buffer, sizeof(T));
                std::memcpy(&weights[i][k], buffer, sizeof(T));
                //std::cout <<"weight \033[32m" << "neuron " << k << " " << i << " " << weights[i][k] << "\033[0m\n";
            }
            //std::cout << "\033[32m" << bias[i] << " " << weights[0] << "\033[0m \n";
            

        }
        for (size_t n = 0; n < numNeurons; n++)
                neurons.emplace_back(bias[n], weights[n]);
        
        std::cout << "The end" << std::endl;
        fwght.close();
    }


    std::vector<T> process(std::vector<T> &values)
    {
        std::vector<T> temp(neurons.size());
        std::vector<std::future<T>> futures;
        std::cout << neurons.size()<< " " << type << " NOWA\n";
        for (size_t i = 0; i < neurons.size(); i++) 
        {
            futures.push_back(std::async(std::launch::async, [i, &values, this]() -> T 
                {
                    //std::cout << "\033[31m Neuron " << i + 1 << "\033[0m\n";
                    return func(values, neurons[i].giveWeights(), neurons[i].giveBias(), type);
                })
            );
        }
        for (size_t i = 0; i < futures.size(); i++) 
            temp[i] = futures[i].get();
        return temp;

    }

    ~Layer() = default;


};

#endif //LAYER_HPP