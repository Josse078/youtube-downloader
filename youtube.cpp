#include <iostream>
#include <cstdlib>
using namespace std;
//jangan lupa isntall yt-dlp
//jangan lupa set up environment variable VIDEO_DIRECTORY
int main() {
    const char* videoDirectory = getenv("VIDEO_DIRECTORY");

    if (!videoDirectory) {
        cerr << "Error: VIDEO_DIRECTORY environment variable not set." << endl;
        return 1;
    }

    string link;
    cout << "Enter the YouTube video URL: ";
    getline(cin, link);

    
    string command = "yt-dlp --output \"" + string(videoDirectory) + "/%(title)s.%(ext)s\" " + link;

    int result = system(command.c_str());

    if (result != 0) {
        cerr << "An error has occurred" << endl;
    } else {
        cout << "Download is completed successfully" << endl;
    }

    return 0;
}