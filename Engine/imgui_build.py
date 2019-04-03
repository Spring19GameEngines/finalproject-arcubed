import os

COMPILER = "c++"
SOURCE = [
    "./src/main.cpp",
    "./lib/imgui/imgui*.cpp",
    "./lib/imgui/examples/imgui_impl_sdl.cpp",
    "./lib/imgui/examples/imgui_impl_opengl3.cpp",
    "./lib/imgui/examples/libs/gl3w/GL/gl3w.c"
]
SOURCE = " ".join(SOURCE)

# Which directories do we want to include.
INCLUDES = [
    "./include/",
    "/Library/Frameworks/SDL2.framework/Headers",
    "/Library/Frameworks/SDL2_image.framework/Headers",
    "/Library/Frameworks/SDL2_mixer.framework/Headers",
    "/Library/Frameworks/SDL2_ttf.framework/Headers",
    "./lib/imgui",
    "./lib/imgui/examples",
    "./lib/imgui/examples/libs/gl3w"
]
INCLUDES = ['-I{0}'.format(inc) for inc in INCLUDES]
INCLUDES = " ".join(INCLUDES)

# What libraries do we want to include
L_PREFIX = "-F/Library/Frameworks"
DEFAULT_LIBS = "-framework OpenGl -framework CoreFoundation"
LIBRARIES = [
    "SDL2",
    "SDL2_image",
    "SDL2_mixer",
    "SDL2_ttf"
]
LIBRARIES = ['-framework {0}'.format(lib) for lib in LIBRARIES]
LIBRARIES = DEFAULT_LIBS + " " + L_PREFIX + " " + (" ".join(LIBRARIES))

# The name of our executable
EXEC_NAME = "-o program"

# Build a string of our compile commands that we run in the terminal

compileString = [
    COMPILER,
    EXEC_NAME,
    INCLUDES,
    SOURCE,
    LIBRARIES
]
compileString = " ".join(compileString)

# Print out the compile string
print(compileString)

# Run our command
os.system(compileString)
