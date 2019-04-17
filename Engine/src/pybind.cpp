#include "GameEngine.h"
#include "SoundComponent.h"

/* PYBIND */

#include <pybind11/pybind11.h>
namespace py = pybind11;

PYBIND11_MODULE(mygameengine, m) {
  py::class_<GameEngine>(m, "GameEngine")
      .def("getInstance", &GameEngine::getInstance,
           py::return_value_policy::reference)
      .def("createGameObject",
           py::overload_cast<std::string>(&GameEngine::createGameObject),
           py::return_value_policy::automatic_reference)
      .def("createGameObject",
           py::overload_cast<std::string, float, float, float, float>(
               &GameEngine::createGameObject),
           py::return_value_policy::automatic_reference)
      .def("deleteGameObject", &GameEngine::deleteGameObject,
           py::return_value_policy::automatic_reference)
      .def("getGameObject", &GameEngine::getGameObject,
           py::return_value_policy::automatic_reference)
      .def("update", &GameEngine::update,
           py::return_value_policy::automatic_reference)
      .def("init", &GameEngine::init,
           py::return_value_policy::automatic_reference)
      .def("run", &GameEngine::run);

  py::class_<SoundComponent>(m, "SoundComponent")
      .def(py::init())
      .def(py::init<Component *>(), py::arg("Component"))
      .def("update", &SoundComponent::update,
           py::return_value_policy::automatic_reference)
      .def("loadMusic", &SoundComponent::loadMusic,
           py::return_value_policy::automatic_reference)
      .def("playMusic", &SoundComponent::playMusic,
           py::return_value_policy::automatic_reference)
      .def("loadEffect", &SoundComponent::loadEffect,
           py::return_value_policy::automatic_reference)
      .def("playEffect", &SoundComponent::playEffect,
           py::return_value_policy::automatic_reference)
      .def("setMusicAlias", &SoundComponent::setMusicAlias,
           py::return_value_policy::automatic_reference)
      .def("setEffectAlias", &SoundComponent::setEffectAlias,
           py::return_value_policy::automatic_reference)
      .def("send", &SoundComponent::send,
           py::return_value_policy::automatic_reference)
      .def("receive", &SoundComponent::receive,
           py::return_value_policy::automatic_reference)
      .def("getMusicPaths", &SoundComponent::getMusicPaths,
           py::return_value_policy::automatic_reference)
      .def("getEffectPaths", &SoundComponent::getEffectPaths,
           py::return_value_policy::automatic_reference)
      .def("getMusicAliases", &SoundComponent::getMusicAliases,
           py::return_value_policy::automatic_reference)
      .def("getEffectAliases", &SoundComponent::getEffectAliases,
           py::return_value_policy::automatic_reference);
}
