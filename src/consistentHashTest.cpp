/* File name: consistentHashTest.cpp
 * Authors: Xiaodan Xi
 */

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "consistentHash.h"

using std::map;
using std::string;
using std::vector;

static inline bool operator==( Entry& lhs, Entry& rhs )
{
    if ( lhs.hashCode() == rhs.hashCode() )
        return true;
    
    return false;
}

class consistentHashTest
{
private:
    Cluster createCluster()
    {
        Cluster _c;
        Server s1 ( "192.168.0.0" );
        Server s2 ( "192.168.0.1" );
        Server s3 ( "192.168.0.2" );
        Server s4 ( "192.168.0.3" );
        Server s5 ( "192.168.0.4" );
        Server s6 ( "192.168.0.5" );
        _c.addServer( s1 );
        _c.addServer( s2 );
        _c.addServer( s3 );
        _c.addServer( s4 );
        _c.addServer( s5 );
        _c.addServer( s6 );
        
        return _c;
    }

    void findEntries( Cluster c, vector<Entry> entries )
    {
        vector<Entry>::const_iterator _iter = entries.begin();
        for ( ; _iter != entries.end(); ++_iter )
        {
            Entry tmpEntry = *_iter;
            Entry tmpEntry2 = c.get(tmpEntry);
            if ( tmpEntry == tmpEntry2 )
                std::cout << "Entry found again: " << tmpEntry.hashCode() << std::endl;
            else
                std::cout << "Entry invalid: " << tmpEntry.hashCode() << std::endl;
        }
    }

public:
    consistentHashTest();

    void test()
    {
        Cluster c = createCluster();
        Entry e1 ( "i" );
        Entry e2 ( "have" );
        Entry e3 ( "a" );
        Entry e4 ( "pen" );
        Entry e5 ( "an" );
        Entry e6 ( "apple" );
        Entry e7 ( "applepen" );
        Entry e8 ( "pineapple" );
        Entry e9 ( "pinapplepen" );
        Entry e10 ( "PPAP" );

        vector<Entry> entries {};
        entries.push_back(e1);
        entries.push_back(e2);
        entries.push_back(e3);
        entries.push_back(e4);
        entries.push_back(e5);
        entries.push_back(e6);
        entries.push_back(e7);
        entries.push_back(e8);
        entries.push_back(e9);
        entries.push_back(e10);

        vector<Entry>::const_iterator iter = entries.begin();
        for ( ; iter != entries.end(); ++iter )
        {
            Entry tmpEntry = *iter;
            c.put(tmpEntry);
        }

        Server newServer ( "192.168.0.6" );
        c.addServer( newServer );

        findEntries( c, entries );
    }
};

consistentHashTest::consistentHashTest() {}

int main()
{
    consistentHashTest test;
    test.test();

    return 0;
}