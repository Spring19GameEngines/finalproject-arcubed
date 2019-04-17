from mygameengine import *

engine = GameEngine.getInstance()
engine.init(420, 630)

# SCRIPTS


class Jump(Command):
    def __init__(self):
        Command.__init__(self)

    def setGameObject(self, gameobject):
        self.go = gameobject

    def execute(self):
        rigidbody = self.go.getComponent("RIGIDBODYCOMPONENT")
        rigidbody.setForceY(-20)


class AngleComponent(Component):
    def __init__(self, gameobject):
        Component.__init__(self, "ANGLECOMPONENT")
        self.go = gameobject

    def update(self):
        rb = self.go.getComponent("RIGIDBODYCOMPONENT")
        angle = (rb.getForceY() / 30.0) * 45

        rc = self.go.getComponent("RENDERERCOMPONENT")
        rc.setAngle(angle)

    def send(self, action, args):
        return

    def receive(self, action, args):
        return


# Music
bgm = "Assets/sound/music/level1.mp3"
music_component = SoundComponent()
music_component.loadMusic(bgm)
music_component.playMusic(bgm)
music_component.update()

# Flappy Bird
flappy = engine.createGameObject("FlappyBird", 100, 150, 0, 0)
# Rendering
flappy_sprite = RendererComponent(flappy)
flappy_sprite.loadAnimation("Assets/art/flappy_bird.png", 0, 1, 1)
flappy.addComponent(flappy_sprite)
angle_component = AngleComponent(flappy)
flappy.addComponent(angle_component)
# RigidBody
flappy_body = RigidBody(flappy)
flappy_body.setGravity(-2)
flappy_body.setMaxForceY(30)
flappy.addComponent(flappy_body)
# Input
jump = Jump()
controller = InputComponent(flappy)
controller.setButton(44, jump)  # 44 is SPACEBAR
flappy.addComponent(controller)

# Pipe


engine.run()
