#include <iostream>
#include <memory>
#include <vector>

// Command Interface
class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
};

// Receiver Class
class Light {
public:
    void on() {
        std::cout << "The light is on\n";
    }
    
    void off() {
        std::cout << "The light is off\n";
    }
};

// Concrete Command for turning the light on
class LightOnCommand : public Command {
public:
    LightOnCommand(std::shared_ptr<Light> light) : light(light) {}

    void execute() override {
        light->on();
    }

    void undo() override {
        light->off();
    }

private:
    std::shared_ptr<Light> light;
};

// Concrete Command for turning the light off
class LightOffCommand : public Command {
public:
    LightOffCommand(std::shared_ptr<Light> light) : light(light) {}

    void execute() override {
        light->off();
    }

    void undo() override {
        light->on();
    }

private:
    std::shared_ptr<Light> light;
};

// Invoker Class
class RemoteControl {
public:
    void setCommand(std::shared_ptr<Command> command) {
        this->command = command;
    }

    void pressButton() {
        if (command) {
            command->execute();
            history.push_back(command);
        }
    }

    void pressUndo() {
        if (!history.empty()) {
            history.back()->undo();
            history.pop_back();
        }
    }

private:
    std::shared_ptr<Command> command;
    std::vector<std::shared_ptr<Command>> history;
};

int main() {
    auto light = std::make_shared<Light>();

    auto lightOn = std::make_shared<LightOnCommand>(light);
    auto lightOff = std::make_shared<LightOffCommand>(light);

    RemoteControl remote;

    remote.setCommand(lightOn);
    remote.pressButton(); // Output: The light is on

    remote.setCommand(lightOff);
    remote.pressButton(); // Output: The light is off

    remote.pressUndo(); // Output: The light is on

    return 0;
}
