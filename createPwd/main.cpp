/*
입력 데이터를 고정된 크기의 해시 값으로 변환: 이를 위해 입력 데이터를 일정한 규칙을 통해 처리하고, 최종적으로 고정된 길이의 값을 만들어야 합니다.
충돌 방지: 해시 함수는 충돌을 피하는 것이 중요합니다. 즉, 두 개의 서로 다른 입력이 동일한 해시 값을 생성하지 않도록 해야 합니다.
일방향성: 해시 값으로부터 원본 데이터를 복원할 수 없게 해야 합니다. 이를 위해 여러 번의 반복적인 연산을 사용할 수 있습니다.
*/

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