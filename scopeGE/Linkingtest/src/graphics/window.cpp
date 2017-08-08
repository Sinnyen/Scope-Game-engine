#include "window.h"
#include <iostream>


namespace Scope { namespace graphics {

	bool Window::m_keys[MAX_KEYS];
	bool Window::m_MouseButton[MAX_BUTTONS];
	double Window::mx;
	double Window::my;
	void window_Resize(GLFWwindow *window, int width, int height);


		Window::Window(const char *title, int width, int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;
			if (!init())
				glfwTerminate();


			//initalize boolean arrys for input
			for (int i = 0; i < MAX_KEYS; i++)
			{
				m_keys[i] = false;
			}
			for (int i = 0; i < MAX_BUTTONS; i++)
			{
				m_MouseButton[i] = false;
			}
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		bool Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "Failed To initialze GLFW!" << std::endl;
				return false;
			}

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
			if (!m_Window)
			{
				std::cout << "Failed to create GLFW Window" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(m_Window);
			glfwSetWindowUserPointer(m_Window, this);
			glfwSetWindowSizeCallback(m_Window, window_Resize);
			glfwSetKeyCallback(m_Window, key_callback);
			glfwSetMouseButtonCallback(m_Window, mouse_button_callback);

			std::cout << "OpenGl" << glGetString(GL_VERSION) << std::endl;
			
			if (glewInit() != GLEW_OK)
			{
				std::cout << "Could not initialize GLEW!" << std::endl;
				return false;
			}

			return true;
		}

		bool Window::isKeyPressed(unsigned int Keycode)
		{
			if (Keycode >= MAX_KEYS)
				return false;

			return m_keys[Keycode];
		}

		bool Window::isMouseButtonPressed(unsigned int button)
		{
			if (button >= MAX_BUTTONS)
				return false;

			return m_MouseButton[button];
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT);
		}

		void Window::update() 
		{
			glfwPollEvents();
			glfwSwapBuffers(m_Window);
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window) == 1;
		}

		void window_Resize(GLFWwindow *window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		void key_callback(GLFWwindow* window, int Key, int scancode, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_keys[Key] = action != GLFW_RELEASE;
			
		}

		void mouse_button_callback(GLFWwindow* window, int Button, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_MouseButton[Button] = action != GLFW_RELEASE;
		}
		
}}