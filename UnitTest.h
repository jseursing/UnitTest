#pragma once
#include "TestPkg.h"

/////////////////////////////////////////////////
// 
// Class: UnitTest
// 
// Description: The following class should be 
// inherited by any test class. This class 
// provides a unit test class skeleton.
//
//

// Macro to trim filename down
#define __FILENAME__ (strrchr(__FILE__, '/\\') ? strrchr(__FILE__, '/\\') + 1 : __FILE__)

// Macros to setup test packages
#define INITIALIZE() \
  TestPackage->Clear();
#define ADD_TEST(_class,_case) \
  TestPackage->AddTestCase(#_case, "", std::bind(&_class::_case, this));
#define ADD_TEST_MSG(_class,_case,str) \
  TestPackage->AddTestCase(#_case, str, std::bind(&_class::_case, this));
#define FINALIZE() \
  return TestPackage;

// Macro to execute tests
#define EXECUTE_TESTS(_class) \
  _class.BuildTestPkg()->ExecuteAllTests();

// Test macros
#define TEST_EQ(x,y) \
  TestPackage->CHECK_EQUALS(__FILENAME__, __LINE__, #x, #y, x, y);
#define TEST_NE(x,y) \
  TestPackage->CHECK_NEQUALS(__FILENAME__, __LINE__, #x, #y, x, y);
#define TEST_TRUE(x) \
  TestPackage->CHECK_TRUE(__FILENAME__, __LINE__, #x, x);
#define TEST_FALSE(x) \
  TestPackage->CHECK_FALSE(__FILENAME__, __LINE__, #x, x);

//
// Class definition
//
class UnitTest
{
public:
  
  // The following virtual functions must be defined
  // by the inheriting test classes.
  virtual TestPkg* BuildTestPkg() = 0;
  virtual void SetUp() = 0;
  virtual void TearDown() = 0;
  TestPkg* GetTestPkg() const;
  UnitTest(const char* className);
  ~UnitTest();
  
protected:
 
  // Members
  std::string ClassName;
  TestPkg* TestPackage;
};

