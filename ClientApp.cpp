#include <iostream>
#include "network_message.h"

enum class CustomMsgTypes : uint32_t
{
    Left,
    Right,
    Up,
    Down
};

int main()
{
    network::message<CustomMsgTypes> msg;
    msg.header.id = CustomMsgTypes::Left;
    
    int x = 12;
    int y = 3;
    int z = 45;

    struct
    {
        float a;
        float b;
    } dim[5];

    msg << x << y << z << dim;

    msg >> dim >> x >> y >> z;

    return 0;
}