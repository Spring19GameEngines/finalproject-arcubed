#include "RendererComponent.h"

RendererComponent::RendererComponent(GameObject *go) : Component("RENDERERCOMPONENT")
{
    this->x = go->pos.x;
    this->y = go->pos.y;
    this->go = go;
}
RendererComponent::RendererComponent(Component *component) : Component(component->getName()) {}

void RendererComponent::update()
{
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

void RendererComponent::loadAnimation(string path, int frames)
{
    SDL_Texture *texture = ResourceManager::getInstance().loadTexture(
        path, ResourceManager::getInstance().gRenderer);
    if (texture != nullptr)
    {
        int w, h;
        SDL_QueryTexture(texture, NULL, NULL, &w, &h);
        this->w = w / frames;
        this->h = h;
        this->go->width = this->w;
        this->go->height = this->h;
        this->loadedAnimation[path] = texture;
        this->animationFrames[path] = frames;
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
    }
    else
    {
        cout << "Scale must be > 0" << endl;
    }
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
    SDL_Rect Dest = {this->x, this->y, this->w * this->scale, this->h * this->scale};
    SDL_Rect Src = {this->w * currentFrame, 0, this->w, this->h};
    SDL_RenderCopy(ResourceManager::getInstance().gRenderer, loadedAnimation[currentAnimationPath], &Src, &Dest);
    currentFrame++;
    if (currentFrame >= animationFrames[currentAnimationPath])
    {
        currentFrame = 0;
    }
}