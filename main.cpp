

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>

float sigmoid(float x)
{
    return 1 / (1 + exp(-x));
}

float cap_to_1(float x)
{
    if (x >= 1)
    {
        return 1;
    }
    if (x <= 0)
    {
        return 0;
    }
    return x;
}

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
    if (activation == 0) // sigmoid Activation Function
    {
        return sigmoid(value) * (0.004 * weight);
    }
    else if (activation == 1) // Rectified Linear Unit
    {
        return cap_to_1(value) * (0.004 * weight);
    }
    else if (activation == 2) // tanh
    {
        return tanh(value) * (0.004 * weight);
    }
    else if (activation == 3) // Leaky ReLU / Leaky Rectified Linear Unit
    {
        return LeakyReLU(value, leak) * (0.004 * weight);
    }
    else
    {
        throw std::invalid_argument("ArgumentError: activation needs to be a char value from 0 to 3");
    }
}

// Define the tuple structs for both 32-bit and 64-bit types
struct tuple4x8
{
    unsigned char a, b, c, d;
};

struct tuple4x16
{
    unsigned short a, b, c, d;
};

// Unified Connections class template that can handle both 32-bit and 64-bit

class Connections
{
    tuple4x8 bin;

  public:
    // Method for encoding 4 values (either 8-bit or 16-bit)
    void enc4(TupleType a, TupleType b, TupleType c, TupleType d)
    {
        if constexpr (std::is_same_v<TupleType, unsigned short int>) // 16-bit encoding
        {
            bin = ((T)a << 48) | ((T)b << 32) | ((T)c << 16) | (T)d;
        }
        else if constexpr (std::is_same_v<TupleType, unsigned char>) // 8-bit encoding
        {
            bin = ((T)a << 24) | ((T)b << 16) | ((T)c << 8) | (T)d;
        }
    }

    auto dec4()
    {
        if constexpr (std::is_same_v<TupleType, short int>)
        // 16-bit decoding
        {
            return tuple4x16{
                (unsigned short int)((bin >> 48) & 0xFFFF),
                (unsigned short int)((bin >> 32) & 0xFFFF),
                (unsigned short int)((bin >> 16) & 0xFFFF),
                (unsigned short int)(bin & 0xFFFF)};
        }
        else if constexpr (std::is_same_v<TupleType, unsigned char>)
        // 8-bit decoding
        {
            return tuple4x8{
                (unsigned char)((bin >> 24) & 0xFF),
                (unsigned char)((bin >> 16) & 0xFF),
                (unsigned char)((bin >> 8) & 0xFF),
                (unsigned char)(bin & 0xFF)};
        }
    }
};

// Type aliases for convenience
using connections64 = Connections<unsigned short int>;
using connections32 = Connections<unsigned char>;

// Template-based Neuron struct to accept any type of connection (32 or 64-bit)
template <typename ConnType>

struct Neuron
{
    float mult;      // precise computation for multiplication
    char scaledBias; // Bias with steps of size 0.05, allows a bias from 0-12.75
    ConnType connections;
};

// Layer class for storing neurons
class Layer
{
    std::vector<Neuron<connections64>> layerlist; 
    // Example using connections64, can be changed to connections32 if needed

  public:
    void constructNetwork(int size)
    {
        for(int i=0; i<=size; i++) {
        }
        // To be implemented
    }
};

int main(int argc, char *argv[])
{
    // Example for 64-bit connections
    connections64 c64;
    c64.enc4(4, 237, 8, 1200);
    
    // Encoding with 16-bit values
    Neuron<connections64> n64{0.56, 200, c64};
    tuple4x16 m64 = n64.connections.dec4();
    
    // Decoding into 16-bit tuple
    std::cout << m64.b << std::endl;

    // Example for 32-bit connections
    connections32 c32;
    c32.enc4(255, 128, 64, 32);
    
    // Encoding with 8-bit values
    Neuron<connections32> n32{0.34, 120, c32};
    tuple4x8 m32 = n32.connections.dec4();
    
   // Decoding into 8-bit tuple
    std::cout << (int)m32.a << std::endl;

    return 0;
}