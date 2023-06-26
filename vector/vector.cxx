#include <cstddef>
#include <iostream>
#include <ctime>
#include <vector>

int main(int argc, char* argv[]) {

	// get the array size from the command line argument
	std::size_t n = 100;
	if (argc > 1) n = atol(argv[1]);

	// allocate
  std::vector<double> a(n);

	time_t start, end;

	// compute
	time(&start);
	double s = 0;
	for (std::size_t i = 0; i < n; ++i) {
		a[i] = i;
		s += a[i];
	}
	time(&end);

	// check
	double sexact = n * (n - 1) / 2.;
	std::cout << "s = " << s << " exact: " << sexact << " time: " << double(end - start) << " sec \n";

	return 0;
}
