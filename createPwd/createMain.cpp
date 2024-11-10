// 1. 메시지 패딩
// 2. 메시지 확장
// 3. 초기 해시 값 설정
// 4. 압축 함수
// 5. 최종 해시 값 계산
#include <iostream>
#include <bitset>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

#define MAX_LENGTH 512 

// 무작위 상수
const uint32_t k[64] = {
	0x243F6A88, 0x85A308D3, 0x13198A2E, 0x03707344,
	0xA4093822, 0xDC9B0858, 0x5F2B57A3, 0x907CF7C6,
	0xA6C5A3B0, 0x6DBCC3F8, 0x18FECAC7, 0x2A7A6F2F,
	0x71A8B663, 0xB02E6D3F, 0x6A7568B3, 0x462B2A1F,
	0x0BC9B0B7, 0x88A56C3F, 0x728B67FE, 0xF6E7D9E4,
	0x4D09C1DC, 0x11A8BC29, 0xF1F0A2F0, 0x5E695742,
	0x8B2D0171, 0x9B16B69F, 0x6F2456B1, 0x489E53B5,
	0xD9A39F4A, 0x2A2E13E6, 0x4137F8B0, 0xF4F07C0F,
	0x945B028A, 0x79F6E76E, 0xD42C3AE9, 0x1B426DC6,
	0x54A7E62F, 0xFA215726, 0x7F307ABE, 0x249E1F9F,
	0xC98F2431, 0x58D7423D, 0x9D6D32DC, 0xB5E7C5B6,
	0xDF3BEBFE, 0xA2304F00, 0xB957734A, 0x44B3B0DB,
	0x5F1B5A9F, 0x3C9E3C61, 0x763F47A2, 0x6CC45327,
	0xEE15E703, 0xCFF5AE7D, 0x9066E03C, 0x45BE6D8E,
	0xE7265E1C, 0xF56FF6AB, 0x94DAA99F, 0xE9ABFD2A,
	0x2C5E689A, 0x8281F3A1, 0xA37A4C87, 0x013380C1
};

// 입력받은 메시지를 패딩(패딩이 추가된 메시지가 512비트 단위의 블록이 되도록 맞춤)
vector<uint8_t> padAndExtMsg(const string& message) {
	vector<uint8_t> paddedData(message.begin(), message.end());

	// 벡터 뒤에 1 추가
	paddedData.push_back(0x80);

	// 512 비트가 맞춰질때까지 0 추가
	while ((paddedData.size() % 64 != 56)) {
		paddedData.push_back(0x00);
	}

	uint64_t originalMsgLength = message.size() * 8;
	for (int i = 7; i >= 0; --i) {
		paddedData.push_back((originalMsgLength >> (i * 8)) & 0xFF);
	}

	return paddedData;
}

uint32_t to32(const uint8_t* block) {
	return (block[0] << 24 | block[1] << 16 | block[2] << 8) | block[3];
}

int main() {
	string input;
	getline(cin, input);

	vector<uint8_t> pad = padAndExtMsg(input);
	for (size_t a : pad) {
		cout << bitset<8>(a) << " ";
	}
	return 0;
}

