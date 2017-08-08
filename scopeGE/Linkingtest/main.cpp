#include <iostream>
#include "src/graphics/window.h"


int main()
{

	using namespace Scope;
	using namespace graphics;

	Window window("Scope", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	while (!window.closed())
	{
		window.clear();
		if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_1))
		{
			std::cout << "Mouse Button 1 Pressed" << std::endl;
		}

		if (window.isKeyPressed(GLFW_KEY_A))
		{
			std::cout << "A Key Pressed" << std::endl;
		}

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();

		window.update();
	}
	return 0;
} 