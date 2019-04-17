import mygameengine

engine = mygameengine.GameEngine.getInstance()
engine.init(420, 630)

mus_path = "Assets/sound/music/level1.mp3"

# Music
bgm = engine.createGameObject("Music", 400, 400, 0, 0)
sc = mygameengine.SoundComponent()
sc.loadMusic(mus_path)
bgm.components.addComponent(sc)
csc = bgm.components.getComponent("SOUNDCOMPONENT")
csc.playMusic(mus_path)

# Character
character = engine.createGameObject("Fox", 400, 400, 0, 0)
rc = mygameengine.RendererComponent(character)
rc.loadAnimation("Assets/art/character.png", 6, 6, 12)
rc.setScale(3)
rc.setFrameDelay(4)
character.components.addComponent(rc)

# RigidBody
rb = mygameengine.RigidBody(character)
rb.setUseGravity(False)
rb.setIsKinematic(False)
character.components.addComponent(rb)


# Input
class Move(mygameengine.Command):
    def __init__(self, x, y):
        mygameengine.Command.__init__(self)
        self.x = x
        self.y = y

    def setGameObject(self, gameobject):
        self.go = gameobject

    def execute(self):
        rigidbody = self.go.components.getComponent("RIGIDBODYCOMPONENT")
        rigidbody.setForce(self.x, self.y)


input = mygameengine.InputComponent(character)
mLeft = Move(-3, 0)
mRight = Move(3, 0)
input.setButton(4, mLeft)
input.setButton(7, mRight)
character.components.addComponent(input)

engine.run()
