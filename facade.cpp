#include <bits/stdc++.h>
using namespace std;

// The Complex Subsystem
class CPU {
public:
    void freeze() { cout << "[CPU] Freezing registers..." << endl; }
    void jump(long position) { cout << "[CPU] Jumping to instruction pointer: 0x" << hex << position << dec << endl; }
    void execute() { cout << "[CPU] Executing boot instructions..." << endl; }
};

class HardDrive {
public:
    string read(long lba, int size) {
        cout << "[HardDrive] Reading " << size << " sectors from LBA sectors at address 0x" << hex << lba << dec << "..." << endl;
        return "BOOT_SECTOR_KERNEL_DATA";
    }
};

class Memory {
public:
    void load(long position, string data) {
        cout << "[Memory] Loading data into RAM address 0x" << hex << position << dec << ": '" << data << "'" << endl;
    }
};

class ComputerFacade {
private:
    CPU *cpu;
    HardDrive* hdd;
    Memory* memory;
    const long BOOT_ADDRESS = 0x7C00;
    const long SECTOR_LBA = 0x0001;
    const int SECTOR_SIZE = 512;
public:
    ComputerFacade()
    {
        this->cpu = new CPU();
        this->hdd = new HardDrive();
        this->memory = new Memory();
    }
    ~ComputerFacade()
    {
        delete cpu;
        delete memory;
        delete hdd;
    }
    void startComputer()
    {
        cout<<"Starting Computer Boot System"<<endl;
        cpu->freeze();
        string bootData = hdd->read(SECTOR_LBA, SECTOR_SIZE);
        memory->load(BOOT_ADDRESS, bootData);
        cpu->jump(BOOT_ADDRESS);
        cpu->execute();
        cout<<"System Ready for Action!!"<<endl;
    }
};


int main()
{
    ComputerFacade* cmp = new ComputerFacade();
    cmp->startComputer();
    delete cmp;
}