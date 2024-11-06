#include <iostream>
#include <stdint.h>
#include <sstream>
#include <iomanip>

using namespace std;
typedef uint32_t u32t;
typedef size_t st;

u32t simple_hash(const char *input) {
	u32t hash = 0xFFFFFFFF;
	int c;

	while ((c = *input++)) {
		hash = ((hash << 5) - hash) + c;
	}
	
	return hash;
}

string to_hex(u32t hash) {
	stringstream ss;
	ss << hex  << setfill('0') << hash;
	return ss.str();
}

int main() {
	char pwd[27];
	while (true) {
		cin >> pwd;
		
		u32t hash_v = simple_hash(pwd);

		cout << "Input :" << pwd << endl;
		cout << "Hv : " << to_hex(hash_v) << endl;

	}

	return 0;
}
