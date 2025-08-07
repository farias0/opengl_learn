#

**GLFW** abstracts the creation and management of the window when using OpenGL. **GLAD** simplifies loading OpenGL function pointers.

#

**Context** refers to the OpenGL's state. **Objects** are a section of this state that can be defined and then bound and unbound as needed, which is how data is loaded to the GPU and renderization parameters are controlled. 

- **Vertex Buffer Objects (VBOs)** stores plain, sequential vertex data. 
- **Element Buffer Objects (EBOs)** stores an ordered list of indicies referencing the vertices in a VBO, which allows to describe complex geometry avoiding repeating vertices. 
- **Vertex Array Objects (VAOs)** stores binded references of both VBOs and EBOs, alongside metadata describing the format of this data, to be used during rendering.

Vertex data stored as part of objects can be used to draw different types of **primitives**.

**Shader** programs need to be compiled at runtime before being used. Vertex and fragment shaders always need to be provided as part of the program.

**Textures** can be bound to the state and then passed to the shaders. The fragment shader can then use this texture data, alonside the **texture coordinates**, to define each fragment's color. Multiple textures can be loaded and passed to the shaders at the same time in different **texture units**.