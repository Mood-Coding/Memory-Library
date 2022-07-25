// Get Process Handle
HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessID);

// Read memory
int buffer;
if (!MM::read(hProcess, 0x006FF748, &buffer))
    return 1;
std::cout << buffer << '\n';

// Write memory
int buffer = -100;
if (!MM::write(hProcess, 0x006FF748, &buffer))
    return 1;
