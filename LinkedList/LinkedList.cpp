/**
 ******************************************************************************
 * @file         	LinkedList.cpp
 * @date			07-Mar-2021, 12:14:02 PM
 * @author			nandanv
 * @brief
 ******************************************************************************
 */

//* Private Include ************************************************************************
#include "LinkedList.hpp"

#include <cassert>

#include <fmt/format.h>
#include <fmt/printf.h>
//* Private Constants **********************************************************************

//* Private Macros *************************************************************************

//* Private Types **************************************************************************

//+-------------------------------------------------------------------------------- Method -
//|Author               : nandanv
//|Created On           : 01-Apr-2021, 4:42:34 AM
//|Description          : <see declaration>
//+-----------------------------------------------------------------------------------------
CLinkedList::CLinkedList() {
}

//+-------------------------------------------------------------------------------- Method -
//|Author               : nandanv
//|Created On           : 30-Mar-2021, 9:49:20 PM
//|Description          : <see declaration>
//+-----------------------------------------------------------------------------------------
CLinkedList::CLinkedList(const uint16_t uiData) {
    pHead = new Node();

    pHead->uiData = uiData;
    pHead->pNext = nullptr;

    pTail = pHead;

    return;
}

//+-------------------------------------------------------------------------------- Method -
//|Author               : nandanv
//|Created On           : 30-Mar-2021, 9:54:20 PM
//|Description          : <see declaration>
//+-----------------------------------------------------------------------------------------
CLinkedList::~CLinkedList() {
    purge();
}

//+-------------------------------------------------------------------------------- Method -
//|Author               : nandanv
//|Created On           : 31-Mar-2021, 9:17:40 PM
//|Description          : <see declaration>
//+-----------------------------------------------------------------------------------------
bool CLinkedList::insert(const uint16_t uiData, const int16_t uiPosition) {
    Node *pNode = getNode(uiPosition);

    if (nullptr
        == pHead) {
        Node *pNewNode = new Node(uiData);

        pHead = pNewNode;
        pTail = pNewNode;

        return true;
    }

    /*
     * Unit Name  : Insert new node
     * Unit ID    : U-LinkedList.cpp-
     * Author     : nandanv (31-Mar-2021, 9:25:02 PM)
     * Comments (if any)
     */
    Node *pNewNode = new Node(uiData,
                              pNode);

    m_uiNodeCount++;

    /*
     * Unit Name  : Pointer from the node behind
     * Unit ID    : U-LinkedList.cpp-
     * Author     : nandanv (04-Apr-2021, 10:17:59 PM)
     * Comments (if any)
     */
    if (0
        != uiPosition) {
        int16_t iPreviousIndex = uiPosition
                                 - 1;

        if (uiPosition
            < 0) {
            iPreviousIndex = uiPosition
                             + 1;
        }

        Node *pPreviousNode = getNode(iPreviousIndex);

        pPreviousNode->pNext = pNewNode;

    } else {
        pHead = pNewNode;
    }

    return true;
}

//+-------------------------------------------------------------------------------- Method -
//|Author               : nandanv
//|Created On           : 01-Apr-2021, 3:25:14 AM
//|Description          : <see declaration>
//+-----------------------------------------------------------------------------------------
void CLinkedList::insert_last(const uint16_t uiData) {
    // Check if tail pointer is valid
    if (nullptr
        == pTail) {
        assert(nullptr
               == pHead);

        assert(1
               == m_uiNodeCount);

        pHead = new Node(uiData);
        pTail = pHead;

        return;
    }

    // Create the node to be inserted
    Node *pNewNode = new Node(uiData);

    // Link the new node to PTail
    pTail->pNext = pNewNode;

    // Move PTail
    pTail = pTail->pNext;

    m_uiNodeCount++;

    return;
}

//+-------------------------------------------------------------------------------- Method -
//|Author               : nandanv
//|Created On           : 01-Apr-2021, 4:31:47 AM
//|Description          : <see declaration>
//+-----------------------------------------------------------------------------------------
bool CLinkedList::insert_fromArray(const uint16_t *uiaArray,
                                   const size_t uiCount) {
    if (nullptr
        == uiaArray) {
        return false;
    }

    if (uiCount
        == 0) {
        return false;
    }

    for (size_t i = 0; i
                       < uiCount; i++) {
        if (nullptr
            == pTail) {
            pHead = new Node(uiaArray[i]);
            pTail = pHead;
            m_uiNodeCount = 1;
            continue;
        }

        pTail->pNext = new Node(uiaArray[i]);

        pTail = pTail->pNext;
        m_uiNodeCount++;
    }

    return true;
}

