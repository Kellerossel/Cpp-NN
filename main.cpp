#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <array>

#define vector std::vector
#define array std::array



float sigmoid(float x)
{
    return 1 / (1 + exp(-x));
}

float cap_to_1(float x)
{
    if (x >= 1){return 1;}
    if (x <= 0){return 0;}
    return x;
}

float 

float LeakyReLU(float x, float leak)
{
    if (x >= 0)
    {
        return x;
    }
    else
    {
        return x * leak;
    } // using α=0.05
}

float calc_output(char activation, char weight, float value, const float leak = 0.05)
{
    switch(activation) {}
    case 0: //sigmoid
        return sigmoid(value) * (0.004 * weight);
    case 1: //Rectified Linear Unit
        return cap_to_1(value) * (0.004 * weight)Z
    case 2: //tanh
        return tanh(value) * (0.004 * weight);
    case 3: //Leaky Rectified Linear Unit
        return LeakyReLU(value, leak) * (0.004 * weight);
    
    //The cases automatically break the switch statement, if none of the cases is executed it throws this error
    throw std::invalid_argument("ArgumentError: activation needs to be a char value from 0 to 3");
}

template <typename Type>
struct Neuron
{
    private:
        float mult;      // precise computation for multiplication
        char scaledBias; // Bias with steps of size 0.05, allows a bias from 0-12.75
        vector<Type> connections; //vector of index of next neurons
    public:
        void shrink() {
            std::sort(connections.begin(), connections.end());
            auto new_end = std::unique(connections.begin(), connections.end());
            connections.erase(new_end, connections.end());
            connections.shrink_to_fit();
        }

        void setup_connections(Number, max) {
            for (int i=0; i<=Number; i++) {
                if (max <= 255) {
                    connections.push_back()
                }
            }
        }

};

// Layer class for storing neurons
class Layer
{
    std::vector<Neuron> layerlist;

  public:
    void constructNetwork(int size)
    {
        for(int i=0; i<=size; i++) {
        }
        //unfinished
    }
};

int main(int argc, char *argv[])
{
    connections64 c64;
    c64.enc4(4, 237, 8, 1200);
    Neuron<connections64> n64{0.56, 200, c64};
    tuple4x16 m64 = n64.connections.dec4();
    std::cout << m64.b << std::endl;
    connections32 c32;
    c32.enc4(255, 128, 64, 32);
    Neuron<connections32> n32{0.34, 120, c32};
    tuple4x8 m32 = n32.connections.dec4();
    std::cout << (int)m32.a << std::endl;

    return 0;
}
