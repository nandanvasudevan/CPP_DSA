/**
 ******************************************************************************
 * @file         	test_Simple.cpp
 * @date			14-Mar-2021, 6:02:20 PM
 * @author			nandanv
 * @brief           Tests for the simple implementation of linked list
 ******************************************************************************
 */

//* Private Include ************************************************************************
#include "../simple.hpp"
#include "catch.hpp"
//* Private Constants **********************************************************************

//* Private Macros *************************************************************************

//* Private Types **************************************************************************
SNode *nodeHead = new SNode(0);

/**
 * BDD test to test the behaviour when
 * - a value is inserted
 * - an array is inserted
 */
SCENARIO(" Linked lists can be created ", "[LinkedList]")
{
    GIVEN(" an integer ")
    {
        const int16_t value = 35;

        WHEN(" the value is inserted ")
        {
            __attribute__((unused)) SNode *nodeTail = new SNode(value,
                                                                *nodeHead);
        }

        THEN(" the number of elements shall increase by one")
        {
            REQUIRE(2
                    == nodeHead->getCount());
        }
    }
    GIVEN(" a head node and an array")
    {
        int16_t array[] =
            {
                1,
                2,
                3,
                4
            };
        const size_t szArray = (sizeof(array)
                                / sizeof(array[0]));

        WHEN(" the array is inserted with the node head element ignored ")
        {

            __attribute__((unused)) SNode *pTail = new SNode(array,
                                                             szArray,
                                                             nodeHead);
            THEN(" the number of elements equals the array ")
            {
                REQUIRE(szArray
                        == nodeHead->getCount());
            }
        }

        WHEN(" the array is inserted without ignoring the node head element")
        {
            __attribute__((unused)) SNode *pTail = new SNode(array,
                                                             szArray,
                                                             nodeHead,
                                                             false);
            THEN(" the number of elements equals the array elements plus 1")
            {
                REQUIRE(szArray
                        + 1
                        == nodeHead->getCount());
            }
        }
    }
}
