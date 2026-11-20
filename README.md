# SFML narrative prototype

A work-in-progress **C++ / SFML 3** interactive narrative prototype. It displays character art over a background, reads dialogue from a script file, and advances the dialogue with mouse clicks.

## What's in the prototype

- An 800 × 600 rendering window with background art and a dialogue panel
- Script-driven character names and dialogue text
- Click-to-advance dialogue
- A character-blinking animation using alternate textures
- Separate C++ classes for game flow, characters, scripts, and sprite wrappers

## Source layout

| File | Role |
| --- | --- |
| [`Project1/main.cpp`](Project1/main.cpp) | Creates and runs the game |
| [`Project1/Game.h`](Project1/Game.h) | Main event, update, and render loop |
| [`Project1/Character.h`](Project1/Character.h) | Character sprite and timed blinking |
| [`Project1/ScriptRead.h`](Project1/ScriptRead.h) | Loads lines and speaker names from the script |
| [`Project1/script.txt`](Project1/script.txt) | Example narrative content |

The `Project1` directory also contains assets and SFML-related files.

## Running the project

The code uses the **SFML 3 API** and requires a compatible C++ toolchain. A portable build configuration is not yet provided.

Before attempting to compile and run it:

1. Install or configure SFML 3 and its dependencies.
2. Replace the hard-coded `D:/A_Project_SFML/Project1/...` paths in the source with valid local paths, preferably relative paths.
3. Check that the images, fonts, and `script.txt` are in those locations.
4. Build `Project1/main.cpp` with the required SFML graphics/window/system libraries.

These steps describe the source requirements; the project has not been packaged as a one-command build.

## Limitations and next steps

- Absolute asset paths prevent running the repository unchanged on a new machine.
- Script loading and texture handling need better validation and error handling.
- The prototype does not yet include a build script, automated tests, or a recording of the interaction.
- Next priorities: portable resource paths, CMake configuration, clearer script format, and a short demo GIF.

The goal is to learn how to structure real-time graphical applications in C++ while building a small narrative interaction system.
