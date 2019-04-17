#include "RendererComponent.h"

RendererComponent::RendererComponent(GameObject *go) : Component("RENDERERCOMPONENT")
{
    this->go = go;
}
RendererComponent::RendererComponent(Component *component) : Component(component->getName()) {}

void RendererComponent::update()
{
    if (camCentered)
    {
        ResourceManager::getInstance().camX = go->pos.x + (this->w * this->scale / 2) -
                                              (ResourceManager::getInstance().SCREEN_WIDTH / 2);
        ResourceManager::getInstance().camY = go->pos.y + (this->h * this->scale / 2) -
                                              (ResourceManager::getInstance().SCREEN_HEIGHT / 2);
    }
    render();
}

// Sends a message to the parent component container
void RendererComponent::send(string action, vector<std::string> args)
{
    if (container != NULL)
    {
        container->send(action, args);
    }
    else
    {
        cout << "Failed to send message" << endl;
    }
}
// default
void RendererComponent::receive(string action, vector<string> args)
{
    return;
}

void RendererComponent::loadAnimation(string path, int startingFrame, int numFrames, int totalSheetFrames)
{
    SDL_Texture *texture = ResourceManager::getInstance().loadTexture(
        path, ResourceManager::getInstance().gRenderer);
    if (texture != nullptr)
    {
        int w, h;
        SDL_QueryTexture(texture, NULL, NULL, &w, &h);
        this->w = w / totalSheetFrames;
        this->h = h;
        this->go->width = this->w;
        this->go->height = this->h;
        this->loadedAnimation[path] = texture;
        this->animationFrames[path] = std::make_tuple(startingFrame, numFrames);
        setAnimation(path);
    }
    else
    {
        cout << "Failed to load Animation" << endl;
    }
}

void RendererComponent::setScale(int scale)
{
    if (scale > 0)
    {
        this->scale = scale;
        this->go->scale = scale;
    }
    else
    {
        cout << "Scale must be > 0" << endl;
    }
}

void RendererComponent::setFrameDelay(int delay)
{
    if (delay >= 0)
    {
        this->frameDelay = delay;
    }
    else
    {
        cout << "Delay must be >= 0" << endl;
    }
}

void RendererComponent::setCamCentered(bool flag)
{
    this->camCentered = flag;
}
// Allows the user to set a alias for a loaded sound path
void RendererComponent::setAnimationAlias(string alias, string existingPath)
{
    if (loadedAnimation.find(existingPath) == loadedAnimation.end())
    {
        cout << "Existing path does not exist" << endl;
        return;
    }
    if (animationAliases.find(alias) != animationAliases.end())
    {
        animationAliases[alias] = existingPath;
    }
    else
    {
        cout << "Animation alias already exists" << endl;
        return;
    }
}
vector<string> RendererComponent::getAnimationAliases()
{
    vector<string> aliases;
    for (auto &pair : animationAliases)
    {
        aliases.push_back("\"" + pair.first + "\" -> \"" + pair.second + "\"");
    }
    return aliases;
}

void RendererComponent::setAnimation(string alias)
{
    if (animationAliases.find(alias) != animationAliases.end())
    {
        currentAnimationPath = animationAliases[alias];
    }
    else if (loadedAnimation.find(alias) != loadedAnimation.end())
    {
        currentAnimationPath = alias;
    }
    else
    {
        cout << "Could not find animation alias or path" << endl;
    }
}
void RendererComponent::render()
{
    int camX = ResourceManager::getInstance().camX;
    int camY = ResourceManager::getInstance().camY;

    SDL_Rect Dest = {(int)go->pos.x - camX, (int)go->pos.y - camY, this->w * this->scale, this->h * this->scale};
    SDL_Rect Src = {this->w * (currentFrame + std::get<0>(animationFrames[currentAnimationPath])), 0, this->w, this->h};
    SDL_RenderCopy(ResourceManager::getInstance().gRenderer, loadedAnimation[currentAnimationPath], &Src, &Dest);
    if (framesPassed++ == frameDelay)
    {
        framesPassed = 0;
        currentFrame++;
    }

    if (currentFrame >= std::get<1>(animationFrames[currentAnimationPath]))
    {
        currentFrame = 0;
    }
}