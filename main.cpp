#include "hammingcoder.cpp"
#include <gtest/gtest.h>

TEST(F,A)
{
    uint8_t a = {0b10100100};
    uint16_t b = {0b1100111010010010};

    ASSERT_EQ( iz8v16(a),b);

    a = {0b10111100};
    b = {0b0110110101111010};

    ASSERT_EQ( iz8v16(a),b);

}

int main(int argc,char* argv[])
{
   testing::InitGoogleTest(&argc,argv);
   return RUN_ALL_TESTS();
}

