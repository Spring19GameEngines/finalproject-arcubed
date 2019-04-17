from mygameengine import *

engine = GameEngine.getInstance()
engine.init(420, 630)

# JUMP COMMAND


class Jump(Command):
    def __init__(self):
        Command.__init__(self)

    def setGameObject(self, gameobject):
        self.gameobject = gameobject

    def execute(self):
        rigidbody = self.gameobject.getComponent("RIGIDBODYCOMPONENT")
        rigidbody.setForceY(6)


# Music
bgm = "Assets/sound/music/level1.mp3"
music_component = SoundComponent()
music_component.loadMusic(bgm)
music_component.playMusic(bgm)
music_component.update()

# Flappy Bird
flappy = engine.createGameObject("FlappyBird", 150, 150, 0, 0)
# Rendering
flappy_sprite = RendererComponent(flappy)
flappy_sprite.loadAnimation("Assets/art/flappy_bird.png", 0, 1, 1)
flappy.addComponent(flappy_sprite)
# RigidBody
flappy_body = RigidBody(flappy)
flappy.addComponent(flappy_body)


engine.run()
