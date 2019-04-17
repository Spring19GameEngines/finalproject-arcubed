import mygameengine

engine = mygameengine.GameEngine.getInstance()
engine.init(1080, 720)

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
rc.loadAnimation("Assets/art/character.png", 12)
rc.setScale(3)
rc.setFrameDelay(4)
character.components.addComponent(rc)

engine.run()
