#

**GLFW** abstracts the creation and management of the window when using OpenGL. **GLAD** simplifies loading OpenGL function pointers.

#

**Context** refers to the OpenGL's state. **Objects** are a section of this state that can be defined and then bound and unbound as needed, which is how data is loaded to the GPU and renderization parameters are controlled.

**Shader** programs need to be compiled at runtime before being used. Vertex and fragment shaders always need to be provided. 

**Vertex Buffer Objects (VBOs)** stores simple, sequential vertex data. **Element Buffer Objects (EBOs)** stores an ordered list of indicies referencing the vertices in a VBO, which allows to describe complex geometry avoiding repeated vertices. **Vertex Array Objects (VAOs)** stores binding references of both VBOs and EBOs, alongside metadata, to be used during rendering. This data can be used to draw different types of primitives.