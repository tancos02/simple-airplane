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
#include <common/controls.hpp>

#include "vertex_points.h"

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
	window = glfwCreateWindow( 1024, 768, "Simple Airplane", NULL, NULL);
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

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	// Create and compile our GLSL program from the shaders
	GLuint programID = LoadShaders( "SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader" );

	// Get a handle for our "MVP" uniform
	GLuint MatrixID = glGetUniformLocation(programID, "MVP");

	// Our vertices. Tree consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
	// A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
	static const GLfloat g_vertex_buffer_data[] = { 
		// Badan utama
		// depan
		0.0f, 0.0f, 0.5f,
		1.5f, 0.0f, 0.5f,
		0.0f, 0.5f, 0.5f,
		1.5f, 0.0f, 0.5f,
		0.0f, 0.5f, 0.5f,
		1.5f, 0.5f, 0.5f,
		// belakang--
		0.0f, 0.0f, 0.0f,
		1.5f, 0.0f, 0.0f,
		0.0f, 0.5f, 0.0f,
		1.5f, 0.0f, 0.0f,
		0.0f, 0.5f, 0.0f,
		1.5f, 0.5f, 0.0f,
		// kanan
		1.5f, 0.0f, 0.5f,
		1.5f, 0.0f, 0.0f,
		1.5f, 0.5f, 0.5f,
		1.5f, 0.5f, 0.5f,
		1.5f, 0.0f, 0.0f,
		1.5f, 0.5f, 0.0f,
		// kiri
		0.0f, 0.0f, 0.5f,
		0.0f, 0.5f, 0.5f,
		0.0f, 0.0f, 0.0f,
		0.0f, 0.5f, 0.5f,
		0.0f, 0.0f, 0.0f,
		0.0f, 0.5f, 0.0f,
		// atas
		0.0f, 0.5f, 0.5f,
		1.5f, 0.5f, 0.5f,
		0.0f, 0.5f, 0.0f,
		1.5f, 0.5f, 0.5f,
		0.0f, 0.5f, 0.0f,
		1.5f, 0.5f, 0.0f,
		// bawah
		0.0f, 0.0f, 0.5f,
		1.5f, 0.0f, 0.5f,
		0.0f, 0.0f, 0.0f,
		1.5f, 0.0f, 0.5f,
		0.0f, 0.0f, 0.0f,
		1.5f, 0.0f, 0.0f,

		// Baling-baling
		// Baling-baling atas
		// belakang
		0.0f, 0.25f, 0.25f,
		0.0f, 0.5f, 0.14f,
		0.0f, 0.5f, 0.36f,
		// depan
		-0.1f, 0.5f, 0.14f,
		-0.1f, 0.5f, 0.36f,
		-0.1f, 0.25f, 0.25f,
		// sisi 1
		0.0f, 0.25f, 0.25f,
		-0.1f, 0.25f, 0.25f,
		-0.1f, 0.5f, 0.36f,

		-0.1f, 0.5f, 0.36f,
		0.0f, 0.5f, 0.36f,
		0.0f, 0.25f, 0.25f,
		// sisi 2
		0.0f, 0.25f, 0.25f,
		-0.1f, 0.25f, 0.25f,
		-0.1f, 0.5f, 0.14f,

		-0.1f, 0.5f, 0.14f,
		0.0f, 0.5f, 0.14f,
		0.0f, 0.25f, 0.25f,
		// sisi 3
		0.0f, 0.5f, 0.14f,
		-0.1f, 0.5f, 0.14f,
		-0.1f, 0.5f, 0.36f,

		-0.1f, 0.5f, 0.36f,
		0.0f, 0.5f, 0.36f,
		0.0f, 0.5f, 0.14f,
	
		// Baling-baling kiri
		// belakang
		0.0f, 0.25f, 0.25f,
		0.0f, 0.0f, 0.16f,
		0.0f, 0.16f, 0.0f,
		// depan
		-0.1f, 0.25f, 0.25f,
		-0.1f, 0.0f, 0.16f,
		-0.1f, 0.16f, 0.0f,
		// sisi 1
		0.0f, 0.25f, 0.25f,
		-0.1f, 0.25f, 0.25f,
		-0.1f, 0.16f, 0.0f,

		0.0f, 0.25f, 0.25f,
		0.0f, 0.0f, 0.16f,
		-0.1f, 0.0f, 0.16f,
		// sisi 2
		-0.1f, 0.0f, 0.16f,
		-0.1f, 0.16f, 0.0f,
		0.0f, 0.0f, 0.16f,

		0.0f, 0.0f, 0.16f,
		0.0f, 0.16f, 0.0f,
		-0.1f, 0.16f, 0.0f,
		// sisi 3
		-0.1f, 0.25f, 0.25f,
		-0.1f, 0.16f, 0.0f,
		0.0f, 0.16f, 0.0f,

		-0.1f, 0.25f, 0.25f,
		0.0f, 0.25f, 0.25f,
		0.0f, 0.16f, 0.0f,


		// Baling-baling kanan
		// belakang
		0.0f, 0.25f, 0.25f,
		0.0f, 0.0f, 0.32f,
		0.0f, 0.16f, 0.5f,
		// depan
		-0.1f, 0.25f, 0.25f,
		-0.1f, 0.0f, 0.32f,
		-0.1f, 0.16f, 0.5f,
		// sisi 1
		0.0f, 0.25f, 0.25f,
		-0.1f, 0.25f, 0.25f,
		-0.1f, 0.0f, 0.32f,

		-0.1f, 0.0f, 0.32f,
		0.0f, 0.0f, 0.32f,
		0.0f, 0.25f, 0.25f,
		// sisi 2
		0.0f, 0.0f, 0.32f,
		-0.1f, 0.0f, 0.32f,
		-0.1f, 0.16f, 0.5f,

		-0.1f, 0.16f, 0.5f,
		0.0f, 0.16f, 0.32f,
		0.0f, 0.0f, 0.32f,
		// sisi 3
		0.0f, 0.25f, 0.25f,
		-0.1f, 0.25f, 0.25f,
		-0.1f, 0.16f, 0.5f,

		-0.1f, 0.16f, 0.5f,
		0.0f, 0.16f, 0.32f,
		0.0f, 0.25f,0.25f,

		// Ekor mendatar
		// Depan
		1.2f, 0.5f, 0.75f,
		1.45f, 0.5f, 0.75f,
		1.2f, 0.6f, 0.75f,
		1.45f, 0.5f, 0.75f,
		1.2f, 0.6f, 0.75f,
		1.45f, 0.6f, 0.75f,
		// belakang
		1.2f, 0.5f, -0.25f,
		1.45f, 0.5f, -0.25f,
		1.2f, 0.6f, -0.25f,
		1.45f, 0.5f, -0.25f,
		1.2f, 0.6f, -0.25f,
		1.45f, 0.6f, -0.25f,
		// kanan
		1.45f, 0.5f, 0.75f,
		1.45f, 0.5f, -0.25f,
		1.45f, 0.6f, 0.75f,
		1.45f, 0.6f, 0.75f,
		1.45f, 0.5f, -0.25f,
		1.45f, 0.6f, -0.25f,
		// kiri
		1.2f, 0.5f, 0.75f,
		1.2f, 0.6f, 0.75f,
		1.2f, 0.5f, -0.25f,
		1.2f, 0.6f, 0.75f,
		1.2f, 0.5f, -0.25f,
		1.2f, 0.6f, -0.25f,
		// atas
		1.2f, 0.6f, 0.75f,
		1.45f, 0.6f, 0.75f,
		1.2f, 0.6f, -0.25f,
		1.45f, 0.6f, 0.75f,
		1.2f, 0.6f, -0.25f,
		1.45f, 0.6f, -0.25f,
		// bawah
		1.2f, 0.5f, 0.75f,
		1.45f, 0.5f, 0.75f,
		1.2f, 0.5f, -0.25f,
		1.45f, 0.5f, 0.75f,
		1.2f, 0.5f, -0.25f,
		1.45f, 0.5f, -0.25f,

		// Sayap tegak
		// depan
		1.2f, 0.6f, 0.3f,
		1.45f, 0.6f, 0.3f,
		1.2f, 0.85f, 0.3f,
		1.45f, 0.6f, 0.3f,
		1.2f, 0.85f, 0.3f,
		1.45f, 0.85f, 0.3f,
		// belakang--
		1.2f, 0.6f, 0.2f,
		1.45f, 0.6f, 0.2f,
		1.2f, 0.85f, 0.2f,
		1.45f, 0.6f, 0.2f,
		1.2f, 0.85f, 0.2f,
		1.45f, 0.85f, 0.2f,
		// kanan
		1.45f, 0.6f, 0.3f,
		1.45f, 0.6f, 0.2f,
		1.45f, 0.85f, 0.3f,
		1.45f, 0.85f, 0.3f,
		1.45f, 0.6f, 0.2f,
		1.45f, 0.85f, 0.2f,
		// kiri
		1.2f, 0.6f, 0.3f,
		1.2f, 0.85f, 0.3f,
		1.2f, 0.6f, 0.2f,
		1.2f, 0.85f, 0.3f,
		1.2f, 0.6f, 0.2f,
		1.2f, 0.85f, 0.2f,
		// atas
		1.2f, 0.85f, 0.3f,
		1.45f, 0.85f, 0.3f,
		1.2f, 0.85f, 0.2f,
		1.45f, 0.85f, 0.3f,
		1.2f, 0.85f, 0.2f,
		1.45f, 0.85f, 0.2f,
		// bawah
		1.2f, 0.6f, 0.3f,
		1.45f, 0.6f, 0.3f,
		1.2f, 0.6f, 0.2f,
		1.45f, 0.6f, 0.3f,
		1.2f, 0.6f, 0.2f,
		1.45f, 0.6f, 0.2f,

		// Sayap bawah
		// depan
		0.4f,-0.1f, 1.0f,
		0.8f,-0.1f, 1.0f,
		0.4f, 0.0f, 1.0f,
		0.8f,-0.1f, 1.0f,
		0.4f, 0.0f, 1.0f,
		0.8f, 0.0f, 1.0f,
		// belakang--
		0.4f,-0.1f, -0.5f,
		0.8f,-0.1f, -0.5f,
		0.4f, 0.0f, -0.5f,
		0.8f,-0.1f, -0.5f,
		0.4f, 0.0f, -0.5f,
		0.8f, 0.0f, -0.5f,
		// kanan
		0.8f,-0.1f, 1.0f,
		0.8f,-0.1f, -0.5f,
		0.8f, 0.0f, 1.0f,
		0.8f, 0.0f, 1.0f,
		0.8f,-0.1f, -0.5f,
		0.8f, 0.0f, -0.5f,
		// kiri
		0.4f,-0.1f, 1.0f,
		0.4f, 0.0f, 1.0f,
		0.4f,-0.1f, -0.5f,
		0.4f, 0.0f, 1.0f,
		0.4f,-0.1f, -0.5f,
		0.4f, 0.0f, -0.5f,
		// atas
		0.4f, 0.0f, 1.0f,
		0.8f, 0.0f, 1.0f,
		0.4f, 0.0f, -0.5f,
		0.8f, 0.0f, 1.0f,
		0.4f, 0.0f, -0.5f,
		0.8f, 0.0f, -0.5f,
		// bawah
		0.4f,-0.1f, 1.0f,
		0.8f,-0.1f, 1.0f,
		0.4f,-0.1f, -0.5f,
		0.8f,-0.1f, 1.0f,
		0.4f,-0.1f, -0.5f,
		0.8f,-0.1f, -0.5f,

		// Sayap atas
		// depan
		0.4f, 0.5f, 1.0f,
		0.8f, 0.5f, 1.0f,
		0.4f, 0.6f, 1.0f,
		0.8f, 0.5f, 1.0f,
		0.4f, 0.6f, 1.0f,
		0.8f, 0.6f, 1.0f,
		// belakang--
		0.4f, 0.5f, -0.5f,
		0.8f, 0.5f, -0.5f,
		0.4f, 0.6f, -0.5f,
		0.8f, 0.5f, -0.5f,
		0.4f, 0.6f, -0.5f,
		0.8f, 0.6f, -0.5f,
		// kanan
		0.8f, 0.5f, 1.0f,
		0.8f, 0.5f, -0.5f,
		0.8f, 0.6f, 1.0f,
		0.8f, 0.6f, 1.0f,
		0.8f, 0.5f, -0.5f,
		0.8f, 0.6f, -0.5f,
		// kiri
		0.4f, 0.5f, 1.0f,
		0.4f, 0.6f, 1.0f,
		0.4f, 0.5f, -0.5f,
		0.4f, 0.6f, 1.0f,
		0.4f, 0.5f, -0.5f,
		0.4f, 0.6f, -0.5f,
		// atas
		0.4f, 0.6f, 1.0f,
		0.8f, 0.6f, 1.0f,
		0.4f, 0.6f, -0.5f,
		0.8f, 0.6f, 1.0f,
		0.4f, 0.6f, -0.5f,
		0.8f, 0.6f, -0.5f,
		// bawah
		0.4f, 0.5f, 1.0f,
		0.8f, 0.5f, 1.0f,
		0.4f, 0.5f, -0.5f,
		0.8f, 0.5f, 1.0f,
		0.4f, 0.5f, -0.5f,
		0.8f, 0.5f, -0.5f,

	};

	// One color for each vertex. They were generated randomly.
	static const GLfloat g_color_buffer_data[] = { 
		// Badan Utama
		0.1f, 0.1f, 0.1f,
		0.1f, 0.1f, 0.1f,
		0.1f, 0.1f, 0.1f,

		0.1f, 0.1f, 0.1f,
		0.1f, 0.1f, 0.1f,
		0.1f, 0.1f, 0.1f,

		0.1f, 0.1f, 0.1f,
		0.1f, 0.1f, 0.1f,
		0.1f, 0.1f, 0.1f,

		0.1f, 0.1f, 0.1f,
		0.1f, 0.1f, 0.1f,
		0.1f, 0.1f, 0.1f,

		0.1f, 0.1f, 0.1f,
		0.1f, 0.1f, 0.1f,
		0.1f, 0.1f, 0.1f,

		0.1f, 0.1f, 0.1f,
		0.1f, 0.1f, 0.1f,
		0.1f, 0.1f, 0.1f,

		0.1f, 0.1f, 0.1f,
		0.1f, 0.1f, 0.1f,
		0.1f, 0.1f, 0.1f,

		0.1f, 0.1f, 0.1f,
		0.1f, 0.1f, 0.1f,
		0.1f, 0.1f, 0.1f,

		0.1f, 0.1f, 0.1f,
		0.1f, 0.1f, 0.1f,
		0.1f, 0.1f, 0.1f,

		0.1f, 0.1f, 0.1f,
		0.1f, 0.1f, 0.1f,
		0.1f, 0.1f, 0.1f,

		0.1f, 0.1f, 0.1f,
		0.1f, 0.1f, 0.1f,
		0.1f, 0.1f, 0.1f,

		0.1f, 0.1f, 0.1f,
		0.1f, 0.1f, 0.1f,
		0.1f, 0.1f, 0.1f,

		// Baling-baling
		// atas
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,

		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,

		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,

		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,

		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,

		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,

		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,

		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		// kiri
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,

		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,

		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,

		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,

		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,

		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,

		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,

		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		// kanan
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,

		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,

		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,

		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,

		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,

		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,

		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,

		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,

		// Ekor Mendatar
		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,

		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,

		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,

		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,

		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,

		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,

		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,

		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,

		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,

		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,

		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,

		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,

		// Ekor tegak
	    0.75f, 0.75f, 0.5f,
		0.75f, 0.75f, 0.5f,
		0.75f, 0.75f, 0.5f,

		0.75f, 0.75f, 0.5f,
		0.75f, 0.75f, 0.5f,
		0.75f, 0.75f, 0.5f,

		0.75f, 0.75f, 0.5f,
		0.75f, 0.75f, 0.5f,
		0.75f, 0.75f, 0.5f,

		0.75f, 0.75f, 0.5f,
		0.75f, 0.75f, 0.5f,
		0.75f, 0.75f, 0.5f,

		0.75f, 0.75f, 0.5f,
		0.75f, 0.75f, 0.5f,
		0.75f, 0.75f, 0.5f,

		0.75f, 0.75f, 0.5f,
		0.75f, 0.75f, 0.5f,
		0.75f, 0.75f, 0.5f,

		0.75f, 0.75f, 0.5f,
		0.75f, 0.75f, 0.5f,
		0.75f, 0.75f, 0.5f,

		0.75f, 0.75f, 0.5f,
		0.75f, 0.75f, 0.5f,
		0.75f, 0.75f, 0.5f,

		0.75f, 0.75f, 0.5f,
		0.75f, 0.75f, 0.5f,
		0.75f, 0.75f, 0.5f,

		0.75f, 0.75f, 0.5f,
		0.75f, 0.75f, 0.5f,
		0.75f, 0.75f, 0.5f,

		0.75f, 0.75f, 0.5f,
		0.75f, 0.75f, 0.5f,
		0.75f, 0.75f, 0.5f,

		0.75f, 0.75f, 0.5f,
		0.75f, 0.75f, 0.5f,
		0.75f, 0.75f, 0.5f,

		// Sayap atas
		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,

		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,

		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,

		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,

		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,

		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,

		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,

		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,

		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,

		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,

		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,

		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,

		 // Sayap bawah
		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,

		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,

		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,

		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,

		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,

		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,

		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,

		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,

		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,

		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,

		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,

		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,
		 0.25f,  0.3f, 0.5f,
		 
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
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Use our shader
		glUseProgram(programID);

		// Compute the MVP matrix from keyboard input
		computeMatricesFromInputs();
		glm::mat4 ProjectionMatrix = getProjectionMatrix();
		glm::mat4 ViewMatrix = getViewMatrix();
		glm::mat4 ModelMatrix = getModelMatrix();
		glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;

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
		if (getShaderStatus() == 1) {
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
		}
		

		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 84*3); // 3 indices starting at 0 -> 1 triangle

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

