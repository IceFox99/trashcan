#include <memory>

int main()
{
	std::unique_ptr<int> i(new int(250));
	//std::unique_ptr<int> j(i);
	// Error message: attempting to reference a deleted function

	return 0;
}