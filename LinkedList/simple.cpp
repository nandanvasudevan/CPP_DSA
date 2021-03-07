/**
 ******************************************************************************
 * @file         	simple.c
 * @date			07-Mar-2021, 3:19:37 PM
 * @brief
 ******************************************************************************
 */

//* Private Include ************************************************************************
#include "simple.hpp"
//* Private Constants **********************************************************************

//* Private Macros *************************************************************************

//* Private Types **************************************************************************

//* Private Methods ************************************************************************

//* Private Variable ***********************************************************************

//* Definitions ****************************************************************************

SNode::SNode() :
    m_lData(0),
    m_pNext(nullptr)
{
}

SNode::SNode(list_data lData) :
    m_lData(lData),
    m_pNext(new SNode())
{
}

SNode::SNode(int16_t iData, SNode &From)
{
    From.m_pNext = this;
    this->m_lData = iData;
    this->m_pNext = nullptr;
}

SNode::SNode(int16_t *iArray, uint16_t uiLength, SNode *pHead,
             const bool bOverwriteHead)
{
    SNode *pIterator = pHead;
    uint16_t i = 0;

    if (bOverwriteHead)
    {
        pIterator->m_lData = iArray[i++];
    }

    for (; i
           < uiLength
             - 1; i++)
    {
        SNode *p = new SNode(iArray[i],
                             *pIterator);
        p->m_pNext = nullptr;
        pIterator = p;
    }

    pIterator->m_pNext = this;
    this->m_lData = iArray[uiLength
                           - 1];
    this->m_pNext = nullptr;
}

//+-------------------------------------------------------------------------------- Method -
//|Author               : nandanv
//|Created On           : 07-Mar-2021, 9:44:57 PM
//|Description          : <see declaration>
//+-----------------------------------------------------------------------------------------
void SNode::display(const std::string svFmt)
{
    forEach([svFmt](SNode sNode)
    {
        fmt::print(fmt::format(svFmt,
                sNode.m_lData));
    });
}

//+-------------------------------------------------------------------------------- Method -
//|Author               : nandanv
//|Created On           : 07-Mar-2021, 9:59:48 PM
//|Description          : <see declaration>
//+-----------------------------------------------------------------------------------------
void SNode::forEach(std::function <void(const SNode)> fnTask)
{
    SNode *pIterator = this;

    while (pIterator)
    {
        fnTask(*pIterator);
        pIterator = pIterator->m_pNext;
    }
}

//+-------------------------------------------------------------------------------- Method -
//|Author               : nandanv
//|Created On           : 07-Mar-2021, 10:14:21 PM
//|Description          : <see declaration>
//+-----------------------------------------------------------------------------------------
uint16_t SNode::getCount()
{
    uint16_t uiCount = 0;

    forEach([&uiCount](SNode sNode) mutable
    {
        uiCount += 1;
    });

    return uiCount;
}

//+-------------------------------------------------------------------------------- Method -
//|Author               : nandanv
//|Created On           : 07-Mar-2021, 10:17:20 PM
//|Description          : <see declaration>
//+-----------------------------------------------------------------------------------------
list_data SNode::getMax()
{
    int16_t iMax = INT16_MIN;

    forEach([&iMax](const SNode sNode) mutable
    {
        if(sNode.m_lData > iMax)
        {
            iMax = sNode.m_lData;
        }
    });

    return iMax;
}

//+-------------------------------------------------------------------------------- Method -
//|Author               : nandanv
//|Created On           : 07-Mar-2021, 10:19:35 PM
//|Description          : <see declaration>
//+-----------------------------------------------------------------------------------------
list_data SNode::getMin()
{
    int16_t iMin = INT16_MAX;

    forEach([&iMin](const SNode sNode) mutable
    {
        if(sNode.m_lData < iMin)
        {
            iMin = sNode.m_lData;
        }
    });

    return iMin;
}
