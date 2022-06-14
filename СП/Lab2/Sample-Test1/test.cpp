#include "pch.h"
#include "../StaticLib1/HT.h"
using namespace std;
using namespace HT;

namespace UnitTest1
{
	class TestFoo : public ::testing::Test
	{
	protected:
		void SetUp()
		{
			HTFirst = HT::Create(10, 2, 10, 10, L"first.ht");
			el = new Element("1", 1, "first", 5);
			HT::Insert(HTFirst, el);
		}

		void TearDown()
		{
			HT::Delete(HTFirst, el);
			HT::Close(HTFirst);
		}

		HT::Element* el;
		HT::HTHANDLE* HTFirst;
	};

	TEST_F(TestFoo, Append)
	{
		HT::Element* el2 = new Element("1", 15, "second1", 51);
		ASSERT_TRUE(HT::Insert(HTFirst, el2));
	}

	TEST_F(TestFoo, Change)
	{
		HT::Element* el3 = new Element("1", 1, "second", 5);
		ASSERT_TRUE(HT::Update(HTFirst, el, el3->payload, el3->payloadlength));
	}

	TEST_F(TestFoo, Purification)
	{
		ASSERT_TRUE(HT::Delete(HTFirst, el));
	}

	int main(int argc, char* argv[])
	{
		::testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
	}
}