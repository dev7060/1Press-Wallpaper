#include <iostream>
#include <string.h>
#include <fstream>
#include <windows.h>
#include <conio.h>
using namespace std;
int main(int argc, char **argv)
{   system("title 1Press-Wallpaper by github.com/dev7060");
    system("color 0A");
    argc=1;
    if(argc==1){
        argv[1] = "1920";
        argv[2] = "1080";
    }
    while(1){
        fflush(stdin);
        system("cls");
        string width = argv[1];
        string height = argv[2];
        cout<<"* Finding...\n";
        string cmd = "curl -v https://source.unsplash.com/random/"+ width + "x" + height + " > temp";
        system(cmd.c_str());
        ifstream ifile("temp");
        string object;
        getline(ifile, object);
        ifile.close();
        system("del temp");
        int loc = object.find("href");
        string url;
        for(int i=loc+6; object[i]!='\"'; i++){
                url = url + object[i];
        }
        cout<<"\n* Downloading...\n";
        string cmd2 = "curl -v \"" + url + "\" > wallpaper.jpg";
        cout<<"\n\n";
        system(cmd2.c_str());
        TCHAR buffer[100];
        GetCurrentDirectory(100, buffer);
        string path = buffer;
        path += "/wallpaper.jpg";
        char path2[100];
        strcpy(path2, path.c_str());
        char *path3;
        path3 = path2;
        int res = SystemParametersInfo( SPI_SETDESKWALLPAPER, 0, path3, SPIF_UPDATEINIFILE );
        system("del wallpaper.jpg");
        if(res){
            cout<<"\n"<<"* Success";
        }else{
            cout<<"\n"<<"* Error";
        }
        fflush(stdin);
        cout<<"\n* Press any key for change...";
        _getch();
    }
    return 0;
}
