/* File name: CMD5HashFun.h
 * Authors: Xiaodan Xi
 */

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <hash>

#include "CMD5HashFun.h"

using std::map;
using std::string;
using std::vector;

long CMD5HashFun::getHashVal(const char * instr)
{
    int i;
    long hash = 0;
    unsigned char digest[16];
 
    /* Use MD5 related funtions to generate MD5 code of instr, and store in digest */
    md5_state_t md5state;
    md5_init(&md5state);
    md5_append(&md5state, (const unsigned char *)instr, strlen(instr));
    md5_finish(&md5state, digest);
 
    /* Every four bytes constitute a 32b integer, and sum the four integers to get hash value of instr */
    for(i = 0; i < 4; i++)
    {
        hash += ((long)(digest[i*4 + 3]&0xFF) << 24)
            | ((long)(digest[i*4 + 2]&0xFF) << 16)
            | ((long)(digest[i*4 + 1]&0xFF) <<  8)
            | ((long)(digest[i*4 + 0]&0xFF));
    }
    return hash;
}
