// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include <common/shader.hpp>

int main( void )
{
	// Initialise GLFW
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		getchar();
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow( 1024, 768, "Tutorial 02 - Red triangle", NULL, NULL);
	if( window == NULL ){
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	// Create and compile our GLSL program from the shaders
	GLuint programID = LoadShaders( "SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader" );

	// Get a handle for our "MVP" uniform
	GLuint MatrixID = glGetUniformLocation(programID, "MVP");

	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	// Camera matrix
	glm::mat4 View       = glm::lookAt(
								glm::vec3(4,3,-3), // Camera is at (4,3,-3), in World Space
								glm::vec3(0,0,0), // and looks at the origin
								glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
						   );
	// Model matrix : an identity matrix (model will be at the origin)
	glm::mat4 Model      = glm::mat4(1.0f);
	// Our ModelViewProjection : multiplication of our 3 matrices
	glm::mat4 MVP        = Projection * View * Model; // Remember, matrix multiplication is the other way around

	// Our vertices. Tree consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
	// A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
	static const GLfloat g_vertex_buffer_data[] = { 
		-1.0f,-1.0f,-1.0f, // triangle 1 : begin
    	-1.0f,-1.0f, 1.0f,
    	-1.0f, 1.0f, 1.0f, // triangle 1 : end
    	1.0f, 1.0f,-1.0f, // triangle 2 : begin
    	-1.0f,-1.0f,-1.0f,
    	-1.0f, 1.0f,-1.0f, // triangle 2 : end
    	1.0f,-1.0f, 1.0f,
    	-1.0f,-1.0f,-1.0f,
    	1.0f,-1.0f,-1.0f,
    	1.0f, 1.0f,-1.0f,
    	1.0f,-1.0f,-1.0f,
    	-1.0f,-1.0f,-1.0f,
    	-1.0f,-1.0f,-1.0f,
    	-1.0f, 1.0f, 1.0f,
    	-1.0f, 1.0f,-1.0f,
    	1.0f,-1.0f, 1.0f,
    	-1.0f,-1.0f, 1.0f,
    	-1.0f,-1.0f,-1.0f,
    	-1.0f, 1.0f, 1.0f,
    	-1.0f,-1.0f, 1.0f,
    	1.0f,-1.0f, 1.0f,
    	1.0f, 1.0f, 1.0f,
    	1.0f,-1.0f,-1.0f,
    	1.0f, 1.0f,-1.0f,
    	1.0f,-1.0f,-1.0f,
    	1.0f, 1.0f, 1.0f,
    	1.0f,-1.0f, 1.0f,
    	1.0f, 1.0f, 1.0f,
    	1.0f, 1.0f,-1.0f,
    	-1.0f, 1.0f,-1.0f,
    	1.0f, 1.0f, 1.0f,
    	-1.0f, 1.0f,-1.0f,
    	-1.0f, 1.0f, 1.0f,
    	1.0f, 1.0f, 1.0f,
    	-1.0f, 1.0f, 1.0f,
    	1.0f,-1.0f, 1.0f
	};
	// One color for each vertex. They were generated randomly.
	static const GLfloat g_color_buffer_data[] = { 
		// 1st square
		0.1f, 0.1f, 0.1f,
		0.1f, 0.1f, 0.1f,
		0.1f, 0.1f, 0.1f,

		0.11f, 0.11f, 0.11f,
		0.11f, 0.11f, 0.11f,
		0.11f, 0.11f, 0.11f,

		0.12f, 0.12f, 0.12f,
		0.12f, 0.12f, 0.12f,
		0.12f, 0.12f, 0.12f,

		0.13f, 0.13f, 0.13f,
		0.13f, 0.13f, 0.13f,
		0.13f, 0.13f, 0.13f,

		0.14f, 0.14f, 0.14f,
		0.14f, 0.14f, 0.14f,
		0.14f, 0.14f, 0.14f,

		0.15f, 0.15f, 0.15f,
		0.15f, 0.15f, 0.15f,
		0.15f, 0.15f, 0.15f,

		0.16f, 0.16f, 0.16f,
		0.16f, 0.16f, 0.16f,
		0.16f, 0.16f, 0.16f,

		0.17f, 0.17f, 0.17f,
		0.17f, 0.17f, 0.17f,
		0.17f, 0.17f, 0.17f,

		0.18f, 0.18f, 0.18f,
		0.18f, 0.18f, 0.18f,
		0.18f, 0.18f, 0.18f,

		0.19f, 0.19f, 0.19f,
		0.19f, 0.19f, 0.19f,
		0.19f, 0.19f, 0.19f,

		0.2f, 0.2f, 0.2f,
		0.2f, 0.2f, 0.2f,
		0.2f, 0.2f, 0.2f,

		0.21f, 0.21f, 0.21f,
		0.21f, 0.21f, 0.21f,
		0.21f, 0.21f, 0.21f,
	};

	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	GLuint colorbuffer;
	glGenBuffers(1, &colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);

	do{

		// Clear the screen
		glClear( GL_COLOR_BUFFER_BIT );

		// Use our shader
		glUseProgram(programID);

		// Send our transformation to the currently bound shader, 
		// in the "MVP" uniform
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

		// 1rst attribute buffer : vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);

		// 2nd attribute buffer : colors
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
		glVertexAttribPointer(
			1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
			3,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);
		

		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 12*3); // 3 indices starting at 0 -> 1 triangle

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );

	// Cleanup VBO
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteVertexArrays(1, &VertexArrayID);
	glDeleteProgram(programID);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
