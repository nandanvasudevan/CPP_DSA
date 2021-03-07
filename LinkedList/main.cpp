/**
 ******************************************************************************
 * @file         	main.cpp
 * @date			07-Mar-2021, 3:23:03 PM
 * @author			nandanv
 * @brief
 ******************************************************************************
 */

//* Private Include ************************************************************************
#include <cstdint>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/format.h>

#include "simple.hpp"
//* Private Constants **********************************************************************

//* Private Macros *************************************************************************

//* Private Types **************************************************************************

SNode *pFirst = new SNode(35);

int main()
{
    int16_t iArray[] =
        {
            1,
            2,
            -345,
            500,
            67
        };

    SNode *pTail = new SNode(iArray,
                             (sizeof(iArray)
                              / sizeof(iArray[0])),
                             pFirst);


    pFirst->display();

    fmt::print(fmt::format("Count: {}\n",
                           pFirst->getCount()));
    fmt::print(fmt::format("Max: {}\n",
                           pFirst->getMax()));
    fmt::print(fmt::format("Min: {}\n",
                           pFirst->getMin()));

    delete pTail;
    return 0;
}

