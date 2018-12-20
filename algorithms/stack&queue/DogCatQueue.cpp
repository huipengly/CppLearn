/**
 * @file Template.cpp
 * @author huipengly
 * @brief 猫狗队列
 * @version 0.1
 * @date 2018-12-20
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <random>
#include <queue>
#include <stack>
#include <memory>

using namespace std;

std::random_device rd;			// 用来播种
default_random_engine e(rd());	// 随机数引擎
// uniform_int_distribution<int> u(0, 10);	// 产生一个[0, 10]的随机整数分布
// uniform_real_distribution<double> u(0, 10);	// 产生一个[0, 10)的随机实数分布
// int rand = u(e);	//产生随机数

// 测试用
auto testMethod(vector<int> &a);
auto compareMethod(vector<int> &a);
vector<int> generateRandomArray(int maxSize, int maxValue);
template <typename T> bool isEqual(T &lhs, T &rhs);
void test();

class Pet
{
public:
	Pet(string type) : type_(type) {};
	string getPetType() { return type_; }

private:
	string type_;
};

class Cat :
	public Pet
{
public:
	Cat() : Pet("cat") {};

};

class Dog :
	public Pet
{
public:
	Dog() : Pet("dog") {}
};

class PetEnter
{
public:
	PetEnter(shared_ptr<Pet> pet, long count) : pet_(pet), count_(count) {}
	string type() { return pet_->getPetType(); }
	long count() { return count_; }
	shared_ptr<Pet> pet() { return pet_; }

private:
	shared_ptr<Pet> pet_;
	long count_;
};

class DogCatQueue
{
public:
	void push(shared_ptr<Pet> pet);
	Pet pollDog();
	Pet pollCat();
	Pet pollAll();
	bool empty() { return catEmpty() && dogEmpty(); }
	bool catEmpty() { return CatQueue_.empty(); }
	bool dogEmpty() { return DogQueue_.empty(); }

private:
	queue<shared_ptr<PetEnter>> CatQueue_, DogQueue_;
	long count_ = 0;
};

void DogCatQueue::push(shared_ptr<Pet> pet)
{
	if (pet->getPetType() == "cat")
		CatQueue_.push(make_shared<PetEnter>(pet, count_++));
	else if (pet->getPetType() == "dog")
		DogQueue_.push(make_shared<PetEnter>(pet, count_++));
}

Pet DogCatQueue::pollDog()
{
	auto ret = DogQueue_.front();
	DogQueue_.pop();
	return *ret->pet();
}

Pet DogCatQueue::pollCat()
{
	auto ret = CatQueue_.front();
	CatQueue_.pop();
	return *ret->pet();
}

Pet DogCatQueue::pollAll()
{
	if (dogEmpty() || CatQueue_.front()->count() < DogQueue_.front()->count())
		return pollCat();
	else
		return pollDog();
}

int main()
{
	DogCatQueue test;

	shared_ptr<Pet> dog1 = make_shared<Dog>();
	shared_ptr<Pet> cat1 = make_shared<Cat>();
	shared_ptr<Pet> dog2 = make_shared<Dog>();
	shared_ptr<Pet> cat2 = make_shared<Cat>();
	shared_ptr<Pet> dog3 = make_shared<Dog>();
	shared_ptr<Pet> cat3 = make_shared<Cat>();

	test.push(dog1);
	test.push(cat1);
	test.push(dog2);
	test.push(cat2);
	test.push(dog3);
	test.push(cat3);

	test.push(dog1);
	test.push(cat1);
	test.push(dog2);
	test.push(cat2);
	test.push(dog3);
	test.push(cat3);

	test.push(dog1);
	test.push(cat1);
	test.push(dog2);
	test.push(cat2);
	test.push(dog3);
	test.push(cat3);
	while (!test.dogEmpty()) {
		cout << test.pollDog().getPetType() << endl;
	}
	while (!test.empty()) {
		cout << test.pollAll().getPetType() << endl;
	}
    return 0;
}

// 以下为测试用代码
auto testMethod(vector<int> &a)
{
	// 测试方法
}

auto compareMethod(vector<int> &a)
{
	// 对的方法
}

// 产生随机大小，数目的数组
vector<int> generateRandomArray(int maxSize, int maxValue)
{
	uniform_int_distribution<unsigned> uValue(0, maxValue);
	uniform_int_distribution<unsigned> uSize(0, maxSize);
	vector<int> vec(uSize(e));
	for (auto &i : vec)
		i = uValue(e);
	return vec;
}

// 判断结果是否相等
template <typename T>
bool isEqual(T &lhs, T &rhs)
{
	return lhs == rhs;
}

void test()
{
	int testTime = 50000;
	int maxSize = 20;
	int maxValue = 200;
	bool succeed = true;
	for (int i = 0; i != testTime; ++i)
	{
		auto TestData = generateRandomArray(maxSize, maxValue);
		auto TrueData = TestData;
		auto OriginData = TestData;

#define NO_RETURN_VALUE
//#define HAS_RETURN_VALUE

#ifdef NO_RETURN_VALUE
		// 无返回类型的判断
		testMethod(TestData);
		compareMethod(TrueData);
		if (!isEqual(TestData, TrueData))
		{
			succeed = false;
			break;
		}
#endif

#ifdef HAS_RETURN_VALUE
		// 有返回类型的判断
		auto TestResult = testMethod(TestData);
		auto CompareResult = compareMethod(TrueData);
		if (!isEqual(TestResult, CompareResult))
		{
			succeed = false;
			break;
		}
#endif
	}

	cout << (succeed ? "passed" : "BUG!") << endl;
}