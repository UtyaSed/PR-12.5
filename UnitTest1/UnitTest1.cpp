#include "pch.h"
#include "CppUnitTest.h"
#include "../PR 12.5/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* one;
			string num = "50";
			push(one, num);

			Assert::AreEqual(one->info, num);
		}
	};
}
