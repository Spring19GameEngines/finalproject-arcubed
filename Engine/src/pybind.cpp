#include <pybind11/pybind11.h>
#include "Command.h"
#include "Component.h"
#include "ComponentContainer.h"
#include "GameEngine.h"
#include "GameObject.h"
#include "InputComponent.h"
#include "RendererComponent.h"
#include "RigidBody.h"
#include "SoundComponent.h"

namespace py = pybind11;

class PyCommand : public Command {
 public:
  using Command::Command;

  /* Trampoline (need one for each virtual function) */
  void execute() override {
    PYBIND11_OVERLOAD_PURE(
        void,    /* Return type */
        Command, /* Parent class */
        execute, /* Name of function in C++ (must match Python name) */
    );
  }

  /* Trampoline (need one for each virtual function) */
  void setGameObject(GameObject *go) override {
    PYBIND11_OVERLOAD(
        void,          /* Return type */
        Command,       /* Parent class */
        setGameObject, /* Name of function in C++ (must match Python name) */
        go);
  }
};

class PyComponent : public Component {
 public:
  /* Inherit the constructors */
  using Component::Component;

  /* Trampoline (need one for each virtual function) */
  void update() override {
    PYBIND11_OVERLOAD_PURE(
        void,      /* Return type */
        Component, /* Parent class */
        update,    /* Name of function in C++ (must match Python name) */
    );
  }

  /* Trampoline (need one for each virtual function) */
  void send(std::string action, std::vector<std::string> args) override {
    PYBIND11_OVERLOAD_PURE(
        void,        /* Return type */
        Component,   /* Parent class */
        send,        /* Name of function in C++ (must match Python name) */
        action, args /* Argument(s) */
    );
  }

  void receive(std::string action, std::vector<std::string> args) override {
    PYBIND11_OVERLOAD_PURE(
        void,        /* Return type */
        Component,   /* Parent class */
        receive,     /* Name of function in C++ (must match Python name) */
        action, args /* Argument(s) */
    );
  }

  void setContainer(ComponentContainer *container) override {
    PYBIND11_OVERLOAD(
        void,         /* Return type */
        Component,    /* Parent class */
        setContainer, /* Name of function in C++ (must match Python name) */
        container,    /* Argument(s) */
    );
  }

  std::string getName() override {
    PYBIND11_OVERLOAD(
        std::string, /* Return type */
        Component,   /* Parent class */
        getName,     /* Name of function in C++ (must match Python name) */
    );
  }
};

/* MODULE */

