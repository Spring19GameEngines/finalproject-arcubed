import mygameengine

engine = mygameengine.GameEngine.getInstance()
engine.init(1080, 720)

mus_path = "Assets/sound/music/level1.mp3"
music_comp = mygameengine.SoundComponent()
music_comp.loadMusic(mus_path)
music_comp.playMusic(mus_path)
