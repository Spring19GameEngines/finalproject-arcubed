# Final Project

This is it--the final course project!

# Final Project - Description

<img width="400px" src="./media/greats.png">

The industry is getting positive buzz as Nolan and Shigeru have been talking about your game development skills. But dynamics change rapidly in the game industry--your team has once again decided to part ways and form a new game studio. Your team during this time has  developed a nice codebase of intellectual property, and has decided forming a 'game making' studio around this technology is the best option. Building an impressive piece of middleware (i.e. a tool or technology that is not a game) to showcase at the giant tradeshows ([PAX East](http://east.paxsite.com/), [GDC](https://www.gdconf.com/), [E3](https://www.e3expo.com/), etc.) is your next task!

# Final Project Options

## Option 1 - Game Maker

For your final project, you will make a 'game maker'. That is, you will build a tool that someone with no C++ knowledge can use. Our pybind11 lab is a good starting point, though you are allowed to explore other technologies like [lua](https://www.lua.org/). For this project, you will build an API (i.e. 2D API or 3D API) for your games and a GUI environment for building your game. 

**You will** implement part of at least 1 classic or original game we have not previously implemented (e.g. pacman, asteroids, snake, super mario, etc.) using your engine to demonstrate how your engine is used.

### Some notes on building a game maker

1. Very likely you will need to integrate some GUI library into your system to make it useable.
2. *Think* data-driven
   - This means your C++ handles your engine, and your scripting language should handle the game logic.

### Examples

See below some example game making tools for inspiration:

- Look on the left panel to see the API for the Love2D engine: https://love2d.org/wiki/Main_Page
- Look at Gamemakers API for inspiration of what commands are exposed. http://docs2.yoyogames.com/
- Here is an example showing integrating an API (through a console interface) with a script language to make changes and build a game in realtime. https://www.youtube.com/watch?v=b8RyQSvmrEU
- https://www.youtube.com/watch?v=5ZuQIbMEjLw (Here is GoDot engine. I would look to GoDot and GameMaker as inspiration).

## Option 2 - Engine API Tech Demo (2D or 3D)

You may implement an API (e.g. a physics engine, or a sound engine) that could be plugged into another technology. For your final project you will then build a high powered tech demo showing off this API. This tech demo would be a short showcase of your engine API showcaseing your technology. The demo can be 2D or 3D--though I urge 2D to keep things smple.

### Some notes on building an engine API

1. For this project you are building a C/C++ API to solve a specific game engine need (e.g. a physics engine, a sound engine).
2. You need to demonstrate its usefulness in a concrete way.
   - Building your engine as a shared library(.so, .dylib, .dll) and using it in another engine.
   - Concrete examples:
      - You build a physics engine as a .dll, and use it with OGRE3D.
      - You build a physics engine and use it with pygame and all of the physics are handled by your library.
3. You need to demonstrate useful game programming patterns with this system.
4. You need to implement at least one classic or original game using our engine API.

## Examples

See below some examples engine apis for inspiration.

- A physics engine with many samples
   - https://www.youtube.com/watch?v=ni-SmkCY-Sw (2D game demo showing off only 1 feature that is sufficiently complex)
- This is a illumination/lighting engine 
   - https://www.youtube.com/watch?v=4W8zxAV8RRY (2D game engine lighting effects)
   - This project does not however have much *wow* factor. (Probably a B- project)
- Here is another illumination engine
   - https://www.youtube.com/watch?v=LseTVMkG7V8 
   - An even better 2D game engine lighting effects, something like this is final project worthy if incorporated into platformer. (Probably in the B+/A- range as it looks like some actual physics are being used, and there is a neat 'debugging' mode to show where light is reaching)
- Here is another lighting engine 
   - https://www.youtube.com/watch?v=jVlxmC2qBGU (Unity3D Tech demo showing off one simple but high powered toggable feature in an editor).
   - This project has a nice GUI, updates in realtime, and looks like it could 
- https://www.youtube.com/watch?v=wB1pcXtEwIs Shows off a subset of a physics engine in use.
   - Here is a more concrete example of the API that would be implemented in tutorial form: https://www.youtube.com/watch?v=3Oay1YxkP5c&list=PLEETnX-uPtBXm1KEr_2zQ6K_0hoGH6JJ0

## Option 3

If neither of these options satisfy you--talk to the instructor if there is something you are more excited about. Generally speaking, most folks should be attempting or targeting projects closer to option 1's for the final project.

# Constraints on Options 1,2,3

For any option you choose, you have the following constraints:

1. Your team must build the majority of your technology.
   - If you use 3rd party code (Say a compression library for example--which would be fine), then cite your source.
2. It is expected you may reuse some code from previous projects.
3. 3rd party libraries for a physics engine are okay if you want to incorporate it into Option 1 for example (If you are implementing a physics engine from scratch in option 2, then you may not use a previously built physics engine.)
4. You cannot build a tech demo with Unity3D or Unreal Engine.
5. Most of your 

Note--if you have not taken computer graphics, you should not be attempting to learn 3D graphics during this duration. It is highly recommended to work on a 2D project.

# Requirements of the final Project

1. Minimum Viable Product
2. Documentation
3. A polished and well engineered project (think of all the game programming patterns we have learned--put them into practice!)
4. Some 'wow' factor that demonstrates you put time, thought, and effort into the project.

# Minimum Viable Product

Make sure you filled out the [Minimum Viable Product](./mvp.md)

# Documentation/Portfolio Requirements (For any option)

## Documentation
Fire up 'Doxygen' <a href="http://www.stack.nl/~dimitri/doxygen/">(Doxygen webpage)</a> to document the source code and automatically generate .html pages. 

- Your documentation should cover your classes and functions.
- Your documentation should have instructions on how to obtain, build, and run your final project. 
   - It must be trivial for a TA or instructor to run your project.

## Build (binary file)
You need to have a compiled binary of your game. You can assume a target audience of either a 64-bit Mac, Ubuntu Linux, or Windows 10 machine. There should additionally be instructions about how to compile your code from source.

## Post mortem
A post mortem in games is a look back at what could be improved. Write a brief (2-3 paragraphs) on what could be improved if you had an additional 8 weeks to work on this project. Where would you allocate time, what tools would you build, would you use any different tools, etc.

## Website

This website will be the first place I look to grab your project. (Additionally, I think it is important to build a portfolio of your game development works!)

Your 1-page .html website includes:

- Your documentation
- A link to your binary
- Uour post mortem
- A 1 minute video trailer
- At least 3 screenshots of your game
- At least 1 diagram showing off the architecture of your code
   - This can be a system diagram, a UML diagram of your classes, or your overall architecture.
   - examples:
      - https://www.gameenginebook.com/figures.html
      - http://tombstoneengine.com/architecture.php
      - https://www.ogre3d.org/docs/manual18/images/uml-overview.png
         - Found on this page https://www.ogre3d.org/docs/manual18/manual_4.html#The-Core-Objects

## Project Hieararchy

There should be some logical hierarchy for your project. Look to previous assignments for inspiration. Your project should not differ greatly unless there is a reason justified in your documentation.

# Rubric (35% of overall grade)
   
<table>
  <tbody>
    <tr>
      <th>Points</th>
      <th align="center">Description</th>
    </tr>
    <tr>
      <td>25% (Documentation/Portfolio Requirements)</td>
      <td align="left">On meeting the requirements above. Do not forget the diagram showing off your solutions architecture</td>
    </tr>    
    <tr>
      <td>25% (Engineering/Design Patterns)</td>
      <td align="left">On the polish of your final project (did it work as intended, were there bugs, did I have to struggle to get your tool running, was your solution well engineered, were there patterns used, etc.)</td>
    </tr>
    <tr>
      <td>25%  (Minimum viable product)</td>
      <td align="left">If you achieved your "Minimum viable product" (from your lab proposal.)</td>
    </tr>
    <tr>
      <td>25%% (Wow Factor)</td>
      <td align="left">On the creativity and overall 'wow' factor of your project. Was there a cool feature or surprise that got me excited about the project? Does this project have potential to be extended in the future? Were there creative additional tools that supported your work. Was there something not covered in class that you were excited about, learned, and implemented anyway? (Document this to bring to my attention if so!)</td>
    </tr>
  </tbody>
</table>

**Note: Everyone on your team earns the same grade for all parts of the project.**

# More Resources

- Writing a press release (Something you should do for your engine or games in the future)
  - https://www.gamedev.net/articles/business/business-and-law/the-last-how-to-write-a-press-release-post-youll-ever-need-r4951
