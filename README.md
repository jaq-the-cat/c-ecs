# ecsj

Simple Entity Component System made in C

## Usage
Components need 2 elements, a structure for its data and a number to identify it. In the example, the structures are located in `include/components.h` and the identifiers are all in an enum.

Then, to make a component, simply declare a variable with type `component_t` with the `COMPONENT` macro. Its arguments are as following:
  - The structure type name
  - The type identifier
  - The data to be stored

Now you can freely pass around the `component_t` variable and get its type with `name.type`. Have fun!
