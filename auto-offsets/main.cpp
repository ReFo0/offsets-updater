#include <windows.h>
#include <iostream>
#include <fstream>
#include <urlmon.h>
#include <string>
#include "json.hpp"
#pragma comment(lib, "urlmon.lib")




void download_offsetjson() {
    std::string dwnld_URL = "https://cdn.discordapp.com/attachments/1169409410867679315/1180187021868797973/offsets.json?ex=657c81d0&is=656a0cd0&hm=e082f105bc556124108ead5322842183abb4848f3685370addbf15a556a6e09d&";
    std::string savepath = "C:\\ProgramData\\offsets.json";
    URLDownloadToFileA(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);
}


int main() {
        download_offsetjson();
        std::ifstream file("C:\\ProgramData\\offsets.json");
        if (!file.is_open()) {
            std::cout << "offsets.json not found." << std::endl;
            std::cin.get();
            return 0;
        }

        nlohmann::json data = nlohmann::json::parse(file);

        int ammo_offsets;
        int weapon_offsets;

        if (data["weapon name"] == "weapon") {
            auto address = data["weapon address"];
            weapon_offsets = address;
            std::cout << "weapon offsets: 0x" << weapon_offsets << std::endl;
        }

        if (data["ammo name"] == "ammo") {
            auto address = data["ammo address"];
            ammo_offsets = address;
            std::cout << "ammo offsets: 0x" << ammo_offsets << std::endl;
        }



        file.close();
        DeleteFileA("C:\\ProgramData\\offsets.json");
        std::cin.get();
        return 0;
}
