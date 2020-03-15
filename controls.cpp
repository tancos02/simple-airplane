// Include GLFW
#include <GLFW/glfw3.h>
extern GLFWwindow* window; // The "extern" keyword here is to access the variable "window" declared in tutorialXXX.cpp. This is a hack to keep the tutorials simple. Please avoid this.

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include "controls.hpp"

glm::mat4 ViewMatrix;
glm::mat4 ProjectionMatrix;
glm::mat4 ModelMatrix = glm::mat4(1.0);
glm::mat4 initMatrix = glm::mat4(1.0);
int shaderStatus;

glm::mat4 getViewMatrix(){
	return ViewMatrix;
}
glm::mat4 getProjectionMatrix(){
	return ProjectionMatrix;
}
glm::mat4 getModelMatrix(){
	return ModelMatrix;
}
int getShaderStatus() {
	return shaderStatus;
}

// Initial horizontal angle : toward -Z
float horizontalAngle = 90.0f;
// Initial vertical angle : none
float verticalAngle = 0.0f;
// Initial angle for Model
float angle = 0.0f;
// Initial Field of View
float initialFoV = 45.0f;
// radius
float rad = 5.0f;
// x init pos
float x = -5.0f;
// y init pos
float y = 0.0f;
// z init pos
float z = 0.0f;
// Angle for the head of projection plane
float projPlaneAngle = 0.0f;

// Initial position : on +Z
glm::vec3 position = glm::vec3( x,y,z ); 

float speed = 3.0f; // 3 units / second

glm::vec3 initPos(-rad,0,0);
glm::vec3 initDir(0,0,0);
glm::vec3 deltaPositionVector(0.01,0,0.01);
// Direction for camera
glm::vec3 direction(0,0,0);
// Up vector
glm::vec3 up(0,1,0);
glm::vec3 initUp(0,1,0);


