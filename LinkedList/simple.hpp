/**
 ******************************************************************************
 * @file            simple.h
 * @date            07-Mar-2021, 3:19:37 PM
 * @brief
 ******************************************************************************
 */

#ifndef LINKEDLIST_SIMPLE_HPP_
#define LINKEDLIST_SIMPLE_HPP_
//* Public Include *************************************************************************
#include <cstdint>
#include <functional>
#include <string_view>
//* Public Constants ***********************************************************************

//* Public Macros **************************************************************************

//* Public Types ***************************************************************************

//* Public Methods *************************************************************************
using SNode = struct SNode;
using list_data = int16_t;

struct SNode
{
    //! Data in node
    list_data m_lData;

    //! Address to the next node
    SNode *m_pNext;

    //! Simple constructor
    SNode();

    /**
     * Create a new node with data
     * @param lData Data in node
     */
    SNode(list_data lData);

    /**
     * Create a new node and link it with another
     * @param iData Data in node
     * @param From Node to be linked
     */
    SNode(int16_t iData, SNode &From);

    /**
     * Create linked list from an array
     * @param iArray The array from which data is extracted for nodes
     * @param uiLength The length of the array
     * @param pHead The head node of the linked list
     * @param bOverwriteHead if true, the head value is overwritten with the first element of
     * the array. If false, the data in head node is preserved.
     */
    SNode(int16_t *iArray, uint16_t uiLength, SNode *pHead, const bool bOverwriteHead = true);

    /**
     * Display all the elements from this node
     * @param svFmt Formatting for output
     */
    void display();

    /**
     * Do a certain task with all the elements
     * @param fnTask The task to be performed
     */
    void forEach(std::function<void(const SNode)> fnTask);

    /**
     * Get the number of elements in the list starting from this
     * @return The number of elements
     */
    uint16_t getCount();

    /**
     * Get the maximum value in the list starting from this node
     * @return The maximum value
     */
    list_data getMax();

    /**
     * Get the minimum value in the list starting from this node
     * @return The minimum value
     */
    list_data getMin();
};


#endif /* LINKEDLIST_SIMPLE_HPP_ */
