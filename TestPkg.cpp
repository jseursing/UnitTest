#include "TestPkg.h"
#include "UnitTest.h"
#include <chrono>
#include <iostream>

/////////////////////////////////////////////////////////////////////////////////////////
//
// Function: Clear
// Notes:    None
//
/////////////////////////////////////////////////////////////////////////////////////////
void TestPkg::Clear()
{
  TestCaseNames.clear();
  TestCasePointers.clear();
}

/////////////////////////////////////////////////////////////////////////////////////////
//
// Function: AddTestCase
// Notes:    None
//
/////////////////////////////////////////////////////////////////////////////////////////
void TestPkg::AddTestCase(const char* name,
                          std::string str,
                          std::function<void()> testFunc)
{
  TestCaseNames.push_back(std::string(std::string(name) + str).c_str());
  TestCasePointers.push_back(testFunc);
}

/////////////////////////////////////////////////////////////////////////////////////////
//
// Function: CHECK_EQUALS
// Notes:    None
//
/////////////////////////////////////////////////////////////////////////////////////////
void TestPkg::CHECK_EQUALS(const char* func,
                           int line,
                           const char* actualStr,
                           const char* expectedStr,
                           void* actual,
                           void* expected)
{
  if (actual != expected)
  {
    std::string failStr = 
      std::string(func) + ":L" + std::to_string(line) + "\t" +
      std::string(actualStr) + "(" +
      std::to_string(reinterpret_cast<uintptr_t>(actual)) + ") != " +
      std::string(expectedStr) + "(" +
      std::to_string(reinterpret_cast<uintptr_t>(expected)) + ")\n";
    TestFailures.push_back(failStr);

    std::cout << failStr.c_str();
  }
}

/////////////////////////////////////////////////////////////////////////////////////////
//
// Function: CHECK_EQUALS
// Notes:    None
//
/////////////////////////////////////////////////////////////////////////////////////////
void TestPkg::CHECK_EQUALS(const char* func,
                           int line,
                           const char* actualStr,
                           const char* expectedStr,
                           int actual,
                           int expected)
{
  if (actual != expected)
  {
    std::string failStr = 
      std::string(func) + ":L" + std::to_string(line) + "\t" +
      std::string(actualStr) + "(" +
      std::to_string(actual) + ") != " +
      std::string(expectedStr) + "(" +
      std::to_string(expected) + ")\n";
    TestFailures.push_back(failStr);

    std::cout << failStr.c_str();
  }
}

/////////////////////////////////////////////////////////////////////////////////////////
//
// Function: CHECK_EQUALS
// Notes:    None
//
/////////////////////////////////////////////////////////////////////////////////////////
void TestPkg::CHECK_EQUALS(const char* func,
                           int line,
                           const char* actualStr,
                           const char* expectedStr,
                           bool actual,
                           bool expected)
{
  if (actual != expected)
  {
    std::string failStr =
      std::string(func) + ":L" + std::to_string(line) + "\t" +
      std::string(actualStr) + "(" +
      std::string(true == actual ? "true" : "false") + ") != " +
      std::string(expectedStr) + "(" +
      std::string(true == expected ? "true" : "false") + ")\n";

    TestFailures.push_back(failStr);

    std::cout << failStr.c_str();
  }
}

/////////////////////////////////////////////////////////////////////////////////////////
//
// Function: CHECK_EQUALS
// Notes:    None
//
/////////////////////////////////////////////////////////////////////////////////////////
void TestPkg::CHECK_EQUALS(const char* func,
                           int line,
                           const char* actualStr,
                           const char* expectedStr,
                           float actual,
                           float expected)
{
  if (actual != expected)
  {
    std::string failStr =
      std::string(func) + ":L" + std::to_string(line) + "\t" +
      std::string(actualStr) + "(" +
      std::to_string(actual) + ") != " +
      std::string(expectedStr) + "(" +
      std::to_string(expected) + ")\n";
    TestFailures.push_back(failStr);

    std::cout << failStr.c_str();
  }
}


/////////////////////////////////////////////////////////////////////////////////////////
//
// Function: CHECK_EQUALS
// Notes:    None
//
/////////////////////////////////////////////////////////////////////////////////////////
void TestPkg::CHECK_EQUALS(const char* func,
                           int line,
                           const char* actualStr,
                           const char* expectedStr,
                           double actual,
                           double expected)
{
  if (actual != expected)
  {
    std::string failStr =
      std::string(func) + ":L" + std::to_string(line) + "\t" +
      std::string(actualStr) + "(" +
      std::to_string(actual) + ") != " +
      std::string(expectedStr) + "(" +
      std::to_string(expected) + ")\n";
    TestFailures.push_back(failStr);

    std::cout << failStr.c_str();
  }
}


