# Hello C++
## Install C++
```
Here goes nothing @@
```
## Making --std=C++17 default in Mac OS 
- Add alias to `~/.zshrc`
```
alias g++='g++ -std=c++17'
```

- follow these commands
    ```
        cd ~
        cat .zshrc
        vim .zshrc
    ```
  - press `i` to INSERT `alias g++='g++ -std=c++17'`.
  - press `ESC` and input `:wq` to save the change.
  - Enter `exec zsh` to restart terminal.

## Setup C++ Configurations in VSCode
- Check c++ version with execute the code below:
    ````c++
    #include <iostream>
    #include <typeinfo>

    int main()
    {
        if (__cplusplus == 201703L) std::cout << "C++17\n";
        else if (__cplusplus == 201402L) std::cout << "C++14\n";
        else if (__cplusplus == 201103L) std::cout << "C++11\n";
        else if (__cplusplus == 199711L) std::cout << "C++98\n";
        else std::cout << "pre-standard C++\n";

    }
    ````
- Create `c_cpp_properties.json` with the text below:
    ```json
    {
        "configurations": [
            {
                "name": "Mac",
                "includePath": [
                    "${workspaceFolder}/**"
                ],
                "defines": [],
                "macFrameworkPath": [
                    "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks"
                ],
                "compilerPath": "/usr/bin/clang",
                "cStandard": "c17",
                "cppStandard": "c++17",
                "intelliSenseMode": "macos-clang-arm64"
            }
        ],
        "version": 4
    }
    ```