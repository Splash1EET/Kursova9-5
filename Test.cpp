#include <UnitTest++/UnitTest++.h>
#include "LicCheck.h"
TEST(UserName) 
{
	CHECK_EQUAL(true,KeyChecker().keyCheck("Dovlatbekyan", "3b10d33ab669060e090e7383cb820c2c"));
	CHECK_EQUAL(true,KeyChecker().keyCheck("Dovla7beky4n", "a8c155cf66a60a38958491dd77877ecb"));
	CHECK_EQUAL(true,KeyChecker().keyCheck("Довла7бекя4", "b8a091e4146bf94be9f95e5b48f11a72"));
	CHECK_EQUAL(true,KeyChecker().keyCheck("Dоvла7бекя4_1", "e819b1f31acecd745111c04799d74a17"));
}
TEST(TestKey)
{
	CHECK_EQUAL(true,KeyChecker().keyCheck("Dovlatbekyan", "3b10d33ab669060e090e7383cb820c2c"));
	CHECK_EQUAL(false,KeyChecker().keyCheck("Dovlatbekyan", "3b10d33ab669060e"));
	CHECK_THROW(KeyChecker().keyCheck("Dovlatbekyan", "3b10d33abв669060eв090e1п73уцф83cb820c2c"), int);
}
TEST(FuncMD5)
{
CHECK_EQUAL("aef8505aa1c1f31be726fe1cab4f7b0c",md5("Dovlatbekyan"));
CHECK_EQUAL("12778f3376109b636d708f5a9f5ee825",md5("Dovla7beky4n"));
CHECK_EQUAL("702dfff5e152f2dbee901fca56afbfe8",md5("Довла7бекя4"));
CHECK_EQUAL("ccfc83927904a249912b4e576ed1dd81",md5("Dоvла7бекя4_1"));
}
int main(int argc, char **argv)
{
	return UnitTest::RunAllTests();
}