/////////////////////////////////////////////////////////////////////////////////////////
//
// Function: CHECK_NEQUALS
// Notes:    None
//
/////////////////////////////////////////////////////////////////////////////////////////
void TestPkg::CHECK_NEQUALS(const char* func,
                            int line,
                            const char* actualStr,
                            const char* expectedStr,
                            void* actual,
                            void* expected)
{
  if (actual == expected)
  {
    std::string failStr = 
      std::string(func) + ":" + std::to_string(line) + "\t" +
      std::string(actualStr) + "(" + 
      std::to_string(reinterpret_cast<uintptr_t>(actual)) + ") == " +
      std::string(expectedStr) + "(" +
      std::to_string(reinterpret_cast<uintptr_t>(expected)) + ")\n";

    TestFailures.push_back(failStr);

    std::cout << failStr.c_str();
  }
}

/////////////////////////////////////////////////////////////////////////////////////////
//
// Function: CHECK_NEQUALS
// Notes:    None
//
/////////////////////////////////////////////////////////////////////////////////////////
void TestPkg::CHECK_NEQUALS(const char* func,
                            int line,
                            const char* actualStr,
                            const char* expectedStr,
                            int actual,
                            int expected)
{
  if (actual == expected)
  {
    std::string failStr =
      std::string(func) + ":" + std::to_string(line) + "\t" +
      std::string(actualStr) + "(" +
      std::to_string(actual) + ") == " +
      std::string(expectedStr) + "(" +
      std::to_string(expected) + ")\n";

    TestFailures.push_back(failStr);

    std::cout << failStr.c_str();
  }
}

/////////////////////////////////////////////////////////////////////////////////////////
//
// Function: CHECK_NEQUALS
// Notes:    None
//
/////////////////////////////////////////////////////////////////////////////////////////
void TestPkg::CHECK_NEQUALS(const char* func,
                            int line,
                            const char* actualStr,
                            const char* expectedStr,
                            bool actual,
                            bool expected)
{
  if (actual == expected)
  {
    std::string failStr =
      std::string(func) + ":" + std::to_string(line) + "\t" +
      std::string(actualStr) + "(" +
      std::string(actual == true ? "true" : "false") + ") == " +
      std::string(expectedStr) + "(" +
      std::string(expected == true ? "true" : "false") + ")\n";

    TestFailures.push_back(failStr);

    std::cout << failStr.c_str();
  }
}

/////////////////////////////////////////////////////////////////////////////////////////
//
// Function: CHECK_NEQUALS
// Notes:    None
//
/////////////////////////////////////////////////////////////////////////////////////////
void TestPkg::CHECK_NEQUALS(const char* func,
                            int line,
                            const char* actualStr,
                            const char* expectedStr,
                            float actual,
                            float expected)
{
  if (actual == expected)
  {
    std::string failStr =
      std::string(func) + ":" + std::to_string(line) + "\t" +
      std::string(actualStr) + "(" +
      std::to_string(actual) + ") == " +
      std::string(expectedStr) + "(" +
      std::to_string(expected) + ")\n";

    TestFailures.push_back(failStr);

    std::cout << failStr.c_str();
  }
}

/////////////////////////////////////////////////////////////////////////////////////////
//
// Function: CHECK_NEQUALS
// Notes:    None
//
/////////////////////////////////////////////////////////////////////////////////////////
void TestPkg::CHECK_NEQUALS(const char* func,
                            int line,
                            const char* actualStr,
                            const char* expectedStr,
                            double actual,
                            double expected)
{
  if (actual != expected)
  {
    std::string failStr =
      std::string(func) + ":" + std::to_string(line) + "\t" +
      std::string(actualStr) + "(" +
      std::to_string(actual) + ") == " +
      std::string(expectedStr) + "(" +
      std::to_string(expected) + ")\n";

    TestFailures.push_back(failStr);

    std::cout << failStr.c_str();
  }
}

/////////////////////////////////////////////////////////////////////////////////////////
//
// Function: CHECK_NEQUALS
// Notes:    None
//
/////////////////////////////////////////////////////////////////////////////////////////
void TestPkg::CHECK_TRUE(const char* func,
                         int line,
                         const char* actualStr,
                         bool actual)
{
  if (true != actual)
  {
    std::string failStr =
      std::string(func) + ":" + std::to_string(line) + "\t" +
      std::string(actualStr) + "(" +
      std::string(actual == true ? "true" : "false") + ") != true\n";

    TestFailures.push_back(failStr);

    std::cout << failStr.c_str();
  }
}

