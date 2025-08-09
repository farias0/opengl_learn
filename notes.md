#

**GLFW** abstracts the creation and management of the window when using OpenGL. **GLAD** simplifies loading OpenGL function pointers.

#

**Context** refers to the OpenGL's state. **Objects** represent a part of this state that can be defined and then bound and unbound as needed, which is how data is loaded to the GPU and renderization parameters are controlled. 

- **Vertex Buffer Objects (VBOs)** stores plain, sequential vertex-related data. 
- **Element Buffer Objects (EBOs)** stores a list of indices referencing the vertices in a VBO, which allows to describe complex geometry avoiding repeating vertices. 
- **Vertex Array Objects (VAOs)** stores references to the buffers of binded VBOs and EBOs, alongside metadata describing the format of this data, to be used during rendering.

Vertex data stored in those buffers can be used to draw different types of **primitives**.

Different **shader** types run at different stages of the rendering pipeline, but only **vertex shaders** (ran for each geometry vertex) and **fragment shaders** (ran later, for each viewport pixel) are required to be provided. Shaders need to be compiled at runtime and then assembled as part of a single program before being used.

**Textures** can be bound to the state (loaded by the GPU) and then passed to the shaders. The fragment shader can then use this texture data, alonside the **texture coordinates**, to define each fragment's color. Multiple textures can be loaded and passed to the shaders at the same time in different **texture units**.

4x4 **matrices** are used to apply transformations (scaling, rotation, translation) to **vectors** when working in the 3D space. These vectors are represented with 4 dimensions (x,y,z,w), known as homogeneous coordinates, which is needed to carry translation operations on them.

> Remeber that matrices multiply from right to left. Or, in code, from bottom to top.

> When applying transformations to objects, most commonly you'll want to do it in this order: Scale, rotation and then translation. Scaling or rotating an object off-center might have undesireable effects.

Matrices can be used to represent different **coordinate systems**. The most important ones are: 

- The **local space** centers around some entity in the scene
- The **world space** represents the scene shared by all entities
- The **view space** centers around the camera 
- The **clip space** is the view space with perspective projection applied (represents the view **frustum**), which allows for object clipping
- The **screen space** is the clip space with the vertex coordinates projected into screen pixels 

To render with perspective, these coordinate systems have to be applied to the world space vertice positions in the vertex shader, according to the following formula:

`gl_Position = projection * view * model * vec4(aPos, 1.0)`

> It's conventional to use right-handed coordinates (-z is forwards) with OpenGL.
