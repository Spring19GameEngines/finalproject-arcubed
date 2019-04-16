import os

COMPILER = "g++"

EXEC_NAME = "engine.so"
ARGUMENTS = "-D LINUX -std=c++14 -fPIC -o " + EXEC_NAME

SOURCE = [
    "./src/*.cpp",
    "./lib/imgui/imgui*.cpp",
    "./lib/imgui/examples/imgui_impl_sdl.cpp",
    "./lib/imgui/examples/imgui_impl_opengl3.cpp",
    "./lib/imgui/examples/libs/gl3w/GL/gl3w.c"
]
SOURCE = " ".join(SOURCE)

# Which directories do we want to include.
INCLUDES = [
    "./include/",
    "./lib/pybind11/include/",
    "/usr/include/SDL2",
    "./lib/imgui",
    "./lib/imgui/examples",
    "./lib/imgui/examples/libs/gl3w"
]
INCLUDES = ['-I{0}'.format(inc) for inc in INCLUDES]
INCLUDES = " ".join(INCLUDES) + " `python3 -m pybind11 --includes`"

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
LIBRARIES = (" ".join(LIBRARIES)) + " " + "`python3-config --ldflags`"


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
