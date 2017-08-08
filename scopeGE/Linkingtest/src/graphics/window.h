#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Scope { namespace graphics {
//Input max values
#define  MAX_KEYS	1024
#define	MAX_BUTTONS	32

	class Window
	{
		private:
			const char *m_Title;
			int m_Width, m_Height;
			GLFWwindow *m_Window;
			bool m_Closed;

			//Input functions used for keyboard and Mousebutton codes along with mouse x, and y cords.
			static bool m_keys[MAX_KEYS];
			static bool m_MouseButton[MAX_BUTTONS];
			static double mx, my;
		public:
			Window(const char *name, int width, int height);
			~Window();
			bool closed() const;
			void update();
			void clear() const;
			inline int getWidth() const { return m_Width; }
			inline int getHeight() const { return m_Height; }

			static bool isKeyPressed(unsigned int Keycode);
			static bool isMouseButtonPressed(unsigned int button);

		private:
			bool init();

			friend static void key_callback(GLFWwindow* window, int Key, int scancode, int action, int mods);
			friend static void mouse_button_callback(GLFWwindow* window, int Button, int action, int mods);

	};
}}