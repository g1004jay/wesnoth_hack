#include <Windows.h>

void injected_thread() {
	if (GetAsyncKeyState('M')) {
		// Change the player's gold
	}

	Sleep(1);
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
	if (fdwReason == DLL_PROCESS_ATTACH) {
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)injected_thread, NULL, 0, NULL);
	}
	

	return true;
}