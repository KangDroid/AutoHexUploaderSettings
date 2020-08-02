#include <iostream>
#include <fstream>
#include <json/json.h>

using namespace std;

int main(void) {
    string url;
    int port;
    string api_key;
    string input_force;
    bool force;
    string printer_type;

    int printer_count;
    cout << "How many printers you want to set[init]: ";
    cin >> printer_count;
    Json::Value total_write;
    for (int i = 0; i < printer_count; i++) {
        cout << "Setting for printer " << i+1 << endl;
        cout << "What is octoprint url for this printer?[Without port]" << endl;
        cout << "For example, url would be http://localhost" << endl;
        cout << "Input: ";
        cin >> url;

        cout << "What is octoprint port for this printer? :";
        cout << "For example, port would be 5000" << endl;
        cout << "Input: ";
        cin >> port;

        cout << "What is apikey for this printer? :";
        cout << "Apikey should be 32-bit length" << endl;
        cout << "Input: ";
        cin >> api_key;

        cout << "Is this printer going to force-upload even its printing?" << endl;
        cout << "Type \"yes\" or \"no\" :";
        cin >> input_force;
        if (input_force == "yes") {
            force = true;
        } else {
            force = false;
        }

        cout << "What is this printer?" << endl;
        cout << "Available printers are: CoreM, SlideFast, CoreM_Multi, Lugo" << endl;
        cout << "Input: ";
        cin >> printer_type;

        // Create json;
        total_write[i]["main_url"] = url;
        total_write[i]["port"] = port;
        total_write[i]["api_key"] = api_key;
        total_write[i]["input_force"] = force;
        total_write[i]["printer_type"] = printer_type;
    }
    ofstream open_file("generated.json");
    open_file << total_write.toStyledString();
    open_file.close();
    return 0;
}