/* File name: CNode_s.h
 * Authors: Xiaodan Xi
 */

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <hash>

using std::map;
using std::string;
using std::vector;

#ifndef CHASH_CNODES_H_
#define CHASH_CNODES_H_

static INIT_IDEN_SIZE = 100;

/* Real node class
 * Description: Each real node has multiple virtual node
 */

class CNode_s
{
public:
    /* Defalut constructor */
    CNode_s();
    /* Explicit constructor */
    CNode_s(string pIden, int pVNodeCount, void* pData);

    /* Get real node ID */
    const string getIden();

    /* Get virtual node number of a real node */
    int getVNodeCount();

    /* Set real node data value */
    void setData(void* data);

    /* Get real node data value */
    void* getData();

private:
    void _setCNode_s(string pIden, int pVNodeCount, void* pData);
    string _iden (INIT_IDEN_SIZE, ''); /* Node ID */
    int _vNodeCount; /* Virtual node number */
    void* _data; /* Data node */
};

#endif