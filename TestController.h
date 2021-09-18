#pragma once
#include <vector>

// Forward declarations
class UnitTest;


class TestController
{
public:
  
  void AddUnitTest(UnitTest* unitTest);
  void ExecuteSingleTest(const char* testName, const char* testCase);
  void ExecuteAllUnitTests();
  TestController();
  ~TestController();

private:
  
  std::vector<UnitTest*> UnitTests;
};