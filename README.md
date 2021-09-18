# UnitTest
This is a generic unit testing class (to be built as a static library).

# Example Usage

#include "UnitTest.h"

class ObjListTest : public UnitTest
{
public:

  ObjListTest() :
  UnitTest("ObjListTest")
  {}
  
  ~ObjListTest() {}

  virtual void SetUp()
  {
    // Code invoked prior to each test case
  }
  
  virtual void TearDown()
  {
    // Code invoked after each test case
  }
  
  void TestCase()
  {
    int a = 1;
    TEST_EQ(a, 1);
    TEST_NE(a, 3);
    TEST_TRUE(1 == a);
    TEST_FALSE(1 != a);
  }
  
  TestPkg* BuildTestPkg()
  {
    INITIALIZE();
    ADD_TEST(ObjListTest, TestCase);
    FINALIZE();
  }

private:

};

# main.cpp
int main(int argc, char* argv[])
{
  TestController controller;
  controller.AddUnitTest(new ObjListTest());
  controller.ExecuteAllUnitTests();
}
