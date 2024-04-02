#include <iostream>
#include <vector>

short int iz8v16(char Bukva)
 {
    short int result = 0;

    unsigned char bits = static_cast<unsigned char>(Bukva);

    bool d[8];
    bool p[8];

    for (int i = 7; i >= 0; --i)
    {
        d[i] = (bits >> (7 - i)) & 1;
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

int main()
 {
    std::vector<char> characters = {'A'};
    for (char Bukva : characters)
    {
        short int newBits = iz8v16(Bukva);
        std::cout << "Bukva: " << Bukva << std::endl;
        std::cout << "Result: ";
        for (int i = 15; i >= 0; --i)
        {
            int bit = (newBits >> i) & 1;
            std::cout << bit;
        }
    std::cout << std::endl;
    }

    return 0;
}
