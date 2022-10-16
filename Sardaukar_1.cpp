#include <iostream>
#include <fstream>
using namespace std;

struct ELFHEADER{
    uint8_t e_ident[16];
    uint16_t e_type; 
    uint16_t e_machine;
    uint32_t e_version;
    uint32_t e_entry;
    uint32_t e_phoff;
    uint32_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
};


int main(){
	FILE* file = fopen("1_1.o", "rb");
	ELFHEADER elf;
	fread(&elf, sizeof(elf), 1, file);

	if(elf.e_ident[4] == 2){
		cout << "Platform: ELF64\n";
	}else{
		cout << "Platform: ELF32\n";
	}

	if(elf.e_ident[5] == 1){
		cout << "Little endian\n";
	}else{
		cout << "Big Endian\n";
	}

	cout << "Virtual memory adress of entry point: " << elf.e_entry << endl;
	cout << elf.e_ehsize;	
	return 0;
}
