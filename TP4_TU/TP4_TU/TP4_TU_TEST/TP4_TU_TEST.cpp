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
	};
}
