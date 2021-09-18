#pragma once
#include <functional>
#include <string>
#include <vector>

// Forward declarations
class UnitTest;

// Class definition
class TestPkg
{
public:

  void Clear();
  void AddTestCase(const char* name, 
                   std::string str,
                   std::function<void()> testFunc);
  void CHECK_EQUALS(const char* func,
                    int line,
                    const char* actualStr,
                    const char* expectedStr,
                    void* actual,
                    void* expected);
  void CHECK_EQUALS(const char* func,
                    int line,
                    const char* actualStr,
                    const char* expectedStr,
                    int actual,
                    int expected);
  void CHECK_EQUALS(const char* func,
                    int line,
                    const char* actualStr,
                    const char* expectedStr,
                    bool actual,
                    bool expected);
  void CHECK_EQUALS(const char* func,
                    int line,
                    const char* actualStr,
                    const char* expectedStr,
                    float actual,
                    float expected);
  void CHECK_EQUALS(const char* func,
                    int line,
                    const char* actualStr,
                    const char* expectedStr,
                    double actual,
                    double expected);
  void CHECK_NEQUALS(const char* func,
                     int line,
                     const char* actualStr,
                     const char* expectedStr,
                     void* actual,
                     void* expected);
  void CHECK_NEQUALS(const char* func,
                     int line,
                     const char* actualStr,
                     const char* expectedStr,
                     int actual,
                     int expected);
  void CHECK_NEQUALS(const char* func,
                     int line,
                     const char* actualStr,
                     const char* expectedStr,
                     bool actual,
                     bool expected);
  void CHECK_NEQUALS(const char* func,
                     int line,
                     const char* actualStr,
                     const char* expectedStr,
                     float actual,
                     float expected);
  void CHECK_NEQUALS(const char* func,
                     int line,
                     const char* actualStr,
                     const char* expectedStr,
                     double actual,
                     double expected);
  void CHECK_TRUE(const char* func,
                  int line,
                  const char* actualStr, 
                  bool actual);
  void CHECK_FALSE(const char* func,
                   int line,
                   const char* actualStr,
                   bool actual);

  // The following functions should be invoked as-is.
  void ExecuteAllTests();
  void ExecuteSingleTest(const char* testCase);
  std::string GetClassName() const;
  TestPkg(const char* className, UnitTest* instance);
  ~TestPkg();

private:

  void Finalize();

  std::string ClassName;
  std::vector<std::string> TestCaseNames;
  std::vector<std::function<void()>> TestCasePointers;
  std::vector<std::string> TestFailures;
  UnitTest* TestInstance;
};