/////////////////////////////////////////////////////////////////////////////////////////
//
// Function: CHECK_NEQUALS
// Notes:    None
//
/////////////////////////////////////////////////////////////////////////////////////////
void TestPkg::CHECK_FALSE(const char* func,
                          int line,
                          const char* actualStr,
                          bool actual)
{
  if (false != actual)
  {
    std::string failStr =
      std::string(func) + ":" + std::to_string(line) + "\t" +
      std::string(actualStr) + "(" +
      std::string(actual == true ? "true" : "false") + ") != false\n";

    TestFailures.push_back(failStr);

    std::cout << failStr.c_str();
  }
}

/////////////////////////////////////////////////////////////////////////////////////////
//
// Function: AddTestCase
// Notes:    None
//
/////////////////////////////////////////////////////////////////////////////////////////
void TestPkg::ExecuteAllTests()
{
  // Output status for test entry
  std::cout << "Executing " << ClassName.c_str() << " : " 
            << TestCasePointers.size() << " Tests" << std::endl;

  // Begin executing all tests
  for (size_t i = 0; i < TestCasePointers.size(); ++i)
  {
    // Retrieve current time and current fail count
    uint32_t currFailCount = TestFailures.size();;    
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    // Begin test case
    std::cout << "[EXEC  ] " << TestCaseNames[i].c_str() << std::endl;
    TestInstance->SetUp();
    TestCasePointers[i]();
    TestInstance->TearDown();

    // Retrieve elapsed time and output status
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    uint32_t elapsedMS = std::chrono::duration_cast<std::chrono::milliseconds>
                         (end - begin).count();
    std::cout << (currFailCount == TestFailures.size() ? "[  PASS] " :
                                                         "[  FAIL] ") 
              << TestCaseNames[i].c_str() <<  " (" << elapsedMS << " ms)" << std::endl;
  }

  // Output end status
  Finalize();
}

/////////////////////////////////////////////////////////////////////////////////////////
//
// Function: GetClassName
// Notes:    None
//
/////////////////////////////////////////////////////////////////////////////////////////
void TestPkg::ExecuteSingleTest(const char* testCase)
{
  // Begin executing all tests
  for (size_t i = 0; i < TestCasePointers.size(); ++i)
  {
    // Retrieve current time and current fail count
    uint32_t currFailCount = TestFailures.size();;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    if (0 == TestCaseNames[i].compare(testCase))
    {
      // Output status for test entry
      std::cout << "Executing " << ClassName.c_str() << " : "
                << TestCasePointers.size() << " Tests" << std::endl;

      // Begin test case
      std::cout << "[EXEC  ] " << TestCaseNames[i].c_str() << std::endl;
      TestInstance->SetUp();
      TestCasePointers[i]();
      TestInstance->TearDown();

      // Retrieve elapsed time and output status
      std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
      uint32_t elapsedMS = std::chrono::duration_cast<std::chrono::milliseconds>
                           (end - begin).count();
      std::cout << (currFailCount == TestFailures.size() ? "[  PASS] " :
                                                           "[  FAIL] ")
                << TestCaseNames[i].c_str() << " (" << elapsedMS << " ms)" << std::endl;

      break;
    }
  }

  // Output end status
  Finalize();
}

/////////////////////////////////////////////////////////////////////////////////////////
//
// Function: GetClassName
// Notes:    None
//
/////////////////////////////////////////////////////////////////////////////////////////
std::string TestPkg::GetClassName() const
{
  return ClassName;
}

/////////////////////////////////////////////////////////////////////////////////////////
//
// Function: TestPkg
// Notes:    None
//
/////////////////////////////////////////////////////////////////////////////////////////
TestPkg::TestPkg(const char* className, UnitTest* instance) :
  ClassName(className),
  TestInstance(instance)
{

}

/////////////////////////////////////////////////////////////////////////////////////////
//
// Function: ~TestPkg
// Notes:    None
//
/////////////////////////////////////////////////////////////////////////////////////////
TestPkg::~TestPkg()
{

}

/////////////////////////////////////////////////////////////////////////////////////////
//
// Function: Finalize
// Notes:    None
//
/////////////////////////////////////////////////////////////////////////////////////////
void TestPkg::Finalize()
{
  if (0 == TestFailures.size())
  {
    std::cout << "All tests passed successfully" << std::endl;
  }
  else
  {
    std::cout << "Total Failures: " << TestFailures.size() << std::endl;
  }
  
  std::cout << std::endl;
}