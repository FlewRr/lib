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
        ASSERT_NO_THROW(xml.load("data/note.xml"));
    }
}