//+-------------------------------------------------------------------------------- Method -
//|Author               : nandanv
//|Created On           : 01-Apr-2021, 3:43:58 AM
//|Description          : <see declaration>
//+-----------------------------------------------------------------------------------------
uint16_t CLinkedList::get_value(uint16_t uiPosition) {
    Node *pNode = getNode(uiPosition);

    if (nullptr
        == pNode) {
        return 0;
    }

    return pNode->uiData;
}

//+-------------------------------------------------------------------------------- Method -
//|Author               : nandanv
//|Created On           : 31-Mar-2021, 9:29:00 PM
//|Description          : <see declaration>
//+-----------------------------------------------------------------------------------------
bool CLinkedList::remove(const int16_t uiPosition) {
    /*
     * Unit Name  : Get the node before the node to be deleted
     * Unit ID    : U-LinkedList.cpp-
     * Author     : nandanv (31-Mar-2021, 9:39:38 PM)
     * Comments (if any)
     */
    Node *pNode = getNode(uiPosition
                          - 1);

    if (nullptr
        == pNode) {
        return false;
    }

    if (nullptr
        == pNode->pNext) {
        return false;
    }

    if ((nullptr
         != pTail)
        && (pTail
            == pNode->pNext)) {
        pTail = pNode;
    }

    // Node to delete
    Node *pDeletion = pNode->pNext;

    // Bypass the node to be deleted
    pNode->pNext = pDeletion->pNext;

    // Delete the node
    pDeletion = nullptr;
    delete pDeletion;

    m_uiNodeCount--;

    return true;
}

//+-------------------------------------------------------------------------------- Method -
//|Author               : nandanv
//|Created On           : 01-Apr-2021, 3:05:37 AM
//|Description          : <see declaration>
//+-----------------------------------------------------------------------------------------
void CLinkedList::display(const char cDelimiter) {
    Node *pIterator = pHead;

    while (nullptr
           != pIterator) {

        if (pIterator->pNext) {
            fmt::print("{}{}",
                       (int) pIterator->uiData,
                       cDelimiter);
        } else {
            fmt::print("{}",
                       pIterator->uiData);
        }

        pIterator = pIterator->pNext;
    }

    fmt::print("\n");
}

//+-------------------------------------------------------------------------------- Method -
//|Author               : nandanv
//|Created On           : 01-Apr-2021, 3:16:25 AM
//|Description          : <see declaration>
//+-----------------------------------------------------------------------------------------
void CLinkedList::for_each(type_fnNode fn) {
    Node *pIterator = pHead;

    while (nullptr
           == pIterator->pNext) {
        fn(pIterator->uiData);
    }
}

//+-------------------------------------------------------------------------------- Method -
//|Author               : nandanv
//|Created On           : 01-Apr-2021, 4:14:24 AM
//|Description          : <see declaration>
//+-----------------------------------------------------------------------------------------
size_t CLinkedList::get_count(void) {
    return m_uiNodeCount;
}

//+-------------------------------------------------------------------------------- Method -
//|Author               : nandanv
//|Created On           : 04-Apr-2021, 9:30:47 PM
//|Description          : <see declaration>
//+-----------------------------------------------------------------------------------------
void CLinkedList::purge(void) {
    // Sweeping node across the entire list
    Node *pSweep;

    pSweep = pHead;

    while (nullptr
           != pSweep) {
        // Backup the next node
        Node *pTemp = pSweep;

        // Traverse the list
        pSweep = pSweep->pNext;

        // Decrement node counter
        --m_uiNodeCount;

        // Delete current node
        pTemp->pNext = nullptr;
        pTemp->uiData = 0;

        pTemp = nullptr;
        delete pTemp;
    }
}

//+-------------------------------------------------------------------------------- Method -
//|Author               : nandanv
//|Created On           : 31-Mar-2021, 9:32:20 PM
//|Description          : <see declaration>
//+-----------------------------------------------------------------------------------------
CLinkedList::Node *CLinkedList::getNode(int32_t uiPosition) {
    // If selected node is past the maximum number of nodes in the list
    if (abs(uiPosition)
        > m_uiNodeCount
          - 1) {
        return nullptr;
    }

    // Get the position for negative index
    uint16_t uiCounter = (uiPosition
                          >= 0) ? uiPosition : (m_uiNodeCount
                                                + uiPosition);

    if (uiCounter >= m_uiNodeCount) {
        return pTail;
    }

    /*
     * Unit Name  : Find node
     * Unit ID    : U-LinkedList.cpp-
     * Author     : nandanv (31-Mar-2021, 9:27:03 PM)
     * Comments (if any)
     */
    Node *pNode = pHead;

    while (0
           != uiCounter) {
        uiCounter--;
        pNode = pNode->pNext;
    }

    return pNode;
}