void computeMatricesFromInputs(){

	// glfwGetTime is called only once, the first time this function is called
	static double lastTime = glfwGetTime();

	// Compute time difference between current and last frame
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);

	// Get mouse position
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);

	// Reset mouse position for next frame
	glfwSetCursorPos(window, 1024/2, 768/2);

	// X rotation
	glm::mat4 xRotate(
		
	);


	// Move forward
	if (glfwGetKey( window, GLFW_KEY_UP ) == GLFW_PRESS){
		position -= position*deltaPositionVector;
		x -= 0.01f;
		z -= 0.01f;
		rad -= 0.01*sqrt(2);
	}
	// Move backward
	if (glfwGetKey( window, GLFW_KEY_DOWN ) == GLFW_PRESS){
		position += position*deltaPositionVector;
		x += 0.01f;
		z += 0.01f;
		rad += 0.01*sqrt(2);
	}
	// Strafe right
	if (glfwGetKey( window, GLFW_KEY_RIGHT ) == GLFW_PRESS){
		angle+=0.01f;
		glm::vec3 rotateVector(-rad*cos(angle),0,rad*sin(angle));
		position = rotateVector;
	}
	// Strafe left
	if (glfwGetKey( window, GLFW_KEY_LEFT ) == GLFW_PRESS){
		angle-=0.01f;
		glm::vec3 rotateVector(-rad*cos(angle),0,rad*sin(angle));
		position = rotateVector;
	}

	// Projection Plane Rotation
	if (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS) {
		projPlaneAngle+=0.01f;
		glm::vec3 rotateVector(0,cos(projPlaneAngle),sin(projPlaneAngle));
		up = rotateVector;
	}
	if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS) {
		projPlaneAngle-=0.01f;
		glm::vec3 rotateVector(0,cos(projPlaneAngle),sin(projPlaneAngle));
		up = rotateVector;
	}

	// Model x rotation
	if(glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) {
		// ViewMatrix = ViewMatrix*deltaTime*
	}
	// Model y rotation
	if(glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) {

	}
	// Model z rotation
	if(glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS) {

	}	
	if(glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS) {
		shaderStatus = 1;
	}
	else if (glfwGetKey(window,GLFW_KEY_Y) == GLFW_PRESS) {
		shaderStatus = 0;
	}
	// Reset view
	if(glfwGetKey(window,GLFW_KEY_R) == GLFW_PRESS) {
		position = initPos;
		direction = initDir;
		rad = 5.0f;
		x = -5.0f;
		y = 0.0f;
		z = 0.0f;
		up = initUp;
		ModelMatrix = initMatrix;
	}

		// Rotation X
	if(glfwGetKey(window,GLFW_KEY_Q) == GLFW_PRESS) {
		// Use #include <glm/gtc/matrix_transform.hpp> and #include <glm/gtx/transform.hpp>
		glm::vec3 myRotationAxis( 1,0,0);
		glm::mat4 rotationMatrix = glm::rotate( glm::mat4(1.0f), 0.05f, myRotationAxis );
		ModelMatrix = rotationMatrix * ModelMatrix;
	}

	if(glfwGetKey(window,GLFW_KEY_W) == GLFW_PRESS) {
		// Use #include <glm/gtc/matrix_transform.hpp> and #include <glm/gtx/transform.hpp>
		glm::vec3 myRotationAxis( 1,0,0);
		glm::mat4 rotationMatrix = glm::rotate( glm::mat4(1.0f), -0.05f, myRotationAxis );
		ModelMatrix = rotationMatrix * ModelMatrix;
	}

	if(glfwGetKey(window,GLFW_KEY_A) == GLFW_PRESS) {
		// Use #include <glm/gtc/matrix_transform.hpp> and #include <glm/gtx/transform.hpp>
		glm::vec3 myRotationAxis( 0,1,0);
		glm::mat4 rotationMatrix = glm::rotate( glm::mat4(1.0f), 0.05f, myRotationAxis );
		ModelMatrix = rotationMatrix * ModelMatrix;
	}

	if(glfwGetKey(window,GLFW_KEY_S) == GLFW_PRESS) {
		// Use #include <glm/gtc/matrix_transform.hpp> and #include <glm/gtx/transform.hpp>
		glm::vec3 myRotationAxis( 0,1,0);
		glm::mat4 rotationMatrix = glm::rotate( glm::mat4(1.0f), -0.05f, myRotationAxis );
		ModelMatrix = rotationMatrix * ModelMatrix;
	}

	if(glfwGetKey(window,GLFW_KEY_Z) == GLFW_PRESS) {
		// Use #include <glm/gtc/matrix_transform.hpp> and #include <glm/gtx/transform.hpp>
		glm::vec3 myRotationAxis( 0,0,1);
		glm::mat4 rotationMatrix = glm::rotate( glm::mat4(1.0f),0.05f, myRotationAxis );
		ModelMatrix = rotationMatrix * ModelMatrix;
	}

	if(glfwGetKey(window,GLFW_KEY_X) == GLFW_PRESS) {
		// Use #include <glm/gtc/matrix_transform.hpp> and #include <glm/gtx/transform.hpp>
		glm::vec3 myRotationAxis( 0,0,1);
		glm::mat4 rotationMatrix = glm::rotate( glm::mat4(1.0f),-0.05f, myRotationAxis );
		ModelMatrix = rotationMatrix * ModelMatrix;
	}

	float FoV = initialFoV;// - 5 * glfwGetMouseWheel(); // Now GLFW 3 requires setting up a callback for this. It's a bit too complicated for this beginner's tutorial, so it's disabled instead.
	// Projection matrix : 45� Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	ProjectionMatrix = glm::perspective(glm::radians(FoV), 4.0f / 3.0f, 0.1f, 100.0f);
	ViewMatrix = glm::lookAt(
						position,           // Camera is here
						direction, // and looks here : at the same position, plus "direction"
						up                  // Head is up (set to 0,-1,0 to look upside-down)
					   );
	// For the next frame, the "last time" will be "now"
	lastTime = currentTime;
}