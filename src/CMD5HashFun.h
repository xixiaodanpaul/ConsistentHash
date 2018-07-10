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

#ifndef CHASH_CMD5HASHFUN_H_
#define CHASH_CMD5HASHFUN_H_

/* MD5 Hash function class
 * Description: Calculate hash value with MD5, derived from CHashFun class
 */

class CMD5HashFun : public CHashFun
{
public:
    /* Defalut constructor */
    CVirtualNode_s();

    /* Get hash value */
    virtual long getHashVal(const string);
};

#endif