import mygameengine

engine = mygameengine.GameEngine.getInstance()
engine.init(1080, 720)

mus_path = "Assets/sound/music/level1.mp3"

music = engine.createGameObject("Music, 400, 400, 0, 0")
sc = mygameengine.SoundComponent()
sc.loadMusic(mus_path)
music.components.addComponent(sc)
csc = music.components.getComponent("SOUNDCOMPONENT")
csc.playMusic(mus_path)

# std:: string mus_path = "Assets/sound/music/level1.mp3"
# std:: string sfx_path = "Assets/sound/effects/spin_jump.wav"

# GameObject * music = createGameObject("Music", 400, 400, 0, 0)
# SoundComponent * sc = new SoundComponent()
# sc -> loadMusic(mus_path)
# sc -> loadEffect(sfx_path)
# music -> components -> addComponent(sc)
# RendererComponent * rc = new RendererComponent(music)
# rc -> loadAnimation("Assets/art/character.png", 12)
# rc -> setScale(3)
# music -> components -> addComponent(rc)
# SoundComponent * csc = static_cast < SoundComponent
# * >(music -> components -> getComponent("SOUNDCOMPONENT"))
# csc -> playMusic(mus_path)
# csc -> playEffect(sfx_path)

engine.run()
