/* File name: CHashFun.h
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

#ifndef CHASH_CHASHFUN_H_
#define CHASH_CHASHFUN_H_

/* Hash function class
 * Description: Define hash function interface, used to calculate hash value
 */

class CHashFun
{
public:
    /* Defalut constructor */
    CVirtualNode_s();

    /* Get hash value */
    virtual long getHashVal(const string) = 0;
};

#endif