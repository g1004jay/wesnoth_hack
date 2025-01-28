#include <Windows.h>

int main(int argc, char** argv) {
	// prefix L casts char* to const wchar_t*.
	HWND wesnoth_window = FindWindow(NULL, L"The Battle for Wesnoth - 1.14.9");

	DWORD process_id = 0;
	GetWindowThreadProcessId(wesnoth_window, &process_id);

	HANDLE wesnoth_process = OpenProcess(PROCESS_ALL_ACCESS, true, process_id);

	DWORD gold_address = 0;
	DWORD gold_value = 0;
	SIZE_T bytes_read = 0;
	ReadProcessMemory(wesnoth_process, (LPCVOID)(0x017EECB8 + 0x60), &gold_address, 4, &bytes_read);
	gold_address += 0xA90;
	ReadProcessMemory(wesnoth_process, (LPCVOID)gold_address, &gold_address, 4, &bytes_read);
	gold_address += 0x4;
	ReadProcessMemory(wesnoth_process, (LPCVOID)gold_address, &gold_value, 4, &bytes_read);

	DWORD new_gold_value = 9999;
	SIZE_T bytes_written = 0;
	WriteProcessMemory(wesnoth_process, (LPVOID)gold_address, &new_gold_value, 4, &bytes_written);

	return 0;
}