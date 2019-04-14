import os

COMPILER = "clang++"

EXEC_NAME = "linux_gui"
ARGUMENTS = "-D LINUX -std=c++14 -o " + EXEC_NAME

SOURCE = [
    "./src/*.cpp",
    "./library/imgui/imgui*.cpp",
    "./library/imgui/examples/imgui_impl_sdl.cpp",
    "./library/imgui/examples/imgui_impl_opengl3.cpp",
    "./library/imgui/examples/libs/gl3w/GL/gl3w.c"
]
SOURCE = " ".join(SOURCE)

# Which directories do we want to include.
INCLUDES = [
    "./include/",
    "/usr/include/SDL2",
    "./library/imgui",
    "./library/imgui/examples",
    "./library/imgui/examples/libs/gl3w"
]
INCLUDES = ['-I{0}'.format(inc) for inc in INCLUDES]
INCLUDES = " ".join(INCLUDES)

# What libraries do we want to include
LIBRARIES = [
    "GL",
    "dl",
    "SDL2",
    "SDL2_image",
    "SDL2_mixer",
    "SDL2_ttf"
]
LIBRARIES = ['-l{0}'.format(lib) for lib in LIBRARIES]
LIBRARIES = (" ".join(LIBRARIES))


# Build a string of our compile commands that we run in the terminal

compileString = [
    COMPILER,
    ARGUMENTS,
    INCLUDES,
    SOURCE,
    LIBRARIES
]
compileString = " ".join(compileString)

# Print out the compile string
print(compileString)

# Run our command
os.system(compileString)
