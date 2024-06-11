## Design Patterns: The Command Pattern

### to run this code:
#### step 1 - g++ -std=c++11 -o command_pattern command_pattern.cpp
#### step 2 - ./command_pattern   

Explanation:

    Command Interface (Command): This is an abstract base class with execute and undo methods.
    Receiver Class (Light): This class contains the actual business logic (turning the light on and off).
    Concrete Commands (LightOnCommand, LightOffCommand): These classes implement the Command interface and encapsulate the actions on the Light receiver.
    Invoker (RemoteControl): This class holds a command and can execute or undo it. It maintains a history to support the undo functionality.

This example showcases how the Command Pattern can be implemented in modern C++ to achieve decoupling between the sender and receiver, and add flexibility in command execution and reversal.
