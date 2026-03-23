#include "pch.h"
#include "CppUnitTest.h"


extern "C" {
#include "../TP4_TU/TP4_TU.h"
}
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TP4TUTEST
{
	TEST_CLASS(TP4TUTEST)
	{
	public:
		
		TEST_METHOD(TestEstPair)
		{
			Assert::AreEqual(estPair(6), 1);
		}
		TEST_METHOD(TestEstPair)
		{
			Assert::AreEqual(estPair(4), 1);
		}
		TEST_METHOD(TestEstPair)
		{
			Assert::AreEqual(estPair(7), 0);
		}
		TEST_METHOD(TestEstPair)
		{
			Assert::AreEqual(estPair(0), 1);
		}
		TEST_METHOD(TestEstPair)
		{
			Assert::AreEqual(estPair(-2), 1);
		}
		TEST_METHOD(TestEstPair)
		{
			Assert::AreEqual(estPair(-3), 0);
		}


	};
}
