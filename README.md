Display Events Mod for mcpelauncher-linux
====================

This is a mod for [mcpelauncher-linux](https://github.com/MCMrARM/mcpelauncher-linux). It prints more player events to the console such as chat and player join events.

### Example Console Output

```
Steve joined the game
<Steve> hello
Steve left the game
```

### Compiling

To compile first extract libminecraftpe.so from the x86 version of the minecraftpe apk (mcpelauncher-linux can download and extract it for you) and copy it into the jni/ directory.
Then run ndk-build in this directory. After that copy the output .so from libs/x86/ to the launcher's mods/ directory.
