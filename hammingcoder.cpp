#include <iostream>

uint16_t  iz8v16(uint8_t a)
 {
    uint16_t  result = 0;

    bool d[8];
    bool p[8];

    for (int i = 7; i >= 0; --i)
    {
        d[i] = (a >> (7 - i)) & 1;
    }

    p[0] = (1 + d[0] + d[2] + d[3]) % 2;
    p[1] = (1 + d[0] + d[1] + d[3]) % 2;
    p[2] = (1 + d[0] + d[1] + d[2]) % 2;
    p[3] = (1 + p[0] + d[0] + p[1] + d[1] + p[2] + d[2] + d[3]) % 2;

    p[4] = (1 + d[4] + d[6] + d[7]) % 2;
    p[5] = (1 + d[4] + d[5] + d[7]) % 2;
    p[6] = (1 + d[4] + d[5] + d[6]) % 2;
    p[7] = (1 + p[4] + d[4] + p[5] + d[5] + p[6] + d[6] + d[7]) % 2;


    for (int i = 0; i < 8; ++i)
    {
        result |= (p[i] << (15 - 2 * i));
        result |= (d[i] << (14 - 2 * i));
    }

    return result;
}

