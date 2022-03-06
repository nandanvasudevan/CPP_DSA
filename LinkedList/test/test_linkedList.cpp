/**
 ******************************************************************************
 * @file         	test_linkedList.cpp
 * @date			28-Mar-2021, 7:55:17 PM
 * @author			nandanv
 * @brief
 ******************************************************************************
 */

//* Private Include ************************************************************************
#include <iostream>
#include <memory>

#include <catch2/catch_test_macros.hpp>

#include "../LinkedList.hpp"
//* Private Constants **********************************************************************

//* Private Macros *************************************************************************

//* Private Types **************************************************************************

TEST_CASE("Insert a node")
{

    SECTION("Insert a node")
    {
        static constexpr uint16_t INSERTION_VALUE = 42;
        auto pList = std::make_unique<CLinkedList>(INSERTION_VALUE);

        // Ensure only head
        CHECK(1 == pList->get_count());

        const uint16_t value = pList->get_value(0);

        CHECK(INSERTION_VALUE
              == value);
        CHECK(1
              == pList->get_count());

        pList->insert(INSERTION_VALUE + 1,
                      0);

        pList->insert(INSERTION_VALUE + 2,
                      0);

        CHECK(3
              == pList->get_count());

        pList->purge();
    }

    SECTION("Insert from array")
    {
        auto pList = std::make_unique<CLinkedList>();

        const uint16_t uiaArray[] =
                {
                        34,
                        43
                };
        const size_t uiCount = sizeof(uiaArray)
                               / sizeof(uiaArray[0]);

        pList->insert_fromArray(uiaArray,
                                uiCount);

        CHECK(2
              == pList->get_count());

    }
}

TEST_CASE("Delete node")
{
    SECTION("Delete head node")
    {
        auto pList = std::make_unique<CLinkedList>();

        bool bDidRemove = pList->remove(0);

        const uint16_t value = pList->get_value(0);

        CHECK(false
              == bDidRemove);
        CHECK(0
              == value);
        CHECK(1
              == pList->get_count());
    }

    SECTION("Delete any other node")
    {
        auto pList = std::make_unique<CLinkedList>(0);

        // Insert new node
        {
            static const uint16_t INSERTION = 42;
            pList->insert_last(INSERTION);

            const uint16_t value = pList->get_value(1);

            CHECK(INSERTION
                  == value);
            CHECK(2
                  == pList->get_count());
        }

        // Delete inserted node
        {
            bool bDidRemove = pList->remove(1);

            const uint16_t value = pList->get_value(0);

            CHECK(true
                  == bDidRemove);
            CHECK(0
                  == value);
            CHECK(1
                  == pList->get_count());
        }
    }
}

TEST_CASE("Remove node")
{
    SECTION("Remove all nodes")
    {
        auto pList = std::make_unique<CLinkedList>();

        const uint16_t uiaArray[] =
                {
                        34,
                        43
                };
        const size_t uiCount = std::size(uiaArray);

        pList->insert_fromArray(uiaArray,
                                uiCount);

        CHECK(2
              == pList->get_count());

        pList->purge();

        CHECK(0
              == pList->get_count());
    }
}
