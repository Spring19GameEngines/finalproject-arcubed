import os

COMPILER = "g++"
SOURCE = [
    "./src/*.cpp",
    "./lib/imgui/imgui*.cpp",
    "./lib/imgui/examples/imgui_impl_sdl.cpp",
    "./lib/imgui/examples/imgui_impl_opengl3.cpp",
    "./lib/imgui/examples/libs/gl3w/GL/gl3w.c",
    "./lib/imgui_sdl/imgui_sdl.cpp"
]
SOURCE = " ".join(SOURCE)

# The name of our executable
EXECUTABLE = "mygameengine.so"

# You can can add other arguments as you see fit.
# What does the "-D MAC" command do?
ARGUMENTS = "-D MAC -std=c++14 -fPIC" + " -o " + EXECUTABLE

# Which directories do we want to include.
INCLUDES = [
    "./include/",
    "./lib/pybind11/include/",
    "/Library/Frameworks/SDL2.framework/Headers",
    "/Library/Frameworks/SDL2_image.framework/Headers",
    "/Library/Frameworks/SDL2_mixer.framework/Headers",
    "/Library/Frameworks/SDL2_ttf.framework/Headers",
    "./lib/imgui",
    "./lib/imgui/examples",
    "./lib/imgui/examples/libs/gl3w",
    "./lib/imgui_sdl"
]
INCLUDES = ['-I{0}'.format(inc) for inc in INCLUDES]
INCLUDES = (" ".join(INCLUDES)) + " " + "`python3 -m pybind11 --includes`"

# What libraries do we want to include
DEFAULT_LIBS = "-framework OpenGl -framework CoreFoundation"
LIBRARY_PREFIX = "-F/Library/Frameworks"
LIBRARIES = [
    "SDL2",
    "SDL2_image",
    "SDL2_mixer",
    "SDL2_ttf"
]
LIBRARIES = ['-framework {0}'.format(lib) for lib in LIBRARIES]
LIBRARIES = DEFAULT_LIBS + " " + LIBRARY_PREFIX + " " + \
    (" ".join(LIBRARIES)) + " " + "`python3-config --ldflags`"

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
