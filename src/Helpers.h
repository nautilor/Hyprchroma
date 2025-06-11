#pragma once

#include <cstring>
#include <hyprland/src/render/Shader.hpp>
#include <string>

#include <hyprland/src/render/OpenGL.hpp>

#include <hyprland/src/config/ConfigManager.hpp>
#include <hyprland/src/plugins/PluginAPI.hpp>
#include <hyprland/src/render/Renderer.hpp>

#include "TexturesDark.h"

namespace std {
inline void swap(SShader &a, SShader &b) {
  // memcpy because speed!
  // (Would break unordered map, but those aren't in use anyway..)
  uint8_t c[sizeof(SShader)];
  std::memcpy(&c, &a, sizeof(SShader));
  std::memcpy(&a, &b, sizeof(SShader));
  std::memcpy(&b, &c, sizeof(SShader));
}
} // namespace std

struct ShaderHolder {
  SShader RGBA;
  GLint RGBA_Invert;
  SShader RGBX;
  GLint RGBX_Invert;
  SShader EXT;
  GLint EXT_Invert;

  // Holds the background color
  GLint BKGA;
  GLint BKGX;
  GLint BKGE;

  void Init();
  void Destroy();

private:
  GLuint CompileShader(const GLuint &type, std::string src);
  GLuint CreateProgram(const std::string &vert, const std::string &frag);
};
