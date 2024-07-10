#include <gtest/gtest.h>
#include "shared_ptr.h"
#include "parser.h"
#include <string>


class Parsers: public ::testing::Test {
protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};

namespace Tests{
    XMLParser xml;
    JSONParser jsn;

    TEST_F(Parsers, JsonParsing){
        ASSERT_NO_THROW(jsn.load("/home/sfleur/lib/tests/tests/data/x.json"));
    }

    TEST_F(Parsers, XMLParsing){
        ASSERT_NO_THROW(xml.load("/home/sfleur/lib/tests/tests/data/note.xml"));
    }

    TEST_F(Parsers, JsonParsingtxt){
        EXPECT_ANY_THROW(jsn.load("/home/sfleur/lib/tests/tests/data/doc.txt"));
    }

    TEST_F(Parsers, XMLParsingtxt){
        EXPECT_ANY_THROW(xml.load("/home/sfleur/lib/tests/tests/data/doc.txt"));     
    }

    TEST_F(Parsers, XMLParsingArbitrary){
        EXPECT_ANY_THROW(xml.load("/home/sfleur/lib/tests/tests/data/x.yzx"));
    }

    TEST_F(Parsers, JSONParsingArbitrary){
        EXPECT_ANY_THROW(jsn.load("/home/sfleur/lib/tests/tests/data/x.yzx"));
    }

    TEST_F(Parsers, JSONParsingCorrupted){
        EXPECT_ANY_THROW(jsn.load("/home/sfleur/lib/tests/tests/data/broken.json"));
    }

    TEST_F(Parsers, XMLParsingCorrupted){
        EXPECT_ANY_THROW(xml.load("/home/sfleur/lib/tests/tests/data/broken.xml"));
    }
}
