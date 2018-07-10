/* File name: CMD5HashFun.h
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

#ifndef CHASH_CCONHASH_H_
#define CHASH_CCONHASH_H_

/* MD5 Hash function class
 * Description: Calculate hash value with MD5, derived from CHashFun class
 */

class CConHash
{
public:
    /* Defalut constructor */
    CConhash();

    /* Explicit constructor */
    CConHash(CHashFun* pFunc);

    /* Set hash function */
    void setHashFunc(CHashFun* pFunc);

    /* Add real node (0 for success, -1 for failure) */
    int addNode_s(CNode_s* pNode);

    /* Delete real node (0 for success, -1 for failure) */
    int delNode_s(CNode_s* pNode);

    /* Look for real node */
    CNode_s* lookupNode_s(const string object);

    /* Get virtual node number */
    int getVNodes();

private:
    /* Hash function */
    CHashFun* _func;

    /* Virtual node number */
    int _vnodes;

    /* Rb-tree to store virtual nodes */
    util_rbtree_t* _vnode_tree;
};

#endif