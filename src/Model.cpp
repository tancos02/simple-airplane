// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;
#include "Model.h"

const GLfloat g_vertex_buffer_data[] = { 
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

const GLfloat g_color_buffer_data[] = { 
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
