#include <algorithm>
#include <vector>
using namespace std;

class Employee {
public:
	int happy;
	vector<Employee> subordiantes;
};

struct ReturnType
{
	int yes_X_max;
	int no_X_max;
};

ReturnType process(const Employee& X)
{
	int yes_X_max = X.happy;
	int no_X_max = 0;
	if (X.subordiantes.empty())
		return { yes_X_max, no_X_max };

	for (auto& subordiante : X.subordiantes)
	{
		auto data = process(subordiante);
		no_X_max += std::max(data.no_X_max, data.yes_X_max);
		yes_X_max += data.no_X_max;
	}

	return { yes_X_max, no_X_max };
}

int getMaxHappy(const Employee& boss)
{
	auto data = process(boss);
	return std::max(data.no_X_max, data.yes_X_max);
}