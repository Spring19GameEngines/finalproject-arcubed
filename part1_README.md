# Final Project

This is it--the final course project!

# Final Project - Description

<img width="400px" src="./media/greats.png">

The industry is getting positive buzz as Nolan and Shigeru have been talking about your game development skills. But dynamics change rapidly in the game industry--your team has once again decided to part ways and form a new game studio. Your team during this time has  developed a nice codebase of intellectual property, and has decided forming a 'game making' studio around this technology is the best option. Building an impressive piece of middleware (i.e. a tool or technology that is not a game) to showcase at the giant tradeshows ([PAX East](http://east.paxsite.com/), [GDC](https://www.gdconf.com/), [E3](https://www.e3expo.com/), etc.) is your next task!

# Final Project Options

## Option 1 - Game Maker

For your final project, you will make a 'game maker'. That is, you will build a tool that someone with no C++ knowledge can use. Our pybind11 lab is a good starting point, though you are allowed to explore other technologies like [lua](https://www.lua.org/). For this project, you will build an API (i.e. 2D API or 3D API) for your games and a GUI environment for building your game.

### Examples

See below some example game making tools for inspiration:

- Look on the left panel to see the API for the Love2D engine: https://love2d.org/wiki/Main_Page
- Look at Gamemakers API for inspiration of what commands are exposed. http://docs2.yoyogames.com/
- Here is an example showing integrating an API (through a console interface) with a script language to make changes and build a game in realtime. https://www.youtube.com/watch?v=b8RyQSvmrEU
- https://www.youtube.com/watch?v=oU69bjOMTUc (Another platformer, shows off some cool extensions to our project, with transparency, particles, etc.)
- https://www.youtube.com/watch?v=o59PVYfKlzQ (A little RPG like game. Neat effects, and can benefit from some sort of scripting engine for battle sequences).
- https://www.youtube.com/watch?v=5ZuQIbMEjLw (Here is GoDot engine. I would look to GoDot and GameMaker as inspiration).

## Option 2 - Engine API Tech Demo (2D or 3D)

Often a game mechanic or graphical technique is developed into a full game. For your final project you may build a high powered tech demo. This should be a short showcase of some feature demo that showcases your technology. The demo can be 2D or 3D.

## Examples

See below some examples engine apis for inspiration.

- https://www.youtube.com/watch?v=ni-SmkCY-Sw (2D game demo showing off only 1 feature that is sufficiently complex)
- https://www.youtube.com/watch?v=4W8zxAV8RRY (2D game engine lighting effects)
- https://www.youtube.com/watch?v=LseTVMkG7V8 (An even better 2D game engine lighting effects, something like this is final project worthy if incorporated into platformer)
- https://www.youtube.com/watch?v=gLAYBdHxfjs (Shows a few of the features of a game tool)
- https://www.youtube.com/watch?v=jVlxmC2qBGU (Unity3D Tech demo showing off one simple but high powered toggable feature in an editor).
- https://www.youtube.com/watch?v=wB1pcXtEwIs Shows off a subset of a physics engine in use.

## Option 3

If neither of these options satisfy you--talk to the instructor if there is something you are more excited about. Generally speaking, most folks should be attempting or targeting projects closer to option 1's for the final project.

# Constraints on Options 1,2,3

For any option you choose, you have the following constraints:

1. Your team must build the majority of your technology.
   - If you use 3rd party code (Say a compression library for example--which would be fine), then cite your source.
2. 3rd party libraries for a physics engine are okay if you want to incorporate it into Option 1 for example (If you are implementing a physics engine from scratch in option 2, then you may not use a previously built physics engine.)
3. You cannot build a tech demo with Unity3D or Unreal Engine.
4. Most of your 

Note--if you have not taken computer graphics, you should not be attempting to learn 3D graphics during this duration. It is highly recommended to work on a 2D project.

# Requirements of the final Project

1. Minimum Viable Product
2. Documentation
3. A polished and well engineered project (think of all the game programming patterns we have learned--put them into practice!)
4. Some 'wow' factor that demonstrates you put time, thought, and effort into the project.

# Minimum Viable Product

Make sure you filled out the [Minimum Viable Product](./mvp.md)

# Documentation/Portfolio Requirements (For either option)

## Documentation
Fire up 'Doxygen' <a href="http://www.stack.nl/~dimitri/doxygen/">(Doxygen webpage)</a> to document the source code and automatically generate .html pages. Your documentation should cover your classes and functions.

Additionally, you documentation should have instructions on how to obtain, build, and run your final project.

## Build (binary file)
You need to have a compiled binary of your game. You can assume a target audience of either a 64-bit Mac, Ubuntu Linux, or Windows 10 machine. There should additionally be instructions about how to compile your code from source.

## Post mortem
A post mortem in games is a look back at what could be improved. Write a brief (2-3 paragraphs) on what could be improved if you had an additional 8 weeks to work on this project. Where would you allocate time, what tools would you build, would you use any different tools, etc.

## Website
Your documentation, a link to your binary, and your post mortem should be put together on a 1-page .html page. Additionally, provide a 1 minute video trailer(but 1 minute I suggest) and at least 3 screenshots of your game. This website will be the first place I look to grab your project. (Additionally, I think it is important to build a portfolio of your game development works!)

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
      <td align="left">On meeting the requirements above</td>
    </tr>    
    <tr>
      <td>25% (Polish)</td>
      <td align="left">On the polish of your final project (did it work as intended, were there bugs, did I have to struggle to get your tool running)</td>
    </tr>
    <tr>
      <td>25%  (Minimum viable product)</td>
      <td align="left">If you achieved your "Minimum viable product" (from your lab proposal.)</td>
    </tr>
    <tr>
      <td>25%% (Wow Factor)</td>
      <td align="left">On the creativity and overall 'wow' factor of your project. Some of this requirement *could* be met with the following idea. But you are not limited to this rubric. Was there a cool feature or surprise that got me excited about the project? Does this project have potential to be extended in the future? Were there creative additional tools that supported your work. Was there something not covered in class that you were excited about, learned, and implemented anyway? (Document this to bring to my attention if so!)</td>
    </tr>
  </tbody>
</table>

**Note: Everyone on your team earns the same grade for all parts of the project.**

# More Resources

- Writing a press release (Something you should do for your engine or games in the future)
  - https://www.gamedev.net/articles/business/business-and-law/the-last-how-to-write-a-press-release-post-youll-ever-need-r4951
