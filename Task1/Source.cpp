#include "sharedptr.cpp"
#include "uniqueptr.cpp"
int main()
{
	unique_ptr<int> p1(new int(1));
	unique_ptr<int> p2;
	p2 = std::move(p1);
	std::cout << p2.get() << std::endl;
	///////////////////////////////////
	shared_ptr<int> s1(new int(2));
	shared_ptr<int> s2(s1);
	shared_ptr<int> s3(s1);
	std::cout << s1.count() << std::endl;
	std::cout << s1.get() << std::endl;
}