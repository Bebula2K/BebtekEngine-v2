# BebtekEngine-v2

Designed to use in UNIX based systems to make terminal games.

Compile using ```g++ Main.cpp -o main -lncurses```

# Implementation

In main.cpp: 
```cpp
#include <iostream>
#include "Engine.h"
int main(){
    Engine engine;
    engine.waitForInput();
    return 0;
}
```
