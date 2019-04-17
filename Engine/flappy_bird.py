from mygameengine import *
import random
import time

engine = GameEngine.getInstance()
engine.init(504, 756)

lost = False

point_sound = "Assets/sound/effects/sfx_point.wav"
flap_sound = "Assets/sound/effects/sfx_wing.wav"
hit_sound = "Assets/sound/effects/sfx_hit.wav"

# SCRIPTS


class Jump(Command):
    def __init__(self):
        Command.__init__(self)
        self.prev_flap = time.time()

    def setGameObject(self, gameobject):
        self.go = gameobject

    def execute(self):
        global lost
        if lost:
            return

        if (self.prev_flap - time.time() < -0.15):
            rigidbody = self.go.getComponent("RIGIDBODYCOMPONENT")
            rigidbody.setForceY(-30)

            sc = self.go.getComponent("SOUNDCOMPONENT")
            sc.playEffect(flap_sound)
            self.prev_flap = time.time()


class CheckLoss(Component):

    def __init__(self, gameobject):
        Component.__init__(self, "CHECKLOSS")
        self.go = gameobject

    def update(self):
        global lost

        if not lost:
            hitbox = self.go.getComponent("BOXCOLLIDERCOMPONENT")
            if hitbox.anyCollision():
                sc = self.go.getComponent("SOUNDCOMPONENT")
                sc.playEffect(hit_sound)
                lost = True
                displayLoss()

    def send(self, action, args):
        return

    def receive(self, action, args):
        return


class DriftLeft(Component):
    def __init__(self, gameobject):
        Component.__init__(self, "DRIFTLEFT")
        self.go = gameobject

    def update(self):
        global lost
        if lost:
            return

        rb = self.go.getComponent("RIGIDBODYCOMPONENT")
        rb.setForceX(-4)

        if 98 < self.go.pos.x < 102:
            if self.go.name == "BotPipe1":
                sc = self.go.getComponent("SOUNDCOMPONENT")
                sc.playEffect(point_sound)

        if self.go.pos.x <= -118:
            self.go.pos.x = 500
            if self.go.name == "BotPipe1":
                self.go.pos.y = random.randint(400, 600)
            else:
                bot_pipe = engine.getGameObject("BotPipe1")
                self.go.pos.y = bot_pipe.pos.y - 697

    def send(self, action, args):
        return

    def receive(self, action, args):
        return


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


def displayLoss():
    gameover.loadAnimation("Assets/art/you_lose.png", 0, 1, 1)
    gameover.setScale(2)


# Music
bgm = "Assets/sound/music/level1.mp3"
music_component = SoundComponent()
music_component.loadMusic(bgm)
music_component.playMusic(bgm)
music_component.update()

# Background
background = engine.createGameObject("Background", 0, -10, 0, 0)
# Rendering
bg = RendererComponent(background)
bg.loadAnimation("Assets/art/flappy_bird_background.jpg", 0, 1, 1)
bg.setScale(2)
background.addComponent(bg)

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
# Sound
flappy_sound = SoundComponent()
flappy_sound.loadEffect(flap_sound)
flappy_sound.loadEffect(hit_sound)
flappy.addComponent(flappy_sound)
# Hitbox
flappy_hitbox = BoxCollider(flappy)
flappy.addComponent(flappy_hitbox)
check_loss = CheckLoss(flappy)
flappy.addComponent(check_loss)


# Pipe
pipe1 = engine.createGameObject("BotPipe1", 450, 500, 108, 447)
# Rendering
pipe_sprite1 = RendererComponent(pipe1)
pipe_sprite1.loadAnimation("Assets/art/pipe.png", 0, 1, 1)
pipe1.addComponent(pipe_sprite1)
# RigidBody
pipe_body1 = RigidBody(pipe1)
pipe_body1.setUseGravity(False)
pipe_body1.setIsKinematic(True)
pipe1.addComponent(pipe_body1)
# Script
drift_script1 = DriftLeft(pipe1)
pipe1.addComponent(drift_script1)
# Sound
pipe_sound_component = SoundComponent()
pipe_sound_component.loadEffect(point_sound)
pipe1.addComponent(pipe_sound_component)
# Hitbox
pipe_hitbox = BoxCollider(pipe1)
pipe1.addComponent(pipe_hitbox)

# Pipe
pipe2 = engine.createGameObject("TopPipe1", 450, 500, 108, 447)
pipe2.pos.y -= 250
pipe2.pos.y -= 447
# Rendering
pipe_sprite2 = RendererComponent(pipe2)
pipe_sprite2.loadAnimation("Assets/art/pipe.png", 0, 1, 1)
pipe_sprite2.setFlipVertical(True)
pipe2.addComponent(pipe_sprite2)
# RigidBody
pipe_body2 = RigidBody(pipe2)
pipe_body2.setUseGravity(False)
pipe_body2.setIsKinematic(True)
pipe2.addComponent(pipe_body2)
# Script
drift_script2 = DriftLeft(pipe2)
pipe2.addComponent(drift_script2)
# Hitbox
pipe_hitbox2 = BoxCollider(pipe2)
pipe2.addComponent(pipe_hitbox2)

loss = engine.createGameObject("GameOver", 75, 100, 0, 0)
gameover = RendererComponent(loss)
loss.addComponent(gameover)

engine.run()
