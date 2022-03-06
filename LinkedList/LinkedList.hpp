/**
 ******************************************************************************
 * @file         	LinkedList.h
 * @date			07-Mar-2021, 12:14:02 PM
 * @author			nandanv
 * @brief        
 ******************************************************************************
 */

#ifndef LINKEDLIST_LINKEDLIST_HPP_
#define LINKEDLIST_LINKEDLIST_HPP_
//* Public Include *************************************************************************
#include <cstdint>
#include <functional>
//* Public Constants ***********************************************************************

//* Public Macros **************************************************************************

//* Public Types ***************************************************************************

class CLinkedList
{
public:
    //! Function to be executed for a node
    using type_fnNode = std::function<void(uint16_t)>;

    CLinkedList();

    /**
     * Constructs a list
     * @param uiData Value for head pointer
     */
    CLinkedList(const uint16_t uiData);

    //! Destructor
    virtual ~CLinkedList();

    /**
     * Insert a new node
     * @param uiData Data for inserted node
     * @param uiPosition Position for insertion
     * @retval true if insertion was successful
     * @retval false if insertion failed
     */
    bool insert(const uint16_t uiData, const int16_t uiPosition = -1);

    void insert_last(const uint16_t uiData);

    bool insert_fromArray(const uint16_t *uiaArray, const size_t uiCount);

    /**
     * Remove a node from list
     * @param uiPosition Position for deletion
     * @retval true if valid node
     */
    bool remove(const int16_t uiPosition = -1);

    /**
     * Display all elements
     * @param cDelimitter Delimiter between elements
     */
    void display(const char cDelimiter = ' ');

    /**
     * Execute a function for each node
     * @param fn Function to be executed
     */
    void for_each(type_fnNode fn);

    /**
     * The data in a node
     * @param uiPosition Position of node
     * @return Data in the node
     */
    uint16_t get_value(uint16_t uiPosition);

    /**
     * @return Number of nodes in the list
     */
    size_t get_count(void);

    //! Remove all nodes
    void purge(void);
private:

    //! Structure for a node
    struct Node
    {
        uint16_t uiData; /**< Data to be stored in the node*/
        Node *pNext; /**< The pointer to next node in the linked list*/

        Node() :
            uiData(0),
            pNext(nullptr)
        {
        }

        /**
         * Constructor
         * @param uiData Data for node
         * @param pNode Next pointer
         */
        Node(const uint16_t uiData, Node *pNode = nullptr) :
            uiData(uiData),
            pNext(pNode)
        {
        }

        ~Node()
        {
            delete pNext;
        }
    };

    //! The head pointer
    Node *pHead = nullptr;

    //! The tail pointer
    Node *pTail = nullptr;

    //! Number of nodes currently in the list
    size_t m_uiNodeCount = 1;

    /**
     * Get the node at a position.
     * If position is negative traverses from last
     * @param uiPosition Position of node
     * @return Node at desired position
     */
    Node* getNode(int32_t uiPosition);
};

#endif /* LINKEDLIST_LINKEDLIST_HPP_ */