PYBIND11_MODULE(mygameengine, m) {
  /* COMMAND */
  py::class_<Command, PyCommand> command(m, "Command");
  command.def(py::init())
      .def("execute", &Command::execute,
           py::return_value_policy::automatic_reference)
      .def("setGameObject", &Command::setGameObject,
           py::return_value_policy::automatic_reference);

  /* COMPONENT (ABSTRACT) */
  py::class_<Component, PyComponent> component(m, "Component");
  component.def(py::init<std::string>(), py::arg("name"))
      .def("update", &Component::update,
           py::return_value_policy::automatic_reference)
      .def("send", &Component::send,
           py::return_value_policy::automatic_reference)
      .def("receive", &Component::receive,
           py::return_value_policy::automatic_reference)
      .def("setContainer", &Component::setContainer,
           py::return_value_policy::automatic_reference)
      .def("getName", &Component::getName,
           py::return_value_policy::automatic_reference);

  /* COMPONENT CONTAINER */
  py::class_<ComponentContainer>(m, "ComponentContainer")
      .def(py::init())
      .def("update", &ComponentContainer::update,
           py::return_value_policy::automatic_reference)
      .def("addComponent", &ComponentContainer::addComponent,
           py::return_value_policy::automatic_reference)
      .def("removeComponent", &ComponentContainer::removeComponent,
           py::return_value_policy::automatic_reference)
      .def("getComponent", &ComponentContainer::getComponent,
           py::return_value_policy::automatic_reference)
      .def("getComponents", &ComponentContainer::getComponents,
           py::return_value_policy::automatic_reference)
      .def("send", &ComponentContainer::send,
           py::return_value_policy::automatic_reference);

  /* GAME ENGINE */
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

  /* GAME OBJECT */
  py::class_<GameObject>(m, "GameObject")
      .def(py::init<std::string>(), py::arg("name"))
      .def(py::init<std::string, float, float, float, float>(), py::arg("name"),
           py::arg("x"), py::arg("y"), py::arg("width"), py::arg("height"))
      .def("update", &GameObject::update,
           py::return_value_policy::automatic_reference)
      .def_readwrite("pos", &GameObject::pos,
                     py::return_value_policy::automatic_reference)
      .def_readwrite("name", &GameObject::name,
                     py::return_value_policy::automatic_reference)
      .def_readwrite("width", &GameObject::width,
                     py::return_value_policy::automatic_reference)
      .def_readwrite("height", &GameObject::height,
                     py::return_value_policy::automatic_reference)
      .def_readwrite("components", &GameObject::components,
                     py::return_value_policy::automatic_reference);

  /* INPUT COMPONENT */
  py::class_<InputComponent>(m, "InputComponent", component)
      .def(py::init<GameObject *>(), py::arg("gameobject"))
      .def(py::init<Component *>(), py::arg("component"))
      .def("update", &InputComponent::update,
           py::return_value_policy::automatic_reference)
      .def("send", &InputComponent::send,
           py::return_value_policy::automatic_reference)
      .def("receive", &InputComponent::receive,
           py::return_value_policy::automatic_reference)
      .def("setButton", &InputComponent::setButton,
           py::return_value_policy::automatic_reference);

  /* RIGID BODY COMPONENT */
  py::class_<RigidBody>(m, "RigidBody", component)
      .def(py::init<GameObject *>(), py::arg("gameobject"))
      .def("update", &RigidBody::update,
           py::return_value_policy::automatic_reference)
      .def("send", &RigidBody::send,
           py::return_value_policy::automatic_reference)
      .def("receive", &RigidBody::receive,
           py::return_value_policy::automatic_reference)
      .def("setGravity", &RigidBody::setGravity,
           py::return_value_policy::automatic_reference)
      .def("shiftPosition", &RigidBody::shiftPosition,
           py::return_value_policy::automatic_reference)
      .def("setMass", &RigidBody::setMass,
           py::return_value_policy::automatic_reference)
      .def("setDrag", &RigidBody::setDrag,
           py::return_value_policy::automatic_reference)
      .def("setUseGravity", &RigidBody::setUseGravity,
           py::return_value_policy::automatic_reference)
      .def("setIsKinematic", &RigidBody::setIsKinematic,
           py::return_value_policy::automatic_reference)
      .def("addForce", &RigidBody::addForce,
           py::return_value_policy::automatic_reference)
      .def("setForce", &RigidBody::setForce,
           py::return_value_policy::automatic_reference);

  /* RENDERER COMPONENT */
  py::class_<RendererComponent>(m, "RendererComponent", component)
      .def(py::init<GameObject *>(), py::arg("gameobject"))
      .def(py::init<Component *>(), py::arg("component"))
      .def("update", &RendererComponent::update,
           py::return_value_policy::automatic_reference)
      .def("send", &RendererComponent::send,
           py::return_value_policy::automatic_reference)
      .def("receive", &RendererComponent::receive,
           py::return_value_policy::automatic_reference)
      .def("loadAnimation", &RendererComponent::loadAnimation,
           py::return_value_policy::automatic_reference)
      .def("setScale", &RendererComponent::setScale,
           py::return_value_policy::automatic_reference)
      .def("setFrameDelay", &RendererComponent::setFrameDelay,
           py::return_value_policy::automatic_reference)
      .def("setAnimationAlias", &RendererComponent::setAnimationAlias,
           py::return_value_policy::automatic_reference)
      .def("getAnimationAliases", &RendererComponent::getAnimationAliases,
           py::return_value_policy::automatic_reference)
      .def("setAnimation", &RendererComponent::setAnimation,
           py::return_value_policy::automatic_reference);

  /* SOUND COMPONENT */
  py::class_<SoundComponent>(m, "SoundComponent", component)
      .def(py::init())
      .def(py::init<Component *>(), py::arg("component"))
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
