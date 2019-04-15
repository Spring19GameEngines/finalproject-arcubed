#include "SpriteTool.h"
#include <string>

using namespace std;

SpriteTool& SpriteTool::getInstance() {
  static SpriteTool instance;
  return instance;
}

// Disabled
SpriteTool::SpriteTool() {}
SpriteTool::~SpriteTool() {}

void SpriteTool::setTexture() {
  SDL_FreeSurface(spriteSheet);
  std::string asset_path = "assets/";
  spriteSheet = IMG_Load((asset_path + asset_name).c_str());

  if (spriteSheet == NULL) {
    SDL_Log("Failed to Allocate Surface");
  }

  SDL_DestroyTexture(texture);
  texture = SDL_CreateTextureFromSurface(renderer, spriteSheet);
}

// Render
void SpriteTool::renderGUI() {
  ImGui::Begin("SpriteTool");

  static int _width = 1;
  static int _height = 1;
  static int mag = 1;
  static int _rows = 1;
  static int _cols = 1;
  static int frame1 = 1;
  static int anim_len = 1;
  static int tick_rate = 1;

  ImGui::Columns(2);

  // Spritesheet fields
  ImGui::Text("Spritesheet");
  ImGui::PushItemWidth(100);
  ImGui::InputScalar("rows", ImGuiDataType_S16, &_rows, &INCREMENT, NULL, "%d");
  ImGui::InputScalar("columns", ImGuiDataType_S16, &_cols, &INCREMENT, NULL,
                     "%d");
  ImGui::Text("");

  ImGui::NextColumn();

  // Sprite fields
  ImGui::Text("Sprite");
  ImGui::PushItemWidth(100);
  ImGui::InputScalar("width (px)", ImGuiDataType_S16, &_width, &INCREMENT, NULL,
                     "%d");
  ImGui::InputScalar("height (px)", ImGuiDataType_S16, &_height, &INCREMENT,
                     NULL, "%d");
  ImGui::InputScalar("magnify", ImGuiDataType_S16, &mag, &INCREMENT, NULL,
                     "%d");
  ImGui::Text("");

  // Console for name
  ImGui::PushItemWidth(200);
  ImGui::InputText("Spritesheet Name", asset_name, 64);
  if (ImGui::Button("accept")) {
    rows = _rows;
    cols = _cols;
    spriteWidth = _width;
    spriteHeight = _height;
    magnify = mag;
    startingFrame = frame1 - 1;
    currentFrame = 0;
    numFrames = anim_len;
    tickRate = tick_rate;
    setTexture();
  }

  ImGui::NextColumn();

  // Animation fields
  ImGui::Text("Animation");
  ImGui::PushItemWidth(100);
  ImGui::InputScalar("first frame", ImGuiDataType_S16, &frame1, &INCREMENT,
                     NULL, "%d");
  ImGui::InputScalar("animation length", ImGuiDataType_S16, &anim_len,
                     &INCREMENT, NULL, "%d");
  ImGui::InputScalar("ticks per frame", ImGuiDataType_S16, &tick_rate,
                     &INCREMENT, NULL, "%d");

  // Entire spritesheet
  if (texture != NULL) {
    getSrc();
    getDest();
    SDL_RenderCopy(renderer, texture, &Src, &Dest);
  }

  ImGui::End();
}

void SpriteTool::getSrc() {
  if (this->currentFrame >= this->numFrames) {
    this->currentFrame = 0;
  }

  // SRC
  Src.x = ((startingFrame + currentFrame) % cols) * spriteWidth;
  Src.y = ((startingFrame + currentFrame) / cols) * spriteHeight;
  Src.w = this->spriteWidth;
  Src.h = this->spriteHeight;

  if (this->currentTick >= this->tickRate) {
    this->currentTick = 0;
    this->currentFrame += 1;
  }

  this->currentTick++;
}

void SpriteTool::getDest() {
  ImVec2 windowpos = ImGui::GetWindowPos();
  Dest.x = windowpos.x;
  Dest.y = windowpos.y - this->spriteHeight * this->magnify;
  Dest.w = this->spriteWidth * this->magnify;
  Dest.h = this->spriteHeight * this->magnify;
}
