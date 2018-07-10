/* File name: CVirtualNode_s.h
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

#ifndef CHASH_CVIRTUALNODES_H_
#define CHASH_CVIRTUALNODES_H_

/* Virtual node class
 * Description: Each virtual node points to one real node
 */

class CVirtualNode_s
{
public:
    /* Defalut constructor */
    CVirtualNode_s();
    /* Explicit constructor */
    CVirtualNode_s(CNode_s* pNode);

    /* Set the real node which this virtual node points to */
    void setNode_s(CNode_s* pNode);

    /* Get the real node which this virtual node points to */
    CNode_s* getNode_s();

    /* Set virtual node hash value */
    void setHash(long pHash);

    /* Get virtual node hash value */
    long getHash();

private:
    long _hash; /* Hash value */
    CNode_s* _node; /* Real node */
};

#endif