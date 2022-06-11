# c-ecs

Simple Entity Component System made in C

## Usage
- Initialize component list with CS_INIT(\<list_name\>)
- Create components with COMPONENT(\<type\>_T, \<c_name\>, \<data\>)
- Add them to the component list with cs_add(\<list_name\>, \<c_name\>)
- Iterate through the components with cs_iter(\<list_name\>, \<func\>)
- That's it for now, I made it as a little test :P
